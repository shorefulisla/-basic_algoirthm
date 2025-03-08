#include <bits/stdc++.h>
using namespace std;

#define d 256 // ASCII বেস
#define q 101 // মৌলিক সংখ্যা

void rabinKarp(string txt, string pat) {
    int n = txt.size();
    int m = pat.size();
    int h = 1;
    int p = 0;  // প্যাটার্নের হ্যাশ
    int t = 0;  // টেক্সটের প্রথম m ক্যারেক্টারের হ্যাশ

    // h এর মান বের করা (d^(m-1) % q)
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // প্রথম m ক্যারেক্টারের হ্যাশ বের করা
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // টেক্সটের মধ্যে প্যাটার্ন খোঁজা
    for (int i = 0; i <= n - m; i++) {
        // প্যাটার্ন এবং টেক্সটের হ্যাশ মিললে
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // টেক্সটের পরবর্তী অংশের জন্য হ্যাশ আপডেট করা
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) // হ্যাশ নেগেটিভ হলে পজিটিভ করো
                t += q;
        }
    }
}

int main() {
    string txt = "ABCCDABCABCD";
    string pat = "ABC";
    rabinKarp(txt, pat);
    return 0;
}
