#include <iostream>
#include <fstream>
#include <vector>
#include "Database.h"

using namespace std;

/// displaying the array /// 
void Database::display(int* data, int array_size) {
	cout << "The array list : " << endl << endl;
	for (int count = 0; count < array_size; count++)
		cout << " " << data[count];
	cout << endl;
};
/// checking if the integer is present ///
int Database::integerPresent(int existInteger, int* data, int array_size)
{
	int existInteger2 = 0;
	int count;
	for (count = 0; count < array_size; count++)
		if (existInteger == data[count])
		{
			cout << "The  integer is present and it's index is:  " << count;
			cout << endl;
			existInteger2++;
			break;
		};
	if (existInteger2 == 0)
		cout << " The integer is not in the database.";

	return count;
}
/// modifying the value os an integer ///
int Database::modification(int index, int value, int* data, int array_size)
{
	try
	{
		if (index > array_size || index < 0)
		{
			throw out_of_range("Invalid index");
		}

		int old_value = data[index];
		data[index] = value;
		return old_value;
	}
	catch (const out_of_range& e) {
		cerr << "Error: " << e.what() << endl;
		return -1;
	}

}
// adding a new value to the array //
void Database::newIntegerAdded(int value, int*& data, int& size) {

	int new_size = size + 1;
	int* data2 = new int[new_size];
	data2[size] = value;
	try 
	{
		for (int count = 0; count < size; count++)
		{
			data2[count] = data[count];
		}
		size = new_size;
		data = data2;
	}
	catch (const bad_alloc& e) {
		cerr << "Error: Failed to add integer to the array" << endl;
	}

}
// removing the integer from the arrar //
void Database::remove(int index, int*& data, int& size) {

	int new_size = size - 1;
	int* data2 = new int[new_size];
	for (int count = 0; count < index; count++)
	{
		data2[count] = data[count];
	}
	for (int count = index; count < new_size; count++)
	{
		data2[count] = data[count + 1];
	}
	size = new_size;
	data = data2;



}
int main()
{
	Database D;
	int* data = new int[100];

	ifstream inputfile;
	inputfile.open("integers.txt.txt");
	if (!inputfile)
	{
		cout << " File can not be found";
		cout << endl;
		system("pause");
		exit(-1);
	}

	int count = 0;
	while (!inputfile.eof())
	{
		inputfile >> data[count];
		count++;
	}
	int array_size = count;
	cout << endl;
	cout << endl;
	cout << " Size of the Array:  " << array_size;
	cout << endl;
	cout << endl;


	int existInteger;
	cout << "Enter an Integer to see if its present and its index:  ";
	cin >> existInteger;
	cout << endl;
	cout << endl;
	D.integerPresent(existInteger, data, array_size);
	cout << endl;
	D.display(data, array_size);
	cout << endl;

	int index;
	cout << "Enter the index of the array that you want to modify:  ";
	cin >> index;
	cout << endl;
	cout << endl;
	int value;
	cout << "Enter the value that you want that index to be modify with:  ";
	cin >> value;
	cout << endl;
	cout << endl;
	int old_value = D.modification(index, value, data, array_size);
	cout << "The value at that index was:  " << old_value << endl;
	cout << endl;
	cout << "The new value at that index is:  " << data[index] << endl;
	cout << endl;

	D.display(data, array_size);
	cout << endl;

	cout << "Integer you would like to add to the array:  ";
	cin >> value;
	cout << endl; 
	D.newIntegerAdded(value, data, array_size);
	cout << endl;
	D.display(data, array_size);
	cout << endl;

	cout << "Integer you would like to remove from the array:  ";
	cin >> index;
	cout << endl;
	cout << endl;
	D.remove(index, data, array_size);
	cout << endl;
	D.display(data, array_size);

}