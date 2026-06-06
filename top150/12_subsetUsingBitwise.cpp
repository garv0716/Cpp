#include<iostream>
 int main(){



}


 int bitwiseSubstring(int number, int startPos, int length) {
    // Generate the mask for the specified length
    int mask = (1 << length) - 1;
    
    // Shift right and apply AND mask
    return (number >> startPos) & mask;
    
}