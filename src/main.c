#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "stack.h"
#include <assert.h>


/**
 * @brief faz a soma dos dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void sum(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = Y.data.i + X.data.i;
        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = Y.data.f + X.data.f;
        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        P.t = DBL;
        P.data.f = X.data.f + Y.data.i;
        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        P.t = DBL;
        P.data.f = X.data.i + Y.data.f;
        push(s,P);
    }
}

/**
 * @brief 
 * 
 * @param s stackpointer
 */
void sub(STACK* s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = Y.data.i - X.data.i;
        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = Y.data.f - X.data.f;
        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        P.t = DBL;
        P.data.f = X.data.f - Y.data.i;
        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        P.t = DBL;
        P.data.f = X.data.i - Y.data.f;
        push(s,P);
    }
}

/**
 * @brief faz a multicação dos dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void mult(STACK* s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = Y.data.i * X.data.i;
        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = Y.data.f * X.data.f;
        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        P.t = DBL;
        P.data.f = Y.data.i * X.data.f;
        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        P.t = DBL;
        P.data.f = Y.data.f * X.data.i;
        push(s,P);
    }
}

/**
 * @brief faz a divisão dos dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void divi(STACK* s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = Y.data.i / X.data.i;
        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = Y.data.f / X.data.f;
        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        P.t = DBL;
        P.data.f = ((Y.data.i)/1.0) / X.data.f;
        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        P.t = DBL;
        P.data.f = (Y.data.f) / X.data.i;
        push(s,P);
    }
}

/**
 * @brief -1
 * 
 * @param s stackpointer
 */
void decrease(STACK* s) {
    STACK_ELEM X = pop(s);
    if (X.t == INT) {
        X.data.i = X.data.i - 1;
        push(s,X);
    }else if (X.t == DBL) {
        X.data.f = X.data.f - 1;
        push(s,X);
    }else if (X.t == CHAR) {
        X.data.c = (X.data.c) - 1;
        push(s,X);
    }
}

/**
 * @brief +1
 * 
 * @param s stackpointer
 */
void increase(STACK* s) {
    STACK_ELEM X = pop(s);

    if (X.t == INT) {
        X.data.i = X.data.i + 1;
        push(s,X);
    }else if (X.t == DBL) {
        X.data.f = X.data.f + 1;
        push(s,X);
    }else if (X.t == CHAR) {
        X.data.c = (X.data.c) + 1;
        push(s,X);
    }
}

/**
 * @brief operação mod
 * 
 * @param s stackpointer
 */
void modulo(STACK* s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = fmod(Y.data.i,X.data.i);
        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = fmod(X.data.f,X.data.f);
        push(s,P);
    }
}

/**
 * @brief operação pow
 * 
 * @param s stackpointer
 */
void power(STACK* s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = pow(Y.data.i,X.data.i);
        push(s, P);
    } else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        P.data.f = pow(Y.data.f,X.data.f);
        push(s, P);
    }else if (X.t == DBL && Y.t == INT) {
        P.t = DBL;
        P.data.f = pow(Y.data.i,X.data.f);
        push(s, P);
    }else if (X.t == INT && Y.t == DBL) {
        P.t = DBL;
        P.data.f = pow(Y.data.f,X.data.i);
        push(s, P);
    }
}

/**
 * @brief Operador bitwise &
 * 
 * @param s stackpointer
 */
void bitwisee(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = (Y.data.i & X.data.i);
        push(s, P);
    }
}

/**
 * @brief Operador bitwise |
 * 
 * @param s stackpointer
 */
void bitwiseor(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = (Y.data.i | X.data.i);
        push(s, P);
    }
}

/**
 * @brief Operador bitwise ^
 * 
 * @param s stackpointer
 */
void bitwisexor(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        P.data.i = (Y.data.i ^ X.data.i);
        push(s, P);
    }
}


/**
 * @brief Operador bitwise ~
 * 
 * @param s stackpointer
 */
void bitwisenot(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM P;
    if (X.t == INT) {
        P.t = INT;
        P.data.i = ~(X.data.i);
        push(s, P);
    }    
}

/**
 * @brief duplica o STACK_ELEM que está no topo da stack
 * 
 * @param s stackpointer
 */
void duplica(STACK *s){
    STACK_ELEM X = pop(s);
    push(s, X);
    push(s, X);
}    

/**
 * @brief troca os dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void trade(STACK *s){    
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    push(s, X);
    push(s, Y);   
}

/**
 * @brief roda os 3 elementos no topo da stack
 * 
 * @param s stackpointer
 */
void rodar(STACK *s){
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM Z = pop(s);
    push(s, Y);
    push(s, X);
    push(s, Z);
}    

/**
 * @brief copia o enesimo elemento stack para o topo da stack
 * 
 * @param s stackpointer
 */
void copyN(STACK *s){
    STACK_ELEM X = pop(s);
    push (s, s -> stack[s -> sp - X.data.i - 1]);
}      

/**
 * @brief print o STACK_ELEM que está no topo da stack
 * 
 * @param s stackpointer
 */
void printTop (STACK *s){
    STACK_ELEM X = pop(s);
    while (s->sp) pop(s);
    if (X.t == INT){
        printf("%li", X.data.i);
    } else if (X.t == CHAR){
        printf("%c", X.data.c);
    } else if (X.t == DBL){
        printf("%g", X.data.f);
    }else if (X.t == STR){
        printf("%s", X.data.s); 
    }
}

/**
 * @brief converte o STACK_ELEM que está no topo da stack para double
 * 
 * @param s stackpointer
 */
void convertedoubl(STACK *s){
    STACK_ELEM X = pop(s);
    STACK_ELEM Y;
    if (X.t == INT){
        Y.t = DBL;
        Y.data.f = X.data.i / 1.0;
        push(s, Y);
    }

    else if (X.t == DBL){
        push(s, X);
    }

    else if (X.t == CHAR){
        Y.t = DBL;
        Y.data.f = (double)(X.data.c);
        push (s, Y);
    } 
    else if (X.t == STR) {
        Y.t = DBL;
        Y.data.f = atof(X.data.s);
        push(s, Y);
    }
}

/**
 * @brief converte o STACK_ELEM que está no topo da stack para int
 * 
 * @param s stackpointer
 */
void converteint(STACK *s){
    STACK_ELEM X = pop(s);
    STACK_ELEM Y;
    if (X.t == INT) {
        push(s, X);
    }

    else if (X.t == DBL) {
        Y.t = INT;
        Y.data.i = X.data.f / 1;
        push(s, Y);
    }

    else if (X.t == CHAR) {
        Y.t = INT;
        Y.data.i = (int)(X.data.c);
        push(s, Y);
    }
    else if (X.t == STR) {
        Y.t = INT;
        Y.data.i = atoi(X.data.s);
        push(s, Y);
    }
}

/**
 * @brief converte o STACK_ELEM que está no topo da stack para char
 * 
 * @param s stackpointer
 */
void convertechar(STACK *s){
    STACK_ELEM X = pop(s);
    STACK_ELEM Y;
    if (X.t == INT){
        Y.t = CHAR;
        Y.data.c = (X.data.i);
        push (s, Y);
    }
    else if (X.t == CHAR){
        push(s, X);
    }
    else if (X.t == DBL){
        Y.t = CHAR;
        Y.data.c = (char)(X.data.f);
        push(s, Y);
    }
    else if (X.t == STR) {
        Y.t = CHAR;
        Y.data.c = atol(X.data.s);
        push(s, Y);
    }
}

/**
 * @brief lê linha
 * 
 * @param s stackpointer
 */
void readLine(STACK *s) {
    STACK_ELEM aux;
    char *str = malloc(sizeof(char) * 10000);
    assert(fgets(str, 10000, stdin) != NULL);
    aux.t = STR;
    aux.data.s = str;
    push(s, aux);
} 

/**
 * @brief operação >
 * 
 * @param s stackpointer
 */
void maior(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    P.t = INT;
    if (X.t == INT && Y.t == INT) {
        if (X.data.i > Y.data.i)
            P.data.i = 0;
        else 
            P.data.i = 1;

        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        if (X.data.f > Y.data.f)
            P.data.i = 0;
        else   
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        if (X.data.f > Y.data.i)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        if (X.data.i > Y.data.f)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == CHAR)) {
        if (X.data.c > Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == INT)) {
        if (X.data.c > Y.data.i)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == INT && Y.t == CHAR)) {
        if (X.data.i > Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == CHAR)) {
        if (X.data.f > Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == DBL)) {
        if (X.data.c > Y.data.f)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
}

/**
 * @brief operação <
 * 
 * @param s stackpointer
 */
void menor(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    P.t = INT;
    if (X.t == INT && Y.t == INT) {
        if (X.data.i < Y.data.i)
            P.data.i = 0;
        else 
            P.data.i = 1;

        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        if (X.data.f < Y.data.f)
            P.data.i = 0;
        else   
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        if (X.data.f < Y.data.i)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        if (X.data.i < Y.data.f)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == CHAR)) {
        if (X.data.c < Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == INT)) {
        if (X.data.c < Y.data.i)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == INT && Y.t == CHAR)) {
        if (X.data.i < Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == CHAR)) {
        if (X.data.f < Y.data.c)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
    else if ((X.t == CHAR && Y.t == DBL)) {
        if (X.data.c < Y.data.f)
            P.data.i = 0;
        else
            P.data.i = 1;

        push(s,P);
    }
}

/**
 * @brief devolve o maior dos dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void emaior(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        if (X.data.i > Y.data.i)
            P.data.i = X.data.i;
        else 
            P.data.i = Y.data.i;

        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        if (X.data.f > Y.data.f)
            P.data.f = X.data.f;
        else   
            P.data.f = Y.data.f;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        if (X.data.f > Y.data.i){
            P.t = DBL;
            P.data.f = X.data.f;
        } 
        else{
            P.t = INT;
            P.data.i = Y.data.i;
        }

        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        if (X.data.i > Y.data.f){
            P.t = INT;
            P.data.i = X.data.i;
        }
        else{
            P.t = DBL;
            P.data.f = Y.data.f;
        }

        push(s,P);
    }
    else if (X.t == CHAR && Y.t == CHAR) {
        P.t = CHAR;
        if (X.data.c > Y.data.c)
            P.data.c = X.data.c;
        else 
            P.data.c = Y.data.c;

        push(s,P);
    }
    else if (X.t == INT && Y.t == CHAR) {
        if (X.data.i > Y.data.c){
            P.t = INT;
            P.data.i = X.data.i;
        }
        else{
            P.t = CHAR;
            P.data.c = Y.data.c;
        }
        push(s,P);
    }
    else if (X.t == CHAR && Y.t == INT) {
        if (X.data.c > Y.data.i){
            P.t = CHAR;
            P.data.c = X.data.c;
        }
        else{
            P.t = INT;
            P.data.i = Y.data.i;
        }
        push(s,P);
    }
    else if (X.t == DBL && Y.t == CHAR) {
        
        if (X.data.f > Y.data.c){
            P.t = DBL;
            P.data.f = X.data.f;
        }
        else{
            P.t = CHAR;
            P.data.c = Y.data.c;
        }
        push(s,P);
    }
    else if (X.t == CHAR && Y.t == DBL) {
        P.t = CHAR;
        if (X.data.c > Y.data.c){
            P.t = CHAR;
            P.data.c = X.data.c;
        }
        else {
            P.t = DBL;
            P.data.f = Y.data.f;
        }
        push(s,P);
    }
}

/**
 * @brief devolve o menor dos dois elementos no topo da stack
 * 
 * @param s stackpointer
 */
void emenor(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    if (X.t == INT && Y.t == INT) {
        P.t = INT;
        if (X.data.i < Y.data.i)
            P.data.i = X.data.i;
        else 
            P.data.i = Y.data.i;

        push(s,P);
    }
    else if (X.t == DBL && Y.t == DBL) {
        P.t = DBL;
        if (X.data.f < Y.data.f)
            P.data.f = X.data.f;
        else   
            P.data.f = Y.data.f;

        push(s,P);
    }
    else if ((X.t == DBL && Y.t == INT)) {
        if (X.data.f < Y.data.i){
            P.t = DBL;
            P.data.f = X.data.f;
        } 
        else{
            P.t = INT;
            P.data.i = Y.data.i;
        }

        push(s,P);
    }
    else if ((X.t == INT && Y.t == DBL)) {
        if (X.data.i < Y.data.f){
            P.t = INT;
            P.data.i = X.data.i;
        }
        else{
            P.t = DBL;
            P.data.f = Y.data.f;
        }

        push(s,P);
    }
    else if (X.t == CHAR && Y.t == CHAR) {
        P.t = CHAR;
        if (X.data.c < Y.data.c)
            P.data.c = X.data.c;
        else 
            P.data.c = Y.data.c;

        push(s,P);
    }
    else if (X.t == INT && Y.t == CHAR) {
        if (X.data.i < Y.data.c){
            P.t = INT;
            P.data.i = X.data.i;
        }
        else{
            P.t = CHAR;
            P.data.c = Y.data.c;
        }
        push(s,P);
    }
    else if (X.t == CHAR && Y.t == INT) {
        if (X.data.c < Y.data.i){
            P.t = CHAR;
            P.data.c = X.data.c;
        }
        else{
            P.t = INT;
            P.data.i = Y.data.i;
        }
        push(s,P);
    }
    else if (X.t == DBL && Y.t == CHAR) {
        
        if (X.data.f < Y.data.c){
            P.t = DBL;
            P.data.f = X.data.f;
        }
        else{
            P.t = CHAR;
            P.data.c = Y.data.c;
        }
        push(s,P);
    }
    else if (X.t == CHAR && Y.t == DBL) {
        P.t = CHAR;
        if (X.data.c < Y.data.c){
            P.t = CHAR;
            P.data.c = X.data.c;
        }
        else {
            P.t = DBL;
            P.data.f = Y.data.f;
        }
        push(s,P);
    }
}

/**
 * @brief e(com shortcut)
 * 
 * @param s stackpointer
 */
void eShortcut(STACK *s) {
    STACK_ELEM Y = pop(s);
    STACK_ELEM X = pop(s); 
    if (X.t == INT) {
        if (X.data.i == 0) {
            push(s,X);
        } else
            push(s,Y);
    }
    else if (X.t == DBL) {
        if (X.data.f == 0) {
            push(s, X);
        } else 
            push(s, Y);
    }
}

/**
 * @brief ou(com shortcut)
 * 
 * @param s stackpointer
 */
void ouShortcut(STACK *s) {
    STACK_ELEM Y = pop(s);
    STACK_ELEM X = pop(s); 
    if (X.t == INT) {
        if (X.data.i == 0) {
            push(s,Y);
        } else
            push(s,X);
    }
    else if (X.t == DBL) {
        if (X.data.f == 0) {
            push(s, Y);
        } else 
            push(s, X);
    }
}


/**
 * @brief se o o terceiro elemento do topo da stack (Z) for == 0, então dá-se push ao elemento do topo da stack (X), caso contrário dá-se push ao segundo elemento (Y)
 * 
 * @param s stackpointer
 */
void ifThenElse(STACK *s){
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM Z = pop(s);
    
    STACK_ELEM P = X;

    if (Z.t == INT) {
        if (Z.data.i) {
            P = Y;
        }
    }
    else if (Z.t == DBL) {
        if (Z.data.f) {
            P = Y;
        }
    }

    push(s, P);
}

/**
 * @brief Altera o valor do elementos no topo da stack, qualquer coisa != de 0 fica 0, e caso seja 0 fica 1
 * 
 * @param s stackpointer
 */
void not(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM P;
    P.t = INT;
    P.data.i = 1;
    if (X.t == INT && X.data.i == 0) {
        push(s, P);
    } else if (X.t == DBL && X.data.f == 0.0) {
        push(s, P);
    } else if (X.t == CHAR && X.data.c == 0) {
        push(s,P);   
    } 
    else {
        P.data.i = 0;
        push(s, P);
    }
}


/**
 * @brief cria um array por ordem crescente, desde 0 ate ao numero que está no topo da stack
 * 
 * @param s stackpointer
 */
void tamanho(STACK *s) {
    int i;
    STACK_ELEM X = pop(s);
    STACK_ELEM S;
    S.t = INT;

    for (i = 0; i < X.data.i; i++) {
        S.data.i = i;
        push(s, S);
    }
}

/**
 * @brief atribui a uma variavel o valor que está no topo da stack
 * 
 * @param s stackpointer
 * @param letra a letra à qual se vai atribuir o valor que está no topo da stack
 */
void valVariavel(STACK *s, char letra) {
    STACK_ELEM X;
    top(s, &X);
    s->letras[letra - 65] = X;
}

/**
 * @brief verifica se os 2 elementos no topo da stack são iguais
 * 
 * @param s stackpointer
 */
void equal(STACK *s) {
    STACK_ELEM X = pop(s);
    STACK_ELEM Y = pop(s);
    STACK_ELEM P;
    P.t = INT;
    P.data.i = 0;
    if (X.t == INT && Y.t == INT && X.data.i == Y.data.i) {
        P.data.i = 1;
    }
    else if (X.t == DBL && Y.t == DBL && X.data.f == Y.data.f) {
        P.data.i = 1;
        }
    else if (X.t == DBL && Y.t == INT && X.data.f == Y.data.i) {
        P.data.i = 1;
    }
    else if (X.t == INT && Y.t == DBL && X.data.i == Y.data.f) {
        P.data.i = 1;
    }
    push(s,P);
}

/**
 * @brief identifica o valor e coloca no topo da stack o respetivo STACK_ELEM
 * 
 * @param s stackpointer
 * @param token caracter que identifica também as operações da stack e também variaveis
 * @return true 
 * @return false 
 */
bool val(STACK *s, char *token) {
    if(*token == '\0') {
        return false;
    }
    
    char* endptr;
    long maybe_long = strtol(token,&endptr,10);
    if (*endptr == '\0') {
        STACK_ELEM val = {
            .t = INT,
            .data.i = maybe_long,
        };
        push(s, val);
        return true;
    }

    char* endptrr;
    double maybe_double = strtod(token,&endptrr);
    if (*endptrr == '\0') {
        STACK_ELEM val = {
            .t = DBL,
            .data.f = maybe_double,
        };
        push(s, val);
        return true;
    }

    if (*token >= 'A' && *token <= 'Z'){
    
        push(s, s->letras[*token - 65]);
        return true;
    }

    return false;    
}

/**
 * @brief devolve o índice da posição do operador
 * 
 * @param token caracter que identifica também as operações da stack e também variaveis
 * @return int posicao do operador no array
 */
int indice(char *token) {
    int i;
    char *array[32] = {"+","-","*","/","(",")","%","#","&","|","^","~","@",
                       "_","\\","$","i","f","c","p","l","=","?",">","<","e&",
                       "e|","e>","e<","!",",",";"};

    for (i = 0; i < 32; i++) {
        if (strcmp(token, array[i]) == 0) {
            return i;
        } else if (token[0] == ':') {
            return 33;
        }
    }
    return 35;
}

/**
 * @brief indica a operação a executar de acordo com o índice
 * 
 * @param s stackpointer
 * @param n índice
 */
void dispatchTable(STACK *s, int n) {
    
    typedef void (*FunctionPointer)(STACK *s);

    FunctionPointer Table[] = {
        sum,
        sub,
        mult,
        divi,
        decrease,
        increase,
        modulo,
        power,
        bitwisee,
        bitwiseor,
        bitwisexor,
        bitwisenot,
        rodar,
        duplica,
        trade,
        copyN,
        converteint,
        convertedoubl,
        convertechar,
        printTop,
        readLine,
        equal,
        ifThenElse,
        maior,
        menor,
        eShortcut,
        ouShortcut,
        emaior,
        emenor,
        not,
        tamanho,      
    };

    Table[n](s);

}

/**
 * @brief handle das variáveis
 * 
 * @param s stackpointer
 * @param token caracter que identifica também as operações da stack e também variaveis
 */
void handleVariaveis(STACK *s, char *token) {
    if (token[0] == ':') {
        char letra = token[1];
        valVariavel(s, letra);        
    }
}

/**
 * @brief função que consoante o índice indica a operação a executar
 * 
 * @param s stackpointer
 * @param token caracter que identifica também as operações da stack e também variaveis
 */
void handle(STACK *s, char *token) {
    int index = indice(token);
    if (index >= 0 && index < 32 && index != 31) {
        dispatchTable(s, index);
    } 
    else if (index == 31) {
        pop(s);
    } else if (index == 33) {
        handleVariaveis(s, token);
    } else {
        val(s, token);
    }
}


/**
 * @brief MAIN
 * 
 * @return int 
 */
int main() {
    
    STACK *s = new_stack();
    char line [BUFSIZ];
    char token [BUFSIZ];
    defaultletters(s->letras);

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle(s, token);            
        }
        handle (s, token);
        for (int i = 0; i < s->sp; i++){
            if ((s->stack[i]).t == INT){
                printf("%li", (s->stack[i]).data.i);
            }else if ((s->stack[i]).t == DBL){
                printf("%g",(s->stack[i]).data.f);
            }else if ((s->stack[i]).t == CHAR){
                printf("%c", (s->stack[i]).data.c);
            }else if ((s->stack[i]).t == STR){
                printf("%s", (s->stack[i]).data.s);
            }
        }
        printf("\n");
    }
    return 0;
}