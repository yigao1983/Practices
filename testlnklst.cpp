#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
  LinkedList<int> lst;
  
  lst.push(9);
  lst.push(4);
  lst.push(9);
  lst.push(9);
  lst.push(9);
  lst.push(4);
  lst.push(4);
  lst.push(4);
  
  lst.traverse();
  
  return 0;
}
