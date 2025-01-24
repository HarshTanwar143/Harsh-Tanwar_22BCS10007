#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // // Brutforce (by loop)  ------> (GIVES TLE AT 18TH TESTCASE)
        // vector<int> prod(nums.size(),0);
        // for(int i = 0;i < nums.size();i++){
        //     int ans = 1;
        //     for(int j = 0;j < nums.size();j++){
        //         if(i != j){
        //             ans *= nums[j];
        //         }
        //     }
        //     prod[i] = ans;
        // }
        // return prod;


        // optimal Approach
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= post;
            post *= nums[i];
        }

        return ans;
    }
};