class Solution {
public:
    string reverse(int start, int end, string s){
        while(start<end){
            char temp=s[start];
            s[start]=s[end];
            s[end]=temp;
            start++;
            end--;
        }
        return s;
    }
    bool helper(int start, int d, int end, string s, string goal){
        s=reverse(start,d-1,s);
        s=reverse(d,end,s);
        s=reverse(start,end,s);
        //string is rotated now check
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i]) return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0; i<s.size(); i++){
            if(helper(0,i,s.size()-1,s,goal)) return true;
        }
        return false;
    }
};