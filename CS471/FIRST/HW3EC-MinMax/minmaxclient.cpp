// Yoshii - MinMax client for a binary tree
// Change this for a trinary tree.
//----------------------------------------
#include <iostream>
#include "mmtree.h"
using namespace std;


// This program demonstrates MinMax game tree
// but is restricted to be binary.
//  Look ahead level is entered by the user.
//  Leaf values are entered by the user.
int main()
{
  mmtree States;   // tree of states
  int mlevel;

  cout << "In this game, there is a binary decision made at each state. ";
  cout << "One can begin to move left or right." << endl << endl;; 

  cout << "Maximum level of lookahead is? "; cin >> mlevel;

  cout << "I am going to build the tree in my head..." << endl;
  States.build(mlevel);

  cout << "Tree is:" << endl;
  States.displayAll();

  char a; // to pause 
  cout << "Type c to continue..";
  cin >> a;

  cout << "Doing MinMax...." << endl;
  States.minMaxDFS(0);

  cout << "After MinMax:" << endl;
  States.displayAll();

}  // end
