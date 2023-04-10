#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, int item) {
    if (is_full(s)) {
        fprintf(stderr, "������ ���� á���ϴ�.\n");  
    }
    else {
        s->stack[++(s->top)] = item;
    }
}

int pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "������ ����ֽ��ϴ�.\n");
    }
    else {
        return s->stack[(s->top)--];
    }
}

int eval(char* exp) {
    StackType s;
    int len = strlen(exp);
    int i, op1, op2, val;
    char ch;

    init_stack(&s);

    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (isdigit(ch)) {  
            push(&s, ch - '0');
        }
        else {  
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            default:
                fprintf(stderr, "�߸��� �������Դϴ�.\n");
                exit(1);
            }
            push(&s, val);
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX_STACK_SIZE];
    int result;
    printf("�������� �Է��ϼ���: ");
    scanf_s("%s", exp, MAX_STACK_SIZE);
    result = eval(exp);
    printf("��� ���: %d\n", result);
    return 0;
}