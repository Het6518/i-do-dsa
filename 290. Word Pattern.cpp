class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n2 = s.size();
        int n = pattern.size();
        unordered_map<char , string > mp ; 
        unordered_map<string ,char> mp2 ;
        vector<string> v ;
        string t = "" ;
        for(int i = 0 ; i < n2 ; i++ ) 
        {
            
            if(s[i] != ' ')t+=s[i] ;
            else 
            {
                v.push_back(t) ;
                t="";
                continue ;
            }
        }
        if(t.size()!= 0 )v.push_back(t);
        int n3 = v.size();
        if(v.size() != pattern.size()) return false;
        for(int i = 0 ; i < n ; i++ ) 
        {
            if(mp.find(pattern[i] ) != mp.end() && mp[pattern[i]] != v[i]) return false ;

               if( mp2.find(v[i] ) != mp2.end() && mp2[v[i]] != pattern[i]) return false ;

            mp[pattern[i]] = v[i] ;
            mp2[v[i]] = pattern[i] ;
        }
       return true;
    }
};
