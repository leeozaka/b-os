// "add" e assim B será um texto todo concatenado a ser analisado.
// "find" e assim B será uma nova palavra que determina fake news.

// #include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int K = 26;
struct Vertex {
    int next[K];
    int cont = 0;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};
vector<Vertex> trie(1);

void insert(string const& s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        trie[v].cont++;
        v = trie[v].next[c];
    }
    trie[v].cont++;
}

int search(string const& s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (trie[v].next[c] == -1) return 0;
        v = trie[v].next[c];
    }
    return trie[v].cont;
}

int main() {
    int n;
    cin >> n;
    string s, s2;
    for (int i = 0; i < n; i++) {
        cin >> s >> s2;
        if (s == "add")
            insert(s2);
        else
            cout << search(s2) << endl;
    }
}
