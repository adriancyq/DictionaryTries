/*
 * File:      DictionaryHashtable.h
 * Authors:   Jonathan Chiu, Adrian Cordova
 * Class:     CSE 100, Winter 2017
 * Date:      2/7/2017
 *
 * Implementation of a dictionary with a hashtable. Supports insertion and
 * lookup.
 */

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>
#include <unordered_set>

/**
 *  The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements
 * a Hashtable, so we strongly suggest you use that to store
 * the dictionary.
 */
class DictionaryHashtable
{
public:

  /* Create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryHashtable();

private:

	// Hash set object
	std::unordered_set<std::string> hashSet;
};

#endif // DICTIONARY_HASHTABLE_H
