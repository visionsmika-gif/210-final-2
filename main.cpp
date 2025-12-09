// COMSC-210 | Final Exam 2 | Mika Aquino
// IDE used: Visual Studio 2022

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <map>

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

const int NUM_PLUSHIES = 5;
const string PLUSHIE_ORDERS[NUM_PLUSHIES] = { "Dog", "Cat", "Squid", "Hamster", "Turtle" };

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

// Coffee booth operations
void customerJoins(list<CoffeeNode>& coffeeBooth);
void serveCustomer(list<CoffeeNode>& coffeeBooth);
void chanceCustomerJoins(list<CoffeeNode>& coffeeBooth);
void printBooth(const list<CoffeeNode>& coffeeBooth) {
	cout << "Coffee booth queue:\n";
	if (!coffeeBooth.empty()) {
		for (const auto& c : coffeeBooth) {
			cout << c.name << ", " << c.order << "]\n";
		}
	}
}

// Muffin booth operations
void customerJoins(deque<MuffinNode>& muffinBooth);
void serveCustomer(deque<MuffinNode>& muffinBooth);
void chanceCustomerJoins(deque<MuffinNode>& muffinBooth);

// Bracelet booth operations
void customerJoins(vector<BraceletNode>& braceletBooth);
void serveCustomer(vector<BraceletNode>& braceletBooth);
void chanceCustomerJoins(vector<BraceletNode>& braceletBooth);

// Plushie booth operations
string customerJoins(map<string, string>& plushieBooth);
void serveCustomer(map<string, string>& plushieBooth);
void chanceCustomerJoins(map<string, string>& plushieBooth);

int main() {
	srand(time(0));

	// Booths
	list<CoffeeNode> coffeeBooth;		// Linked list for the coffee booth.
	deque<MuffinNode> muffinBooth;		// Deque for the muffin booth.
	vector<BraceletNode> braceletBooth;	// Vector for the friendship bracelet booth.
	map<string, string> plushieBooth;	// Map for the plushie booth.

	// Initialize each booth with 3 customers.
	const int INIT_NUM_CUSTOMERS = 3;
	for (int i = 0; i < INIT_NUM_CUSTOMERS; ++i) {
		customerJoins(coffeeBooth);
		customerJoins(muffinBooth);
		customerJoins(braceletBooth);
		customerJoins(plushieBooth);
	}
	cout << "Initial coffee booth:\n";
	printBooth(coffeeBooth);


	// Run 10 rounds of simulation.
	cout << "==== BOOTH SIMULATIONS ====\n\n";
	for (int i = 0; i < NUM_ROUNDS; ++i) {
		cout << "------- TIME " << i + 1 << " ------- \n";

		// Coffee booth
		cout << "* At the coffee booth:\n";
		serveCustomer(coffeeBooth);				// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(coffeeBooth);		// 50% chance that a customer joins the queue.

		// Muffin booth
		cout << "* At the muffin booth:\n";
		serveCustomer(muffinBooth);				// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(muffinBooth);		// 50% chance that a customer joins the queue.

		// Bracelet booth
		cout << "* At the bracelet booth:\n";
		serveCustomer(braceletBooth);			// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(braceletBooth);		//50% chance that a customer joins the queue.

		// Plushie booth
		cout << "* At the plushie booth:\n";
		serveCustomer(plushieBooth);			// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(plushieBooth);		// 50% chance that a customer joins the queue.

		cout << "\n";
	}

	return 0;
}

void customerJoins(list<CoffeeNode>& coffeeBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = COFFEE_ORDERS[rand() % NUM_COFFEES];
	coffeeBooth.push_back(CoffeeNode(randomName, randomOrder));
}

void serveCustomer(list<CoffeeNode>& coffeeBooth) {
	if (!coffeeBooth.empty()) {
		cout << "\tServed: [" << coffeeBooth.front().name << ", " << coffeeBooth.front().order << " Coffee]\n";
		coffeeBooth.pop_front();
	}
}

void chanceCustomerJoins(list<CoffeeNode>& coffeeBooth) {
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(coffeeBooth);
		cout << "\tCustomer joins: [" << coffeeBooth.back().name << ", " << coffeeBooth.back().order << " Coffee]\n";
	}
}

void customerJoins(deque<MuffinNode>& muffinBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = MUFFIN_ORDERS[rand() % NUM_MUFFINS];
	muffinBooth.push_back(MuffinNode(randomName, randomOrder));
}

void serveCustomer(deque<MuffinNode>& muffinBooth) {
	if (!muffinBooth.empty()) {
		cout << "\tServed: [" << muffinBooth.front().name << ", " << muffinBooth.front().order << " Muffin]\n";
		muffinBooth.pop_front();
	}
}

void chanceCustomerJoins(deque<MuffinNode>& muffinBooth) {
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(muffinBooth);
		cout << "\tCustomer joins: [" << muffinBooth.back().name << ", " << muffinBooth.back().order << " Muffin]\n";
	}
}

void customerJoins(vector<BraceletNode>& braceletBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = BRACELET_ORDERS[rand() % NUM_BRACELETS];
	braceletBooth.push_back(BraceletNode(randomName, randomOrder));
}

void serveCustomer(vector<BraceletNode>& braceletBooth) {
	if (!braceletBooth.empty()) {
		cout << "\tServed: [" << braceletBooth.front().name << ", " << braceletBooth.front().order << " Bracelet]\n";
		braceletBooth.erase(braceletBooth.begin());
	}
}

void chanceCustomerJoins(vector<BraceletNode>& braceletBooth) {
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(braceletBooth);
		cout << "\tCustomer joins: [" << braceletBooth.back().name << ", " << braceletBooth.back().order << " Bracelet]\n";
	}
}

string customerJoins(map<string, string>& plushieBooth) {
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = PLUSHIE_ORDERS[rand() % NUM_PLUSHIES];
	plushieBooth[randomName] = randomOrder;
	return randomName;
}

void serveCustomer(map<string, string>& plushieBooth) {
	if (!plushieBooth.empty()) {
		cout << "\tServed: [" << plushieBooth.begin()->first << ", " << plushieBooth.begin()->second << " Plushie]\n";
		plushieBooth.erase(plushieBooth.begin());
	}
}

void chanceCustomerJoins(map<string, string>& plushieBooth) {
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		string customer = customerJoins(plushieBooth);
		cout << "\tCustomer joins: [" << customer << ", " << plushieBooth[customer] << " Plushie]\n";
	}
}