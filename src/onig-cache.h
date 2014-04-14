#ifndef SRC_ONIG_CACHE_H_
#define SRC_ONIG_CACHE_H_

#include "onig-reg-exp.h"
#include "onig-result.h"
#include <memory>
#include <string>
#include <vector>

using ::std::shared_ptr;
using ::std::string;
using ::std::vector;

class OnigCache {
 public:
  explicit OnigCache(int maxSize) :
    maxCachedIndex(-1),
    lastStartLocation(-1),
    useCache(false) {
    results.resize(maxSize);
  }

  ~OnigCache() {}

  void Clear();
  void Init(const string &searchString, int byteOffset);
  shared_ptr<OnigResult> Search(OnigRegExp *regExp, const string &searchString, int byteOffset, bool hasMultibyteCharacters);

 private:
  vector<shared_ptr<OnigResult>> results;
  string lastMatchedString;
  int maxCachedIndex;
  int lastStartLocation;
  bool useCache;
};

#endif  // SRC_ONIG_CACHE_H_
