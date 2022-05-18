#define _CRT_SECURE_NO_WARNINGS
//#include  <stdio.h>
//#include  <stdlib.h>
//#define    N    5
//typedef struct node {
//    int  data;
//    struct node* next;
//} NODE;
//void fun(NODE* h)
//{
//    NODE* p, * q, * r;
//    /**********found**********/
//    p = h->next;
//    /**********found**********/
//    if (p == NULL)  return;
//    q = p->next;
//    p->next = NULL;
//    while (q)
//    {
//        r = q->next;    q->next = p;
//        /**********found**********/
//        p = q;
//        q = r;
//    }
//    h->next = p;
//}
//NODE* creatlist(int  a[])
//{
//    NODE* h, * p, * q;        int  i;
//    h = (NODE*)malloc(sizeof(NODE));
//    h->next = NULL;
//    for (i = 0; i < N; i++)
//    {
//        q = (NODE*)malloc(sizeof(NODE));
//        q->data = a[i];
//        q->next = NULL;
//        if (h->next == NULL)  h->next = p = q;
//        else { p->next = q;  p = q; }
//    }
//    return  h;
//}
//void outlist(NODE* h)
//{
//    NODE* p;
//    p = h->next;
//    if (p == NULL)  printf("The list is NULL!\n");
//    else
//    {
//        printf("\nHead  ");
//        do
//        {
//            printf("->%d", p->data); p = p->next;
//        } while (p != NULL);
//        printf("->End\n");
//    }
//}
//void main()
//{
//    NODE* head;
//    int  a[N] = { 2,4,6,8,10 };
//    head = creatlist(a);
//    printf("\nThe original list:\n");
//    outlist(head);
//    fun(head);
//    printf("\nThe list after inverting :\n");
//    outlist(head);
//}

#include <stdio.h>
#include <conio.h>
#define M 3
#define N 20
void fun(char a[M][N], char* b)
{
    int i, j, k = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; a[i][j] != '\0'; j++)
        {
            b[k++] = a[i][j];
        }
    }
    b[k] = '\0';
}
void main()
{
   
    char w[M][N] = { "AAAA", "BBBBBBB", "CC" }, i;
    char a[100] = { " ##############################" };
    printf("The string:\n ");
    for (i = 0; i < M; i++)
        puts(w[i]);
    printf("\n ");
    fun(w, a);
    printf("The A string:\n ");
    printf("%s ", a);
    printf("\n\n ");
}
