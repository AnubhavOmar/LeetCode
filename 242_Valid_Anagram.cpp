// Solution in CPP
// 242 Valid Anagram 
// Approach -1 
#include<string>
class Solution {
public:
    bool isAnagram(string s, string t) {
         sort(s.begin(),s.end());
         sort(t.begin(),t.end());
        if(s==t) {
            return true ;
        }
        else {
            return false;
        }
    }   
};

//Approach - 2 
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1; 
        map<char,int> m2 ; 
        for(auto a :s ){
            m1[a]++;
        }
        for(auto a :t ){
            m2[a]++ ;
        }
        if(m1==m2){
            return true ;
        }
        else return false ;
    }
};