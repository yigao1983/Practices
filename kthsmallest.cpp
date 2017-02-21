#include <iostream>
#include <cstdlib>

using namespace std;

void exchange(int arr[], int i, int j)
{
  int buffer;
  
  buffer = arr[j];
  arr[j] = arr[i];
  arr[i] = buffer;
}

int partition(int lo, int hi, int arr[])
{
  int i = lo, j = hi+1;
  
  while (true) {
    while (arr[++i] < arr[lo]) {
      if (i == hi) break;
    }
    while (arr[--j] > arr[lo]) {
      if (j == lo) break;
    }
    
    if (i >= j) break;
    
    exchange(arr, i, j);
  }
  
  exchange(arr, lo, j);
  
  return j;
}

int get_kthsmallest(int k, int n, int arr[])
{
  int lo = 0, hi = n-1;
  
  while (hi >= lo) {
    int p = partition(lo, hi, arr);
    if (p < k) lo = p+1;
    else if (p > k) hi = p-1;
    else break;
  }
  
  return arr[k];
}

int main()
{
  const int N = 10;
  int *arr = new int [N];
  
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 1000;
  }
  
  cout << get_kthsmallest(5, N, arr) << endl;
  
  delete [] arr;
}
