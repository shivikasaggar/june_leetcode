//Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//Note:Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(int i=0;i<nums.size();i++){
        //     if(mp[nums[i]]==1){
        //         return nums[i];
        //     }
        // }
        // return 0;
        int once = 0, twice = 0;
        for(int num: nums) {
            once = ~twice & (once ^ num);
            twice = ~once & (twice ^ num);
        }
        return once;  
    }
};
