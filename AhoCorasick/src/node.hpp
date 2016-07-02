#pragma once

#include <string>
#include <set>
#include <vector>
#include <unordered_map>

namespace AhoCorasick {
  class Node {
    private:
      char mark;
      std::unordered_map<char, std::shared_ptr<Node>> next;
      std::set<std::string> output;

    public:
      Node();
      explicit Node(const char &);

      std::shared_ptr<Node> insert(const char &);
      std::shared_ptr<Node> getNext(const char &);

      void setOutput(const std::string &);
      std::set<std::string> getOutput();

      char getMark();

  };
}
