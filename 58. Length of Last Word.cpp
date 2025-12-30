// Solution of LeetCode Problem 
// 58. Length of Last Word 
// Solution in CPP 


// Appraoch - 1 

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
      int count= 0 ;
      int i = s.size()-1;
      while(i>=0 && (count==0 || s[i]!=' ') )
      {
        if(s[i] != ' ')
        {
            count++;
        }
        i--;
      } 
      
      return count ;  
    }
};