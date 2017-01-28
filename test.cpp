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
  cout << "Inserting into Dictionaries test 1..." << endl;

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

   /* ========================================================================
  Test 2: Insert 5 words into BST, HashTable, and Trie, then reinsert to check
  that they are already in the container.
  ======================================================================== */

  //Initialize words
  vector<std::string> words2;
  vector<string>::iterator wit2;
  vector<string>::iterator wen2;

  //Initialize data structures
  DictionaryBST d_bst2;
  DictionaryHashtable d_ht2;
  DictionaryTrie dt2;

  // Success/failure of insertion
  int t_bst2, t_ht2, tt2;

  // Words to insert
  words2.push_back("cherry");
  words2.push_back("apple");
  words2.push_back("lemon");
  words2.push_back("bicycle");
  words2.push_back("vehicle");

  // Insert into three data structures
  cout << "Inserting into Dictionaries for test 2..." << endl;

  // Iterator boundaries
  wit2 = words2.begin();
  wen2 = words2.end();

  // Insert each word into each data structure
  for(; wit2 != wen2; ++wit2) {
    cout << "Inserting: \"" << *wit2 << "\"... ";
    t_bst2 = d_bst2.insert(*wit2);
    t_ht2 = d_ht2.insert(*wit2);
    tt2 = dt2.insert(*wit2, 1);

    // Check BST dictionary for successful insertion
    if(!t_bst2) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // Check HashSet dictionary for successful insertion
    if(!t_ht2) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Check Trie dictionary for successful insertion
    if(!tt2) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(t_bst2 && t_ht2 && tt2) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  // Reset iterators
  wit2 = words2.begin();
  wen2 = words2.end();
  for(; wit2 != wen2; ++wit2) {
    
    cout << "Inserting: \"" << *wit2 << "\"... ";
    t_bst2 = d_bst2.insert(*wit2);
    t_ht2 = d_ht2.insert(*wit2);
    tt2 = dt2.insert(*wit2, 0);

    // BST dictionary should return false since word already exists
    if(t_bst2) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // HashSet dictionary should return false since word already exists
    if(t_ht2) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Trie dictionary should return false since word already exists
    if(tt2) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(!t_bst2 && !t_ht2 && !tt2) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl;

   /* ========================================================================
  Test 3: Insert 5 words into BST, HashTable, and Trie, then reinsert to check
  that they are already in the container.
  ======================================================================== */

  //Initialize words
  vector<std::string> words3;
  vector<string>::iterator wit3;
  vector<string>::iterator wen3;

  //Initialize data structures
  DictionaryBST d_bst3;
  DictionaryHashtable d_ht3;
  DictionaryTrie dt3;

  // Success/failure of insertion
  int t_bst3, t_ht3, tt3;

  // Words to insert
  words3.push_back("ballast");
  words3.push_back("bobble");
  words3.push_back("sculpin");
  words3.push_back("pineapple");
  words3.push_back("armadillo");

  // Insert into three data structures
  cout << "Inserting into Dictionaries for test 3..." << endl;

  // Iterator boundaries
  wit3 = words3.begin();
  wen3 = words3.end();

  // Insert each word into each data structure
  for(; wit3 != wen3; ++wit3) {
    cout << "Inserting: \"" << *wit3 << "\"... ";
    t_bst3 = d_bst3.insert(*wit3);
    t_ht3 = d_ht3.insert(*wit3);
    tt3 = dt3.insert(*wit3, 1);

    // Check BST dictionary for successful insertion
    if(!t_bst3) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // Check HashSet dictionary for successful insertion
    if(!t_ht3) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Check Trie dictionary for successful insertion
    if(!tt3) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(t_bst3 && t_ht3 && tt3) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  // Reset iterators
  wit3 = words3.begin();
  wen3 = words3.end();
  for(; wit3 != wen3; ++wit3) {
    
    cout << "Inserting: \"" << *wit3 << "\"... ";
    t_bst3 = d_bst3.insert(*wit3);
    t_ht3 = d_ht3.insert(*wit3);
    tt3 = dt3.insert(*wit3, 0);

    // BST dictionary should return false since word already exists
    if(t_bst3) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // HashSet dictionary should return false since word already exists
    if(t_ht3) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Trie dictionary should return false since word already exists
    if(tt3) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(!t_bst3 && !t_ht3 && !tt3) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl;

   /* ========================================================================
  Test 4: Insert 5 words into BST, HashTable, and Trie, then reinsert to check
  that they are already in the container.
  ======================================================================== */

  //Initialize words
  vector<std::string> words4;
  vector<string>::iterator wit4;
  vector<string>::iterator wen4;

  //Initialize data structures
  DictionaryBST d_bst4;
  DictionaryHashtable d_ht4;
  DictionaryTrie dt4;

  // Success/failure of insertion
  int t_bst4, t_ht4, tt4;

  // Words to insert
  words4.push_back("phone");
  words4.push_back("tissue");
  words4.push_back("purchase");
  words4.push_back("chubbies");
  words4.push_back("crocodile");

  // Insert into three data structures
  cout << "Inserting into Dictionaries for test 4..." << endl;

  // Iterator boundaries
  wit4 = words4.begin();
  wen4 = words4.end();

  // Insert each word into each data structure
  for(; wit4 != wen4; ++wit4) {
    cout << "Inserting: \"" << *wit4 << "\"... ";
    t_bst4 = d_bst4.insert(*wit4);
    t_ht4 = d_ht4.insert(*wit4);
    tt4 = dt4.insert(*wit4, 1);

    // Check BST dictionary for successful insertion
    if(!t_bst4) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // Check HashSet dictionary for successful insertion
    if(!t_ht4) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Check Trie dictionary for successful insertion
    if(!tt4) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(t_bst4 && t_ht4 && tt4) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  // Reset iterators
  wit4 = words4.begin();
  wen4 = words4.end();
  for(; wit4 != wen4; ++wit4) {
    
    cout << "Inserting: \"" << *wit4 << "\"... ";
    t_bst4 = d_bst4.insert(*wit4);
    t_ht4 = d_ht4.insert(*wit4);
    tt4 = dt4.insert(*wit4, 0);

    // BST dictionary should return false since word already exists
    if(t_bst4) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // HashSet dictionary should return false since word already exists
    if(t_ht4) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Trie dictionary should return false since word already exists
    if(tt4) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(!t_bst4 && !t_ht4 && !tt4) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl;

   /* ========================================================================
  Test 5: Insert 5 words into BST, HashTable, and Trie, then reinsert to check
  that they are already in the container.
  ======================================================================== */

  //Initialize words
  vector<std::string> words5;
  vector<string>::iterator wit5;
  vector<string>::iterator wen5;

  //Initialize data structures
  DictionaryBST d_bst5;
  DictionaryHashtable d_ht5;
  DictionaryTrie dt5;

  // Success/failure of insertion
  int t_bst5, t_ht5, tt5;

  // Words to insert
  words5.push_back("soccer");
  words5.push_back("octopus");
  words5.push_back("gelatin");
  words5.push_back("igloo");
  words5.push_back("elephant");

  // Insert into three data structures
  cout << "Inserting into Dictionaries for test 5..." << endl;

  // Iterator boundaries
  wit5 = words5.begin();
  wen5 = words5.end();

  // Insert each word into each data structure
  for(; wit5 != wen5; ++wit5) {
    cout << "Inserting: \"" << *wit5 << "\"... ";
    t_bst5 = d_bst5.insert(*wit5);
    t_ht5 = d_ht5.insert(*wit5);
    tt5 = dt5.insert(*wit5, 1);

    // Check BST dictionary for successful insertion
    if(!t_bst5) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // Check HashSet dictionary for successful insertion
    if(!t_ht5) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Check Trie dictionary for successful insertion
    if(!tt5) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(t_bst5 && t_ht5 && tt5) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  // Reset iterators
  wit5 = words5.begin();
  wen5 = words5.end();
  for(; wit5 != wen5; ++wit5) {
    
    cout << "Inserting: \"" << *wit5 << "\"... ";
    t_bst5 = d_bst5.insert(*wit5);
    t_ht5 = d_ht5.insert(*wit5);
    tt5 = dt5.insert(*wit5, 0);

    // BST dictionary should return false since word already exists
    if(t_bst5) {
      cout << "failed for DictionaryBST... ";
      return -1;
    }

    // HashSet dictionary should return false since word already exists
    if(t_ht5) {
      cout << "failed for DictionaryHashset... ";
      return -1;
    }

    // Trie dictionary should return false since word already exists
    if(tt5) {
      cout << "failed for DictionaryTrie... ";
      return -1;
    }

    // All successful
    if(!t_bst5 && !t_ht5 && !tt5) {
      cout << "PASSED! :D ";
    }

    cout << endl;
  }

  cout << endl;


  return 0;
}
