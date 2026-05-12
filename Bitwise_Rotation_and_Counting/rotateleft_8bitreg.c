/*Rotate Left in an 8-bit Register
You are given an 8-bit register and a number of positions n. Rotate the register to the left by n bits. The rotation must be circular, meaning the leftmost bits wrap around to the right.

Use 0-based indexing, and return the result as an 8-bit value.


Example 1

Input: reg = 0b1011 0000, n = 1 
Output: 0b0110 0001

Example 2

Input: reg = 0b1000 0001, n = 2 
Output: 0b0000 0110

Example 3

Input: reg = 0b1111 1111, n = 4 
Output: 0b1111 1111*/

#include <stdio.h>
#include <stdint.h>

uint8_t rotate_left(uint8_t reg, uint8_t n) {
    // Your code here
    n = n%8;

    reg = (reg << n) | (reg >> (8-n));

    return reg;
}

int main() {
    uint8_t reg, n;
    scanf("%hhu %hhu", &reg, &n);
    printf("%u", rotate_left(reg, n));
    return 0;
}