/*Macro-Based Register Config Helper
In embedded systems, registers are often configured by setting specific bits. To make the code cleaner and reusable, firmware developers use macros to set fields in a register.

You are given a 16-bit control register layout:

Field	Bits	Position (LSB-first)
ENABLE	1	Bit 0
MODE	2	Bits 1–2
SPEED	3	Bits 3–5
RESERVED	2	Bits 6–7 (must be 0)
Your task is to:

Write macros to:
Set the ENABLE bit
Set the MODE field
Set the SPEED field
Read ENABLE, MODE, SPEED from input
Use the macros to pack a final 16-bit register value
RESERVED bits (6–7) must be left 0

Example-1

Input: enable = 1, mode = 2, speed = 4
Output: 37
(Binary: 0000 0000 0010 0101)
Example-2

Input: enable = 0, mode = 1, speed = 3
Output: 26
(Binary: 0000 0000 0001 1010)
*/

/*Macro-Based Register Config Helper*/
#include <stdio.h>
#include <stdint.h>

// Field-setting macros
#define SET_ENABLE(x)  ((x & 0x01) << 0)   // Bit 0
#define SET_MODE(x)    ((x & 0x03) << 1)   // Bits 1\u20132
#define SET_SPEED(x)   ((x & 0x07) << 3)   // Bits 3\u20135
// Reserved bits 6\u20137 left 0

// Build register using macros
uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
    uint16_t reg = 0;

    reg |= SET_ENABLE(enable);
    reg |= SET_MODE(mode);
    reg |= SET_SPEED(speed);

    return reg;
}

int main() {
    uint8_t enable, mode, speed;
    scanf("%hhu %hhu %hhu", &enable, &mode, &speed);

    uint16_t reg = build_register(enable, mode, speed);
    printf("%u", reg);
    return 0;
}
/*
Why Use Macros for Register Fields?

Improves readability and reuse
Avoids hardcoding bit positions
Simulates how hardware drivers are built
Macro Logic Summary

Each macro masks value to field width
Shifts it to correct bit position
OR\u2019d into the register
*/