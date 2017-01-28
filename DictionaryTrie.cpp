#include "util.h"
#include "DictionaryTrie.h"

#define LETTERS 26

/* ==========================================================================
  Multi-way Trie Methods
===========================================================================*/
MWTNode::MWTNode() {
  endWord = false;
  frequency = 0;

  // Initialize the children
  for(int i = 0; i < LETTERS; i++) {
      children[i] = NULL;
  }
}


/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  root = new MWTNode();
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  // Start at the root
  MWTNode * current = root;

  // Nothing to insert
  if (word.length() == 0) {
    return false;
  }

  // Traverse down the trie
  for (unsigned int level = 0; level < word.length(); level++) {

    // Create a new node at current position if there is none
    if (current->children[word[level] - 'a'] == NULL) {
      current->children[word[level] - 'a'] = new MWTNode();
    }

    // Move down
    current = current->children[word[level] - 'a'];
  }

  // Check if the word was already inserted
  if (current->endWord) {

    // Return false to indicate word already exists
    current->frequency = freq;
    return false;
  }
  // Mark end of word
  current->frequency = freq;
  current->endWord = true;
  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  // Check for invalid (empty) strings
  if (word.length() == 0) {
    return false;
  }

  // Start looking at the root
  MWTNode * current = root;

  // Traverse the trie
  for (unsigned int level = 0; level < word.length(); level++) {

    // Nowhere to go
    if (!current) {
      return false;
    }

    // Move down
    current = current->children[word[level] - 'a'];
  }

  // Check if we marked this node to be the end of a word
  if (current->endWord) {
    return true;
  }

  // Word is not in the trie
  return false;
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie() {
  deleteAll(root);
}

/* Destructor helper function. */
void DictionaryTrie::deleteAll(MWTNode * curr) {

  // No node to delete
  if (!curr) {
    return;
  }

  // Check to see if there are any children
  for (int i = 0; i < LETTERS; i++) {

    // There is a child
    if (curr->children[i]) {
      deleteAll(curr->children[i]);
    }
  }

  // Delete the current node
  delete curr;
}
