#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // // BY SORTING
        // sort(nums.begin(),nums.end());
        // for(int i = 0;i<nums.size()-1;i++)
        // {
        //     if(nums[i] == nums[i+1])
        //     {
        //         return nums[i];
        //     }
        // }
        // return -1;


        // // BY MODIFYING THE ARRAY
        // int ans = -1;
        // for(int i = 0;i<nums.size();i++){
        //     int index = abs(nums[i]);
        //     if(nums[index]<0){
        //         ans = index;
        //         return ans;
        //     }
        //     nums[index] *= -1;
        // }
        // return ans;

        // BY POSTIONING METHOD
       while(nums[0] != nums[nums[0]]){
           swap(nums[0],nums[nums[0]]);
       }
       return nums[0];

    }
};