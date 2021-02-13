#include <iostream>
#include <string>
using namespace std;
char parser[4] = { 'A', 'E', 'I' , 'O' } ;
int diagonal(int x) {
	return 3-x;
}
int indexParser(char x){
	for(int i = 0; i<4 ; i++)
		if(x == parser[i])
			return i;
	return -1;
}
char characterParser(int x){
	return parser[x];
}
char eval(int x){
	switch(x){
		case 0 : return 'F';
		case 1 : return 'T';
		case 2 : return 'D';
	}
	return 'x';
}
void prettyPrinter(int arr[], int inp){
	cout << parser[inp] <<":" << eval(arr[inp]) << endl;
	for(int i = 0 ; i< 4; i++){
		if( i==inp) continue;
		else cout << parser[i] <<":" << eval(arr[i]) << endl;
	}
	
}

void squareOfOpposition(){
	char p,q; cin>>p >> q;
	int arr[4] = {2, 2, 2, 2};
	// arr = { 0, 1, 2, 3 }
	// arr = [ A  E  I  O ]

	
	int inp = indexParser(p);
	if( q == 'T') {arr[inp] = 1; arr[diagonal(inp)] = 0; }
	else {arr[inp] = 0; arr[diagonal(inp)] = 1;}

	for(int i = 0; i < 4; i++){
		if(i == inp || i == diagonal(inp)) continue;
		if( inp < 2 && arr[inp] == 1){
			if(abs(i-inp) > 1) arr[i] = arr[inp];
			else arr[i] = 0;
		}
		if( inp > 1 && arr[inp] == 0){
			arr[i] = 0;
		}
	}
	prettyPrinter(arr, inp);
}
