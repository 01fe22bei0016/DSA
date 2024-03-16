#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack
{
    char data[SIZE];
    int top;
};

void stackinit(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, char element)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->data[s->top] = element;
    printf("Element '%c' pushed to the stack\n", element);
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    char element = s->data[s->top];
    s->top--;
    return element;
}

char stacktop(struct stack s)
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }

    return s.data[s.top];
}

void display(struct stack s)
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = s.top; i >= 0; i--)
    {
        printf("%c\n", s.data[i]);
    }
}

int main()
{
    char x, ch, ele;

    struct stack s;
    stackinit(&s);

    printf("1. Push character to stack\n");
    printf("2. Pop character from stack\n");
    printf("3. Get stack top\n");
    printf("4. Display stack elements\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case '1':
                printf("Enter character: ");
                scanf(" %c", &ele);
                push(&s, ele);
                break;

            case '2':
                x = pop(&s);
                if (x != '\0')
                    printf("Popped character is '%c'\n", x);
                break;

            case '3':
                x = stacktop(s);
                if (x != '\0')
                    printf("Stack top character is '%c'\n", x);
                break;

            case '4':
                display(s);
                break;

            case '5':
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
