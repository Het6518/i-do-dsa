// used r - 1 to make sure that:

// l + 1 ≤ r
// r - 1 ≥ l

class Solution {
public:
    int minimumLength(string s) {

        int n = s.size();
        int l = 0;
        int r = n - 1;

        if(n == 1) return 1;

        while(l < r)
        {
            if(s[l] == s[r])
            {
                while(l < r - 1 && s[l] == s[l+1]) l++;
                while(l < r - 1 && s[r] == s[r-1]) r--;

                if(s[l] == s[r])
                {
                    l++;
                    r--;
                }
            }
            else
            {
                return r - l + 1;
            }
        }

        return r - l + 1;
    }
};
