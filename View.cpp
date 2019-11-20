#include "View.h"

using namespace std;

void View::printMessage(const string & str){
	cout << str << endl; 
}

void View::printMenu(){ 
	cout << "Menu:" << endl;
	cout << "(0) Quit" << endl;
	cout << "(1) Vanilla." << endl; 
	cout << "(2) Chocolate." << endl;
	cout << "(3) Strawberry." << endl; 
	cout << "(4) Neapolitan." << endl; 
}

int View::getSelection() { 
	string str; 
	int choice = -1; 

	while (1) {
		cout << "Please enter your selection: " << endl; 
		getline(cin, str); 
		stringstream ss(str);
		ss >> choice; 
		if (choice == 0) {
			return 0; 
		}else if (choice > 0 || choice < 5) {
			return choice;
		}
	}

	return choice;
}