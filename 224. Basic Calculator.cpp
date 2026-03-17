class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st ;

        int val = 0 ;
        long long  num = 0 ; // it can be of the form "10"
        int sign = 1; 
        
        for(int i = 0 ; i < n ;i++)
        {
            if(isdigit(s[i]) ) 
            {
                num  = num*10 + (s[i] - '0');
            }
            else if(s[i] == '+')
            {
                val += num* sign ;//1
                num = 0 ;
                sign = 1 ;
            }
            else if(s[i] == '-')
            {
                val += num * sign ;
                num = 0 ;
                sign = -1 ;
            }
            else if(s[i] == '(')
            {
                st.push(val) ; // 0 // st 0 1 1 
                st.push(sign) ; // + +  
                num = 0;
                val = 0 ;
                sign = 1 ;
            }
            else if(s[i] == ')')
            {
                val += num*sign ;
                num = 0 ;
                int old_sign = st.top();
                st.pop();
                int oldres = st.top();
                st.pop();
                val = val * old_sign ;
                // int oldres = st.top();
                // st.pop();
                val += oldres ;
            }
        }
        val += num*sign ;

        return val;
    }
};
