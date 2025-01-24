#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = 0;
        for(int i = 0;i < nums.size();i++){
            if(i > steps){
                return false;
            }

            steps = max(steps, i + nums[i]);
        }

        return true;
    }
};


/*
2 3 1 1 4
0 1 2 3 4
          i
r = 4
*/