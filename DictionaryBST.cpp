/*
 * File:      DictionaryBST.cpp
 * Authors:   Jonathan Chiu (A12113428), Adrian Cordova (A12010305)
 * Class:     CSE 100, Winter 2017
 * Date:      2/7/2017
 *
 * Implementation of a dictionary with a BST backend. Supports insertion and
 * lookup.
 */
#include "util.h"
#include "DictionaryBST.h"

/*
 * Constructor for a dictionary with a BST backend.
 */
DictionaryBST::DictionaryBST() {}

/*
 * Insert a word into the dictionary.
 * Return true on successful insertion, or false otherwise.
 */
bool DictionaryBST::insert(std::string word)
{

  // Initialize the pair that captures the return of insert
  std::pair<std::set<std::string>::iterator,bool> success;

  // Insert the word in the dictionary
  success = dict.insert(word);
  return success.second;
}

/*
 * See if a word exists in the dictionary.
 * Return true if word is in the dictionary, and false otherwise.
 */
bool DictionaryBST::find(std::string word) const
{

  // Find returns dict.end() if it cannot find the element
  return dict.find(word) != dict.end();
}

/*
 * Destructor for the dictionary.
 */
DictionaryBST::~DictionaryBST() {}
