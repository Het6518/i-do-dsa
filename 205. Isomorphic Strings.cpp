class Solution {
public:
    bool isIsomorphic(string s, string t) {
         int n2 = s.size();
        int n = t.size();
        unordered_map<char , char > mp ; 
        unordered_map<char,char> mp2 ;
       // vector<string> v ;
        // string t = "" ;
        // for(int i = 0 ; i < n2 ; i++ ) 
        // {
            
        //     if(s[i] != ' ')t+=s[i] ;
        //     else 
        //     {
        //         v.push_back(t) ;
        //         t="";
        //         continue ;
        //     }
        // }
        // if(t.size()!= 0 )v.push_back(t);
        // int n3 = v.size();
        if(s.size() != t.size()) return false;
        for(int i = 0 ; i < n ; i++ ) 
        {
            if(mp.find(s[i] ) != mp.end() && mp[s[i]] != t[i]) return false ;

               if( mp2.find(t[i] ) != mp2.end() && mp2[t[i]] != s[i]) return false ;

            mp[s[i]] = t[i] ;
            mp2[t[i]] = s[i] ;
        }
       return true;
    }
};
