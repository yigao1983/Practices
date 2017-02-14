#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// Program to find if a string forms an additive number strings, such as
// 12358, 1+2=3, 2+3=5, 3+5=8

// Check if the initial segmentation with index i and j
// forms a chain of additive number
bool is_additive(string num_str, size_t i, size_t j)
{
  int num_l = atoi(num_str.substr(0, i).c_str());
  int num_m = atoi(num_str.substr(i, j-i).c_str());
  
  size_t k = j+1;
  
  while (k < num_str.length()+1) {
    int num_r = atoi(num_str.substr(j, k-j).c_str());
    if (num_l + num_m == num_r) {
      cout << "num_l, num_m, num_r =" << num_l << " " << num_m << " " << num_r << endl;        
      i = j;
      j = k;
      num_l = num_m;
      num_m = num_r;
      cout << (k == num_str.length()) << endl;
      if (k == num_str.length()) {
        return true;
      }
    }
    k++;
  }
  
  return false;
}

int main()
{
  int num;
  stringstream ss;
  string num_str;
  
  cin >> num;
  ss << num;
  ss >> num_str;
  
  //cout << num_str << endl;
  //cout << num_str.length() << endl;
  
  bool num_additive = false;
  
  for (size_t j = 2; j < num_str.length(); j++) {
    // The right number should not have leading 0 while with more than 1 digits
    if (num_str.at(j) == '0' && j < num_str.length()-1) {
      continue;
    }
    for (size_t i = 1; i < j; i++) {
      // The middle number should not have leading 0 while with more than 1 digits
      if (num_str.at(i) == '0' && i < j-1) {
        continue;
      }
      num_additive = num_additive or is_additive(num_str, i, j);
    }
  }
  
  cout << "Additive: " << num_additive << endl;
  
  return 0;
}
