#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
	std::unordered_set<std::string> hashSet;
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
	hashSet.insert(word);
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
	
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
	
}
