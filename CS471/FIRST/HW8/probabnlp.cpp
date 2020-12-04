//***********************************
// Name: Kevyn Higbee
// Date: 11/30/20
// File: HW8
// CS471  N-gram probability use
// The input file can be of any format
// ***********************************

// add includes here
#include <iostream>       // for cin+cout
#include <string>         // for non c_strings
#include <fstream>        // for file input
#include <vector>         // for dynamically reading file
#include <sstream>        // for reading from file

using namespace std;

// struct for storing read probilities
struct prob {
  char letter;  // next letter
  string pre;   // preceding letter(s)
  double prob;  // probability of occurence
};

double probability(vector<prob>&, string);                  // recursive helper function for finding probability
double probability(vector<prob>&, string, string, double);  // recursive function for finding probabiltiy

int main()  {
  vector<prob> v;                           // stores probabilites from file in vector, this is less efficient and a worse idea than using a map, table, or tree
  string path = "", line = "", read = "";   // strings for reading file path/input
  string user_in;                           // user string input for probability
  fstream fin;                              // file interaction
  prob tmp;                                 // temporary prob struct for reading file 
  double P = 0;                             // probability of phrase from user

  // Ask the user for the input file name
  cout << "Enter a file name:" << endl;
  cin >> path;

  // Read in the trigram probabilties
  fin.open(path.c_str());
  if(!fin) {                                // make sure we have a valid file to open
    cout << "Unable to open file: " << path << endl;
    exit(1);                                // exit status 1 if no file is found
  } 
  while(getline(fin,line)) {
    stringstream ss(line);                  // using a stringstream to read from file into struct
    ss >> read;
    tmp.letter = read[0];
    ss >> read;
    tmp.pre = read;
    ss >> read;
    tmp.prob = stod(read);
    v.push_back(tmp);
  }

  // Display in a readable format.
  cout << "The probabilities of each letter sequence are:" << endl;
  for(prob a : v) {
    cout << "P(" << a.letter << " | " << a.pre << ") = " << a.prob << endl;
  }
  cout << "-- end --" << endl;
  
  // Repeat the following until the user
  // wants to quit:
  
  do {
     // Ask the user to enter a word
    cout << "Enter a phrase to find the probability of or quit to quit: " << endl;
    cin >> user_in;                 // relying on user input to be consisting of A,B,C's in all uppercase otherwise program fails
    if (user_in == "quit") {}       // we aren't validating for correct input at all because it's not in the scope
    else {
     // Show all the probabilities you used
     // to calculate the P(word)
     P = probability(v, user_in);   // uses recursive helper function
     cout << endl;
     // Show the P(word)
     cout << "The probability of the phrase \"" << user_in <<"\" is: " << P << "" << endl << endl;
    }
  } while (user_in != "quit");
  return 0;
} 

double probability(vector<prob> &v, string input) {
  int i = 0;
  // find index in vector of correct probability based on next and preceding letters
  // because this is always the first letter, the preceding should be null string
  while((input[0] != v[i].letter) && (v[i].pre == "null")) {
    i+=1;
  }

  // output
  cout << "P(" << input << ") " << "= " << v[i].prob << "(" << v[i].letter << " | " << v[i].pre << ") ";

  // call recursive function as return
  return probability(v, input.substr(1,input.length()-1), string(1, input[0]), v[i].prob);
}

double probability(vector<prob> &v, string input, string pre, double p) {
  // make sure we havent reached the end of the string
  if (!input.empty()) {
    int i = 0;
    // find appropriate index of vector
    while((input[0] != v[i].letter) || (pre != v[i].pre)) {
      i+=1;
    }
    // output stuff
    cout << "* " << v[i].prob << "(" << v[i].letter << " | " << v[i].pre << ") ";
    p*=v[i].prob;                                                   // find new probability
    string nextpre;                                             
    if (v[i].pre.length() > 1) nextpre = v[i].pre.substr(1,1);      // if there should be multiple preceding letters
    else nextpre = v[i].pre.substr(0,1);                            // if there should be only 1 preceding letter
    nextpre+=v[i].letter;                                           // add current letter to the next preceding letters for recursive call
    return probability(v, input.substr(1,input.length()-1), nextpre, p);  // recursive call
  }
  else
    return p;                                                       // if the string was empty return the last probabilty
}