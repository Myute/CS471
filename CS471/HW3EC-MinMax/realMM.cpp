#include <iostream>
using namespace std;
#include "bst.h"

// DFS MinMax Sample Program by Yoshii 
int main()
{

  BST MyTree;  // my tree 

  // I am entering nodes into the tree 
  // to create a triangular tree
     MyTree.InsertVertex('D');

      MyTree.InsertVertex('B');
      MyTree.InsertVertex('A');  
      MyTree.InsertVertex('C');

      MyTree.InsertVertex('F');
      MyTree.InsertVertex('E');  
      MyTree.InsertVertex('G');

  cout << "A triangular tree has been created." << endl;
  cout << "Enter scores of leaves as prompted" << endl;
  MyTree.Search(1);

  cout << endl;
  cout << "Here is the initial tree..." << endl; 
  MyTree.Search(2);

  char a;
  cout << "Type any key to continue"; cin >> a;  

  cout << "MinMax  being done..." << endl;
  MyTree.Search(3);

}
