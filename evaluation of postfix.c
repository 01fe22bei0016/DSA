#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 50
struct stack
{
    int data[SIZE];
    int top;
};
void push(struct stack *sptr,int op1)
{
    if(sptr->top==SIZE-1)
        printf("stack overflow.\n");
    else
        sptr->data[++sptr->top]=op1;
}
int pop(struct stack *sptr)
{
    if(sptr->top==-1)
    {
        printf("pop: stack overflow\n");
        return -1;
    }
    else
        return(sptr->data[(sptr->top)--]);
}
void evaluate(char postfix[SIZE])
{
    struct stack st,*sptr;
    sptr=&st;
    sptr->top=-1;
    char ch;
    int i=0,op1,op2;
    while((ch=postfix[i++])!='\0')
    {
        if(isdigit(ch))
            push(sptr,ch-'0');
        else
        {
            op2=pop(sptr);
            op1=pop(sptr);
            switch(ch)
            {
                    case '+':push(sptr,op1+op2);
                             break;
                    case '-':push(sptr,op1-op2);
                             break;
                    case '*':push(sptr,op1*op2);
                             break;
                    case '/':push(sptr,(op1/op2));
                             break;
                     case '%':push(sptr,op1%op2);
                             break;
                    case '^':push(sptr,(pow(op1,op2)));
                             break;
            }
        }
    }
    printf("Given postfix Expression: %s\n",postfix);
    printf("Result after Evaluation: %d\n",pop(sptr));
}
int main()
{
    char postfix[SIZE];
    scanf("%s",postfix);
    evaluate(postfix);
    return 0;
}
