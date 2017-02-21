#include <iostream>
#include <set>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool has_duplicate(int n, int nums[])
{
  set<int> distinct;
  
  for (int i = 0; i < n; i++) {
    distinct.insert(nums[i]);
  }
  
  return static_cast<int>(distinct.size()) != n;
}

int main()
{
  const int N = 10;
  int *nums = new int [N];
  
  for (int i = 0; i < N; i++) {
    nums[i] = rand() % 1000;
    cout << nums[i] << endl;
  }
  
  cout << boolalpha << has_duplicate(N, nums) << endl;
  
  delete [] nums;
}
