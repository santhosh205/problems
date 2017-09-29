#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 100

typedef struct {
    int top;
    char items[STACKSIZE];
} charStack;

int isCharStackEmpty(charStack *s) {
    if(s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void charStackPush(charStack *s, char c) {
    if(s->top == STACKSIZE-1) {
        printf("Stack Overflow");
        exit(1);
    } else {
        s->items[++(s->top)] = c;
    }
}

char charStackTop(charStack *s) {
    if(isCharStackEmpty(s)) {
        printf("Stack Empty");
        exit(1);
    } else {
        return s->items[s->top];
    }
}

char charStackPop(charStack *s) {
    if(isCharStackEmpty(s)) {
        printf("Stack Empty");
        exit(1);
    } else {
        return s->items[(s->top)--];
    }
}

int precd(char opr1, char opr2) {
    char as[] = "+-";
    char md[] = "*/";
    char *check1, *check2, *check3, *check4;
    check1 = strchr(as, opr1);
    check2 = strchr(md, opr2);
    check3 = strchr(md, opr1);
    check4 = strchr(as, opr2);
    if(check1 != NULL && check2 != NULL) {
        return 0;
    } else if(check3 != NULL && check4 != NULL) {
        return 1;
    } else if(check1 != NULL && check4 != NULL) {
        return 0;
    } else {
        return 1;
    }
}

int main() {

    char infix[201];
    printf("Enter input expression:\n");
    scanf("%s", infix);

    int i = 0;

    char postfix[201];
    int top = -1;

    char operators[] = "+-*/";
    char inputChar;
    char topOpr;

    charStack *oprstk;
    oprstk = (charStack *) malloc(sizeof(charStack));
    oprstk->top = -1;

    char *check;

    while(infix[i] != '\0') {
        inputChar = infix[i];
        check = strchr(operators, inputChar);
        if(check == NULL) {
            postfix[++top] = inputChar;
        } else {
            while(!isCharStackEmpty(oprstk) && precd(charStackTop(oprstk), inputChar)) {
                topOpr = charStackPop(oprstk);
                postfix[++top] = topOpr;
            }
            charStackPush(oprstk, inputChar);
        }
        i++;
    }

    while(!isCharStackEmpty(oprstk)) {
        topOpr = charStackPop(oprstk);
        postfix[++top] = topOpr;
    }

    postfix[++top] = '\0';

    printf("%s\n", postfix);

    return 0;

}
