//basic intution is we need to look up the freq array for every string that is balanced if the string is balanced we update the max len seen
// tc -> o(n*n*26)
// sc -> o(26) -> o(1)

class Solution {
public:
    bool is_balanced(vector<int>& freq)
{
    int val = 0;

    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
        {
            if(val == 0)val = freq[i];
            else if(freq[i] != val)return false;
        }
    }
    return true;
}
    int longestBalanced(string s) {
        int n = s.size() ;
       
        // int st = 0 ;
         int ans = 0 ;
        // int maxlen = 0 ;
        // int currlen = 0 ;
        for(int i = 0 ; i < n ; i++ ) 
        {
            vector<int> freq(26,  0) ;
           for(int j = i ; j < n ; j++ )
           {
                freq[s[j] - 'a']++;
                if(is_balanced(freq))ans = max(ans, j-i+1);
           }

            
        }
        return ans;
    }
};
