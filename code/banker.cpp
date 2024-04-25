/*

    Minh Nhat Nguyen

    Operating Systems - CS33211, Project 2

    Banker's algorithm

*/


#include <iostream>
#include <vector>
#include <fstream>

using std::vector;
using std::ifstream;
using std::cout; using std::endl;

// input for the algorithm
int n;
int m;

vector<int> available;
vector<vector<int>> max;
vector<vector<int>> allocation;
vector<vector<int>> need;

// Read allocation information from file
void readAllocation() {
   ifstream allocationFile("allocation.txt");
   int t;
   vector<int> temp;
   allocationFile >> t;
   n = t;
   allocationFile >> t;
   m = t;

   for (int i = 0; i < n; ++i) {
      temp.clear();
      for (int j = 0; j < m; ++j) {
         allocationFile >> t;
         temp.push_back(t);
      }
      allocation.push_back(temp);
   }
}

// Read available information from file
void readAvailable() {
   ifstream availableFile("available.txt");
   int t;
   while (availableFile >> t) {
      available.push_back(t);
   }
}

// Read max information from file
void readMax() {
   ifstream maxFile("max.txt");
   int t;
   vector<int> temp;
   for (int i = 0; i < n; ++i) {
      temp.clear();
      for (int j = 0; j < m; ++j) {
         maxFile >> t;
         temp.push_back(t);
      }
      max.push_back(temp);
   }
}

// Use the max and allocation vectors to make the need vector
void makeNeed() {
   vector<int> temp;
   for (int i = 0; i < n; ++i) {
      temp.clear();
      for (int j = 0; j < m; ++j) {
         temp.push_back(max[i][j] - allocation[i][j]);
      }
      need.push_back(temp);
   }
}

int main() {
   // Read and prepare all inputs from files
   readAllocation();
   readAvailable();
   readMax();
   makeNeed();

   // vectors and variables for the algorithm
   vector<int> finish(n, 0);
   vector<int> result(n);
   int index = 0;

   // The Banker's Algorithm
   for (int k = 0; k < 5; k++) {
      for (int i = 0; i < n; i++) {
         if (finish[i] == 0) {

            int flag = 0;
            for (int j = 0; j < m; j++) {
               if (need[i][j] > available[j]) {
                  flag = 1;
                  break;
               }
            }

            if (flag == 0) {
               result[index++] = i;
               for (int y = 0; y < m; y++)
                  available[y] += allocation[i][y];
               finish[i] = 1;
            }
         }
      }
   }

   // Check whether or not the sequence was safe
   int check = 1;

   for (int i = 0; i < n; i++) {
      if (finish[i] == 0) { // Sequence was not safe
         check = 0;
         cout << "The given sequence is not safe";
         return 0;
      }
   }

   // Prints out the safe sequence
   cout << "The safe sequence is:" << endl;
   for (int i = 0; i < n - 1; i++) {
      cout << "P" << result[i] << " -> ";
   }
   cout << "P" << result[n - 1] << endl;

   return 0;
}

