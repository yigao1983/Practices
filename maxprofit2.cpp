#include <iostream>
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
  
  int *history_profit = new int [N];
  
  for (int i = 0, min_price = price_arr[0], max_profit = 0; i < N; ++i) {
    int pnl = price_arr[i] - min_price;
    max_profit = (pnl > max_profit) ? pnl : max_profit;
    min_price = (price_arr[i] < min_price) ? price_arr[i] : min_price;
    history_profit[i] = max_profit;
  }
  
  int *future_profit = new int [N];
  
  for (int i = N-1, max_price = price_arr[N-1], max_profit = 0; i > -1; --i) {
    int pnl = max_price - price_arr[i];
    max_profit = (pnl > max_profit) ? pnl : max_profit;
    max_price = (price_arr[i] > max_price) ? price_arr[i] : max_price;
    future_profit[i] = max_profit;
  }
  // Debug
  cout << "History profit: ";
  for (int i = 0; i < N; ++i) {
    cout << history_profit[i] << " ";
  }
  cout << endl;
  cout << "Future profit: ";
  for (int i = 0; i < N; ++i) {
    cout << future_profit[i] << " ";
  }
  cout << endl;
  
  int max_profit = 0;
  
  for (int i = 0; i < N; ++i) {
    int pnl = history_profit[i] + future_profit[i];
    max_profit = (pnl > max_profit) ? pnl : max_profit;
  }
  
  cout << "Max profit: " << max_profit << endl;
  
  if (future_profit) {
    delete [] future_profit;
  }
  
  if (history_profit) {
    delete [] history_profit;
  }
  
  if (price_arr) {
    delete [] price_arr;
  }
  
  return 0;
}
