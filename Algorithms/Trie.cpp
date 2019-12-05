/*
    Implementation of dynamic Prefix Tree (Trie) data structure
    Usage:
        - Initialize dynamicaly like: Trie <string, 26> *root = new Trie <string, 26> ()
        - Insert (word) inserts a iterable word (string, vector etc) into the Trie
        - Count (word) returns the total occurance of word and number of words having prefix word, respectively
        - If using pointer, don't forget to delete the Trie after each usage!
            Trie <string, 26> *root = new Trie <string, 26> ();
            ...
            delete root;
    Input:
        - T, an iterable class name like string, vector etc
        - n, alphabet size
        - value(), an function to convert item to alphabet index, like [a-z] to [0, 26) or [a-zA-Z] to [0, 52)
    Tested Problems:
        - Codeforces: 455B
        - UVA: 760, 12837
*/


template <class T, int n> struct Trie {
    int words, prefixes;
    Trie <T, n> **children;

    Trie (): words(0), prefixes(0), children (NULL) {}

    int value (typename T::const_iterator it) {
        // return *it; // for integers
        return *it - 'a'; // for lowercase strings
        // return *it - 'A'; // for uppercase strings
        // return 'a' <= *it && *it <= 'z' ? *it - 'a' : *it - 'A' + 26; // for both lower and uppercase strings
        // return *it - '0'; // for integer strings
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes += val;
        if (it != end) {
            int i = value(it);
            if (!children) {
                children = new Trie <T, n> *[n] ();
            }
            if (!children[i]) {
                children[i] = new Trie <T, n> ();
            }
            children[i]->Insert(++it, end, val);
        } else {
            words += val;
        }
    }

    void Insert (const T& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = value(it);
            return children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
        }
    }

    pair <int, int> Count (const T& word) {
        return Count(word.begin(), word.end());
    }

    void Print (int tab = 0) {
        cout << "Words: " << words << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        for (int i = 0; i < n; ++i) if (children[i]) {
                cout << setw(tab) << i << " -> ";
                children[i]->Print(tab + 4);
            }
    }

    ~Trie () {
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    delete children[i];
                }
            delete[] children;
        }
    }
};