#include "headers.h"

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode();
    ListNode* tail = dummyHead;
    bool carry = false;
    while(l1 != nullptr || l2 != nullptr || carry) {
      int sum = 0;
      if(carry) {
        sum+=1;
      }
      if(l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }

      if(l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }

      carry = sum > 9;
      sum = sum % 10;

      tail->next = new ListNode(sum);
      tail = tail->next;
    }

    return dummyHead->next;
  }
};

TEST(addTwoNumbers, example1) {
  Solution s;
  List inputL1{2, 4, 3};
  List inputL2{5, 6, 4};
  List expected{7, 0, 8};
  EXPECT_TRUE(is_same_list(expected.head, s.addTwoNumbers(inputL1.head, inputL2.head)));
}

TEST(addTwoNumbers, example2) {
  Solution s;
  List inputL1{0};
  List inputL2{0};
  List expected{0};
  EXPECT_TRUE(is_same_list(expected.head, s.addTwoNumbers(inputL1.head, inputL2.head)));
}

TEST(addTwoNumbers, example3) {
  Solution s;
  List inputL1{9, 9, 9, 9, 9, 9, 9};
  List inputL2{9, 9, 9, 9};
  List expected{8, 9, 9, 9, 0, 0, 0, 1};
  EXPECT_TRUE(is_same_list(expected.head, s.addTwoNumbers(inputL1.head, inputL2.head)));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
