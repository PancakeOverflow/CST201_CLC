// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class hashTable {
private:
	string table[11]{ "" };

public:
	// returns the key (hash function sans conflicts)
	int getHash(string key) {
		cout << "Searching for key " << key << endl;
		int number = 0;
		int result = 0;
		int digits[7];
		int j = 6; //use to insert into the digits array backwards.

		//convert the key to a number.
		for (char c : key) {
			number += c;
		}

		return number % 11;

		/*
		//split the number up into its digits.
		for (int i = 0; i < 1; ++i) {//as long as there is still a number.
									 //get the last digit of the number.
			digits[j] = number % 10;
			number = number / 10; //shift the number over one digit.
			--j;
		}
		//get the first three digits of the number.
		for (int i = 0; i < 3; ++i) {
			//add the digit to the result.
			result += digits[i];
		}
		//make sure the result will be a number within the length
		//of the hashTable.
		result = result % 11;
		return result;
		*/
	}

	void insert(int index, string data) {
		//check if the hasTable at the index is null. (empty)

		if (table[index] == "") {
			cout << "Inserting " << index << endl;
			table[index] = data;
		}
		else {
			while (table[index] != "") {
				cout << "Found a clash at: " << index << endl;
				if (index != 11) {
					index += 1;
				}
				else {
					index = 0;
				}
			}
			cout << "Inserting " << index << endl;
			table[index] = data;
		}
	}

	string getData(string key) {
		int index = getHash(key);
		string atIndexInHash = getKeyAsString(table[index]);
		int catchInteration = 0;
		while (atIndexInHash != key) {
			index = (index + 1) % 11;
			atIndexInHash = getKeyAsString(table[index]);
			if (catchInteration++ > 11) {
				cout << "it's not working ";
			}
		}
		
		return table[index];
	}

	string getKeyAsString(string data) {
		string result = "";
		std::istringstream stream(data);
		while (getline(stream, result, ' '));
		return result;
	}

	void display() {
		for (int i = 0; i < 11; ++i) {
			cout << "Table[" << i << "]: " << table[i] << endl;
		}
	}
};


/*void open(string myArry[9]) {
	string line;
	string temp;

	ifstream inputFile;
	inputFile.open("Phone_Numbers.txt");
	int i = 0;
	while (getline(inputFile, line)) {
		istringstream lineStream(line);

		while (getline(lineStream, temp, ',')) {
			myArry[i] = temp;
			cout << "Array: " << myArry[i] << endl;
			++i;
		}
	}
	inputFile.close();
}*/

void getKeys(string data[9], string keys[9]) {
	string key;
	//loop through the data array.
	for (int i = 0; i < 9; i++) {
		string temp = data[i];
		//get the substring after the space.
		//.find to get the position of the " " between the name and data.
		key = temp.substr(temp.find(" ") + 1);//+1 to skip over space.
		keys[i] = key;
		cout << "Key: " << keys[i] << endl;
	}
}

int main() {

	string data[9] = { "Adam 123-4567", "Brenda 345-5352", "Brendon 983-7373", "Charles 987-1122",
		"Jeremiah 789-4563", "Katherine 823-1573", "Patrick 757-4532", "Raymond 090-9383", "Thorsten 929-6632" };
	string keys[9] = { "123-4567", "345-5352", "983-7373", "987-1122", "789-4563", "823-1573", "757-4532", "090-9383", "929-6632" };
	int num;
	hashTable test;

	//get the data by opening the file.
	// open(data);

	//parse the keys out of the data.
	// getKeys(data, keys);

	//for every key in the array get its hash index.
	for (int i = 0; i < 9; ++i) {
		string key = keys[i];
		string combinedData = data[i];
		int result;
		//get the hash index;
		result = test.getHash(key);

		//add the data to the hashTable at the hash index retrieved.
		test.insert(result, combinedData);
	}
	cout << endl;

	cout << "Displaying the hash Table" << endl;
	test.display();
	string input;
	cout << " Please enter a phone number" << endl;
	cin >> input;
	string key = input;
	auto retreive = test.getData(key);
	cout << retreive << endl;
	return 0;
}