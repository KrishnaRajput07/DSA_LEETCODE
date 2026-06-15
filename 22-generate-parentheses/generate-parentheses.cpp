class Solution {
public:
    void helper(int n,int c,vector<string> &ans,string level){
        if(n==0){
          if(c!=0){
           while(c!=0){
           level.push_back(')');
           c--;
            }
          }
          ans.push_back(level);
          return;
        }
        if(level.empty()){
            level.push_back('(');
            helper(n-1,c,ans,level);
        }
        else{
           level.push_back('(');
           helper(n-1,c,ans,level);
           level.pop_back();
           if(c>n){
            level.push_back(')');
           helper(n,c-1,ans,level);
           }
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string level="";
        helper(n,n,ans,level);
        return ans;
    }
};