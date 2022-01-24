#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  int Partition(vector<int> & arr, int front, int end) {
    int pivot = arr[end];
    int i = front - 1;
    for (int j = front; j < end; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(&arr[i], &arr[j]);
      }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
  }
  void QuickSort(vector<int> &arr, int front, int end) {
    if (front < end) {
      int pivot = Partition(arr, front, end);
      QuickSort(arr, front, pivot - 1);
      QuickSort(arr, pivot + 1, end);
    }
  }

 public:
  void sortColors(vector<int> &nums) {
    QuickSort(nums, 0, nums.size() - 1);
  }
};

void traverse(vector<int> input) {
  vector<int>::iterator it;
  for (it = input.begin(); it != input.end(); ++it) cout << *it << " ";
}

int main() {
  Solution sol;
  int array[6] = {2, 0, 2, 1, 1, 0};
  vector<int> input(array, array + 6);
  sol.sortColors(input);
  traverse(input);

  return 0;
}