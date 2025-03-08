
vector<int> computeLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0; 
    for (int i = 1; i < n; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


void KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0; 

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == pattern.size()) { 
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
      string text,pattern;
      cin>>text>>pattern;
      KMP(text, pattern);
   }
    return 0;
}


//// ai code ta chat gpt theke nea
