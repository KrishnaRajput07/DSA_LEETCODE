class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return 0;
        int cnt=0;
        int b=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')' && cnt==0) b++;
            else if(s[i]==')') cnt--;
        }
        return abs(cnt)+abs(b);
    }
};