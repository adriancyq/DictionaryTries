#include "util.h"
#include "DictionaryBST.h"


/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{

  // Initialize the pair that captures the return of insert
  std::pair<std::set<std::string>::iterator,bool> success;

  // Insert the word in the dictionary
  success = dict.insert(word);
  return success.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{

  // Find returns dict.end() if it cannot find the element
  return dict.find(word) != dict.end();
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
