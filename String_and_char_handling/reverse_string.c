/*Reverse a String In-Place
You are given a null-terminated string (maximum 100 characters). Your task is to reverse the string in-place without using any additional array or library functions like strrev().

You must swap characters from both ends until the string is reversed. The null-terminator must remain at the end.

Example-1

Input: "firmware"
Output: erawmrif

Example-2

Input: "abc 123"
Output: 321 cba

Example-3

Input: ""
Output: ``*/

#include <stdio.h>

void reverse_string(char *str) {
    int start=0;
    int end=0;

    while(str[end]!='\0') //Move end to the length of the string
    {
        end++;
    }

    end=end-1; //subract 1 to neglect the null character
   
    while(start<end)
    {
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
    // Your logic here
}

int main() {
    char str[101];
    fgets(str, sizeof(str), stdin);

    // Remove newline
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '')
         {
            str[i] = '\0';
            break;
        }
        i++;
    }

    reverse_string(str);
    printf("%s", str);
    return 0;
}