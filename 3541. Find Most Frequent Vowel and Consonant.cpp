// Solution in CPP 
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>charecters_of_strings ;
        
        for(auto a : s){
            charecters_of_strings[a]++;
        }

        int vowel_max =0 ,consonant_max =0;
        for (auto a: charecters_of_strings){
             if ((a.first=='a')||(a.first=='e')||(a.first=='i')||(a.first=='o')||(a.first=='u')){
                vowel_max = max(vowel_max,a.second);
             }
        
        else {
                    consonant_max = max(consonant_max,a.second);
        }
        }
          
    return vowel_max + consonant_max ;
    }
};