class Solution {
public:
    int myAtoi(string s) {
        string temp;
        bool neg=false;
        int i=0;
        while(i < s.length() && s[i]==' '){
          i++;
        }
        if(i<s.length() && s[i]=='-'){ 
           neg=true;
           i++;
        }
        else if(i<s.length() && s[i]=='+'){
           i++;
        }
        string num;
        for (int j = i; j < s.length(); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                num.push_back(s[j]);
            }
            else {
                break;
            }
        }
        long long val=0;
        for(int i=0; i<num.length(); i++){
           int digit = num[i] - '0';

            if (val > INT_MAX / 10 ||
                (val == INT_MAX / 10 && digit > 7)) {
                return neg ? INT_MIN : INT_MAX;
            }

            val = val * 10 + digit;
        }
        if(neg)val=-1*val;
        if(val>INT_MAX)return INT_MAX;
        if(val<INT_MIN) return INT_MIN;
        return int(val);
    }
};