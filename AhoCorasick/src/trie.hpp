#pragma once

#include "node.hpp"

#include <string>
#include <set>

namespace AhoCorasick {

  class Trie {
    protected:
      std::shared_ptr<Node> root;

    public:
      Trie();
      void insert(const std::string &);
      std::set<std::string> find(const std::string &);
  };

}
