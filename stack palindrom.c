#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct stack
{
    char alpha[SIZE];
    int top;
} STACK;

void push(STACK *s, char ch)
{
    if (s->top == SIZE - 1)
        printf("STACK OVERFLOW\n");
    else
        s->alpha[++(s->top)] = ch;
}

char pop(STACK *s)
{
    if (s->top == -1)
    {
        printf("pop: Stack underflow\n");
        return '\0'; // Added a return value to avoid undefined behavior
    }
    else
        return (s->alpha[(s->top)--]);
}

void reversestring(STACK *s)
{
    int i = 0;
    char inputstr[SIZE], outputstr[SIZE];
    printf("Enter a string: ");
    scanf("%s", inputstr);
    while (inputstr[i] != '\0')
    {
        push(s, inputstr[i]);
        i++;
    }
    i = 0;
    while (s->top != -1)
    {
        outputstr[i] = pop(s);
        i++;
    }
    outputstr[i] = '\0';
    if (strcmp(inputstr, outputstr) == 0)
        printf("%s is a palindrome string\n", inputstr);
    else
        printf("%s is not a palindrome string\n", inputstr);
}

int main()
{
    STACK st, *s;
    s = &st;
    s->top = -1;
    reversestring(s);
    return 0;
}
