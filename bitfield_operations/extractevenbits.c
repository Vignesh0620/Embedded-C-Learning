/*Extract Even Bits Only from 32-bit Register
From a 32-bit register, extract all even-positioned bits (0, 2, 4, …, 30).

Return the compressed value formed by only these bits (shifted to be consecutive).


Example 1

Input: reg = 0b0101 0101 
Output: 0b1111
Example 2 

Input: reg = 0b1010 1010 
Output: 0b0000*/

#include <stdio.h>
#include <stdint.h>

uint32_t extract_even_bits(uint32_t reg) {
    // Your code here
    uint32_t result =0;

    int val_res =0;

    for(int i=0;i<32;i+=2)
    {
        //Check if the bit is set or not by shifting the bit to the LSB 
        if((reg >> i)&1)
        {
            //if set store the bit in the result if not set the 0 remains in the position
            result = result |(1U <<val_res);

        }
        //increment the result index value 
        val_res ++;
    }
    return result;
}

int main() {
    uint32_t reg;
    scanf("%u", &reg);
    printf("%u", extract_even_bits(reg));
    return 0;
}