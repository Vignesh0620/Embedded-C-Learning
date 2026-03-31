/*Replace Bit Field in a 32-bit Register
Given a 32-bit register, replace a few bits (starting at position pos) with a new value.

Only the targeted bits must change — others should stay unchanged.

 
Example 1

Input: reg = 0b1111 1111, val = 0b0000, pos = 4, len = 4  
Output: 0b0000 1111
Example 2

Input: reg = 0b0000 1111, val = 0b10, pos = 1, len = 2  
Output: 0b0000 1101
 

 */

#include <stdio.h>
#include <stdint.h>

uint32_t replace_field(uint32_t reg, uint32_t val, uint8_t pos, uint8_t len) {
    // Your code here
    //1.create a mask to clear the target bits
    uint32_t mask = ((1U << len) -1 )<<pos;

    //2.Clear the target bits using inverted mask
    reg = reg & ~mask;

    //3. Create a new mask for the replace bit field using val
    uint32_t new_mask = ((val & (1U << len) - 1U) << pos);

    //set the bits of the new mask in the reg
    reg |= new_mask;
    return reg;
}

int main() {
    uint32_t reg, val;
    uint8_t pos, len;
    scanf("%u %u %hhu %hhu", &reg, &val, &pos, &len);
    printf("%u", replace_field(reg, val, pos, len));
    return 0;
}