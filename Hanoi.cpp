// Towers of Hanoi proof-of-concept using custom stack implementation
#include <iostream>
#include "stack.h"
using namespace std;

// Recursive function implementing the Towers of Hanoi algorithm
void towerOfHanoi(int n, Stack<int> *from_rod, Stack<int> *to_rod, Stack<int> *aux_rod)
{
    if (n == 1)
    {
        cout << "Se mueve el disco 1 de la torre " << from_rod->id << " a la torre " << to_rod->id << endl;
        to_rod->push(from_rod->pop());
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout << "Se mueve el disco " << n << " de la torre " << from_rod->id << " a la torre " << to_rod->id << endl;
    to_rod->push(from_rod->pop());
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

// Print a tower's stack
void printTower(Stack<int> tower) {
    cout << "Torre " << tower.id << ":" << endl;
    while(!tower.isEmpty()) {
        cout << tower.pop() << endl;
    }
}

int main()
{
    int discos;
    cout << "Número de discos de la torre: ";
    cin >> discos;

    // Create the towers stacks
    Stack<int> A('A');
    Stack<int> B('B');
    Stack<int> C('C');
    for(int i = discos; i > 0; i--) A.push(i); // Fill the LIFO stack
/*
    cout << "==> Antes:" << endl;
    printTower(A);
    printTower(B);
    printTower(C);
    cout << endl;
*/
    towerOfHanoi(discos, &A, &C, &B); // A, B and C are names of rods
    cout << endl;
/*
    cout << "==> Después:" << endl;
    printTower(A);
    printTower(B);
    printTower(C);
*/
    return 0;
}
