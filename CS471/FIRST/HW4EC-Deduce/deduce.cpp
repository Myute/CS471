#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Yoshii - HW4 Extra Credit for Inferences
//   Given two facts and one implies rule
//   see what you can deduce.
//   Each fact has a true or false value
//   The condition part of the implication rule
//   may use AND or OR.
// Look for ** to complete.

// Each fact is a word e.g. RAINING
// Each fact is followed by either true or false
string facts[2][2];

struct rule
{
  string p1;
  string op; // op is AND or OR
  string p2;
  string concl;
};



rule myrule; // the rule  
int num; // number of conditions in the rule

// check to see if a condition is notted
bool isnotted(string s)
{ 
  if (s[0] == '~') return true; else return false;
}

// readin the contents of a kb file
// and display them
void readin()
{ string kb;
  cout << "Enter the KB name: ";
  cin >> kb;
  ifstream fin (kb.c_str(), ios::in);

  fin >> num;  // how many facts or conditions

  //** for each fact
    // ** read the fact word
    // ** read true or false
 
  // ** display the facts

  // ** read the rule condition(s) 
  // ** read the operator
  // ** read the implies symbol 
  // ** read the conclusion
  // ** display them

}// end of reading the kb   

// deduce based on one condition
string deduceOne()
{
  // ** check the notted condition vs. false fact
  // ** check the unnotted condition vs. true fact
  // ** check the conclusion vs. false fact 
  else
    return "nothing";
}

// deduce based on two conditions
 string deduceTwo()
 { 
   // ** check to see if the first condition is true
   // ** check to see if the second condition is true
   // ** check the operator to decide if the conclusion is true
   else return "error";
 }

 int main()
 {
   cout << "Reading the KB..." << endl;
   readin();
   cout << "DEDUCED:" << endl;
   if (num == 1) cout << deduceOne() << endl;
   else cout << deduceTwo() << endl;
 }
