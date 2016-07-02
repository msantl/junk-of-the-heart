#include "trie.hpp"

using namespace std;

namespace AhoCorasick {

  Trie::Trie() {
    this->root = make_shared<Node>('~');
  }

  void Trie::insert(const string &s) {
    shared_ptr<Node> current = this->root;
    for (auto c: s) {
      current = current->insert(c);
    }
    current->setOutput(s);
    return;
  }

  set<string> Trie::find(const string &s) {
    shared_ptr<Node> current = this->root;
    for (auto c: s) {
      auto next = current->getNext(c);
      if (next == nullptr) {
        return {};
      }
      current = next;
    }

    return current->getOutput();
  }

}
