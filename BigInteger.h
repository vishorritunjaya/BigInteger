#include <stdio.h>
#include <stdlib.h>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H

struct node
{
    int data;
    struct node *next;
};
struct BigInteger
{
    struct node *L;
    int length;
};
void display(struct BigInteger head);

struct BigInteger initialize(char *s);

void insertNode(struct node **head, int d);

struct BigInteger add(struct BigInteger a, struct BigInteger b);

struct BigInteger sub(struct BigInteger a, struct BigInteger b);

struct BigInteger mul(struct BigInteger a,struct BigInteger b);

struct BigInteger div1(struct BigInteger a, struct BigInteger b);

void reverseLL(struct node **start);

int compare(struct node *a, struct node* b);

#endif // BIGINTEGER_H
