#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct NODE {
    int val;
    struct NODE *left;
    struct NODE *right;
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
    return p;
}

bool insertNode(node *tree, int x) {
    node *p, *q, *r;
    p = tree;
    bool flag = true;
    bool add = true;
    while (flag) {
        if (p != NULL && x > p->val) {
            q = p;
            p = p->right;
        } else if (p != NULL && x < p->val) {
            q = p;
            p = p->left;
        } else {
            flag = false;
            if (p != NULL) {
                printf("-%d- already exists in the tree\n", x);
                add = false;
            }
        }
    }
    if (add) {
        r = getNode();
        r->val = x;
        r->left = NULL;
        r->right = NULL;
        if (x > q->val) {
            q->right = r;
        } else {
            q->left = r;
        }
        return true;
    } else {
        return false;
    }
}

int traverseInorder(node *tree) {
    printf("Inorder Traversal: ");
    node *p;
    p = tree;
    node *s[100];
    int top = -1, count = 0;
    while (p != NULL || top != -1) {
        while (p != NULL) {
            s[++top] = p;
            p = p->left;
        }
        p = s[top--];
        printf("%d ", p->val);
        count += 1;
        p = p->right;
    }
    printf("\n");
    return count;
}

node *deleteNode(node *tree, int x) {
    node *p;
    if (tree == NULL) {
        return tree;
    }
    if (x < tree->val) {
        tree->left = deleteNode(tree->left, x);
    } else if (x > tree->val) {
        tree->right = deleteNode(tree->right, x);
    } else {
        if (tree->left == NULL) {
             p = tree->right;
             free(tree);
             return p;
        } else if (tree->right == NULL) {
             p = tree->left;
             free(tree);
             return p;
        }
        p = tree->right;
        while (p->left != NULL) {
            p = p->left;
        }
        tree->val = p->val;
        tree->right = deleteNode(tree->right, p->val);
    }
    return tree;
}

void searchBST(node *tree, int x) {
    node *p;
    p = tree;
    bool flag = true;
    while (flag) {
        if (p != NULL && x > p->val) {
            p = p->right;
        } else if (p != NULL && x < p->val) {
            p = p->left;
        } else {
            flag = false;
            if (p != NULL) {
                printf("True ");
            } else {
                printf("False ");
            }
        }
    }
}

int main() {
    char op;
    int i = 0, j, num, count, store, leftOut, nodes;
    node *bst;
    bool check;
    while (true) {
        printf("Enter Operation Name (Insertion-i, Deletion-d, Search-s, Quit-q): ");
        scanf("%c", &op);
        getchar();
        if (op == 'i') {
            printf("Number of entries (Current Count: %d, Maximum Count: 100) ? ", i);
            scanf("%d", &count);
            getchar();
            printf("Enter the numbers: ");
            store = i;
            while (i < store+count && i < 100) {
                scanf("%d", &num);
                if (i == 0) {
                    bst = makeTree(num);
                    check = true;
                } else {
                    check = insertNode(bst, num);
                }
                if (check) {
                    i += 1;
                } else {
                    count -= 1;
                }
            }
            leftOut = count-i+store;
            if (i-store < count) {
                count = i-store;
            }
            for (j=0; j<leftOut; j++) {
                scanf("%d", &num);
            }
            getchar();
            printf("%d numbers inserted\n", count);
            i = traverseInorder(bst);
        } else if (op == 'd') {
            printf("Number of entries ? ");
            scanf("%d", &count);
            getchar();
            printf("Enter the numbers: ");
            for(j=0; j<count; j++) {
                scanf("%d", &num);
                bst = deleteNode(bst, num);
            }
            getchar();
            i = traverseInorder(bst);
        } else if (op == 's') {
            printf("Number of entries ? ");
            scanf("%d", &count);
            getchar();
            printf("Enter the numbers: ");
            for(j=0; j<count; j++) {
                scanf("%d", &num);
                searchBST(bst, num);
            }
            getchar();
            printf("\n");
        } else if (op == 'q') {
            exit(1);
        } else {
            printf("There is no operation named -%c-\n", op);
        }
    }
    return 0;
}
