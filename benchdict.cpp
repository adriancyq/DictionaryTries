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
int main(int argc, char* argv[]){

	//evaluates number of input args is correct
	int argamount = 5;
	if(argc != argamount){

		std::cout<<"Wrong number of arguments"<<std::endl;

	}

	int min_size = atoi(argv[1]); //converts 1st arg string to int
	int step_size = atoi(argv[2]); //converts 2nd arg string to int
	int num_iterations = atoi(argv[3]); //converts 3rd arg string to int
	std::string nameofFile = argv[4];
	int runDict = RUNDICTS; 

	//Timers created
	Timer timeOne;
	Timer timeTwo;
	Timer timeThree;

	//Dictionaries created
	DictionaryBST *myDictBST = new DictionaryBST();		
	DictionaryHashtable	*myDictHash = new DictionaryHashtable();
	DictionaryTrie *myDictMWT = new DictionaryTrie();

	//files are opened
	std::ifstream inputfile;
	inputfile.open(nameofFile);
	if(!inputfile.is_open()){
		cout<<"file was not opened"<<endl;
	}

	//make sure the file was read out 
	string readLine = "";
	int count = 0;
	while(getline(inputfile, readLine)){
		count=count+1;
	}

	/*BST handler*/
	std::cout<<"DictionaryBST class benchmark runs"<<endl;

	std::vector<std::string> DictBST;

	int wordAmount = 0;

	double addBST = 0;

	for (int i=0; i<num_iterations; i++){

		inputfile.close();

		inputfile.open(nameofFile);

		wordAmount = min_size + (i*step_size);

		//Loads word into dict from utils.h
		if(wordAmount<=count){
			Utils::load_dict(*myDictBST, inputfile, wordAmount);
		}

		else{
			cout<<"Warning! DictionaryBST does not have enough words"<<endl;
		}

		//Grab following 100 words to be found
		for(int l=0; l<100; l++){

			getline(inputfile, readLine);

			DictBST.push_back(readLine);
		}

		//times process of finding 100 words
		for(int n=0; n<runDict; n++){

			timeOne.begin_timer();

			for(int p=0; p<100; p++){

				myDictBST->find(DictBST[p]);
			}

			double BSTtime = timeOne.end_timer();

			//adds the times together
			addBST = addBST + BSTtime;
		}

		//Finds the average time
		addBST = (addBST/runDict);
		cout<<wordAmount<<"   vs    "<<addBST<<endl;
	}
	//deletes BST
	delete myDictBST;

		/*Hash Table handler*/
	std::cout<<"DictionaryHashTable class benchmark runs"<<endl;

	std::vector<std::string> DictHash;

	wordAmount = 0;

	double addHash = 0;

	for (int i=0; i<num_iterations; i++){

		inputfile.close();

		inputfile.open(nameofFile);

		wordAmount = min_size + (i*step_size);

		//Loads word into dict from utils.h
		if(wordAmount<=count){
			Utils::load_dict(*myDictHash, inputfile, wordAmount);
		}

		else{
			cout<<"Warning! DictionaryHashTable does not have enough words"<<endl;
		}

		//Grab following 100 words to be found
		for(int l=0; l<100; l++){

			getline(inputfile, readLine);

			DictHash.push_back(readLine);
		}

		//times process of finding 100 words
		for(int n=0; n<runDict; n++){

			timeTwo.begin_timer();

			for(int p=0; p<100; p++){

				myDictHash->find(DictHash[p]);
			}

			double Hashtime = timeTwo.end_timer();

			//adds the times together
			addHash = addHash + Hashtime;
		}
		
		//Finds the average time
		addHash = (addHash/runDict);
		cout<<wordAmount<<"    vs    "<<addHash<<endl;
	}
	//deletes Hash
	delete myDictHash;

	/*MWT handler*/
	std::cout<<"DictionaryMWT class benchmark runs"<<endl;

	std::vector<std::string> DictMWT;

	wordAmount = 0;

	double addMWT = 0;

	for (int i=0; i<num_iterations; i++){

		inputfile.close();

		inputfile.open(nameofFile);

		wordAmount = min_size + (i*step_size);

		//Loads word into dict from utils.h
		if(wordAmount<=count){
			Utils::load_dict(*myDictMWT, inputfile, wordAmount);
		}

		else{
			cout<<"Warning! DictionaryMWT does not have enough words"<<endl;
		}

		//Grab following 100 words to be found
		for(int l=0; l<100; l++){

			getline(inputfile, readLine);

			DictMWT.push_back(readLine);
		}

		//times process of finding 100 words
		for(int n=0; n<runDict; n++){

			timeThree.begin_timer();

			for(int p=0; p<100; p++){

				myDictMWT->find(DictMWT[p]);
			}

			double MWTtime = timeThree.end_timer();

			//adds the times together
			addMWT = addMWT + MWTtime;
		}
		
		//Finds the average time
		addMWT = (addMWT/runDict);
		cout<<wordAmount<<"    vs    "<<addMWT<<endl;
	}
	//deletes MWT
	delete myDictMWT;

	return 0;
}