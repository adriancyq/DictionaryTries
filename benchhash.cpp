/*
 * File:      benchhash.cpp
 * Authors:   Jonathan Chiu A12113428, Adrian Cordova A12010305
 * Class:     CSE 100, Winter 2017
 * Date:      2/7/2017
 *
 * Benchmarking the summation and bernstein hash functions.
 */
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include "util.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

/*
 * Summation function. Adds up the ASCII value of each letter in the string.
 *
 * Source: http://research.cs.vt.edu/AVresearch/hashing/strings.php
 */
int summationHash(string key, int tableSize)
{

	// Sum the ASCII value of each letter
	int sum = 0;
	for (int i = 0; i < key.length(); i++) {
		sum += key[i];
	}

	// Modulo the tableSize to ensure we get an index within the table
	return sum % tableSize;
}

/*
 * Bernstein hash function. Similar to summation function, but multiply
 * the sum by 33 upon each iteration before adding the ASCII value.
 *
 * Source: http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
 */
unsigned bernsteinHash(string key, int tableSize)
{
	long sum = 0;
	for (int i = 0; i < key.length(); i++) {
	  sum = 33 * sum + key[i];
	}
	return sum % tableSize;
}

/*
 * Tests for the summation and bernstein hash functions. It is currently
 * not called in the main method below, but was previously ran and all tests
 * passed. The expected hash value was hand computed.
 */
int testHashes()
{
	/*
	* Test 1: Hash a single letter.
	*/
	string test1 = "h";
	int size1 = 100;
	cout << "Test 1, Hashing \"" << test1 << "\": ";

	if (bernsteinHash(test1, size1) != 4) {
	  cerr << "Bernstein hash is incorrectly implemented." << endl;
	  return -1;
	}

	else if (summationHash(test1, size1) != 4) {
	  cerr << "Summation hash is incorrectly implemented." << endl;
	  return -1;
	}

	else {
	  cout << "PASSED" << endl;
	}

	/*
	* Test 2: Hash a single lowercase word with no spaces.
	*/
	string test2 = "hello";
	int size2 = 100;
	cout << "Test 2, Hashing \"" << test2 << "\": ";

	if (bernsteinHash(test2, size2) != 8) {
	  cerr << "Bernstein hash is incorrectly implemented." << endl;
	  return -1;
	}

	else if (summationHash(test2, size2) != 32) {
	  cerr << "Summation hash is incorrectly implemented." << endl;
	  return -1;
	}

	else {
	  cout << "PASSED" << endl;
	}

	/*
	* Test 3: Hash a single all-caps word with no spaces.
	*/
	string test3 = "HELLO";
	int size3 = 100;
	cout << "Test 3, Hashing \"" << test3 << "\": ";

	if (bernsteinHash(test3, size3) != 16) {
	  cerr << "Bernstein hash is incorrectly implemented." << endl;
	  return -1;
	}

	else if (summationHash(test3, size3) != 72) {
	  cerr << "Summation hash is incorrectly implemented." << endl;
	  return -1;
	}

	else {
	  cout << "PASSED" << endl;
	}

	return 0;
}


int main (int argc, char* argv[]) {

	// Check that the user has supplied a filename and hashtable size
	if (argc != 3) {
		cerr << "Invalid number of arguments." << endl;
		return -1;
	}

	// Process user input
	string fileName = argv[1];
	unsigned int numWords = atoi(argv[2]);
	unsigned int tableSize = 2 * numWords;

	// Open file
	ifstream inputStream;
  inputStream.open(fileName);
	if (!inputStream.is_open()) {
		cerr << "Unable to open file." << endl;
		return -1;
	}

	string word; 												// Next string to hash
	unsigned int key1;									// Hash value using summations
	unsigned int key2;									// Hash value using bernstein
	unsigned int maxHits1 = 0;
	unsigned int maxHits2 = 0;

	vector<int> table1(tableSize, 0);
	vector<int> table2(tableSize, 0);

	// Hash "numWords" words with our two functions and see how many collisions
	// we get.
	for (int i = 0; i < numWords; i++) {
		getline(inputStream, word);

		// Use two different hashing functions
		key1 = summationHash(word, tableSize);
		key2 = bernsteinHash(word, tableSize);

		// Keep track of number of hits
		table1[key1]++;
		table2[key2]++;

		// Keep track of maxes
		if (maxHits1 < table1[key1]) {
			maxHits1 = table1[key1];
		}

		if (maxHits2 < table2[key2]) {
			maxHits2 = table2[key2];
		}
	}

	// Number of slots that received each number of hits
	vector<int> numHits1(maxHits1 + 1, 0);
	vector<int> numHits2(maxHits2 + 1, 0);

	int collision1 = 0;
	int collision2 = 0;
	double average1 = 0;
	double average2 = 0;

	// Populate hit counts for hash function #1
	for (int i = 0; i <= maxHits1; i++) {
		for (int j = 0; j < tableSize; j++) {
			if (table1[j] == i) {
				numHits1[i]++;
			}

			// Count up number of slots that have at least "i" hits
			if (table1[j] >= i && i != 0) {
				collision1++;
			}
		}

		// Number of slots * number of hits for each slot
		average1 += (collision1 * i);
		collision1 = 0;
	}
	average1 = average1 / numWords;

	// Statistics for hash function #1
	cout << "Printing the statistics for hashFunction1 with hash table size " << tableSize << endl;
	cout << "#hits		#slots receiving the #hits" << endl;
	for (int i = 0; i <= maxHits1; i++) {

		// Don't output if no slots got "i" hits
		if (numHits1[i] != 0) {
			cout << i << "		" << numHits1[i] << endl;
		}
	}

	// Average and worst for hash function #1
	cout << "The average number of steps for a successful search for hash function 1 would be " << average1 << endl;
	cout << "The worst case steps that would be needed to find a word is " << maxHits1 << endl;



	// Populate hit count for hash function #2
	for (int i = 0; i <= maxHits2; i++) {
		for (int j = 0; j < tableSize; j++) {
			if (table2[j] == i) {
				numHits2[i]++;
			}

			// Count up number of slots that have at least "i" hits
			if (table2[j] >= i && i != 0) {
				collision2++;
			}
		}

		// Number of slots * number of hits for each slot
		average2 += (collision2 * i);
		collision2 = 0;
	}
	average2 = average2 / numWords;

	// Statistics for hash function #2
	cout << "Printing the statistics for hashFunction2" << endl;
	cout << "#hits		#slots receiving the #hits" << endl;
	for (int i = 0; i <= maxHits2; i++) {

		// Don't output if no slots got "i" hits
		if (numHits2[i] != 0) {
			cout << i << "		" << numHits2[i] << endl;
		}
	}

	// Average and worst for hash function #2
	cout << "The average number of steps for a successful search for hash function 2 would be " << average2 << endl;
	cout << "The worst case steps that would be needed to find a word is " << maxHits2 << endl;

	return 0;
}
