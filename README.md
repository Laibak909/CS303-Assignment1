# CS303-Assignment1
//Array-Database//
//This first file integers.txt.txt contains the integers we use in the code. Make sure to add the integers.txt.txt file before running the code.//
//if the file is not added to the coding folder the code will generate file not found.//

23 44 55 60 71 82 5 12 90 68 2 10 70 54 22 53 87 81 20 41 16 0 52 64 47
26 38 66 85 73 51 72 61 24 46 35 56 65 74 83 92 63 32 8 17 97 78 57 21 9
42 11 1 31 91 62 3 13 33 43 93 4 14 34 84 94 6 15 37 25 95 76 80 19 30 99
40 50 96 98 75 45 86 77 67 36 27 18 88 59 79 58 29 28 49 48 39 89 69 7

//This second file Database.h the header file. This contains all the function declarations.//
//This file contains all the class details and their function.//
//This is file which will be provide as a public it won't have all the unesssary details only the main ideas of the assignment.//

#ifndef DATABASE_H_
#define DATABASE_H_
//#include <iostream>

/** Class details */
class Database {
public:
	void display(int* data, int array_size);

	int integerPresent(int existInteger, int* data, int array_size);

	int modification(int index, int value, int* data, int array_size);

	void newIntegerAdded(int value, int*& data, int& size);

	void remove(int index, int*& data, int& size);

};
#endif	  

//This third file is the main Database.cpp file. //
//This file contains all the main codes which are required to make a programe which can read data.//
//Make sure to add the header file in this file so it can read the funtions from the header file. //
//It used to for the basic input/output streams and read data from a given file(integers.txt.txt). //
//Also when you are working with arrays.//

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
	try                                                                 // using try and catch blocks //
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
	     try {                                                    // adding try and catch blocks for errors//
		for (int count = 0; count < size; count++)
		{
			data2[count] = data[count];
		}
		size = new_size;
		data = data2;
	   } catch (const bad_alloc& e) {
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

//To run the programe add all these three file in visual studio.//
//We have already included the header file in the cpp file so it can automatically read that file.//
//MAKE SURE TO ADD THE TEXT FILE (integers.txt.txt) so it can be read. Run the programe.//

//Final result should be similar to the one mention down below.//

// This last file contains the final product when the code runs //
![Screenshot (5)](https://github.com/Laibak909/CS303-Assignment1/assets/113943791/fef0c345-af9c-4349-bbb3-d62b95da0ac1)
