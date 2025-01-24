#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 1 2 55 6 9

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    insertionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
