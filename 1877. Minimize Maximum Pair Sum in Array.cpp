 // key idea we canot just randomly take two numbers for finding max pair sum 
      //The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs
      // if we take 2 smallest so in the end we need to take two largest not optimal so we take one smallest one largest after sorting 
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end()) ;
     
        int l = 0 ; // 3 5 4 2 4 6
        // 2 3 4 4 5 6
        int r = n -1 ;
        int ans = INT_MIN;
        while(l<r) 
        {
            ans = max(nums[l] + nums[r] , ans ) ;
            l++;
            r--;
        }
        return ans;
    }
};
