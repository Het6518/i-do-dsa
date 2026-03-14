// we only need the size here so we use set instead of the map as map will use extra o(n) time 
 
class Solution {
public:
    bool is_balanced(unordered_set<int>& even,unordered_set<int>& odd)
{
    // int eveval = 0;
    // int oddval =0 ;
    // for(auto it :mp )
    // {
    //     if(it.second > 0 ) {
    //     if(it.first %2!=0 ) oddval++;
    //      if(it.first %2 == 0 ) eveval++;
    // }
    // }
    return odd.size() == even.size();
}
    int longestBalanced(vector<int>& nums) {
         int n = nums.size() ;
       
        // int st = 0 ;
         int ans = 0 ;
        // int maxlen = 0 ;
        // int currlen = 0 ;
        for(int i = 0 ; i < n ; i++ ) 
        {
            unordered_set<int> even ;
            unordered_set<int> odd ;
           for(int j = i ; j < n ; j++ )
           {
                if(nums[j] % 2==0 ) even.insert(nums[j] ) ;
                else odd.insert(nums[j]) ;
                if(is_balanced(even , odd ))ans = max(ans, j-i+1);
           }

            
        }
        return ans;
    }
};
