#  Solution of LeetCode Problem 
#  58. Length of Last Word 
#  Solution in CPP 


#  Appraoch - 1 

class Solution(object):
    def lengthOfLastWord(self, s):
        count =0 
        i = 0
        s = s[::-1] 
        while i < len(s) and s[i] == ' ':
            i += 1
        while(i< len(s) and s[i]!=' ') :
            count += 1 
            i += 1
        return count 
       
        