#include "Control.h"

using namespace std;

Control::~Control() {
	for(auto & ele : vanillaCone)
		delete ele; 
	for(auto & ele : chocolateCone)
		delete ele; 
	for(auto & ele : strawberryCone) 
		delete ele; 
	for(auto & ele : neapolitanCone)
		delete ele; 
}

void Control::run(){
	int selection; 
	view.printMessage("Ice Cream Shoppe \n Version 0.1 alpha \n This code is for a valgrind and memory management demo.");
	while(1){
		view.printMenu();
		selection = view.getSelection();
		if (selection == 0) {
			break; 
		} else {
			if (selection == 1) {
				vanillaScoop = new Vanilla();
				vanillaScoop->prepare();
				vanillaScoop->serve(); 
				vanillaCone.push_back(vanillaScoop); 
			}else if (selection == 2) {
				chocolateScoop = new Chocolate();
				chocolateScoop->prepare();
				chocolateScoop->serve(); 
				chocolateCone.push_back(chocolateScoop); 
			}else if (selection == 3) {
				strawberryScoop = new Strawberry();
				strawberryScoop->prepare();
				strawberryScoop->serve(); 
				strawberryCone.push_back(strawberryScoop); 
			}else if (selection == 4) {
				neapolitanScoop = new Neapolitan();
				neapolitanScoop->prepare();
				neapolitanScoop->serve(); 
				neapolitanCone.push_back(neapolitanScoop); 
			}
		} 
	}
}