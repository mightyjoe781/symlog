#include <iostream>
#include <string>
using namespace std;
struct prep {
	bool S,P;
	prep(bool S, bool P){
		this->S = S; this->P = P;
	};
};
typedef prep *link;
link init(char a) {
	switch(a){
		case 'A': return new prep(true,false);
		case 'E': return new prep(true,true);
		case 'I': return new prep(false,false);
		case 'O': return new prep(false,true);
	}
	return new prep(true,true);
}
bool quality(char a) {
	if( a == 'A' || a == 'I') return true;
	if( a == 'E' || a == 'O') return false;
	return false;
}
int figure(string p1, string p2, string c){
	if(p1[0] == 'M' && p2[1] == 'M') return 1;
	if(p1[1] == 'M' && p2[1] == 'M') return 2;
	if(p1[0] == 'M' && p2[0] == 'M') return 3;
	if(p1[1] == 'M' && p2[0] == 'M') return 4;
	return 0;
}
void argumentsSolver(){
	string s; cin >> s;
	string p1,p2,c; cin >> p1 >> p2 >> c;
	link x1 = init(s[0]);			
	link x2 = init(s[1]);
	link x3 = init(s[2]);
	
	// checking Rules
	// Rule - 1 (3 terms check)
	if(s.length() == 3) cout << "Rule-1 : Fallacy of 4 terms : Passed" << endl;
	else cout << "Rule-1 : Fallacy of 4 terms : Failed" << endl;

	// Rule - 2 (middle term distribution once )
	bool flag2 = false;
	if ( ( p1[0] == 'M' && x1->S) || ( p1[1] == 'M' && x1->P) || (p2[0] == 'M' && x2->S) || ( p2[1] == 'M' && x2->P)) flag2 = true;
	if ( flag2 ) cout<< "Rule-2 : Fallacy of Undistributed Middle : Passed" << endl;
	else cout<< "Rule-2 : Fallacy of Undistributed Middle : Failed" << endl;

	// Rule - 3 ( Illicit Major // Illicit Minor )
	bool flag3min = true, flag3max = true;
	if( x3->S )
		if(!(( p2[0] == 'M' && x2->P) || (p2[1] == 'M' && x2->S))) flag3min = false;
	if ( x3->P )
		if(!(( p1[0] == 'M' && x1->P) || (p1[1] == 'M' && x1->S))) flag3max = false;
	if( flag3min && flag3max ) cout << "Rule-3 : Illicit Minor/Major : Passed" << endl;
	else if(flag3max) cout << "Rule-3 : Illicit Minor : Failed " << endl;
	else if(flag3min) cout << "Rule-3 : Illicit Major : Failed " << endl;
	else cout << "Rule-3 : Illicit Minor/Major : Failed " << endl;
	
	// Rule - 4 ( 2 Negative Premise -> No conclusion)
	
	if(quality(s[0]) == false && quality(s[1]) == false) cout << "Rule-4 : 2 Negative Premise-> No conclusion : Failed" <<endl; 
	else cout << "Rule-4 : 2 Negative Premise-> No conclusion : Passed" <<endl; 
	
	// Rule - 5 ( 1 premise negative -> conclusion must be negative)
	bool flag5 = true;
	if( (quality(s[0])^quality(s[1])) && !(quality(s[0]) & quality(s[1])) )
		if(quality(s[2]))
			flag5 = false;
	if(flag5) cout<<"Rule-5 : 1 premise negative -> conclusion negative : Passed" << endl;
	else cout << "Rule-5 : 1 premise negative -> conclusion negative : Failed" << endl;
	// Rule - 6 ( if 1 premise particular then conclusion must be particular )
	//
	bool flag6 = true;	
	if( (x1->S == false || x2->S == false))
		if(x3->S == true) flag6 = false;
	if(flag6) cout<< "Rule-6 : 1 particular -> conclusion particular : Passed" << endl;
	else cout<< "Rule-6 : 1 particular -> conclusion particular : Failed" << endl;

	// Rule - 7 ( 2 affirmative -> no negative conclusion )
	bool flag7 = true;
	if( quality(s[0]) & quality(s[1])) 		
		 if(!quality(s[2]))
			 flag7 = false;
	if(flag7) cout << "Rule-7 : 2 Affirmatives -> no negative conclusion: Passed" << endl; 
	else cout << "Rule-7 : 2 Affirmatives -> no negative conclusion: Failed" << endl; 
	// Rule - 8 Existential Fallacy : 2 universal No Particular Conclusion
	// oo
	bool flag8 = true;	
	if( x1->S == true && x2->S == true )
		if(x3->S == false) flag8 = false;
	if(flag8) cout<< "Rule-8 : Existential Fallacy : Passed" << endl;
	else cout<< "Rule-8 : Existential Fallacy : Failed" << endl;

}
