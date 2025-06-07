#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[5];

public:
    Stack() {
        top = -1; // Initialize stack
    }

    void push() {
        if (top >= 4) {
            cout << "Stack Overflow" << endl;
            return;
        }
        int x;
        cout << "Enter the number to push: ";
        cin >> x;
        arr[++top] = x;
        cout << "Pushed " << x << " onto stack." << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped element: " << arr[top--] << endl;
    }

    void Top() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void empty() {
        if (top == -1)
            cout << "Stack is empty" << endl;
        else
            cout << "Stack is not empty" << endl;
    }
};

int main() {
    Stack obj;

    while (1) {
        int x;
        cout << "\n1.PUSH\n2.POP\n3.TOP\n4.EMPTY\n5.EXIT\nChoose: ";
        cin >> x;
        switch (x) {
            case 1:
                obj.push();
                break;
            case 2:
                obj.pop();
                break;
            case 3:
                obj.Top();
                break;
            case 4:
                obj.empty();
                break;
            case 5:
                return 0;
            default:
                cout << "INVALID CHOICE" << endl;
        }
    }
}
