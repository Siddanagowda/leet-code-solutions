class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        int space_i=0;
        for(int i=0;i<s.size();i++){
            if((space_i<spaces.size())&&i==spaces[space_i]){
                res+=' ';
                space_i++;
            }
            res+=s[i];
        }
        return res;
    }
};