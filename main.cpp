// COMSC-210 | Final Exam 2 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

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

const int NUM_BRACELETS = 5;
const string BRACELET_ORDERS[NUM_BRACELETS] = { "Chain", "Braided", "Charm", "Knotted", "Beaded" };


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

// Bracelet node
struct BraceletNode {
	string name;
	string order;

	BraceletNode(const string& n, const string& o) : name(n), order(o) {}
};

// Customer joins coffee booth
void customerJoins(list<CoffeeNode>& coffeeBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = COFFEE_ORDERS[rand() % NUM_COFFEES];
	coffeeBooth.push_back(CoffeeNode(randomName, randomOrder));
	cout << "\tCustomer joins: " << coffeeBooth.back().name << " - " << coffeeBooth.back().order << " Coffee\n";
}

// Customer joins muffin booth
void customerJoins(deque<MuffinNode>& muffinBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = MUFFIN_ORDERS[rand() % NUM_MUFFINS];
	muffinBooth.push_back(MuffinNode(randomName, randomOrder));
	cout << "\tCustomer joins: " << muffinBooth.back().name << " - " << muffinBooth.back().order << " Muffin\n";
}

// Customer joins bracelet booth
void customerJoins(vector<BraceletNode> braceletBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = BRACELET_ORDERS[rand() % NUM_BRACELETS];
	braceletBooth.push_back(BraceletNode(randomName, randomOrder));
	cout << "\tCustomer joins: " << braceletBooth.back().name << " - " << braceletBooth.back().order << " Bracelet\n";
}

int main() {
	srand(time(0));
	const int NUM_BOOTHS = 2;
	list<CoffeeNode> coffeeBooth;		// Linked list for coffee booth.
	deque<MuffinNode> muffinBooth;		// Deque for muffin booth.
	vector<BraceletNode> braceletBooth;	// Vector for friendship bracelet booth.

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
			cout << "\tServed " << coffeeBooth.front().name << " - " << coffeeBooth.front().order << " Coffee\n";
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
			cout << "\tServed " << muffinBooth.front().name << " - " << muffinBooth.front().order << " Muffin\n";
			muffinBooth.pop_front();
		}

		// 50% chance that someone joins the queue.
		probability = rand() % 100 + 1;
		if (probability <= 50) {
			customerJoins(muffinBooth);
		}

		cout << "* At the bracelet booth:\n";
		// Serve the customer at the front if the queue is not empty.
		if (!braceletBooth.empty()) {
			cout << "\tServed " << braceletBooth.front().name << " - " << braceletBooth.front().order << " Bracelet \n";
			braceletBooth.erase(braceletBooth.begin());
		}

		// 50% chance that someone joins the queue.
		probability = rand() % 100 + 1;
		if (probability <= 50) {
			customerJoins(braceletBooth);
		}
	}

	return 0;
}