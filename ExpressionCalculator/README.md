# Expression Calculator

## 1. Project Overview

This C++ program is a command-line expression calculator that can evaluate standard mathematical infix expressions. It first converts the user-provided infix expression (e.g., `5 + (10 * 2)`) into a postfix expression (e.g., `5 10 2 * +`), also known as Reverse Polish Notation (RPN). It then evaluates the postfix expression to compute the final result. The program correctly handles operator precedence (`*` and `/` before `+` and `-`) and parentheses.

## 2. Features

- **Infix to Postfix Conversion**: Implements the Shunting-yard algorithm to convert standard mathematical expressions into postfix notation.
- **Postfix Evaluation**: Evaluates the generated postfix expression to produce a numerical result.
- **Operator Precedence**: Correctly handles the order of operations (multiplication/division have higher precedence than addition/subtraction).
- **Parentheses Handling**: Properly evaluates expressions within parentheses first.
- **Error Handling**: Catches and reports errors such as mismatched parentheses or division by zero.
- **Supports Floating-Point Numbers**: Can handle expressions with decimal numbers.

## 3. Data Structures Used

- **`std::stack`**: The stack is the core data structure for this project. It is used in two key places:
  1.  **Infix to Postfix Conversion**: A stack is used to temporarily store operators and parentheses while building the postfix string. This ensures that operators are added to the output string in the correct order based on precedence rules.
  2.  **Postfix Evaluation**: A stack is used to store operands (numbers). When an operator is encountered in the postfix string, the required number of operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.

## 4. How to Run the Code

### Prerequisites
- A C++ compiler (e.g., G++, Clang, MSVC).

### Compilation
1.  Open your terminal and navigate to the `src` directory.
2.  Compile the `main.cpp` file.

    ```bash
    g++ main.cpp -o calculator
    ```

### Execution
1.  Run the compiled executable.

    ```bash
    ./calculator
    ```

2.  When prompted, enter the infix mathematical expression you want to evaluate and press Enter.

## 5. Sample Run/Output

### Example 1: Simple Expression
```
Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): 3 + 4 * 2
Postfix Expression: 3 4 2 * +
Result: 11
```

### Example 2: Expression with Parentheses
```
Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): (3 + 4) * 2
Postfix Expression: 3 4 + 2 *
Result: 14
```

### Example 3: Complex Expression
```
Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): 3 + 5 * (2 - 8) / 2
Postfix Expression: 3 5 2 8 - * 2 / +
Result: -12
```

### Example 4: Error Handling
```
Enter an infix expression (e.g., 3 + 5 * (2 - 8) / 2): (5 + 2
Error: Mismatched parentheses.

