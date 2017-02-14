#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
  string str;
  list<char> charlst;
  
  cin >> str;
  
  for (int i = 0; i < str.length(); ++i) {
    charlst.push_back(str.at(i));
  }
  
  int size = 0;
  for (list<char>::iterator iter = charlst.begin(); iter != charlst.end(); iter++) {
    size++;
  }
  
  return 0;
}
