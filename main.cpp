// COMSC-210 | Final Exam 2 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <list>

using namespace std;

// Data sets
const string NAMES[] = { "Liam", "Olivia", "Jasper", "Delilah", "Theodore", "Amelia", "Noah", "Emma", "Knox", "Sloane",
						 "Zoe", "Flynn", "Saoirse", "Maxton", "Scarlett", "Lucian", "Aisha", "Kairi", "Zariah", "Nova" };

const string COFFEE_ORDERS[] = { "Latte", "Cappuccino", "Mocha", "Americano", "Espresso" };

// Coffee node
struct CoffeeNode {
	string name;
	string order;

	CoffeeNode(const string& n, const string& o) : name(n), order(o) {}
};

int main() {
	list<CoffeeNode> coffeeBooth;	// Linked list for coffee orders

	return 0;
}