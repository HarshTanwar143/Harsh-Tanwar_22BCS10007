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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == 0 && list2 == 0)
        return NULL;

        // make a mptr and a temp pointer 
        ListNode* mptr = new ListNode(-1);
        ListNode* temp = mptr;

        // connect the nodes by iteration and comparison
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
            else{
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }

        if(list1 != NULL){
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }
        
        if(list2 != NULL){
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }

        // delete the temp node and point the temp to the real head
        ListNode* temp2 = temp;
        temp = temp->next;
        temp2->next = NULL ;
        delete temp2;

        return temp;
    }
};