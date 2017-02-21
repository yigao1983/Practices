#include <iostream>
#include <cstdlib>
#include "quicksort.hpp"

using namespace std;

int main()
{
  const int N = 1;
  int *arr = new int [N];
  
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 2;
  }
  
  QuickSort<int>::sort(arr, N);
  
  for (int i = 0; i < N; i++) {
    cout << arr[i] << endl;
  }
  
  delete [] arr;
  
  return 0;
}
