#include <iostream>
#include <cstring> 
using namespace std;

class Stack {
    int top;
    int arr[100];

public:
    Stack() {
        top = -1; // Initialize stack
    }

    void push() {
        if (top >= 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        int x;
        cout << "Enter the number to push: ";
        cin >> x;
        arr[++top] = x;
        
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
class List {
int  arr[100];
};

int main() {
    Stack obj;
    List opt;


        char x[100];
        int Length;
        int i;
        cout << "Enter the Expression \n ";
        cin>>x;

        Length=strlen(x);
        for(i=0;i<Length;i++)
        {
            cout<<x[i];
        }

        
        
        cout<<"\n the string is:\n";
        cout<<x;
return 0;
}
