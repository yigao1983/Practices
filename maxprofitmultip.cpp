#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  const int N = 10;
  int *price_arr;
  
  price_arr = new int [N];
  
  srand(time(NULL));
  
  for (int i = 0; i < N; ++i) {
    price_arr[i] = rand() % 100;
    cout << price_arr[i] << " ";
  }
  cout << endl;
  
  int max_profit = 0;
  for (int i = 1; i < N; ++i) {
    int pnl = price_arr[i] - price_arr[i-1];
    max_profit += (pnl > 0) ? pnl : 0;
  }
  
  cout << "Max profit: " << max_profit << endl;
  
  if (price_arr) {
    delete [] price_arr;
  }
  
  return 0;
}
