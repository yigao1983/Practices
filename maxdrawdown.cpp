#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  const int N = 9;
  double *arr = NULL;
  
  srand (time(NULL));
  
  arr = new double[N];
  
  for (int i = 0; i < N; ++i) {
    arr[i] = static_cast<double>(rand()) / RAND_MAX;
    cout << arr[i] << endl;
  }
  
  int max_idx = 0;
  double max_val = arr[max_idx];
  
  //int min_idx = 0;
  //double min_val = arr[min_idx];
  
  double max_drawdown = 0;
  
  for (int i = 1; i < N; ++i) {
    
    if (max_val-arr[i] > max_drawdown) {
      max_drawdown = max_val-arr[i];
    }
    
    if (arr[i] > max_val) {
      max_idx = i;
      max_val = arr[i];
    }
  }
  
  cout << endl;
  cout << max_idx << " " << max_val << endl;
  cout << max_drawdown << endl;
  
  delete [] arr;
  
  return 0;
}
