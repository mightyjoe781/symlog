#include <iostream>
#include <string>
char parser[4] = { 'A', 'E', 'I' , 'O' } ;
int diagonal(int x) {
	return 3-x;
}
int ngb(int x, int y){
	return abs(x-y);	
}
int indexParser(char x){
	for(int i = 0; i<4 ; i++)
		if(x == i)
			return i;
	return -1;
}
char characterParser(int x){
	return parser[x];
}
using namespace std;

int main(){
	char p,q; cin>>p >> q;
	int arr[4] = { 2 };
	// arr = { 0, 1, 2, 3 }
	// arr = [ A  E  I  O ]

	int inp = indexParser(p);
	if( q == 'T') {arr[inp] = 1; arr[diagonal(inp)] = 0; }
	else {arr[inp] = 0; arr[diagonal(inp)] = 1;}

	for(int i = 0; i < 4; i++){
		if(i == inp || i == diagonal(inp)) continue;
		if( inp < 2 && arr[inp] == 1){
			if(abs(x,y) > 1) arr[i] = arr[inp];
			else arr[i] = 0;
		}
		if( inp > 1 && arr[inp] == 0){
			arr[i] = 0;
		}
	}
	for(int i = 0; i < 4 ; i ++)
		cout << arr[i] << " ";

}
