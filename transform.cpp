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
  
  inline bool operator==(const sqPattern& left, const sqPattern& right){
    if (left.size == right.size){
      for (int i = 0; i < left.size; i++)
        for (int j = 0; j < left.size; j++)
          if (left[i][j] != right[i][j]) return false;
      return true;
    }
    else return false;
  }
  
  int size;
  std::vector<std::vector<char>> pattern;
  
};
