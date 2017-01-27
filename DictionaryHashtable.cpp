#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{	
	//Initialize the pair that captures the return of insert
	std::pair<std::unordered_set<std::string>::iterator,bool> success;

	//Insert the word in the dictionary
	success = hashSet.insert(word);
	return success.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
	return hashSet.find(word) != hashSet.end();
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
	
}
