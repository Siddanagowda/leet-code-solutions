class Solution {
public:
    long minEnd(int n, int x) {
        //  long long i=x+1;
        // while(n>1){
        //     if((i & x)==x){
        //         last=i;
        //         n--;
        //     }
        //     i++;
        // }
        long result = x;
        long remaining = n - 1;
        long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};
