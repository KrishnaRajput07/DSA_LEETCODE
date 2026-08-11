class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bits = 0;
        int temp = n;

        while(temp>0) {
           bits++;
           temp >>= 1;
        }
        int mask = (1 << bits) - 1;
        int flipped = n ^ mask;
        return flipped;
    }
};