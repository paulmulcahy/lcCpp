#include "headers.h"

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> pairs;
  
    for(int i = 0; i < (signed) nums.size(); i++) {
      int complement = target - nums[i];
      if(pairs.count(complement)) {
        vector<int> vect{pairs.at(complement), i};
        return vect;
      }
      pairs.insert(std::make_pair(nums[i], i));
    }
    return vector<int>();
  }
};

TEST(q0001, example1)
{
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;

    vector<int> expected;
    expected.push_back(0);
    expected.push_back(1);

    EXPECT_EQ(expected, s.twoSum(nums, target));
}

TEST(q0001, example2)
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);

    int target = 6;

    vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);

    EXPECT_EQ(expected, s.twoSum(nums, target));
}

TEST(q0001, example3)
{
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);

    int target = 6;

    vector<int> expected;
    expected.push_back(0);
    expected.push_back(1);

    EXPECT_EQ(expected, s.twoSum(nums, target));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
