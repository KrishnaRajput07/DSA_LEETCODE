class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        int bits = log2(num) + 1;
        unsigned int mask = (1u << bits) - 1;
        int flipped = num ^ mask;

        return flipped;
    }
};