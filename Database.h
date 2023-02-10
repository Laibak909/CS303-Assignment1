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

