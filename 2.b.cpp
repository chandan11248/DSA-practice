#include <iostream>
#include <stack>
#include <algorithm> // for reverse
#include <cctype>    // for isalpha and isdigit
using namespace std;

// Step 1: Precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Step 2: Check if operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Step 3: Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(char c : infix) {
        if(isalpha(c) || isdigit(c)) {
            postfix += c;
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
        }
        else if(isOperator(c)) {
            while(!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Step 4: Infix to Prefix using steps
string infixToPrefix(string infix) {
    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Swap brackets
    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // Get postfix of modified expression
    string postfix = infixToPostfix(infix);

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Step 5: Example usage
int main() {
    string infix = "a+c(s)-r";
    cout << "Infix: " << infix << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}