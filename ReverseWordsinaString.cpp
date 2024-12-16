class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word="";
        for(char c:s){
            if(c==' '){
                if(!word.empty()){
                    st.push(word);
                    word="";
                }
            }
            else{
               word+=c;
            }
        }
        if(!word.empty()){
            st.push(word);
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty()){
                res+=" ";
            }
        }
        return res;
    }
};