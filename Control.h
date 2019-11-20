#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <iostream>
#include <vector>
#include "View.h"
#include "IceCream.h"

using namespace std;

class Control {
	public:
		~Control();
		void run(); 		
	private: 
		View view;
		Vanilla* vanillaScoop;
		Chocolate* chocolateScoop;
		Strawberry* strawberryScoop;
		Neapolitan* neapolitanScoop; 
		vector<Vanilla *> vanillaCone;
		vector<Chocolate *> chocolateCone;
		vector<Strawberry *> strawberryCone; 
		vector<Neapolitan *> neapolitanCone; 
};

#endif