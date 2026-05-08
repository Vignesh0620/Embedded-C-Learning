/*Implement a Simple Shell Command Parser
In embedded CLI (command-line interface) systems, you often need to parse commands typed by the user into tokens (like command and its arguments). A lightweight parser is used to extract each word (separated by spaces) into an array of strings.

Your task is to:

Read a single input line (up to 100 characters)
Split it into words separated by one or more spaces
Print each token on a new line
Do not use strtok() or any string library function (except gets() or scanf())

Example-1

Input:
led set 3 on

Output:
led  
set  
3  
on

Example-2

Input:
 uart   config 9600 8N1

Output:
uart  
config  
9600  
8N1

Example-3

Input:
status

Output:
status*/

#include <stdio.h>
#include <ctype.h>

void parse_shell_input(char *line) {
    // Your logic here
    int index=0;
    int in_token=0;
    while(line[index]!='\0' && line[index]!='\n')
    {
        if(isspace(line[index]))
        {
            if(in_token)
            {
                putchar('\n');
                in_token=0;
            }
        }
        else
        {
            putchar(line[index]);
            in_token=1;
        }
    index++;
    }

    if(in_token)
    {
        putchar('\n'); //last token end
    }

}

int main() {
    char line[101];
    fgets(line, sizeof(line), stdin);

    parse_shell_input(line);
    return 0;
}