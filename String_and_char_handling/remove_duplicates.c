/* Remove Duplicate Characters from a String
You are given a null-terminated string containing lowercase and uppercase letters, digits, symbols, or spaces.

Your task is to:

Remove all duplicate characters from the string
Keep only the first occurrence of each character
The order of characters must be preserved.
 

Example-1

Input: "programming"
Output: progamin

Example-2

Input: "aabbcc"
Output: abc

Example-3

Input: "C language"
Output: C langue*/

#include <stdio.h>
#include <stdint.h>

void remove_duplicates(char *str) {
	//Your logic here
    uint8_t hash[256] = {0}; //1-byte flasg for a ASCII char
    uint8_t start=0,write=0;
    while(str[start]!='\0')
    {
        uint8_t ch=(uint8_t)str[start];
        if(!hash[ch])
        {
            hash[ch]=1;
            str[write++]=str[start];
        }
        start++;
    }
    str[write]='\0';//terminate the final string
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

    remove_duplicates(str);
    printf("%s", str);
    return 0;
}