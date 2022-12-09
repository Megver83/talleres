#include "Month.h"

// Calcula la altura de un árbol
int height(Month*);

// Obtiene el factor de balance
int difference(Month*);

// Hace una rotación RR
Month* rr_rotat(Month*);

// Hace una rotación LL
Month* ll_rotat(Month*);

// Hace una rotación LR
Month* lr_rotat(Month*);

// Hace una rotación RL
Month* rl_rotat(Month*);

// Balancea un árbol binario
Month* balance(Month *);

// Inserta un nodo al árbol
Month* insert(Month*, Month*);

// Imprime en orden in-order
void inorder(Month*);

// Imprime en orden pre-order
void preorder(Month*);

// Imprime en orden post-order
void postorder(Month*);

// Busca un mes con el mismo peso
bool find(Month*, int);
