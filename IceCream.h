#ifndef ICECREAM_H
#define ICECREAM_H 

#include <iostream>
#include <string>

using namespace std;

// IceCream superclass goes here!!! 
// The other classes will inherit IceCream. 

class Vanilla {
	public:
		Vanilla(){
			nameOfFlavour = "Simple Vanilla";
			cout << this << endl; 
		}
		~Vanilla(){
			cout << this << endl; 
		}
		void prepare(){
			cout << "Preparing the " + nameOfFlavour + " ice cream!" << endl;
		}
		void serve(){
			cout << "Scooping out some " + nameOfFlavour + " ice cream!" << endl;
		} 
	private:
		string nameOfFlavour; 
}; 

class Chocolate {
	public:
		Chocolate(){
			nameOfFlavour = "Simple Chocolate";
			cout << this << endl; 
		}
		~Chocolate(){
			cout << this << endl; 
		}
		void prepare(){
			cout << "Preparing the " + nameOfFlavour + " ice cream!" << endl;
		}
		void serve(){
			cout << "Scooping out some " + nameOfFlavour + " ice cream!" << endl;
		} 
	private:
		string nameOfFlavour; 
}; 

class Strawberry {
	public:
		Strawberry(){
			nameOfFlavour = "Simple Strawberry";
			cout << this << endl; 
		}
		~Strawberry(){
			cout << this << endl; 
		}
		void prepare(){
			cout << "Preparing the " + nameOfFlavour + " ice cream!" << endl;
		}
		void serve(){
			cout << "Scooping out some " + nameOfFlavour + " ice cream!" << endl;
		} 
	private:
		string nameOfFlavour; 
}; 

class Neapolitan {
	public:
		Neapolitan(){
			nameOfFlavour = "Simple Neapolitan";
			cout << this << endl; 
			vanilla = new Vanilla();
			chocolate = new Chocolate();
			strawberry = new Strawberry();
		}
		~Neapolitan(){
			delete vanilla;
			delete chocolate;
			delete strawberry;
			cout << this << endl;
		}
		void prepare(){
			cout << "Preparing the " + nameOfFlavour + " ice cream!" << endl;
		}

		void serve(){
			cout << "Scooping out some " + nameOfFlavour + " ice cream!" << endl;
		} 
	private:
		string nameOfFlavour; 
		Vanilla* vanilla; 
		Chocolate* chocolate;
		Strawberry* strawberry;
}; 

#endif