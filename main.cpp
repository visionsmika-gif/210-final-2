// COMSC-210 | Final Exam 2 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

const int NUM_ROUNDS = 10;

// Data sets
const int NUM_NAMES = 20;
const string NAMES[NUM_NAMES] = { "Liam", "Olivia", "Jasper", "Delilah", "Theodore", "Amelia", "Noah", "Emma", "Knox", "Sloane",
						 "Zoe", "Flynn", "Saoirse", "Maxton", "Scarlett", "Lucian", "Aisha", "Kairi", "Zariah", "Nova" };

const int NUM_COFFEES = 5;
const string COFFEE_ORDERS[NUM_COFFEES] = { "Latte", "Cappuccino", "Mocha", "Americano", "Espresso" };

const int NUM_MUFFINS = 5;
const string MUFFIN_ORDERS[NUM_MUFFINS] = { "Blueberry", "Banana", "Apple", "Lemon", "Cranberry" };

// Coffee node
struct CoffeeNode {
	string name;
	string order;

	CoffeeNode(const string& n, const string& o) : name(n), order(o) {}
};

// Muffin node
struct MuffinNode {
	string name;
	string order;

	MuffinNode(const string& n, const string& o) : name(n), order(o) {}
};

// Customer joins coffee booth
void customerJoins(list<CoffeeNode>& coffeeBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = COFFEE_ORDERS[rand() % NUM_COFFEES];
	coffeeBooth.push_back(CoffeeNode(randomName, randomOrder));
	cout << "\tCustomer joins: " << coffeeBooth.back().name << " - " << coffeeBooth.back().order << "\n";
}

// Customer joins muffin booth
void customerJoins(deque<MuffinNode>& muffinBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = MUFFIN_ORDERS[rand() % NUM_MUFFINS];
	muffinBooth.push_back(MuffinNode(randomName, randomOrder));
	cout << "\tCustomer joins: " << muffinBooth.back().name << " - " << muffinBooth.back().order << "\n";
}

int main() {
	srand(time(0));
	const int NUM_BOOTHS = 2;
	list<CoffeeNode> coffeeBooth;	// Linked list for coffee booth.
	deque<MuffinNode> muffinBooth;	// Deque for muffin booth.

	// Initialize the queue with 3 customers.
	const int INIT_NUM_CUSTOMERS = 3;

	cout << "INITIAL COFFEE BOOTH:\n";
	for (int i = 0; i < INIT_NUM_CUSTOMERS; ++i) {
		customerJoins(coffeeBooth);
	}

	cout << "INITIAL MUFFIN BOOTH:\n";
	for (int i = 0; i < INIT_NUM_CUSTOMERS; ++i) {
		customerJoins(muffinBooth);
	}

	// Run 10 rounds of simulation.
	cout << "\n---BOOTH SIMULATIONS---\n";
	for (int i = 0; i < NUM_ROUNDS; ++i) {
		cout << "TIME " << i + 1 << ":\n";

		cout << "* At the coffee booth:\n";
		// Serve the customer at the front if the queue is not empty.
		if (!coffeeBooth.empty()) {
			cout << "\tServed " << coffeeBooth.front().name << " - " << coffeeBooth.front().order << "\n";
			coffeeBooth.pop_front();
		}

		// 50% chance that someone joins the queue.
		int probability = rand() % 100 + 1;
		if (probability <= 50) {
			customerJoins(coffeeBooth);
		}

		cout << "* At the muffin booth:\n";
		// Serve the customer at the front if the queue is not empty.
		if (!muffinBooth.empty()) {
			cout << "\tServed " << muffinBooth.front().name << " - " << muffinBooth.front().order << "\n";
			muffinBooth.pop_front();
		}

		// 50% chance that someone joins the queue.
		probability = rand() % 100 + 1;
		if (probability <= 50) {
			customerJoins(muffinBooth);
		}
	}

	return 0;
}