class Solution {
public:
    int calculate(string s) {
        return postfix(s);
    }
    int postfix(string s) {
        stack<char> s1;
        string exp; 
        bool lastwasoperator=true;

        for (int i=0;i<s.size();i++) {
            char c=s[i];
            if(c==' '){
                continue;
            }
            if (isdigit(c)) {
                while(i<s.size()&&isdigit(s[i])){
                exp += s[i];
                i++;
                }
                exp+=' ';
                i--;
                lastwasoperator=false;
            } 
            else if (c == '(') {
                s1.push(c);
                lastwasoperator=true;
            } 
            else if (c == ')') {
                while (!s1.empty() && s1.top() != '(') {
                    exp += s1.top();
                    exp+=' ';
                    s1.pop();
                }
                s1.pop();
                lastwasoperator=false;
            }
             else {
                if(c=='-' && lastwasoperator){
                    exp+='0';
                    exp+=' ';
                }
                while (!s1.empty() && priority(s1.top()) >= priority(c)) {
                    exp += s1.top();
                    exp+=' ';
                    s1.pop();
                }
                s1.push(c);
                lastwasoperator=true;
            }
        }
        while (!s1.empty()) {
            exp += s1.top();
            exp+=' ';
            s1.pop();
        }
        return evaluate(exp);
    }
    int evaluate(string s) {
        stack<int> s1;
        int i=0;
        while (i<s.size()) {
            if(s[i]==' '){
                i++;
                continue;
            }
            if (isdigit(s[i])) {
                int num=0;
                while(i<s.size() && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                s1.push(num);
            } 
            else {
                int n1 = s1.top();
                s1.pop();
                int n2 = s1.top();
                s1.pop();
                switch (s[i]) {
                    case '+': s1.push(n2 + n1); break;
                    case '-': s1.push(n2 - n1); break;
                    case '*': s1.push(n2 * n1); break;
                    case '/': s1.push(n2 / n1); break;
                }
                i++;
            }
        }
        return s1.top();
    }
    int priority(char opr) {
        if (opr == '(' || opr == ')') return 0;
        if (opr == '+' || opr == '-') return 1;
        if (opr == '*' || opr == '/') return 2;
        return 0;
    }
};
