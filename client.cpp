#include <iostream>
#include <string>
#include "argumentsSolver.cpp"
using namespace std;

void menu(){
	cout << endl;
	cout << "Press 1 for Square of Opposition" << endl;
	cout << "Press 2 for Arguments Validator" << endl;
	cout << "Press 3 for Help Documents on I/O" <<endl;
	cout << "Press 0 to exit" << endl;
}
void help(){
	cout << "For command 1 we need to input the arguments and its boolean e.g. A T ( this means universal affirmative true) Program tries to find all possible conclusion it can find from this.\n T-True, F-false, D-Doubtful "<<endl;
	cout << "For command 2 we need to input mode followed by arrangements of major and minor premise along with conclusion e.g. AAA MS MP SP .\n Then program will check for possibility of any rules being broken by this argument;" << endl << endl;
}
int main(){
	cout << "Welcome to Aristotle Concepts Solver : Version 0.2" << endl;
	int c; 
	do {
		menu();
		cin >> c;
		switch(c){
			case 1 : cout << "Input Format : <Argument> <boolean>" << endl;
					 //squareOfOpposition();
					 break;
			case 2 : cout << "Input Format : <mode(3)> <major prep> <minor prep> <conclusion>"<<endl;
					 arguementsSolver();
					 break;
			case 3 : cout << "===== Help Document =====" <<endl;
					 help();
					 break;
		}
	} while ( c!=0 );

}
