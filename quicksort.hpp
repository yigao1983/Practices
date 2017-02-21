#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

template <class T>
class QuickSort {
  
public:
  
  static void sort(T arr[], int n)
  { sort(arr, 0, n-1); }
  
private:
  
  static void sort(T arr[], int lo, int hi)
  {
    if (lo >= hi) return;
    
    int p = partition(arr, lo, hi);
    sort(arr, lo, p-1);
    sort(arr, p+1, hi);
  }
  
  static int partition(T arr[], int lo, int hi)
  {
    int i = lo, j = hi+1;
    
    while (true) {
      
      while (arr[++i] < arr[lo] && i < hi) {}
      while (arr[--j] > arr[lo] && j > lo) {}
      
      if (j <= i) break;
      
      swap(arr, i, j);
    }
    
    swap(arr, lo, j);
    
    return j;
  }

  static void swap(T arr[], int i, int j)
  {
    T tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
};

#endif
