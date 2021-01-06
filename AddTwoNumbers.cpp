#include <iostream>
#define LOG(x, y) std::cout << x << y; 

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *last_element = l3;
        unsigned int carry = 0;
        unsigned int new_val;
        while (l1 != NULL || l2 != NULL || carry > 0)
        {
            new_val = 0;
            if (l1 != NULL) {
               new_val += l1 -> val;
               l1 = l1 -> next;
            }
            if (l2 != NULL) {
                new_val += l2 -> val;
                l2 = l2 -> next; 
            }
            // Add carry from previous iteration
            new_val += carry;
            // Check if the sumed value is less than 10 
            if (new_val < 10) {
                carry = 0;
            } 
            else {
                carry = 1;
                new_val -= 10;
            }
            
            // Create a new node at the end of the list
            ListNode *new_node = new ListNode(new_val);
            last_element->next = new_node;
            last_element = last_element->next;
        }
        return l3->next;
    }
};



int main()
{
	// Define 342 as list node
	ListNode ln342_3(3);
	//std::cout << ln342_3.val << std::endl;
	ListNode ln342_4(4, &ln342_3);
	ListNode ln342_2(2, &ln342_4);

	// Define 465 as list node
	ListNode ln465_4(4);
	ListNode ln465_6(6, &ln465_4);
	ListNode ln465_5(5, &ln465_6);

	Solution sol;

	auto iterator = sol.addTwoNumbers(&ln342_2, &ln465_5);

	auto power = 0;
	auto sum = 0;

	LOG("\n", "\n");
	LOG("Reversed order = ", "");

	while (iterator)
	{
		auto multiplier = 1;
		for (int i = 0; i < power; ++i)
			multiplier *= 10;

		sum += (iterator->val) * multiplier;

		// Print 
		LOG(iterator->val, "");

		// Update
		iterator = iterator->next;
		power++;
	}

	LOG("\n", "\n");
	LOG("Summation = ", sum);
	LOG("\n", "");
	LOG("\n", "Finished");
	LOG("\n", "\n");

	return 0; 
}