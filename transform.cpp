/*
ID: jason.z2
PROG: transform
LANG: C++
*/

#include <fstream>
#include <vector>
#include <string>

struct sqPattern {
  public:
  pattern(int sz, string items) : size(sz) {
    pattern.resize(size);
    int index = 0;
    for (int i = 0; i < size; i++)
      for (j = 0; j < size; i++){
        pattern[i].push_back(items[index]);
        index++;
      }
  }
  
  int size;
  std::vector<std::vector<char>> pattern;
  
};
