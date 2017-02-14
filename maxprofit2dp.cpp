#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int main()
{
  const int N = 10;
  int *price_arr = new int [N];
  
  srand(1234567);
  
  for (int i = 0; i < N; ++i) {
    price_arr[i] = rand() % 100;
    cout << price_arr[i] << " ";
  }
  cout << endl;
  
  int max_pnl_buy1  = -price_arr[0];
  int max_pnl_sell1 = 0;
  int max_pnl_buy2  = 0;
  int max_pnl_sell2 = 0;
  
  for (int i = 1; i < N; ++i) {
    max_pnl_buy1  = max(-price_arr[i], max_pnl_buy1);
    max_pnl_sell1 = max(price_arr[i] + max_pnl_buy1, max_pnl_sell1);
    max_pnl_buy2  = max(-price_arr[i] + max_pnl_sell1, max_pnl_buy2);
    max_pnl_sell2 = max(price_arr[i] + max_pnl_buy2, max_pnl_sell2);
  }
  
  cout << "Max profit: " << max_pnl_sell2 << endl;
  
  if (price_arr) {
    delete [] price_arr;
  }
  
  return 0;
}
