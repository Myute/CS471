// (Yoshii) MinMax Game tree (binary) header file.
// Change this to make it tri-nary.
// Function prototypes need to be changed.
// Look for **
//-----------------------------------------
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// each state
struct state
{
  int value;  // value of the state
  int level;  // what level of the tree (0 to maxlevel)
  string op;  // what operator led to it 
};

class mmtree
{
  private:

  state Q[100];// array holding the states
  int count;   // how many states are in Q
  int lastinternal; 
     // the slot of the last internal node
     // helps us differentiate leaves from
     // internal nodes
  int maxlevel; 
     // the maximum level of look ahead
        
  // utility functions 
  bool evenLevel(int);  // is the node's level even? - helps determine Min vs Max level

  bool even(int); //**
       // is the slot number even?  
            // helps determine
            // left or right child

  int  maxof(int, int); //**
        // maximum of the two child values
  int  minof(int, int); //**
        // minimum of the two child values

  void getUtilityValues(int); 
    // obtain the values of terminal nodes
    // need the slot number where terminal nodes
    // begin and the maxlevel 

  void blanks(int);  // display blanks

public:
    mmtree();
    ~mmtree();

  void build(int); 
         // build the tree to the max level

  int  minMaxDFS(int);  
    // minMAX values for internal nodes are computed starting at the given slot 

  void displayAll(); // display the tree in a nice way

};
