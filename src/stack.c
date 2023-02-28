#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief Nova stack
 * 
 * @return STACK* 
 */
STACK *new_stack() {
    STACK *s = malloc(sizeof(STACK));
    s -> sp = 0;
    return s;
}

/**
 * @brief função push
 * 
 * @param s stackpointer
 * @param elem STACK_ELEM
 */
void push(STACK *s, STACK_ELEM elem) {
    s -> stack[s -> sp] = elem;
    s -> sp++;
}

/**
 * @brief função pop
 * 
 * @param s syackpointer
 * @return STACK_ELEM 
 */
STACK_ELEM pop(STACK *s) {
    s -> sp--;
    STACK_ELEM ret = s -> stack[s -> sp];
    return ret;
}

/**
 * @brief variáveis com valores pre-defenidos
 * 
 * @param l pointer para um STACK_ELEM
 */
void defaultletters (STACK_ELEM *l){
    l[0].t = INT;
    l[0].data.i = 10;

    l[1].t = INT;
    l[1].data.i = 11;
    
    l[2].t = INT;
    l[2].data.i = 12;

    l[3].t = INT;
    l[3].data.i = 13;
 
    l[4].t = INT;
    l[4].data.i = 14;
 
    l[5].t = INT;
    l[5].data.i = 15;
 
    l[13].t = CHAR;
    l[13].data.c = '\n';
 
    l[18].t = CHAR;
    l[18].data.c = ' ';
 
    l[23].t = INT;
    l[23].data.i = 0;

    l[24].t = INT;
    l[24].data.i = 1;

    l[25].t = INT;
    l[25].data.i = 2;
}

/**
 * @brief atribui a um STACK_ELEM o elemento do topo da stack
 * 
 * @param s stackpointer
 * @param elem pointer para um STACK_ELEM
 */
void top(STACK *s, STACK_ELEM *elem) {
    *elem = s -> stack[s -> sp - 1] ;
}