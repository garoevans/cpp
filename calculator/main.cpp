#include <iostream>
#include "calculator.h"

enum Operands
{
    OPERAND_ADD,
    OPERAND_SUBTRACT,
    OPERAND_DIVIDE,
    OPERAND_MULTIPLY
};

int evaluate(Operands, int*, int*);

int main()
{
    using namespace std;

    int output;
    int a;
    int b;
    int toDo;

    cout << "What would you like to do?" << endl;
    cout << "0: add, 1: subtract, 2: divide, 3: multiply? ";
    cin >> toDo;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << "Output: " << evaluate(static_cast<Operands>(toDo), &a, &b) << endl;

    return 0;
}

int evaluate(Operands operand, int *a, int *b)
{
    switch(operand) {
        case OPERAND_ADD:
            return add(a, b);
        case OPERAND_SUBTRACT:
            return subtract(a, b);
        case OPERAND_DIVIDE:
            return divide(a, b);
        case OPERAND_MULTIPLY:
            return multiply(a, b);
    }

    return 0;
}
