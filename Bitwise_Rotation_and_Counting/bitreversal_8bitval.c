/*Bit Reversal in an 8-bit Value
You are given an 8-bit unsigned integer. Your task is to:

Reverse the order of its bits
Print the resulting 8-bit value (in decimal)
You must not use any lookup table or standard library function. Use pure bitwise logic.


Example-1

Input: val = 0b00011010
Output: 0b01011000 → Decimal: 88

Example-2

Input: val = 0b10110000
Output: 0b00001101 → Decimal: 13

Example-3

Input: val = 255
Output: 255 (All bits reversed remain the same)*/

#include <stdio.h>
#include <stdint.h>

uint8_t reverse_bits(uint8_t val) {
    // Your logic here
    uint8_t res;

    //do not use while as 0's may end the loop
    for(int i=0;i<8;i++)
    {
        res <<=1; // ledt shift res by 1 bit
        res |= (val & 1); //Extract LSB of val and store in result
        val >>=1; //right shift val by 1
    }
    return res;
}

int main() {
    uint8_t val;
    scanf("%hhu", &val);

    uint8_t result = reverse_bits(val);
    printf("%u", result);
    return 0;
}