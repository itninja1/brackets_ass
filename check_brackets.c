#include <string.h>
#include "stack.h"



int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;

	fgets(input_buffer, max_line, stdin);
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    //printf("%d characters were read.\n",input_len);
    //printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line);
    Bracket brack;
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];
        if (next == '(' || next == '[' || next == '{') {
            brack.position = position;
            if(next == '('){
              brack.type = ROUND;
            }
            if(next == '['){
              brack.type = SQUARE;
            }
            if(next == '{'){
              brack.type = CURLY;
            }
            push(opening_brackets_stack, brack);
            // Process opening bracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
          if(isEmpty(opening_brackets_stack)){
            printf("%d", position + 1);
            return position + 1;
          }
          int b;
          if(next == ')'){
            b = 0;
          }
          if(next == ']'){
            b = 1;
          }
          if(next == '}'){
            b = 2;
          }
          Bracket top = pop(opening_brackets_stack);
          if(top.type != b){
            printf("%d", position + 1);
            return position + 1;
          }

            // Process closing bracket, write your code here
        }
    }
    if(!isEmpty(opening_brackets_stack)){
      Bracket top = pop(opening_brackets_stack);
      printf("%d",top.position + 1);
      return top.position + 1;
    }
    printf("Success");
    return "Success";

    // Printing answer, write your code here
    //printf("My result is:\n");
    //return 0;
}
