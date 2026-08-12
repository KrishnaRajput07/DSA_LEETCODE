class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length(), left=0, right=n-1;
        while(left<=right){
            if(s[left]=='1') left++;
            if(s[right]=='0') right--;

            if(left<=right && s[left]=='0' && s[right]=='1') swap(s[left],s[right]);
        }
        swap(s[right],s[n-1]);
        return s;
    }
};