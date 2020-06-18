//Given an array of citations sorted in ascending order 
//(each citation is a non-negative integer) of a researcher,
// write a function to compute the researcher's h-index.

//According to the definition of h-index on Wikipedia: "A scientist 
//has index h if h of his/her N papers have at least h citations each, and the other N - h papers have no more than h citations each."


class Solution {
public:
    
	int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int res=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if((n-mid)<=citations[mid]){
                res=max(n-mid,res);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
        
    }
};
