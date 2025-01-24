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
    // Helper function to reverse k nodes
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* prv = NULL;
        ListNode* forw = NULL;

        while (k > 0 && cur != NULL) {
            forw = cur->next;
            cur->next = prv;
            prv = cur;
            cur = forw;
            k--;
        }

        // `prv` is the new head after reversing k nodes
        head->next = cur; // Connect the tail of the reversed list to the next segment
        return prv;       // Return the new head
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) return head;

        // Count the total number of nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Calculate the number of complete groups of size k
        int groups = count / k;

        // Pointers to manage the result
        ListNode* newHead = NULL;
        ListNode* prevTail = NULL;
        ListNode* cur = head;

        while (groups > 0) {
            // Reverse the current group of k nodes
            ListNode* groupHead = reverseList(cur, k);

            if (newHead == NULL) {
                newHead = groupHead; // Set the new head for the first group
            } else {
                prevTail->next = groupHead; // Link the previous group's tail to the current group's head
            }

            // Move the prevTail pointer to the current group's tail
            prevTail = cur;

            // Move the cur pointer to the next group
            cur = cur->next;

            groups--;
        }

        return newHead;
    }
};