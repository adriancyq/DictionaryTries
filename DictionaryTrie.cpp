/*
 * File:      DictionaryTrie.cpp
 * Authors:   Jonathan Chiu, Adrian Cordova
 * Class:     CSE 100, Winter 2017
 * Date:      2/7/2017
 *
 * Implementation of a multiway trie and its node. Supports insertion, lookup,
 * and completion prediction, given a prefix string.
 *
 */

#include "util.h"
#include "DictionaryTrie.h"
#define LETTERS 26
#define ALPHABET 27
#define SPACE 26

/*
 * Constructor function for a multiway trie node.
 */
MWTNode::MWTNode()
{
  endWord = false;
  frequency = 0;

  // Initialize the children
  for(int i = 0; i < ALPHABET; i++) {
      children[i] = NULL;
  }
}

/*
 * Constructor function for a multiway trie.
 */
DictionaryTrie::DictionaryTrie()
{
  root = new MWTNode();
}

/*
 * Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string)
 */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  MWTNode * current = root;       // Current position in trie
  int next;                       // Index of next child

  // Nothing to insert
  if (word.length() == 0) { return false; }

  // Traverse down the trie
  for (unsigned int level = 0; level < word.length(); level++) {
    next = word[level] - 'a';

    // Next char is space
    if (word[level] == ' ') {
      next = SPACE;
    }

    // Invalid char
    if (next < 0 || next > 26) {
      return false;
    }

    // Create a new node at current position if there is none
    if (!current->children[next]) {
      current->children[next] = new MWTNode();
    }

    // Move down one level
    current = current->children[next];
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
  current->word = word;
  return true;
}

/*
 * Determine whether a given string is in the dictionary.
 * Return true if word is in the dictionary, and false otherwise
 */
bool DictionaryTrie::find(std::string word) const
{
  // Check for invalid (empty) strings
  if (word.length() == 0) { return false; }

  // Current position in the trie
  MWTNode * current = root;
  int next;

  // Traverse down valid paths within the trie
  for (unsigned int level = 0; level < word.length(); level++) {
    if (!current) { return false; }

    // Move down a level
    next = word[level] - 'a';

    // Next char is space
    if (word[level] == ' ') {
      next = SPACE;
    }

    // Invalid char
    if (next < 0 || next > 26) {
      return false;
    }

    current = current->children[next];
  }

  if (!current) { return false; }
  
  // Found our word
  if (current->endWord) { return true; }

  // Word is not in the trie
  return false;
}

/*
 * Given a string prefix, determine most likely possible completions.
 *
 * Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(
  std::string prefix,
  unsigned int num_completions)
{
  std::vector<std::string> words;   // Container for most frequent words

  // Check for empty string
  if (prefix.empty()) {
    std::cerr << "Invalid Input. Please retry with correct input" << std::endl;
    return words;
  }

  MWTNode * current = root;         // Current position in Trie
  int next;

  // Keep in sorted order the most frequent completions
  std::priority_queue<std::pair<std::string, int>,
    std::vector<std::pair<std::string, int>>,
    CompareFrequencies>
      mostFrequent;

  // Traverse to the given prefix in the trie
  for (unsigned int level = 0; level < prefix.length(); level++) {
    if (current == NULL) { return words; }
    next = prefix[level] - 'a';
    current = current->children[next];
  }

  // Begin looking for completed words with DFS
  std::stack<MWTNode*> stack;
  stack.push(current);
  while (!stack.empty()) {
    current = stack.top();
    stack.pop();

    // Found a word, push to priority queue
    if (current->endWord) {
      std::pair<std::string, int> foundWord(current->word, current->frequency);
      mostFrequent.push(foundWord);
    }

    // Add all existing children
    for (int i = 0; i < LETTERS; i++) {
      if (current->children[i]) {
        stack.push(current->children[i]);
      }
    }
  }

  // Populate the vector with "num_completions" most frequent words
  for (unsigned int index = 0; index < num_completions; index++) {
    if (!mostFrequent.empty()) {
      words.push_back(mostFrequent.top().first);
      mostFrequent.pop();
    }
  }

  return words;
}

/*
 * Destructor for the multiway trie.
 */
DictionaryTrie::~DictionaryTrie()
{
  deleteAll(root);
}

/*
 * Helper function for the destructor of the multiway trie.
 */
void DictionaryTrie::deleteAll(MWTNode * curr)
{

  // No node to delete
  if (!curr) { return; }

  // Preorder traversal
  for (int i = 0; i < LETTERS; i++) {
    if (curr->children[i]) {
      deleteAll(curr->children[i]);
    }
  }

  // Delete the current node
  delete curr;
}
