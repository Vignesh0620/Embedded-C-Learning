/*Convert a String to Float
You are given a null-terminated string representing a floating-point number, which may contain:

An optional sign (+ or -)
A decimal point
Only valid digits and one dot
Your task is to convert this string to its floating-point value (float), without using standard library functions like atof() or strtof().

Do not handle scientific notation (e.g., "1.2e5").


Example-1

Input: "123.45"
Output: 123.45

Example-2

Input: "-0.75"
Output: -0.75

Example-3

Input: "100"
Output: 100.00

Example-4

Input: "+9.99"
Output: 9.99
*/

#include <stdio.h>
#include <stdint.h>

float custom_atof(const char *str) {
    // Your logic here
    float result=0.0f,fraction=0.0f, divisor=10.0f;
    uint8_t index=0;
    int sign=1,in_fraction=0;
    if(str[index]=='-')
    {
        sign=-1;
        index++;
    }
    else if(str[index]=='+')
        index++;

    while(str[index]!='\0')
    {
        if(str[index]=='.')
        {
            in_fraction=1;
            index++;
            continue;
        }
        if(str[index]>='0' && str[index]<='9')
        {
            if(!in_fraction)
            {
                result=result*10.0f+(str[index]-'0');
            }
            else
            {
                fraction+= (str[index]-'0')/divisor;
                divisor*=10.0f;
            }
        }
        else
        {
            break; //stop if a non digit
        }

        index++;
    }
    return (result+fraction)*sign;
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    // Remove newline
    uint8_t i = 0;
    while (str[i]) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    float value = custom_atof(str);
    printf("%.2f", value);
    return 0;
}