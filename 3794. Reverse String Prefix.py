# Solution of LeetCode Problem 
# 3794. Reverse String Prefix
# Solution in Python 

# Approach 1 (using slicing)

class Solution(object):
    def reversePrefix(self, s, k):
        if k == 1 :
            return  s 
        return s[k-1 :  :-1] + s [k::]