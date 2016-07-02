#include "node.hpp"

using namespace std;

namespace AhoCorasick {

  Node::Node() {}

  Node::Node(const char &c) {
    this->mark = c;
  }

  shared_ptr<Node> Node::insert(const char &c) {
    if (this->next.count(c) > 0) {
      return this->next[c];
    } else {
      shared_ptr<Node> child(new Node(c));

      this->next[c] = child;
      return child;
    }
  }

  shared_ptr<Node> Node::getNext(const char &c) {
    if (this->next.count(c) > 0) {
      return this->next[c];
    } else {
      return nullptr;
    }
  }

  void Node::setOutput(const string &s) {
    this->output.insert(s);
  }

  set<string> Node::getOutput() {
    return this->output;
  }

  char Node::getMark() {
    return this->mark;
  }

}
