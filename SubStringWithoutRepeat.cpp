class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int len=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            while(set.find(s[r])!=set.end()){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            len=max(len,r-l+1);
        }
        return len;
    }
};