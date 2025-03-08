#include <iostream>
using namespace std;

// ট্রাই নোড ক্লাস
class TrieNode {
public:
    TrieNode* children[26];  // এখানে 26টি অক্ষরের জন্য জায়গা
    bool isEndOfWord;         // শব্দের শেষ চিহ্নিত করার জন্য
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;  // কোনো চরিত্রের জন্য নোড তৈরি হবে না, যদি তা না থাকে
        }
        isEndOfWord = false;  // প্রাথমিকভাবে কোনো শব্দ শেষ হয়নি
    }
};

// ট্রাই ক্লাস
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();  // রুট নোড তৈরি করা
    }

    // শব্দ সন্নিবেশ করা
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';  // অক্ষর থেকে ইনডেক্স বের করা
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();  // যদি নোড না থাকে, তাহলে নতুন নোড তৈরি
            }
            node = node->children[index];  // পরবর্তী নোডে চলে যাওয়া
        }
        node->isEndOfWord = true;  // শব্দের শেষ চিহ্নিত করা
    }

    // শব্দ খোঁজা
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;  // যদি কোনো অক্ষরের জন্য নোড না থাকে, তাহলে শব্দটি পাওয়া যাবে না
            }
            node = node->children[index];
        }
        return node->isEndOfWord;  // শেষ নোডটি শব্দের শেষ কিনা তা চেক করা
    }
};

int main() {
    Trie trie;
    
    trie.insert("cat");
    trie.insert("cap");
    trie.insert("bat");
    trie.insert("bar");

    cout << trie.search("cat") << endl;  // 1 (পাওয়া গেছে)
    cout << trie.search("cap") << endl;  // 1 (পাওয়া গেছে)
    cout << trie.search("car") << endl;  // 0 (পাওয়া যায়নি)
    
    return 0;
}
