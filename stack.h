//
// Created by Freedom Coder on 05.10.2021.
//

#ifndef LAB4_STACK_H
#define LAB4_STACK_H

struct MStack
{
    struct MStackElement *top;
};

struct MStackElement
{
    int data;
    struct MStackElement *next;
};

void init(struct MStack *stack);
void push(struct MStack *stack, int item);
int pop(struct MStack *stack);
int peek(struct MStack *stack);
int empty(struct MStack *stack);

#endif //LAB4_STACK_H
