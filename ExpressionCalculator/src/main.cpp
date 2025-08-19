#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>

// --- Function Prototypes ---
int getPrecedence(char op);
std::string infixToPostfix(const std::string& infix);
double evaluatePostfix(const std::string& postfix);
double applyOperation(double a, double b, char op);

// --- Main Application Logic ---
int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): ";
    std::getline(std::cin, infixExpression);

    try {
        std::string postfixExpression = infixToPostfix(infixExpression);
        std::cout << "Postfix Expression: " << postfixExpression << std::endl;

        double result = evaluatePostfix(postfixExpression);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

// --- Function Implementations ---

// Returns the precedence of an operator. Higher number means higher precedence.
int getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For non-operators
}

// Converts an infix mathematical expression to postfix (Reverse Polish Notation).
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;

    for (size_t i = 0; i < infix.length(); ++i) {
        char token = infix[i];

        // If the token is a whitespace, skip it.
        if (isspace(token)) {
            continue;
        }

        // If the token is a number (operand), read the whole number.
        if (isdigit(token) || token == '.') {
            std::string numberStr;
            while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                numberStr += infix[i];
                i++;
            }
            i--; // Decrement i because the outer loop will increment it.
            postfix += numberStr + " ";
        }
        // If the token is an opening parenthesis, push it to the stack.
        else if (token == '(') {
            operatorStack.push(token);
        }
        // If the token is a closing parenthesis, pop and output from the stack
        // until an opening parenthesis is encountered.
        else if (token == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                postfix += " ";
                operatorStack.pop();
            }
            if (operatorStack.empty()) throw std::runtime_error("Mismatched parentheses.");
            operatorStack.pop(); // Pop the opening parenthesis.
        }
        // If an operator is encountered.
        else {
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(operatorStack.top()) >= getPrecedence(token)) {
                postfix += operatorStack.top();
                postfix += " ";
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    // Pop all the remaining operators from the stack.
    while (!operatorStack.empty()) {
        if (operatorStack.top() == '(') throw std::runtime_error("Mismatched parentheses.");
        postfix += operatorStack.top();
        postfix += " ";
        operatorStack.pop();
    }

    return postfix;
}

// Evaluates a given postfix expression.
double evaluatePostfix(const std::string& postfix) {
    std::stack<double> operandStack;

    for (size_t i = 0; i < postfix.length(); ++i) {
        char token = postfix[i];

        if (isspace(token)) {
            continue;
        }

        if (isdigit(token) || token == '.') {
            std::string numberStr;
            while (i < postfix.length() && !isspace(postfix[i])) {
                numberStr += postfix[i];
                i++;
            }
            i--;
            operandStack.push(std::stod(numberStr));
        } else { // Token is an operator
            if (operandStack.size() < 2) throw std::runtime_error("Invalid postfix expression.");
            
            double val2 = operandStack.top();
            operandStack.pop();
            double val1 = operandStack.top();
            operandStack.pop();

            operandStack.push(applyOperation(val1, val2, token));
        }
    }

    if (operandStack.size() != 1) throw std::runtime_error("Invalid postfix expression.");
    return operandStack.top();
}

// Applies a binary operation to two operands.
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero.");
            return a / b;
        default: throw std::runtime_error("Invalid operator.");
    }
}

