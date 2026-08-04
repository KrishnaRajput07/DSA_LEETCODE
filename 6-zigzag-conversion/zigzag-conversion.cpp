class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>s.size()) return s;
        string ans="";
        int cycle=2*numRows-2;
        for(int i=0; i<numRows; i++){
            int j=i;
            bool toggle=false;
            while(j<s.size()){
                ans+=s[j];
                if(i==0 || i==numRows-1){
                    j+=cycle;
                }
                else{
                    int jump1=cycle-2*i;
                    int jump2=2*i;

                    if(!toggle){
                        j+=jump1;
                    }
                    else{
                        j+=jump2;
                    }

                    toggle=!toggle;
                }
            }
        }
        return ans;
    }
};