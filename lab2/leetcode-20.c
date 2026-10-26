bool isValid(char* s) {
    char stack[10000];
    int top = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(') stack[top++] = ')';
        else if (c == '[') stack[top++] = ']';
        else if (c == '{') stack[top++] = '}';
        else {
            if (top == 0 || stack[--top] != c) return false;
        }
    }

    return top == 0;
}