// COMSC-210 | Final Exam 2 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_ROUNDS = 10;

// Data sets
const int NUM_NAMES = 20;
const string NAMES[NUM_NAMES] = { "Liam", "Olivia", "Jasper", "Delilah", "Theodore", "Amelia", "Noah", "Emma", "Knox", "Sloane",
						 "Zoe", "Flynn", "Saoirse", "Maxton", "Scarlett", "Lucian", "Aisha", "Kairi", "Zariah", "Nova" };

const int NUM_COFFEES = 5;
const string COFFEE_ORDERS[NUM_COFFEES] = { "Latte", "Cappuccino", "Mocha", "Americano", "Espresso" };

// Coffee node
struct CoffeeNode {
	string name;
	string order;

	CoffeeNode(const string& n, const string& o) : name(n), order(o) {}
};

void customerJoins(list<CoffeeNode>& coffeeBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = COFFEE_ORDERS[rand() % NUM_COFFEES];
	coffeeBooth.push_back(CoffeeNode(randomName, randomOrder));
}

int main() {
	srand(time(0));
	list<CoffeeNode> coffeeBooth;	// Linked list for coffee orders.

	// Initialize the queue with 3 customers.
	for (int i = 0; i < 3; ++i) {
		customerJoins(coffeeBooth);
	}

	// Run 10 rounds of simulation.
	for (int i = 0; i < NUM_ROUNDS; ++i) {
		cout << "Time " << i + 1 << ":\n";

		// Serve the customer at the front if the queue is not empty.
		if (!coffeeBooth.empty()) {
			cout << "Served " << coffeeBooth.front().name << " - " << coffeeBooth.front().order << "\n";
			coffeeBooth.pop_front();
		}

		// 50% chance that someone joins the queue.
		int probability = rand() % 100 + 1;
		if (probability <= 50) {
			customerJoins(coffeeBooth);
		}
	}

	return 0;
}