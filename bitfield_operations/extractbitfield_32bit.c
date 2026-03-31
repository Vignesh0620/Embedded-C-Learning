/*Extract a Bit Field from a 32-bit Register
You are working with a 32-bit hardware status register. Extract a few bits from it, starting from a given bit position and covering a given length. Return the extracted value as an unsigned integer.


Use 0-based indexing (LSB = position 0).


Example 1

Input: reg = 0b1011 0110 0111 0000 0000 0000 0000 0000, pos = 28, len = 4 
Output: 0b1011
Example 2

Input: reg = 0b0000 0000 0000 0000 0000 0000 1111 1111, pos = 0, len = 8  
Output: 0b11111111*/

#include <stdio.h>
#include <stdint.h>

uint32_t extract_field(uint32_t reg, uint8_t pos, uint8_t len) {
    // Your code here
    reg = reg >> pos; // shidt the register right to the possition
    
    uint32_t mask = 0; //32 bit 0
    
    mask |= ((1U << len) -1); // set the mask upto the length and make -1 to make the len-1 indexing to 1's (Ex : mask of 1 << 4 = 0001 0000) - 1 = 0000 1111 

    return reg & mask;
}

int main() {
    uint32_t reg;
    uint8_t pos, len;
    scanf("%u %hhu %hhu", &reg, &pos, &len);
    printf("%u", extract_field(reg, pos, len));
    return 0;
}