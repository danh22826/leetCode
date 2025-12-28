class Solution {
public:
    bool isValid(string s) {
       map<char,char> mp = 
       {
        {'(',')'},
        {'[',']'},
        {'{','}'}
       };
       stack<char> st;
       for(char& x : s)
       {
        if(x == '{' || x == '(' || x == '[')
        {
            st.push(x);
            continue;
        }
        if(st.empty() || mp[st.top()] != x)
        {
            return false;
        }
        st.pop();
       }
       return st.empty();
    }
};