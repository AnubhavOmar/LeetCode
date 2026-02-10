// Solution in C language of Leetcode problem 
// 717. 1-bit and 2-bit Characters 
// Solution in CPP 
bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0 ;  
        while(i<bitsSize-1)
        {
            if(bits[i]==1) i += 2 ;
            else i++;
        }

        if( i == bitsSize -1 ) return true ;
        return false ;
    
}