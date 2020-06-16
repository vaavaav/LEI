#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "avltrees.h"

//Funtions Auxs
int numtostr(char *s, int x){
    int i, y, tam;
    for(tam = 1, y = x / 10; y ; tam++) y /= 10;
    s[tam] = '\0';
    for(i = tam - 1; i >= 0; i--){
        s[i] = (x % 10) + 48;
        x /= 10; 
    }
    return tam;
}


void printTree(AVLTree t){
    char tree[1000];  //size of print in screen: MAX CHARACTERES = 1000
    //makeTreeLine(t,tree);
    makeTreeED(t,tree,0);
    printf("%s",tree);

}

int makeTreeED(AVLTree t, char *tree, int n){
    char tostr[10]; int r = 0, tam = 0, i; //size of number in tree MAX = 10
    if(t!= NULL){
        tam = numtostr(tostr, t->value);
        r += makeTreeED(t->right, tree, n + tam + 2);
        for(i = 0; i < n; i++)
            tree[i + r] = ' ';
        r += n;
        strcpy(tree + r, "(");
        r++;
        strcpy(tree + r, tostr);
        r += tam;
        strcpy(tree + r,")\n");
        r += 2;  
        r += makeTreeED(t->left, tree + r, n + tam + 2);
    }
    return r;
}


int makeTreeLine(AVLTree t, char *tree){
    int r = 0; int aux; char tostr[10]; //size of number in tree MAX = 10
    if(t != NULL){
        strcpy(tree,"( ");
        r += 2;
        if(t -> left != NULL){
            r += makeTreeLine(t->left, tree + r);
            strcpy(tree + r, " <- ");
            r += 4;
        }
        aux = numtostr(tostr,t->value);
        strcpy(tree + r, tostr);
        r += aux;
        if(t -> right != NULL){
            strcpy(tree + r, " -> ");
            r +=4;
            r += makeTreeLine(t->right, tree + r);
        }
        strcpy(tree + r, " )");
        r += 2;
    }
    else{
        strcpy(tree,"X");
        r++;
    }
    return r;
}


int maxTree(AVLTree t){
    int max;
    if(t != NULL){
        max = t->value;
        t = t -> right;
        while(t != NULL){
            if(max < t->value) max = t->value;
            t = t -> right;
        }
    }
    return max;
}

int minTree(AVLTree t){
    int min;
    if(t != NULL){
        min = t->value;
        t = t -> left;
        while(t != NULL){
            if(min > t->value) min = t->value;
            t = t -> left;
        }
    }
    return min;
}

AVLTree updateBal(AVLTree t){   //is there a way to avoid this process?
    if(t!= NULL){
        t -> left = updateBal(t->left); 
        t -> right = updateBal(t->right); 
        t -> bal = alturaAVL(t->left) - alturaAVL(t->right);
    }     
    return t;
}

//END
int alturaAVL(AVLTree t){
    int r = 0;
    if(t != NULL)
        r = (t->bal > 0) ? 1 + alturaAVL(t->left) : 1 + alturaAVL(t->right);
    return r;
}

//Rotations

AVLTree rotateLeft(AVLTree a){
    AVLTree A, aux;
    A = a;
    a = a->right;
    A->right = NULL;
    aux = a->left;
    A->right=aux;
    A->bal = 0;
    a->bal = 0;
    a->left = A;
    return a;
}

AVLTree rotateRight(AVLTree a){
    AVLTree A, aux;
    A = a;
    a = a->left;
    A->left = NULL;
    aux = a->right;
    A->left=aux;
    A->bal = 0;
    a->bal = 0;
    a->right = A;
    return a;
}

//END



//Utilitaries

AVLTree insertAVL(AVLTree t, int x){
    if(t == NULL){   
        t = malloc(sizeof(struct avlTree));
        t->value = x;
        t->bal = 0;
        t ->left = t -> right = NULL;
    }
    else{
        if(t->value > x)
            t -> left = insertAVL( t -> left, x);
        else
            t -> right = insertAVL( t->right, x);
        t = updateBal(t); //better way??
        
        if(t->bal > 1){
            printf("\n\nAVL-TREE RULE VIOLATED - Node %d: Balance = %d", t->value, t->bal);
            printTree(t);
            if((t -> left)->bal < 0){
                printf("\n\nRotation: LEFT Rotation\n\n");
               t->left = (rotateLeft(t->left));
               printTree(t);
            }
            printf("\n\nRotation: RIGHT Rotation\n\n");
            t = rotateRight(t);
            printTree(t);
            }
        else 
            if(t->bal < -1){
                printf("\n\nAVL-TREE RULE VIOLATED - Node %d: Balance = %d\n\n", t->value, t->bal);
                printTree(t);
                if((t->right)->bal > 0){
                    printf("\n\nRotation: RIGHT Rotation\n\n");
                    t->right = (rotateRight(t->right));
                    printTree(t);
                }
                printf("\n\nRotation: LEFT Rotation\n\n");
                t = rotateLeft(t);
                printTree(t);
            }
    }   
    return t;
}



AVLTree deleteAVL(AVLTree t, int x){
    int y;
    if(t!= NULL){
        if(t -> value == x){
            if(t -> right == NULL && t -> left == NULL){
                free(t);
                t = NULL;
            }
            else{ 
                if(t -> bal >= 0){
                    y = maxTree(t->left);
                    t -> value = y;
                    t -> left = deleteAVL(t->left,y);
                }
                else{
                    y= minTree(t->right);
                    t -> value = y;
                    t -> right = deleteAVL(t->right,y);
                }
            }
        }
        else{ if(t -> value < x)
                t -> right = deleteAVL(t -> right, x);
            else
                t -> left = deleteAVL(t -> left, x);
        }
            t = updateBal(t);
    }
    return t;
}


void clearAVL(AVLTree t){
    if(t != NULL){
        clearAVL(t->left);
        clearAVL(t->right);
        free(t);
    }
}
