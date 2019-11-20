# Tutorial 9

### Overview

This tutorial covers the following topics;

- inheritance 
- polymorphism 
- the factory method design pattern 

### Description 

The key topic for this tutorial is to apply inheritance, polymorphism, and learn about the factory method design pattern and the abstract factory design pattern. These design patterns part of the "Gang of Four" design patterns. They are what we call creational design patterns. 

### Learning Objectives

- understand inheritance and polymorphism
- understand the factory method design pattern
- understand the abstract factory design pattern
- understand where and when you may wish to apply these concepts 

### Preliminary Requirements 

- Ensure that `valgrind` is installed on your system. 
  - Ubuntu installation instructions: `sudo apt-get install valgrind` 
  - Mac installation instructions: `brew install valgrind`
  - Different distros may have different package managers, so remember Google is your friend! 
- Read up on the factory method pattern and the abstract factory pattern.
  - https://en.wikipedia.org/wiki/Factory_method_pattern
  - https://en.wikipedia.org/wiki/Abstract_factory_pattern
  - https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Factory 
- Review and compile the provided code, think about how you may want to refactor this code. 

### Compilation and Execution

To compile: 

```bash
g++ -std=c++11 main.cpp Control.cpp View.cpp
```

To run with `valgrind`:

```bash
valgrind ./a.out 
```

Please compile and test your code (with `valgrind` as well!) as you go, it will save you a lot of grief! 

### Part 1: Creating the IceCream Class

Review the code and you will notice that there is a lot of issues with the code. First of all, if we look at the implementation of `Vanilla`, `Chocolate`, `Strawberry`, and `Neapolitan`, it's pretty evident that these classes are very similar and many methods are simply cut and paste! When you look at `Control.h` and `Control.cpp` you may notice a lot of repetition for what are otherwise very similar classes. 

In `Control.h`: 

```c++
Vanilla* vanillaScoop;
Chocolate* chocolateScoop;
Strawberry* strawberryScoop;
Neapolitan* neapolitanScoop; 
vector<Vanilla *> vanillaCone;
vector<Chocolate *> chocolateCone;
vector<Strawberry *> strawberryCone; 
vector<Neapolitan *> neapolitanCone; 
```

In `Control.cpp`;

```c++
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
```

```c++
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
```

To fix this issue we are going to create an `IceCream` class in which the flavours will inherit from. 

First, look at `IceCream.h` and make note of which methods and attributes are virtually identical between the classes. 

- The constructors all have this line in common;

  ```c++
  cout << this << endl; 
  ```

- The destructors all have this line in common;

  ```c++
  cout << this << endl; 
  ```

- The following two methods are identical across all classes;

  ````c++
  void prepare(){
      cout << "Preparing the " + nameOfFlavour + " ice cream!" << endl;
  }
  void serve(){
      cout << "Scooping out some " + nameOfFlavour + " ice cream!" << endl;
  } 
  ````

- All classes have this attribute in common;

  ```c++
  string nameOfFlavour;
  
  ```

Your `IceCream` class should take all of this into consideration. The majority of your subclasses should look something like this;

```c++
class Vanilla: public IceCream {
	public:
		Vanilla(){
			nameOfFlavour = "Simple Vanilla";
		}
}; 

```

The exception will obviously be the `Neapolitan` subclass, so I will also provide it for you.

```c++
class Neapolitan: public IceCream {
	public:
		Neapolitan(){
			nameOfFlavour = "Simple Neapolitan"; 
			vanilla = new Vanilla();
			chocolate = new Chocolate();
			strawberry = new Strawberry();
		}
		~Neapolitan(){
			delete vanilla;
			delete chocolate;
			delete strawberry;
		}
	private:
		Vanilla* vanilla; 
		Chocolate* chocolate;
		Strawberry* strawberry;
}; 

```

Your job is to write the `IceCream` class will handle all of the other methods and the one common attribute.  

A couple of considerations for your `IceCream` class;

- The constructor will simply just have this line of code;

  ```c++
  cout << this << endl; 
  
  ```

  The assignment of the `nameOfFlavour` attribute will be handled by the subclasses. 

- The `nameOfFlavour` attribute should be `protected`, not `private`. Why is this? The `protected` access modifier allows derived classes to access the attribute while classes like `Control` cannot. It is very similar to `private`. 

After you are done creating the `IceCream` class, make the following modifications to `Control`: 

In `Control.h` replace the redundant code with the following;

```c++
IceCream* scoop;
vector<IceCream *> cone;

```

In `Control.cpp` replace the redundant code with the following;

```c++
Control::~Control() {
	for(auto & ele : cone)
		delete ele; 
}

```

And update `run()` method so it works with the new member attributes; 

```c++
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
				scoop = new Vanilla();
				scoop->prepare();
				scoop->serve(); 
				cone.push_back(scoop); 
			}else if (selection == 2) {
				scoop = new Chocolate();
				scoop->prepare();
				scoop->serve(); 
				cone.push_back(scoop); 
			}else if (selection == 3) {
				scoop = new Strawberry();
				scoop->prepare();
				scoop->serve(); 
				cone.push_back(scoop); 
			}else if (selection == 4) {
				scoop = new Neapolitan();
				scoop->prepare();
				scoop->serve(); 
				cone.push_back(scoop); 
			}
		} 
	}
}

```

Run your code with `valgrind`, add some scoops of Neapolitan, to make sure it works before moving onto the next step. 

If you notice any memory leaks, double check that your `IceCream` destructor is `virtual`, if it is not, make it so, and try again. 

You can read up on why you need to use a `virtual` destructor here. This article also provides a good explanation of the topic.

https://www.quantstart.com/articles/C-Virtual-Destructors-How-to-Avoid-Memory-Leaks

 Essentially, when you don't have a `virtual` destructor for your `IceCream` class and when it is time for the `Neapolitian` object to call it's destructor, it deletes it's `Vanilla`, `Chocolate`, and `Strawberry` objects, they only call the destructor for `IceCream` and not their derived destructors. If you add the `virtual` keyword to `IceCream`'s destructor, and when it comes time for `Vanilla`, `Chocolate`, and `Strawberry` to be deleted, it will correctly call the destructor associated with those classes before calling the destructor associated with the `IceCream` class. 

I would also strongly encourage you to make it so the subclasses don't use a default destructor, and that the `IceCream` class destructor prints out something more meaningful, and watch how they behave with and without the `virtual` keyword. However, activity is not required for the tutorial. 

***After you have made the changes described above, the behaviour of your code should not change.***

### Part 2: Applying the Factory Method Design Pattern

We are going to now create something called a `factory method` in the `Control` class. It is going to have the following signature. 

```c++
IceCream * createInstance(int i);

```

This method will take in the user's selection and return an `IceCream` object. You are going to have the method create the objects of the subclasses for you. It should take over some of the work of the `run()` method.

The `run()` method should look something like this now; 

```c++
void Control::run(){
	int selection; 
	view.printMessage("Ice Cream Shoppe \n Version 0.1 alpha \n This code is for a valgrind and memory management demo.");
	while(1){
		view.printMenu();
		selection = view.getSelection();
		if (selection == 0) {
			break; 
		} else {
			scoop = createInstance(selection);
			scoop->prepare();
			scoop->serve(); 
			cone.push_back(scoop);
		} 
	}
}

```

The benefits of the changes that you made is that you were able to create a bunch of objects without having to specify their concrete types. 

***After you have made the changes described above, the behaviour of your code should not change.***

### Part 3: Applying the Abstract Factory Design Pattern

Now, we are going to move the method you just work into a separate class called `Factory`. Make a file called `Factory.h` and add the provided code to build this class from;

```c++
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include "IceCream.h"

class Factory {
	public:
		virtual ~Factory() {}
		virtual IceCream * createInstance(int selection) = 0;
};

#endif

```

As you may have noticed, I have provided you an abstract factory class, with a pure virtual `IceCream * createInstance(int selection) = 0` method. Your job is to create a concrete class that contains the method that you wrote in the previous step. The concrete class will be called `IceCreamFactory`. 

After you are done, add the following attribute to your `Control` class; 

```c++
Factory * factory;

```

You will also need to add the following line of code to your destructor. 

```c++
delete factory;

```

And instantiate the `IceCreamFactory`, and call it's `createInstance()` method. 

*Note: Make sure you remember to include the `Factory.h` file!* 

***After you have made the changes described above, the behaviour of your code should not change.***

***The changes described above should not result in any memory leaks!***

Now, we are going to make further modifications to see the benefits of the `abstract factory` design pattern.

First, in your `IceCream.h` file, add the following additional classes;

```c++
class DarkChocolateGelato: public IceCream {
	public:
		DarkChocolateGelato(){
			nameOfFlavour = "Dark Chocolate Gelato";
		}
};

class RaspberryGelato: public IceCream {
	public:
		RaspberryGelato(){
			nameOfFlavour = "Raspberry Gelato";
		}
};

class LemonGelato: public IceCream {
	public:
		LemonGelato(){
			nameOfFlavour = "Lemon Gelato";
		}
};

class OrangeGelato: public IceCream {
	public:
		OrangeGelato(){
			nameOfFlavour = "Orange Gelato";
		}
};

```

Now, in `Factory.h`, add a concrete `GelatoFactory` class and implement the `createInstance()` method. This method should be similar to the method you wrote for `IceCreamFactory` except it will create instances of Gelato objects instead. This is also an example of `polymorphism`, as the two objects respond differently when you make a call to `createInstance()`. 

Now, in control, instantiate the `GelatoFactory` instead of the `IceCreamFactory`, test your code, your program should be serving up Gelato instead of Ice Cream. 

You can continue to make more factories this way and easily switch between them.

### Notes on the material: 

Hopefully, after finishing the tutorial you should walk away with a better understanding of the `Factory` design pattern and how it can aid you in the refactoring of your code. You should be encouraged to consider practical contexts in which you may wish to use this design pattern. For instance, when I took 3004, we used this design pattern to instantiate a bunch of card objects (we were making a card game), and it made that aspect of our software more manageable. 

Another example could be cross-platform user interface elements, where you can develop one factory for Windows widgets, another factory for Linux widgets, etc. 
