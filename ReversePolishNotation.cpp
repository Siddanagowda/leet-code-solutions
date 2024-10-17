// class Solution {
// public:
//     int evalRPN(vector<string>& tokens) {
//         stack<int> s1;
//         for(const string& c : tokens) {
//             if (isdigit(c[0])) {
//                 s1.push(stoi(c));
//             } else {
//                 int n1=0;int n2=0;
//                 if(!s1.empty()){
//                     n1 = s1.top();
//                     s1.pop();
//                 }
//                 if(!s1.empty()){
//                     n2 = s1.top();
//                     s1.pop();
//                 }
//                 cout<<n1<<"\t"<<n2;
//                 switch (c[0]) {
//                     case '+': s1.push(n2 + n1); break;
//                     case '-': s1.push(n2 - n1); break;
//                     case '*': s1.push(n2 * n1); break;
//                     case '/': s1.push(n2 / n1); break;
//                 }
//             }
//         }
//         return s1.top();
//     }
// };


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& token : tokens) {
            try {
                int num = stoi(token);
                stack.push(num);
            } catch (const exception& e) {
                if (stack.size() < 2) {
                    throw runtime_error("Invalid RPN expression");
                }
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();
                int result = calculate(operand1, operand2, token[0]);
                stack.push(result);
            }
        }
        if (stack.size() != 1) {
            throw runtime_error("Invalid RPN expression");
        }
        return stack.top();
    }

private:
    int calculate(int operand1, int operand2, char operator_) {
        switch (operator_) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/':
                if (operand2 == 0) {
                    throw runtime_error("Division by zero");
                }
                return operand1 / operand2;
            default:
                throw runtime_error("Invalid operator");
        }
    }
};