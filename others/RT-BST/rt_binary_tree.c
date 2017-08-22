#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct NODE {
    int val;
    struct NODE *left;
    struct NODE *right;
    bool rThread;
};

typedef struct NODE node;

node *getNode() {
    node *p;
    p = (node *) malloc(sizeof(node));
    return p;
}

node *makeTree(int x) {
    node *p;
    p = getNode();
    p->val = x;
    p->left = NULL;
    p->right = NULL;
    p->rThread = true;
    return p;
}

int addLeft(node *p, int x) {
    node *q;
    q = getNode();
    q->val = x;
    p->left = q;
    q->left = NULL;
    q->right = p;
    q->rThread = true;
    return 0;
}

int addRight(node *p, int x) {
    node *q, *r;
    q = getNode();
    q->val = x;
    r = p->right;
    p->right = q;
    p->rThread = false;
    q->left = NULL;
    q->right = r;
    q->rThread = true;
    return 0;
}

int insertNode(node *p, int x) {
    node *q;
    q = p;
    while(1) {
        if(x < q->val) {
            if(q->left == NULL) {
                addLeft(q, x);
                break;
            } else {
                q = q->left;
            }
        } else {
            if(q->rThread) {
                addRight(q, x);
                break;
            } else {
                q = q->right;
            }
        }
    }
    return 0;
}

node *goToLastLeft(node *p) {
    while(p->left != NULL) {
        p = p->left;
    }
    return p;
}

int main() {
    printf("Total no. of entries? ");
    int count, i, num;
    scanf("%d", &count);
    node *tree;
    printf("Enter the numbers (with a space between them):\n");
    // Check the algorithm with 5, 4, 9, 3, 1, 7, 8, 11, 12
    // Test the algorithm with 11, 6, 8, 19, 4, 10, 5, 17, 43, 49, 31
    for(i=0; i<count; i++) {
        scanf("%d", &num);
        if(i == 0) {
            tree = makeTree(num);
        } else {
            insertNode(tree, num);
        }
    }
    printf("Right Threaded Binary Search Tree (RT-BST) is complete\n");
    printf("Numbers in increasing order (In-Order Traversal): \n");
    node *p, *q;
    p = tree;
    while(p != NULL) {
        q = goToLastLeft(p);
        printf("%d ", q->val);
        while(q->rThread) {
            if(q->right == NULL) {
                break;
            }
            q = q->right;
            printf("%d ", q->val);
        }
        p = q->right;
    }
    return 0;
}
