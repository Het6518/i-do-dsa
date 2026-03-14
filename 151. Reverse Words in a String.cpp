class Solution {
public:
    string reverseWords(string s) {

      //core logic first reverse the string given and then reverse each of the word in the string now only problem left is the extra spaces to get rid of them we use a flag to track whether a space has been encountered
       int n = s.size() ;
       reverse(s.begin() , s.end()) ;
       int st = 0 ; 
       int j = 0 ; 
       for(int i = 0 ; i <= n ; i++) 
       {
          //  if(s[i] != ' ') j++;
            if(i==n||  s[i] == ' ' )
            {
                reverse(s.begin() + st , s.begin() + i ) ;
                st = i + 1  ; 

            }
       }
       string ans = "" ;
    bool space = true;
        for(char c : s)
        {
            if(c != ' ')
            {
                ans.push_back(c);
                space = false;
            }
            else if(!space)
            {
                ans.push_back(' ');
                space = true;
            }
        }

        if(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
