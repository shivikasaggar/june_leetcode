//Given a sorted array and a target value, 
//return the index if the target is found. If not, return the index where it would be if it were inserted in order.
int searchh(vector<int>nums,int l,int r,int x){
  if(l>=r){
          if(nums[l]<x)
        return l+1;
          if(nums[l]>x){
              return l;
          }
    }
    int mid=(l+r)/2;
      
    if(nums[mid]==x){
        return mid;
    }
    else if(nums[mid]>x){
        return searchh(nums,l,mid-1,x);
    }
    else{
        return searchh(nums,mid+1,r,x);
    }
    
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target>nums[n-1]){
            return n;
        }
        if(target<nums[0]){
            return 0;
        }
        return searchh(nums,0,n-1,target);
        
    }
};
