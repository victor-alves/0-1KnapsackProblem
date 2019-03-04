#include "Item.h"

Item::Item()
:mName("")
,mWeight(0)
,mValue(0)
{
}

Item::Item(const string name, const int weight, const int value)
:mName(name)
,mWeight(weight)
,mValue(value)
{
}

bool operator<(const Item  &lhs, const Item &rhs)
{
	return lhs.mWeight < rhs.mWeight;
}

Item * readInputFile(ifstream & file, const int maxItems)
{
	string		name;
	int			weight = 0,
				value = 0;
	Item*		items = new Item[maxItems];

	for (auto i = 0; i < maxItems; i++)
	{
		file >> name >> weight >> value;
		items[i] = Item(name, weight, value);
	}

	return items;
}

void knapsack(Item * items, const int maxItems, const int maxWeight)
{
            // create the rows of the table
    int		**table = new int *[maxItems + 1],
	        // Created variables to make it easier to follow along
			previousMax = 0,
			valRemainingSpace = 0,
			currentVal = 0,
			row = 0,
			col = 0;

	for (auto k = 0; k < maxItems + 1; k++)
        // create the columns of the table
		table[k] = new int[maxWeight + 1];

	for (row = 0; row <= maxItems; row++)
	{
		for (col = 0; col <= maxWeight; col++)
		{
			if (row == 0 || col == 0)
			{
				table[row][col] = 0;
			}
			// Check current item weight to knapsack's current max weight
			else if (items[row - 1].mWeight <= col)
			{
				currentVal = items[row - 1].mValue;
				valRemainingSpace = table[row - 1][col - items[row - 1].mWeight];
				previousMax = table[row - 1][col];

				// Take the max of (the current value plus the value of the remaining space) and the previous maximum value
				table[row][col] = max((currentVal + valRemainingSpace), previousMax);
			}
			else
			{
				// Set it to the previous max
				table[row][col] = table[row - 1][col];
			}
		}
	}

	cout << "\nThe maximum value of loot for the " << maxWeight << " pound knapsack is $" << table[maxItems][maxWeight] << "." << endl;

	for (int i = 0; i < maxItems; i++)
		// Delete each int array (columns)
		delete [] table[i];

	// Delete the array of int arrays (rows)
	delete[] table;
	table = nullptr;
}