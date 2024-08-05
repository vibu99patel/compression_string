/*
Vaibhavi Patel
this program is an encoding algorithm which encode the message that you sent 
to reduce the time and data trnsfer it will take, the encoding is as follow:
consecutive character count followed by the character. do not encode the character
unless they lead to compression 
*/

#include <stdio.h>

// function prototype
void compress(char *input, char *output);

int main () {
    // declaring the string array varibles 
    char input_str[1000], output_str[1000];
    // getting the input from the user and storing in the char array 
    printf("Enter message:");
    scanf("%s", input_str);
    // function call
    compress(input_str, output_str);
    // printing the new compress string  
    printf("Output: %s\n", output_str);

    return 0;
}

// function definition 
void compress(char *input, char *output) {
    // declaring pointer varibles and initializing it to the start of string 
    char *p, *q;
    p = input;   
    q = output;   
    // encoding the message
    while (*p != '\0') {
        char current_ch = *p;  // store comparing character 
        int count_ch = 1;    // keep track of repeated characters
        while (*(p+1) == current_ch) { // to check if character equals
            count_ch++;    
            p++;
        }
        if (count_ch > 1) {    // convert number to character 
            *q++ = count_ch + '0';
        }
        *q++ = current_ch;
        p++;
    }
    *q = '\0';   // terminating the compress string 
}