#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Struct to hold item
struct Item
{
	Item();
	Item(string name, int weight, int value);

	string mName;
	int mWeight;
	int mValue;
};

// Function to read the items from the file
Item* readInputFile(ifstream &file, const int maxItems);

// Overloaded comparison operator to compare weights
bool operator< (const Item &lhs, const Item & rhs);

// Dynamic programming solution to the given knapsack
void knapsack(Item * items, const int maxItems, const int maxWeight);
