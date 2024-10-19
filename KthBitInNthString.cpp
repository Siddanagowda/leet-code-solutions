class Solution {
public:
    char findKthBit(int n, int k) {
        vector<string> s(20);  // Initialize vector with size 20
        for(int i = 0; i < 20; i++) {
            if(i == 0) 
                s[i] = "0";
            else {
                string st = invert(s[i-1]);
                reverse(st.begin(), st.end());
                s[i] = s[i-1] + "1" + st;
            }
        }
        return s[n-1][k-1];  // Adjust indices to 0-based for n and k
    }
    
    string invert(string s) {
        for(char &c : s) {  // Use char reference to modify in place
            if(c == '0') 
                c = '1';
            else 
                c = '0';
        }
        return s;
    }
};
