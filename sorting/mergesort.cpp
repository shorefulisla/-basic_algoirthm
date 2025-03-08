#include <iostream>
using namespace std;

// merge ফাংশন: দুইটি সজ্জিত অংশকে একত্রিত করা
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // প্রথম অংশের আকার
    int n2 = r - m;     // দ্বিতীয় অংশের আকার

    int left[n1], right[n2];

    // বাম অংশে ডেটা কপি করা
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }

    // ডান অংশে ডেটা কপি করা
    for (int j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    
    // দুটি অংশ একত্রিত করা
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // বাম অংশে কোনো উপাদান অবশিষ্ট থাকলে তা কপি করা
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // ডান অংশে কোনো উপাদান অবশিষ্ট থাকলে তা কপি করা
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// mergeSort ফাংশন: অ্যারের মধ্যবর্তী অংশে mergeSort কল করে সজ্জিত করা
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return; // যদি অ্যারের আকার ১ বা তার কম হয়, তাহলে আর কিছু করা যাবে না

    int m = l + (r - l) / 2;  // মধ্যবর্তী ইনডেক্স
    mergeSort(arr, l, m);  // বাম অংশের জন্য mergeSort
    mergeSort(arr, m + 1, r);  // ডান অংশের জন্য mergeSort
    merge(arr, l, m, r);  // দুইটি সজ্জিত অংশ একত্রিত করা
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    // সজ্জিত অ্যারে প্রদর্শন করা
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
