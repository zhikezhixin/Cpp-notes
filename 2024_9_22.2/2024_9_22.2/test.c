#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode 
{
    char data;
    struct StackNode* next;
} SN;

void Push(SN** stack, char x)
{
    SN* newnode = (SN*)malloc(sizeof(SN));
    newnode->data = x;
    newnode->next = *stack;
    *stack = newnode;
}

char Pop(SN** stack)
{
    if (*stack == NULL) return '\0'; 
    SN* temp = *stack;
    char value = temp->data;
    *stack = temp->next;
    free(temp);
    return value;
}

int main() {
    SN* stack = NULL;

    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        Push(&stack, ch);
    }

    for (char ch = 'z'; ch >= 'x'; --ch) {
        Pop(&stack);
    }

    char topElement = stack ? stack->data : '\0';
    printf("ÐÂÕ»¶¥ÔªËØ: %c\n", topElement);

    return 0;
}
