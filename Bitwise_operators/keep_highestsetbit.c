/*Keep Only the Highest Set Bit
You are given a 16-bit register (uint16_t).
Your task is to:

Return a value where only the highest (leftmost) set bit is retained
All other bits must be cleared

Example-1

Input:  44        // Binary: 0000000000101100  
Output: 32        // Binary: 0000000000100000
Example-2

Input:  512       // Binary: 0000001000000000  
Output: 512       // Binary: 0000001000000000
Example-3

Input:  255       // Binary: 0000000011111111  
Output: 128       // Binary: 0000000010000000*/


#include <stdio.h>
#include <stdint.h>

// Complete the function
uint16_t highest_set_bit(uint16_t reg) {
    // Your logic here
    int pos = -1; //fix a random position value

    for(int i=0;i<16;i++) //iterate through 0 to 15 bit index and check
    {
        if(reg & (1 << i)) //If bit is set and store highest index if bit is set
          pos = i;
    }

    if(pos == -1) //return if none of the bits are set
     return 0;

    else
    return (1 << pos); //return the set bit with shifting to the highest index
}

int main() {
    uint16_t reg;
    scanf("%hu", &reg);

    uint16_t result = highest_set_bit(reg);
    printf("%hu", result);
    return 0;
}