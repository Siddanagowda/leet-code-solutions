class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(char c :s){
            if(isalnum(c))
                str+=tolower(c);
        }
        cout<<str;
        int left=0;
        int right=str.length()-1;
        while(left<right){
            if(tolower(str[left]!=tolower(str[right]))) return false;
            left++;
            right--;
        }
        return true;
    }
};