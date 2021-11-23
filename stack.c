//
// Created by Freedom Coder on 05.10.2021.
//

#include <stdlib.h>
#include "stack.h"

void init(struct MStack *stack)
{
    stack->top = NULL;
}

void push(struct MStack *stack, int item)
{
    struct MStackElement *top = stack->top;
    struct MStackElement *nptr = malloc(sizeof(struct MStackElement));
    nptr->data = item;
    nptr->next = top;
    stack->top = nptr;
}

int pop(struct MStack *stack)
{
    struct MStackElement *top = stack->top;
    if (top != NULL) {
        struct MStackElement *temp;
        temp = top;
        stack->top = top->next;
        free(temp);
        return top->data;
    }
    return -1;
}

int peek(struct MStack *stack)
{
    if (stack->top != NULL) return stack->top->data;
    return -1;
}

int empty(struct MStack *stack)
{
    return stack->top == NULL;
}