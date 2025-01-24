#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return head;

        ListNode*fast = head->next;
        ListNode*slow = head;
        ListNode*LastNode ;
        int sum = 0;
        while(fast){
            if(fast->val == 0){
                slow->val = sum;
                sum = 0;
                LastNode = slow;
                slow = slow->next;
            }
            sum += fast->val;
            fast = fast->next;
        }

        LastNode->next = NULL;
        while(slow){
            ListNode* temp = slow->next;
            delete slow;
            slow = temp;
        }
        return head;
    }
};