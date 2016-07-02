#include "aho_corasick.hpp"

#include <queue>

using namespace std;

namespace AhoCorasick {

  AhoCorasick::AhoCorasick() {
    Trie::Trie();
    this->alphabet = "abcdefghijklmnoprstquvwxyz";
  }

  AhoCorasick::AhoCorasick(const string &a) {
    Trie::Trie();
    this->alphabet = a;
  }

  shared_ptr<Node> AhoCorasick::g(shared_ptr<Node> node, const char &c) {
    shared_ptr<Node> next = node->getNext(c);
    if (next != nullptr) {
      return next;
    } else if (this->goto_transition.count(make_pair(node, c)) > 0) {
      return this->goto_transition[make_pair(node, c)];
    } else {
      return nullptr;
    }
  }

  shared_ptr<Node> AhoCorasick::f(shared_ptr<Node> node) {
    if (this->fail_transition.count(node) > 0) {
      return this->fail_transition[node];
    } else {
      return nullptr;
    }
  }

  void AhoCorasick::construct(const vector<string> &words) {
    queue<shared_ptr<Node>> q;

    // phase 1
    for (auto w: words) {
      Trie::insert(w);
    }

    for (auto c: this->alphabet) {
      shared_ptr<Node> next = this->root->getNext(c);
      if (next == nullptr) {
        this->goto_transition[make_pair(this->root, c)] = this->root;
      } else {
        this->fail_transition[next] = this->root;
        q.push(next);
      }
    }

    // phase 2
    while (!q.empty()) {
      shared_ptr<Node> curr = q.front();
      q.pop();

      for (auto c: this->alphabet) {
        shared_ptr<Node> next = this->g(curr, c);
        if (next != nullptr) {
          q.push(next);

          shared_ptr<Node> v = this->f(curr);
          while (this->g(v, c) == nullptr) {
            v = this->f(v);
          }
          this->fail_transition[next] = this->g(v, c);

          for (auto w: this->f(next)->getOutput()) {
            next->setOutput(w);
          }
        }
      }
    }

    return;
  }

  set<string> AhoCorasick::search(const string &s) {
    set<string> ret;
    shared_ptr<Node> curr = this->root;

    for (auto c: s) {
      while (this->g(curr, c) == nullptr) {
        curr = this->f(curr);
      }

      curr = this->g(curr, c);

      for (auto o: curr->getOutput()) {
        ret.insert(o);
      }
    }
    return ret;
  }
}
