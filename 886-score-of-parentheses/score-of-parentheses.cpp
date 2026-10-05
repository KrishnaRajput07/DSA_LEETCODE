class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt=0;
        char last;
        stack<int> st;
        for(char c:s){
            if(c=='('){
                st.push(cnt);
                cnt=0;
                last='(';
            }
            else{
                if(st.empty()){
                    continue;
                }
                else{
                    if(last=='('){
                        cnt=1;
                    }
                    else{
                        cnt*=2;
                    }
                    last=')';
                    cnt+=st.top();
                    st.pop();
                }
            }
            
        }
        return cnt;
    }
};