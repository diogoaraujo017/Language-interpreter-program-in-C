#ifndef A_STACK_H

/**
 * @brief define 
 * 
 */
#define A_STACK_H

/**
 * @brief define max stack size
 * 
 */
#define MAX_STACK 1000 

/**
 * @brief define max string size
 * 
 */
#define MAX 10000


/**
 * @brief tipo de elemento
 * 
 */
typedef enum {
    CHAR,  /**< char.*/
    INT,   /**< int.*/  
    DBL,   /**< float.*/  
    STR,   /**< string.*/ 
} TYPE;    


typedef struct {
    TYPE t;  /**< tipo do elemento.*/
    union {
        long i;
        double f;
        char c;
        char *s;
    } data; /**< elemento.*/
} STACK_ELEM;


/** 
    *A STACK é defenida por: 
    *Um array de STACK_ELEM;
    *Array de STACK_ELEM que guarda o valor das variáveis;
    *Stack pointe.
*/
typedef struct {
    STACK_ELEM stack[MAX_STACK]; /**<Array principal da stack. */
    STACK_ELEM letras[26]; /**<Variáveis guardadas. */
    int sp; /**<Stack pointer. */
} STACK;


void defaultletters (STACK_ELEM *l);
void top (STACK *s, STACK_ELEM *elem);
STACK *new_stack ();
void push(STACK *s, STACK_ELEM);
STACK_ELEM pop(STACK *s);

#endif //A_STACK_H