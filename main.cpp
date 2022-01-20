#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &nums) {
    // FIXME
  }
};

void TestNextPermutation() {
  Solution s;
  {
    vector<int> nums{1,2,3};
    vector<int> expected{1,3,2};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
  {
    vector<int> nums{1,1,5};
    vector<int> expected{1,5,1};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
  {
    vector<int> nums{3,2,1};
    vector<int> expected{1,2,3};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
  {
    vector<int> nums{1,2,3,4};
    vector<int> expected{1,2,4,3};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
  {
    vector<int> nums{1,2,4,3};
    vector<int> expected{1,3,2,4};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
  {
    vector<int> nums{1,3,4,2};
    vector<int> expected{1,4,2,3};
    s.nextPermutation(nums);
    assert(expected == nums);
  }
}

int main() {
  TestNextPermutation();
  std::cout << "Ok!" << std::endl;
  return 0;
}
