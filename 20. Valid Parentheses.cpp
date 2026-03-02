// Solution of LeetCode Problem 
// 20. Valid Parentheses 
// Solution in CPP 

// Approach - 1 (Using Stack)

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st ;
        for(int i = 0 ; i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' ||s[i] == '{' )
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.empty())
                {
                    return false;
                }
                // && wali condtion ye bata rahi hai ki jo top pe value hai wo jo traverse me encounter hua hai closing baracket usske equal nahi hona chaheye tabhi order galat hoga else stack top value and string ith value are opening and closing respectively then pop the stack top value ... 
                
                if(s[i] == ')' && st.top() != '(')
                    return false;

                if(s[i] == ']' && st.top() != '[')
                    return false;

                if(s[i] == '}' && st.top() != '{')
                    return false;
                    
                st.pop();
            }
        }

        if(!st.empty()) return false ;
        return true;
    }
};