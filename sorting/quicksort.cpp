#include <bits/stdc++.h>
using namespace std;

// Partition Function: Array কে দুই ভাগে ভাগ করে
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Pivot হিসেবে শেষ উপাদান নির্বাচন
    int i = low - 1;       // i: ছোট উপাদানের শেষ ইন্ডেক্স

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Pivot থেকে ছোট হলে swap
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Pivot কে সঠিক স্থানে রাখা
    return i + 1;               // Pivot এর ইন্ডেক্স রিটার্ন
}

// Quick Sort Function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);        // Left অংশ sort
        quickSort(arr, pi + 1, high);       // Right অংশ sort
    }
}

int main() {
    // vector<int> arr = {8, 3, 6, 2, 7, 5};
    // int n = arr.size();
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
       cin>>arr[i];
    }


    quickSort(arr, 0, n - 1); // Quick Sort ডাকলাম

    // Sorted Array দেখাও
    for (int x : arr) cout << x << " ";
    return 0;
}
