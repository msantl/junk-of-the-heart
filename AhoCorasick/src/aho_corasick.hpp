#pragma once

#include <string>
#include <set>
#include <vector>
#include <map>

#include "trie.hpp"

namespace AhoCorasick {

  class AhoCorasick: public Trie {
    private:
      std::string alphabet;
      std::map<
        std::pair<std::shared_ptr<Node>, char>,
        std::shared_ptr<Node>
      > goto_transition;

      std::map<
        std::shared_ptr<Node>,
        std::shared_ptr<Node>
      > fail_transition;

      // goto function
      std::shared_ptr<Node> g(std::shared_ptr<Node>, const char &);
      // fail function
      std::shared_ptr<Node> f(std::shared_ptr<Node>);

    public:
      AhoCorasick();
      explicit AhoCorasick(const std::string &);
      void construct(const std::vector<std::string> &);
      std::set<std::string> search(const std::string &);
  };

}
