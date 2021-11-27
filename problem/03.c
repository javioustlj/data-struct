#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int exponent;
    double coefficient;
    PtrToNode next;
};

typedef PtrToNode Polynomial;

Polynomial readPolynomial()
{
    int n;
    scanf("%d", &n);
    Polynomial poly = malloc(sizeof(struct Node));
    poly->next = NULL;
    poly->exponent = n;
    PtrToNode rear = poly;
    for (int i = 0; i < n; ++i) {
        PtrToNode p = malloc(sizeof(struct Node));
        p->next = NULL;
        scanf("%lf %d", &p->coefficient, &p->exponent);
        rear->next = p;
        rear = p;
    }
    return poly;
}

void printPolynomial(Polynomial poly)
{
    if (!poly->next) {
        printf("0 0\n");
        return;
    }
    int n = poly->exponent;
    for (PtrToNode p = poly->next; p; p = p->next)
        printf("%.0lf %d%c", p->coefficient, p->exponent, --n ? ' ': '\n');
}

Polynomial appendNode(Polynomial poly, int exponent, double coefficient)
{
    PtrToNode tmp = malloc(sizeof(struct Node));
    tmp->coefficient = coefficient;
    tmp->exponent = exponent;
    tmp->next = NULL;
    poly->next = tmp;
    return tmp;
}

Polynomial addPolynomial(Polynomial poly1, Polynomial poly2)
{
    PtrToNode p1 = poly1->next, p2 = poly2->next;
    Polynomial poly = malloc(sizeof(struct Node));
    poly->next = NULL;
    poly->exponent = 0;
    PtrToNode p = poly;
    int exponent;
    double coefficient;
    while(p1 || p2) {
        if (!p1) {
            for ( ; p2; p2 = p2->next)
                p = appendNode(p, p2->exponent, p2->coefficient);
            break;
        }
        if (!p2) {
            for ( ; p1; p1 = p1->next)
                p = appendNode(p, p1->exponent, p1->coefficient);
            break;
        }
        if (p1->exponent == p2->exponent) {
            exponent = p1->exponent;
            coefficient = p1->coefficient + p2->coefficient;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent) {
            exponent = p1->exponent;
            coefficient = p1->coefficient;
            p1 = p1->next;
        }
        else {
            exponent = p2->exponent;
            coefficient = p2->coefficient;
            p2 = p2->next;
        }
        if (coefficient != 0) {
            p = appendNode(p, exponent, coefficient);
        }
    }
    for (p = poly->next; p ; p = p->next)
        ++(poly->exponent);
    return poly;
}

Polynomial multiplePolynomial(Polynomial poly1, Polynomial poly2)
{
    PtrToNode p1 = poly1->next, p2 = poly2->next;
    Polynomial poly = malloc(sizeof(struct Node));
    poly->next = NULL;
    poly->exponent = 0;
    if (!p1 || !p2) {
        return poly;
    }
    int exponent;
    double coefficient;
    PtrToNode tmpNode;
    for (PtrToNode p1 = poly1->next; p1; p1 = p1->next) {
        Polynomial tmpPoly = malloc(sizeof(struct Node));
        tmpPoly->next = NULL;
        tmpPoly->exponent = 0;
        PtrToNode tmpNode = tmpPoly;
        for (PtrToNode p2 = poly2->next; p2; p2 = p2->next) {
            coefficient = p2->coefficient * p1->coefficient;
            exponent = p2->exponent + p1->exponent;
            tmpNode = appendNode(tmpNode, exponent, coefficient);
        }
        poly = addPolynomial(poly, tmpPoly);
    }
    poly->exponent = 0;
    for (PtrToNode p = poly->next; p ; p = p->next)
        ++(poly->exponent);
    return poly;
}

int main(void)
{
    Polynomial p1 = readPolynomial();
    Polynomial p2 = readPolynomial();
    Polynomial sum = addPolynomial(p1, p2);
    Polynomial product = multiplePolynomial(p1, p2);
    printPolynomial(product);
    printPolynomial(sum);

    return 0;
}
