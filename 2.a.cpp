#include <iostream>
#include <stack>
#include <cctype>   // for isalpha and isdigit
using namespace std;

// Step 1: Function to define precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Step 2: Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Step 3: Main function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(char c : infix) {
        // If operand, add to result
        if(isalpha(c) || isdigit(c)) {
            postfix += c;
        }
        // If '(', push to stack
        else if(c == '(') {
            s.push(c);
        }
        // If ')', pop until '('
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '(' from stack
        }
        // If operator
        else if(isOperator(c)) {
            while(!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Step 4: Example use
int main() {
    string infix ;
    cout<<"Enter the expression\n";
    cin>>infix;
    
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}