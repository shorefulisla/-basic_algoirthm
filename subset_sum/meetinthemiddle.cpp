// bismillahir rahmanir rahim
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate all subset sums
void generateSubsetSums(vector<int>& arr, vector<int>& subsetSums) {
    int n = arr.size();
    int totalSubsets = (1 << n); // 2^n subsets

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) { // Check if the i-th bit is ON
                sum += arr[i];
            }
        }
        subsetSums.push_back(sum);
    }
}

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();

    // Divide the array into two halves
    vector<int> A1(arr.begin(), arr.begin() + n / 2);
    vector<int> A2(arr.begin() + n / 2, arr.end());

    // Generate subset sums for both halves
    vector<int> subsetSums1, subsetSums2;
    generateSubsetSums(A1, subsetSums1);
    generateSubsetSums(A2, subsetSums2);

    // Sort the second half's subset sums
    sort(subsetSums2.begin(), subsetSums2.end());

    // Check for each subset sum in the first half
    for (int x : subsetSums1) {
        int y = target - x; // Complement sum to find in A2
        // Use binary search to find y in subsetSums2
        if (binary_search(subsetSums2.begin(), subsetSums2.end(), y)) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    if (isSubsetSum(arr, target)) 
        cout << "Yes, it is possible." << endl;
    else 
        cout << "No, it is not possible." << endl;

    return 0;
}
