/*Implement Custom strcmp function
You are given two null-terminated strings.

Your task is to:

Compare them character by character using ASCII values
Return:
 
0 if all characters are the same and both strings end at the same time
If mismatched: ASCII difference of the first mismatched characters. I.e. positive value if the first non-matching character in string a is greater than that in string b or negative value (vice-versa)
Do not use built-in functions like strcmp().

 

Example-1

Input: "apple" and "apple"
Output: 0

Example-2

Input: "cat" and "bat"
Output: 1 
(because 'c' - 'b' = 1)

Example-3

Input: "abc" and "abcd"
Output: -100 
(because 'a'-'a'=0, 'b'-'b'=0, 'c'-'c'=0, then '\0' - 'd' = -100)*/

#include <stdio.h>

int custom_strcmp(const char *a, const char *b) {
    // Your logic here
    int len=0;
    while(a[len]!='\0' && b[len]!='\0')
    {
        if(a[len] != b[len])
        {
            if(a[len] > b[len])
            {
                return a[len]-b[len];
            }
        }
        len++;
    }
    return a[len]-b[len]; //If one is longer than other
}

int main() {
    char a[101], b[101];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    // Remove newline
    int i = 0;
    while (a[i]) {
        if (a[i] == '') 
        { 
            a[i] = '\0'; 
            break; 
        }
        i++;
    }
    i = 0;
    while (b[i]) {
        if (b[i] == '') 
        { 
            b[i] = '\0';
            break; 
        }
        i++;
    }

    printf("%d", custom_strcmp(a, b));
    return 0;
}