#include<iostream>
#include<vector>
using namespace std;


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
    int getDecimalValue(ListNode* head) {
        if(head == nullptr) return 0;

        vector<int> num;

        while(head!=nullptr){
            num.push_back(head->val);
            head = head -> next;
        }

        int n = num.size(), ans=0;

        for(int i:num){
            ans += pow(2,n-1) * i;
            n--;
        }
        
        return ans;
    }
};