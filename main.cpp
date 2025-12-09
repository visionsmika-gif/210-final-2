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
void printBooth(const list<CoffeeNode>& coffeeBooth);

// Muffin booth operations
void customerJoins(deque<MuffinNode>& muffinBooth);
void serveCustomer(deque<MuffinNode>& muffinBooth);
void chanceCustomerJoins(deque<MuffinNode>& muffinBooth);
void printBooth(const deque<MuffinNode>& muffinBooth);

// Bracelet booth operations
void customerJoins(vector<BraceletNode>& braceletBooth);
void serveCustomer(vector<BraceletNode>& braceletBooth);
void chanceCustomerJoins(vector<BraceletNode>& braceletBooth);
void printBooth(const vector<BraceletNode>& braceletBooth);

// Plushie booth operations
string customerJoins(map<string, string>& plushieBooth);
void serveCustomer(map<string, string>& plushieBooth);
void chanceCustomerJoins(map<string, string>& plushieBooth);
void printBooth(const map<string, string>& plushieBooth);

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

	// Print the initial state of each booth.
	cout << "Initial coffee booth:\n";
	printBooth(coffeeBooth);
	cout << "Initial muffin booth:\n";
	printBooth(muffinBooth);
	cout << "Initial bracelet booth:\n";
	printBooth(braceletBooth);
	cout << "Initial plushie booth:\n";
	printBooth(plushieBooth);

	// Run 10 rounds of simulation.
	cout << "\n==== BOOTH SIMULATIONS ====\n\n";
	for (int i = 0; i < NUM_ROUNDS; ++i) {
		cout << "------- TIME " << i + 1 << " ------- \n";

		// Coffee booth
		cout << "* At the COFFEE BOOTH:\n";
		serveCustomer(coffeeBooth);				// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(coffeeBooth);		// 50% chance that a customer joins the queue.
		cout << "Resulting queue:\n";
		printBooth(coffeeBooth);
		cout << "\n";

		// Muffin booth
		cout << "* At the MUFFIN BOOTH:\n";
		serveCustomer(muffinBooth);				// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(muffinBooth);		// 50% chance that a customer joins the queue.
		cout << "Resulting queue:\n";
		printBooth(muffinBooth);
		cout << "\n";

		// Bracelet booth
		cout << "* At the BRACELET BOOTH:\n";
		serveCustomer(braceletBooth);			// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(braceletBooth);		//50% chance that a customer joins the queue.
		cout << "Resulting queue:\n";
		printBooth(braceletBooth);
		cout << "\n";

		// Plushie booth
		cout << "* At the PLUSHIE BOOTH:\n";
		serveCustomer(plushieBooth);			// Serve the customer at the front if the queue is not empty.
		chanceCustomerJoins(plushieBooth);		// 50% chance that a customer joins the queue.
		cout << "Resulting queue:\n";
		printBooth(plushieBooth);
		cout << "\n";
	}

	return 0;
}

// COFFEE BOOTH OPERATIONS

void customerJoins(list<CoffeeNode>& coffeeBooth) {			// Add a customer to coffee booth.
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = COFFEE_ORDERS[rand() % NUM_COFFEES];
	coffeeBooth.push_back(CoffeeNode(randomName, randomOrder));
}

void serveCustomer(list<CoffeeNode>& coffeeBooth) {			// Serve a customer in the coffee booth.
	if (!coffeeBooth.empty()) {
		cout << "\tServed: [" << coffeeBooth.front().name << ", " << coffeeBooth.front().order << " Coffee]\n";
		coffeeBooth.pop_front();
	}
}

void chanceCustomerJoins(list<CoffeeNode>& coffeeBooth) {	// 50% chance to add a customer to the coffee booth.
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(coffeeBooth);
		cout << "\tCustomer joins: [" << coffeeBooth.back().name << ", " << coffeeBooth.back().order << " Coffee]\n";
	}
}

void printBooth(const list<CoffeeNode>& coffeeBooth) {		// Print the coffee booth.
	if (!coffeeBooth.empty()) {
		for (const auto& c : coffeeBooth) {
			cout << "\t>> [" << c.name << ", " << c.order << " Coffee]\n";
		}
	}
	else {
		cout << "\tEmpty\n";
	}
}

// MUFFIN BOOTH OPERATIONS

void customerJoins(deque<MuffinNode>& muffinBooth) {		// Add a customer to the muffin booth.
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = MUFFIN_ORDERS[rand() % NUM_MUFFINS];
	muffinBooth.push_back(MuffinNode(randomName, randomOrder));
}

void serveCustomer(deque<MuffinNode>& muffinBooth) {		// Serve a customer in the muffin booth.
	if (!muffinBooth.empty()) {
		cout << "\tServed: [" << muffinBooth.front().name << ", " << muffinBooth.front().order << " Muffin]\n";
		muffinBooth.pop_front();
	}
}

void chanceCustomerJoins(deque<MuffinNode>& muffinBooth) {	// 50% chance to add a customer to the muffin booth.
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(muffinBooth);
		cout << "\tCustomer joins: [" << muffinBooth.back().name << ", " << muffinBooth.back().order << " Muffin]\n";
	}
}

void printBooth(const deque<MuffinNode>& muffinBooth) {		// Print the muffin booth.
	if (!muffinBooth.empty()) {
		for (const auto& m : muffinBooth) {
			cout << "\t>> [" << m.name << ", " << m.order << " Muffin]\n";
		}
	}
	else {
		cout << "\tEmpty\n";
	}
}

// BRACELET BOOTH OPERATIONS

void customerJoins(vector<BraceletNode>& braceletBooth) {		// Add a customer to the bracelet booth.
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = BRACELET_ORDERS[rand() % NUM_BRACELETS];
	braceletBooth.push_back(BraceletNode(randomName, randomOrder));
}

void serveCustomer(vector<BraceletNode>& braceletBooth) {		// Serve a customer in the bracelet booth.
	if (!braceletBooth.empty()) {
		cout << "\tServed: [" << braceletBooth.front().name << ", " << braceletBooth.front().order << " Bracelet]\n";
		braceletBooth.erase(braceletBooth.begin());
	}
}

void chanceCustomerJoins(vector<BraceletNode>& braceletBooth) {	// 50% chance to add a customer to the bracelet booth.
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		customerJoins(braceletBooth);
		cout << "\tCustomer joins: [" << braceletBooth.back().name << ", " << braceletBooth.back().order << " Bracelet]\n";
	}
}

void printBooth(const vector<BraceletNode>& braceletBooth) {	// Print the bracelet booth.
	if (!braceletBooth.empty()) {
		for (const auto& b : braceletBooth) {
			cout << "\t>> [" << b.name << ", " << b.order << " Bracelet]\n";
		}
	}
	else {
		cout << "\tEmpty\n";
	}
}

// PLUSHIE BOOTH OPERATIONS

string customerJoins(map<string, string>& plushieBooth) {		// Add a customer to the plushie booth.
	string randomName = NAMES[rand() % NUM_NAMES];
	string randomOrder = PLUSHIE_ORDERS[rand() % NUM_PLUSHIES];
	plushieBooth[randomName] = randomOrder;
	return randomName;
}

void serveCustomer(map<string, string>& plushieBooth) {			// Serve a customer in the plushie  booth.
	if (!plushieBooth.empty()) {
		cout << "\tServed: [" << plushieBooth.begin()->first << ", " << plushieBooth.begin()->second << " Plushie]\n";
		plushieBooth.erase(plushieBooth.begin());
	}
}

void chanceCustomerJoins(map<string, string>& plushieBooth) {	// 50% chance to add a customer to the plushie booth.
	int probability = rand() % 100 + 1;
	if (probability <= 50) {
		string customer = customerJoins(plushieBooth);
		cout << "\tCustomer joins: [" << customer << ", " << plushieBooth[customer] << " Plushie]\n";
	}
}

void printBooth(const map<string, string>& plushieBooth) {		// Print the plushie booth.
	if (!plushieBooth.empty()) {
		for (const auto& pair : plushieBooth) {
			cout << "\t>> [" << pair.first << ", " << pair.second << " Plushie]\n";
		}
	}
	else {
		cout << "\tEmpty\n";
	}
}
