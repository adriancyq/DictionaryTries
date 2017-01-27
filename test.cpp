#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  /* ========================================================================
  Test 1: Insert 5 words into BST, HashTable, and Trie, then reinsert to check
  that they are already in the container.
  ======================================================================== */

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;

  // Success/failure of insertion
  int t_bst, t_ht, tt;

  // Words to insert
  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");

  // Insert into three data structures
  cout << "Inserting into Dictionaries..." << endl;

  // Iterator boundaries
  wit = words.begin();
  wen = words.end();

  // Insert each word into each data structure
  for(; wit != wen; ++wit) {
    cout << "Inserting: \"" << *wit << "\"... ";
    t_bst = d_bst.insert(*wit);
    t_ht = d_ht.insert(*wit);
    tt = dt.insert(*wit, 1);

    // Check BST dictionary for successful insertion
    if(!t_bst) {
      cout << "failed for DictionaryBST... ";
    }

    // Check HashSet dictionary for successful insertion
    if(!t_ht) {
      cout << "failed for DictionaryHashset... ";
    }

    // Check Trie dictionary for successful insertion
    if(!tt) {
      cout << "failed for DictionaryTrie... ";
    }

    // All successful
    if(t_bst && t_ht && tt) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  // Reset iterators
  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit) {
    
    cout << "Inserting: \"" << *wit << "\"... ";
    t_bst = d_bst.insert(*wit);
    t_ht = d_ht.insert(*wit);
    tt = dt.insert(*wit, 0);

    // BST dictionary should return false since word already exists
    if(t_bst) {
      cout << "failed for DictionaryBST... ";
    }

    // HashSet dictionary should return false since word already exists
    if(t_ht) {
      cout << "failed for DictionaryHashset... ";
    }

    // Trie dictionary should return false since word already exists
    if(tt) {
      cout << "failed for DictionaryTrie... ";
    }

    // All successful
    if(!t_bst && !t_ht && !tt) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl;


/*You are supposed to add more test cases in this file */

  return 0;
}
