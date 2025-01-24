#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        // // BruteForce
        // int water = 0;
        // int n = height.size();

        // for(int i = 0;i < n;i++){
        //     int l = i,r = i;
        //     int leftMax = 0,rightMax = 0;
        //     while(l >= 0){
        //         leftMax = max(leftMax,height[l]);
        //         --l;
        //     }
        //     while(r < n){
        //         rightMax = max(rightMax,height[r]);
        //         ++r;
        //     }
        //     water += min(rightMax,leftMax) - height[i];
        // }
        // return water;


        // // Array PreProcessing
        // int n = height.size();
        // vector<int> left(n,0),right(n,0);
        // int maxi = 0;
        // for(int i = 0;i < n;i++){
        //     maxi = max(height[i],maxi);
        //     left[i] = maxi;
        // }
        // maxi = 0;
        // for(int i = n-1;i >= 0;i--){
        //     maxi = max(height[i],maxi);
        //     right[i] = maxi;
        // }

        // int water = 0;
        // for(int i = 0;i < n;i++){
        //     water += min(left[i],right[i]) - height[i];
        // }
        // return water;


        // // By Stack
        // stack<int>st;
        // int n = height.size();
        // int water = 0;
        // for(int i = 0;i < n;i++){
        //     while(!st.empty() && height[i] > height[st.top()]){
        //         int curr = st.top();
        //         st.pop();
        //         if(!st.empty()){
        //             int distance = i - st.top() - 1; 
        //             int high = min(height[i],height[st.top()]) - height[curr];
                    
        //             water += distance * high;
        //         }
        //     }
        //     st.push(i);
        // }
        // return water;


        // Optimal
        int l = 0, r = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }
                else{
                    water += leftMax - height[l];
                }
                ++l;
            }
            else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }
                else{
                    water += rightMax - height[r];
                }
                --r;
            }
        }
        return water;
    }

};

