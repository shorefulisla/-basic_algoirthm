#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr) {
    int n = arr.size();
    
    // Step 1: সর্বোচ্চ মান খুঁজে বের করুন
    int maxVal = *max_element(arr.begin(), arr.end());
    
    // Step 2: Frequency Array তৈরি করুন
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
    
    // Step 3: Cumulative Sum Array তৈরি করুন
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }
    
    // Step 4: Sorted Array তৈরি করুন
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Step 5: Sorted Array মূল array-তে কপি করুন
    arr = output;
}

int main() {
    //vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }

    countingSort(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}
