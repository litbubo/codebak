#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
} LinkList;

main()
{
    LinkList *L;
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
}
