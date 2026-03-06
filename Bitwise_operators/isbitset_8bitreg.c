/*Given an 8-bit register, check whether the bit at a specific position is set (i.e., equals 1).

Return 1 if the bit is set, otherwise return 0.


Example 1

Input: reg = 0b00000100, pos = 2 
Output: 1Copy
Example 2

Input: reg = 0b00000100, pos = 1 
Output: 0*/

#include <stdio.h>
#include <stdint.h>

uint8_t is_bit_set(uint8_t reg, uint8_t pos) {

    if(reg & (1<<pos))
    return 1;
    else
    return 0;
    // Your code here
}