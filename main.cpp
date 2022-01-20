#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  bool permuteToNextNumber(vector<int> &nums, int offset) {
    auto tail_begin = nums.begin() + offset + 1;
    sort(tail_begin, nums.end());
    auto iter = upper_bound(tail_begin, nums.end(), nums[offset]);
    if (nums.end() != iter) {
      swap(nums[offset], *iter);
      sort(tail_begin, nums.end());
      return true;
    }

    reverse(tail_begin, nums.end());
    return false;
  }

  bool nextPermutation(vector<int> &nums, int offset) {
    const int len = nums.size() - offset;
    if (2 == len) {
      if (nums[nums.size() - 2] < nums.back()) {
        swap(nums[nums.size() - 2], nums.back());
        return true;
      } else { return false; }
    } else if (2 < len) {
      return nextPermutation(nums, offset + 1)
          or permuteToNextNumber(nums, offset);
    }

    return false;
  }

 public:
  void nextPermutation(vector<int> &nums) {
    if (not nextPermutation(nums, 0)) {
      reverse(nums.begin(), nums.end());
    }
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
