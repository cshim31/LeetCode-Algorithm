class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string s = tokens.back();
        tokens.pop_back();
        
        int first = 0;
        int last = 0;
        if(s == "*" || s == "/" || s == "-" || s == "+") {
            first = evalRPN(tokens);
            last = evalRPN(tokens);
        }
        
        if(s == "+") return first + last;
        if(s == "-") return last - first;
        if(s == "*") return first * last;
        if(s == "/") return last / first;
        return stoi(s);
    }
};