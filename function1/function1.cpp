#include <iostream>

void doPrint()
{
    using namespace std;
    cout << "Inside doPrint()" << endl;

    cout << "Enter a number: "; // ask user for a number
    int x;
    cin >> x;
    cout << "Input: " << x << endl;
}

int main()
{
    using namespace std;
    cout << "Running main" << endl;
    cout << "Calling doPrint()" << endl;
    doPrint();
    return 0;
}
