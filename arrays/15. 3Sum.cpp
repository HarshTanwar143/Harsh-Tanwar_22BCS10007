#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // // By using 3 loops (Bruteforce Approcah) ---> GIVES TLE 
        // set<vector<int>> st;
        // int n = nums.size();

        // for(int i = 0;i < n;i++){
        //     for(int j = i+1;j < n;j++){
        //         for(int k = j+1;k < n;k++){
        //             int sum = nums[i] + nums[j] + nums[k];
        //             if(sum == 0){
        //                 vector<int> temp = {nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int> > ans(st.begin(),st.end());
        // return ans;



        // // By Hashing (Better approach) ---> GIVES TLE
        // set<vector<int>> st;
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     set<int> hashset;
        //     for(int j = i+1;j < n;j++){
        //         int x = -(nums[i] + nums[j]);
        //         if(hashset.count(x)){
        //             vector<int> temp = {nums[i],nums[j],x};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         else{
        //             hashset.insert(nums[j]);
        //         }
        //     }
        // }
        // vector<vector<int> > ans(st.begin(),st.end());
        // return ans;



        // By 2 Pointer Approach (Optimal Approach)
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(i != 0 && nums[i-1] == nums[i])  continue;

            int l = i+1, h = n-1;
            while(l < h){
                int sum = nums[i] + nums[l] + nums[h];
                if(sum < 0) l++;
                else if(sum > 0)    h--;
                else{
                    ans.push_back({nums[i],nums[l],nums[h]});
                    l++,h--;
                    while(h>l && nums[l-1] == nums[l]) ++l;
                    while(h>l && nums[h+1] == nums[h]) --h;
                }
            }
        }

        return ans;
    }
};






















