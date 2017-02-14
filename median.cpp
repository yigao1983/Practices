#include <iostream>
#include <vector>

using namespace std;

double subarray_median(vector<int> arr, int k)
{
  int indx_end;
  
  for (indx_end = arr.size()-1; indx_end > -1 && k < arr.at(indx_end); --indx_end)
    {}
  
  cout << indx_end << endl;
  
  if (indx_end % 2 == 0){
    return arr.at(indx_end/2);
  } else {
    return 0.5*(arr.at(indx_end/2)+arr.at(indx_end/2+1));
  }
}

int main()
{
  vector<int> arr(10);
  
  for (int i = 0; i < arr.size(); i++) {
    arr.at(i) = i;
    // cout << arr.at(i) << endl;
  }
  
  cout << subarray_median(arr, 5) << endl;
  
  return 0;
}
