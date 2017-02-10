/*CSE 100 PA2
Adrian Cordova y Quiroz A12010305
Jonathan Chiu PIDDDDDDDDDD */

#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include "util.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#define RUNDICTS 50 //C
using std::istream;
using namespace std;

/*main initiates data structures, records the time needed for each to  find words in dictionary*/
int main(int argc, char* argv[]) {

	// Check that we have 4 user-specified arguments
	if (argc >= 5){
		cerr << "Wrong number of arguments, " << argc << " given." << endl;
		return -1;
	}

	// User-specified arguments
	// int minSize = atoi(argv[1]);
	// int stepSize = atoi(argv[2]);
	// int numIterations = atoi(argv[3]);
	// string fileName = argv[4];
	int minSize = 2;
	int stepSize = 2;
	int numIterations = 2;
	string fileName = "dictionary/smalldictionary.txt";

	// Useful values
	unsigned int dictSize;
	unsigned int nextWords = 100;

	// Open the file
	ifstream inputStream;
	inputStream.open(fileName);
	if (!inputStream.is_open()) {
		cerr << "Unable to open file." << endl;
		return -1;
	}

	// Find out how many words there are
	int numWords = 0;
	string word;
	while (getline(inputStream, word)) {
		numWords++;
	}

	/* =========================================================================
	 *
	 * Benchmarking the BST-based Dictionary.
	 *
	 * ====================================================================== */
	cout << "DictionaryBST" << endl;
	vector<string> wordsBST;
	Timer timeBST;
	double averageTimeBST = 0;

	for (int i = 0; i < numIterations; i++) {

		// Reset stream so we read file from beginning
		inputStream.close();
		inputStream.open(fileName);

		// Create a new dictionary object for each iteration
		DictionaryBST * dictBST = new DictionaryBST();

		// Check that we have minSize + i * stepSize words to load
		dictSize = minSize + (i * stepSize);
		if (numWords < dictSize) {
			cerr << "Not enough words for the specified minSize and stepSize." << endl;
			return -1;
		}

		// Load minSize + i * stepSize words from beginning of dictionary file
		Utils::load_dict(* dictBST, inputStream, dictSize);
		Utils::load_vector(wordsBST, inputStream, nextWords);

		// Time how long it takes to find these 100 words
		for (int i = 0; i < RUNDICTS; i++) {
			timeBST.begin_timer();
			for (int j = 0; j < 100; j++) {
				dictBST->find(wordsBST[j]);
			}

			// End time
			double elapsedBST = timeBST.end_timer();
			averageTimeBST += (elapsedBST / RUNDICTS);
		}

		// Report of average time for specific problem size
		cout << dictSize << "	" << averageTimeBST << endl;

		// Reset
		delete dictBST;
		wordsBST.clear();
	}


	/* =========================================================================
	 *
	 * Benchmarking the MWT-based Dictionary.
	 *
	 * ====================================================================== */
	cout << "DictionaryTrie" << endl;
	vector<string> wordsMWT;
	Timer timeMWT;
	double averageTimeMWT = 0;

	for (int i = 0; i < numIterations; i++) {

		// Reset stream so we read file from beginning
		inputStream.close();
		inputStream.open(fileName);

		// Create a new dictionary object for each iteration
		DictionaryTrie * dictMWT = new DictionaryTrie();

		// Check that we have minSize + i * stepSize words to load
		dictSize = minSize + (i * stepSize);
		if (numWords < dictSize) {
			cerr << "Not enough words for the specified minSize and stepSize." << endl;
			return -1;
		}

		// Load minSize + i * stepSize words from beginning of dictionary file
		Utils::load_dict(* dictMWT, inputStream, dictSize);
		Utils::load_vector(wordsMWT, inputStream, nextWords);

		// Time how long it takes to find these 100 words
		for (int i = 0; i < RUNDICTS; i++) {
			timeMWT.begin_timer();

			for (int j = 0; j < 100; j++) {
				dictMWT->find(wordsMWT[j]);
			}

			// End time
			double elapsedMWT = timeMWT.end_timer();
			averageTimeMWT += (elapsedMWT / RUNDICTS);
		}

		// Report of average time for specific problem size
		cout << dictSize << "	" << averageTimeMWT << endl;

		// Reset
		delete dictMWT;
		wordsMWT.clear();
	}


	return 0;
}
