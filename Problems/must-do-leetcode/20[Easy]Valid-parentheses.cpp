class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        stack<int> parenthese;
        
        int difference = 0;
        for(int i = 0; i < length; i++) {
            if(parenthese.empty()) {
                parenthese.push(s[i]);
                continue;
            }
            
            difference = abs(parenthese.top() - s[i]);
            // center most bracket closed properly
            if(difference <= 2 && difference > 0 ) {
                parenthese.pop();
            }
            // new bracket showed
            else {
                parenthese.push((int) s[i]);
            }
        }
        
        // return types : 
        // 1. return true if string is empty
        // 2. return true if all brackets in stack are closed
        // 3. return false if brackets remain in stack
        return length == 0? true : parenthese.empty();
    }
};