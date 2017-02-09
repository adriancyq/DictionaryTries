/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#define LETTERS 26

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>

/*
* Word-Frequency vector compare class.
* Used in predictCompletions to get k most frequent words.
*/
class CompareFrequencies {
public:
  /* Compare the first vector with the second. Each vector contains a string,
  *  and an associated frequency.
  *  Return true if the frequency of the first word is less than the frequency
  *  of the second word. */
  bool operator() (std::pair<std::string, int> word1,
    std::pair<std::string, int> word2) {
      return word1.second < word2.second;

  }
};

/**
* Multi-way Trie node class. Each node holds a reference to each child, to
* ensure faster find.
*/
class MWTNode
{
public:

  /* Array of children for constant access. */
  MWTNode * children[LETTERS];

  /* Marker for end of word. */
  bool endWord;

  /* Hold the word */
  std::string word;

  /* If this Node marks the end of a word, it holds how frequent this word
  * is searched for.
  */
  int frequency;

  /* Constructor for the multiway trie node. */
  MWTNode();
};

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:

  /* Root node of the trie */
  MWTNode * root;

  /* Destructor helper function. */
  void deleteAll(MWTNode* curr);
};

#endif // DICTIONARY_TRIE_H
