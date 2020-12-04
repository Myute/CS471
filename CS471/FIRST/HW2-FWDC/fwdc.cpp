#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>  /* to use exit */
using namespace std;

// Update this file for HW2 FWDC (Yoshii)
// Look for *** using control-S and add code 
//-----------------------------------------

// State description class.
// Could have used struct.
// Items here are  FWDC on L or R 
//    e.g. RRRR for the initial state
class state
{
public:
  string items;  
  string camefrom; // the parent on the solution path
  int g;   // cost so far
  int h;   // estimated cost to the goal
  int f;   // g+h
};

vector<state> frontier;  // Frontier nodes
vector<state> beenThere; // already expanded nodes

void addtoBeenThere(state x)
{  beenthere.push_back(x); }

void addtoFrontier(state x)
{  frontier.push_back(x); }

// to remove state X from the frontier
void removefromFrontier(state x)
{  
  vector<state> newfrontier;
  for (int k = 0; k < frontier.size(); k++)
    if (frontier[k].items != x.items)
      newfrontier.push_back(frontier[k]);

  frontier = newfrontier;
}

//===============================================

// Display the states in the frontier 
void displayFrontier()
{
  for (int k = 0; k < frontier.size(); k++)
    { cout << frontier[k].items << " ";  
      cout << "g = " <<frontier[k].g << " ";
      cout << "h = " <<frontier[k].h << " ";
      cout << "f = " <<frontier[k].f << endl; 
    }
}

// Trace the solution path from goal to initial.
// Note that camefrom of each state should be used.
void tracePath(state goal)
{
  // *** add code here to display the path (recursion?)
}  

// Check to see if next's items is already in frontier and return true or false.
//   If it is already in frontier, 
//   and if the next's f is better, 
//   update the node to next. 
bool inFrontier(state next)
{
  // **** add code here, possibly updating
  // the frontier
}


// Try to add next to frontier but stop if LLLL 
void add(state next)
{ bool unsafe = false;  int h = 0;

  cout << "Trying to add: " << next.items; 

  if (next.items  == "LLLL") 
    { cout << ">>Reached: " << next.items << endl;
      tracePath(next);  // display the solution path
      exit(0); }//done

  // *** if been there before, do not add

  // *** if unsafe, do not add

  // *** else compute h and f for next and

  if (!inFrontier(next))
    addtoFrontier(next); // add next to Frontier
}   

// Generate all new states from current
void generate(state current)
{
  state next;  // a generated one

 // each next will be modified from current for ease
  current.g = current.g + 1; // to update g
  // storing the parent so that we can produce the solution path
  current.camefrom = current.items; 

  // check all possibilities as follows..

  next = current;  // starting point of next
  // move F alone to L
  if (current.items[0] == 'R')
    { next.items[0]='L'; add(next);};

  next = current; // starting point of next
  // move F alone to R
  if (current.items[0] == 'L')
    { next.items[0]='R'; add(next);};

  next = current; // starting point of next
  // move FW to L
  if (current.items[0] == 'R' && current.items[1] == 'R')
    { next.items[0]='L'; next.items[1] = 'L'; add(next);};  

  next = current; // starting point of next
  // move FW to R
  if (current.items[0] == 'L' && current.items[1] == 'L')
    { next.items[0]='R'; next.items[1] = 'R'; add(next);};  
  
  next = current; // starting point of next
  // move FD to L
  if (current.items[0] == 'R' && current.items[2] == 'R')
    { next.items[0]='L'; next.items[2] = 'L'; add(next);};  

  next = current; // starting point of next
  // move FD to R
  if (current.items[0] == 'L' && current.items[2] == 'L')
    { next.items[0]='R'; next.items[2] = 'R'; add(next);};  

  next = current; // starting point of next
  // move FC to L
  if (current.items[0] == 'R' && current.items[3] == 'R')
    { next.items[0]='L'; next.items[3] = 'L'; add(next);};  

  next = current; // starting point of next
  // move FC to R 
  if (current.items[0] == 'L' && current.items[3] == 'L')
    { next.items[0]='R'; next.items[3] = 'R'; add(next);};  

}// end of generate


// Find the best f state out of the frontier and return it
state bestofFrontier()
{ 
  // **** add code here
}


//===========================================

int main() 
{

  state  current = {"RRRR", 0, 3, 3};  // initial
  addtoFrontier(current);

  char ans;
  while ( ans != 'n')
    { 
      removefromFrontier(current);      
      addtoBeenThere(current);

      cout << ">>>Expand:" << current.items << endl; 
      generate(current);  // new states are added to frontier

      cout << "Frontier is:" << endl;
      displayFrontier();

      current = bestofFrontier(); // pick the best state out of frontier
      cin >> ans;

    }// end while

}//end of main

