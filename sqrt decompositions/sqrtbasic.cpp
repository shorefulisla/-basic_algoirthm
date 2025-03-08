#include <bits/stdc++.h>
using namespace std;

// মূল array এবং ব্লকের ভেরিয়েবল
vector<int> arr, block;
int blockSize;

// Pre-processing: ব্লকের sum বের করা
void preprocess(int n) {
    blockSize = sqrt(n);  // ব্লক সাইজ নির্ধারণ
    block.assign((n + blockSize - 1) / blockSize, 0); // ব্লক সংখ্যা অনুযায়ী vector
    for (int i = 0; i < n; i++) {
        block[i / blockSize] += arr[i];
    }
}

// Range sum query
int query(int l, int r) {
    int sum = 0;
    int startBlock = l / blockSize, endBlock = r / blockSize;
    
    if (startBlock == endBlock) {
        // পুরো range একই ব্লকে
        for (int i = l; i <= r; i++) sum += arr[i];
    } else {
        // প্রথম ব্লকের অংশ
        for (int i = l; i < (startBlock + 1) * blockSize; i++) sum += arr[i];
        // মাঝখানের ব্লক
        for (int i = startBlock + 1; i < endBlock; i++) sum += block[i];
        // শেষ ব্লকের অংশ
        for (int i = endBlock * blockSize; i <= r; i++) sum += arr[i];
    }
    return sum;
}

// Update function
void update(int idx, int value) {
    int blockIdx = idx / blockSize; // ব্লক নির্ধারণ
    block[blockIdx] += value - arr[idx]; // ব্লকের মান আপডেট
    arr[idx] = value; // মূল array আপডেট
}

int main() {
    int n, q;
    cin >> n; // Array size
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    preprocess(n); // প্রি-প্রসেসিং
    
    cin >> q; // Query সংখ্যা
    while (q--) {
        int type, l, r;
        cin >> type;
        if (type == 1) { // Query type: Range sum
            cin >> l >> r;
            cout << query(l, r) << endl;
        } else if (type == 2) { // Query type: Update
            int idx, value;
            cin >> idx >> value;
            update(idx, value);
        }
    }
    return 0;
}
