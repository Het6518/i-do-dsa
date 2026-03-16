// the only thing to keep in mind is we need to avoid the duplicates in the winners array

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      //  vector<vector<int>> ans;
        int n = matches.size();
        unordered_map<int , int> mp ;
        vector<int> once ;
        vector<int> never ;
        for(int i = 0 ; i < n ; i++ ) 
        {
            int lost = matches[i][1];
            mp[lost]++;
        }

        for(int i = 0 ; i < n ; i++ ) 
        {
            int lost = matches[i][1];
            if(mp.find(matches[i][0] )  == mp.end())
            {
                never.push_back(matches[i][0]) ;
                int add = matches[i][0];
                mp[add] = 2 ;
            }

            if(mp[lost] == 1 ) once.push_back(lost) ;
        }

        sort(once.begin() , once.end()) ;
        sort(never.begin() , never.end()) ;

        // ans.push_back({never , once});


        return {never , once};
    }
};
