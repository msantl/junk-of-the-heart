#include <iostream>
#include <vector>
#include <cassert>

#include "aho_corasick.hpp"

using namespace std;

int main(int argc, char **argv) {
  AhoCorasick::AhoCorasick ac;

  int n, m;
  vector<string> words;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string word;
    cin >> word;

    words.emplace_back(move(word));
  }

  ac.construct(words);

  cin >> m;
  for (int i = 0; i < m; ++i) {
    string word;
    cin >> word;

    auto res = ac.search(word);
    if (!res.empty()) {
      cout << "Words found: ";
      for (auto r: res) {
        cout << r << endl;
      }
    } else {
      cout << "No matches!" << endl;
    }
  }

  return 0;
}
