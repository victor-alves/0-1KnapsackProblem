#include "Item.h"

int main()
{
	string		input;
	int			maxWeight = 0,
				maxItems = 0;
	bool		running = true;

	// Specify test case by entering the name of the test case (file name without extension)
	while (running)
	{
		cout << "\nWhich test case would you like to load?" << endl
			<< "Do not specify the extension." << endl
			<< "If you want to quit, enter \"quit\"." << endl;

		cin >> input;

		if (input == "quit")
			running = false;
		else
		{
			string path = "./test cases/" + input + ".txt";
			ifstream loadData(path);

			if (loadData)
			{
                // Get max weight and maxHeight
			    loadData >> maxWeight >> maxItems;

				// Get items from file and store them in an array of Items
				Item* items = readInputFile(loadData, maxItems);
				// Sort by weight using overloaded comparison operator to make sure items are in ascending weight order
				sort(items, items + maxItems);

				// Perform the dynamic programming algorithm
				knapsack(items, maxItems, maxWeight);

				// Clean up the array of Items
				delete[] items;
			}
			else
				cout << "\nSpecified file doesn't exist." << endl;
		}
	}

	return 0;
}