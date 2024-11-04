class Solution {
public:
    string compressedString(string word) {
        string result="";
        int n=word.size();
        int i=0;
        while(i<n){
            char c=word[i];
            int count=0;
            while(i<n && c==word[i] && count<9){
                count++;
                i++;
            }
            result+=to_string(count)+c;
        }
        return result;
    }
};