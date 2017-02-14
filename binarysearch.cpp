#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
int binary_search(T v, T arr[], int lo, int hi)
{
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (arr[mid] == v) {
      return mid;
    } else if (arr[mid] < v) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  } 
  
  return -1;
}

int main()
{
  const int N = 10;
  int *arr = new int [N];
  
  srand(time(NULL));
  
  arr[0] = rand() % (10*N);
  for (int i = 0; i < N; ++i) {
    arr[i] = arr[i-1] + rand() % (10*N);
    cout << arr[i] << " ";
  }
  cout << endl;
  
  int indx = rand() % N;
  cout << indx << endl;
  cout << binary_search(arr[indx], arr, 0, N-1) << endl;
  
  if (arr) {
    delete [] arr;
  }
  
  return 0;
}
