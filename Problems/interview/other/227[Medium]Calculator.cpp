class Solution {
public:
    int calculate(string s) {
    	// Tokenize numbers based on sign
    	istringstream is('+' + s + '+');
    	
    	char temp;
    	int prev = 0;
    	int next = 0;
    	int n;
    	while(is >> temp) {
    		// addition / subtraction
    		if(temp == '+' || temp == '-') {
    			prev += next;
				is >> next;
				// change number sign
				next *= 44 - temp;		
			}
			
			// multiplication
			else if(temp == '*') {
				is >> n;
				next *= n;
			}
			
			// division
			else {
				is >> n;
				next /= n;
			}
		}
		
		return prev;
    }
};