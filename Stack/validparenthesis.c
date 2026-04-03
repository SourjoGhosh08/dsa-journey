/*
 * TOPIC: Stack — Balanced Brackets (Valid Parentheses)
 * LeetCode #20 — Easy
 * ----------------------------------------------------
 * Problem: Given a string of brackets, check if they
 * are properly opened and closed in the correct order.
 *
 * Example:
 *   Input:  "{[()]}"  → Output: Valid
 *   Input:  "{[(]}"   → Output: Invalid
 *
 * Logic: Push every opening bracket onto the stack.
 * When a closing bracket appears, check if the top of
 * the stack has its matching opening bracket.
 * If not — invalid. If stack is empty at end — valid.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0'; // empty stack
    return stack[top--];
}

// check if pair is matching
int isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char str[MAX];

    printf("Enter bracket string: ");
    scanf("%s", str);

    int n = strlen(str);
    int valid = 1;

    for (int i = 0; i < n; i++) {
        char c = str[i];

        // push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        // for closing bracket, check match
        else if (c == ')' || c == '}' || c == ']') {
            char top_char = pop();
            if (!isMatch(top_char, c)) {
                valid = 0;
                break;
            }
        }
    }

    // stack must be empty for full validity
    if (valid && top == -1)
        printf("Valid brackets\n");
    else
        printf("Invalid brackets\n");

    return 0;
}