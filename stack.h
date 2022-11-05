// C++ Program to Implement LIFO stack using Class Templates
#include <iostream>
using namespace std;

// Taking size of stack as 1000
#define SIZE 1000

// To represent stack using template by class
// taking class in template
template <class T> class Stack {
public:
    // To create a stack with an identifier
    Stack(char letter);

    // Stack identificator
    char id;

    // To add element to stack which can be any type
    // using stack push() operation
    void push(T k);

    // To remove top element from stack
    // using pop() operation
    T pop();

    // To print top element in stack
    // using peek() method
    T topElement();

    // To check whether stack is full
    // using isFull() method
    bool isFull();

    // To check whether stack is empty
    // using isEmpty() method
    bool isEmpty();
private:
    // Taking data member top
    int top;

    // Initialising stack(array) of given size
    T st[SIZE];
};

// To initialise top to
// -1(default constructor)
template <class T> Stack<T>::Stack(char letter) {
    id = letter;
    top = -1;
}

// To add element element k to stack
template <class T> void Stack<T>::push(T k)
{

    // Checking whether stack is completely filled
    if (isFull()) {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }

    // Inserted element
    //cout << "Inserted element " << k << " to " << id << endl;

    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;

    // Now, adding element to stack
    st[top] = k;
}

// To check if the stack is empty
template <class T> bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Utility methods

// To check if the stack is full or not
template <class T> bool Stack<T>::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else

        // As top can not exceeds th size
        return 0;
}

// To remove the top element
template <class T> T Stack<T>::pop()
{
    // Initialising a variable to store popped element
    T popped_element = st[top];

    // Decreasing the top as
    // element is getting out from the stack
    top--;

    //cout << "Deleted " << popped_element << " from " << id << endl;
    // Returning the element/s that is/are popped
    return popped_element;
}

// To return the top element
template <class T> T Stack<T>::topElement()
{
    // Initialising a variable to store top element
    T top_element = st[top];

    // Returning the top element
    return top_element;
}
