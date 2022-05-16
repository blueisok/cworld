#define _CRT_SECURE_NO_WARNINGS
//#include  <stdio.h>
//#include  <stdlib.h>
//#define    N    5
//typedef struct node {
//    int  data;
//    struct node* next;
//} NODE;
///**********found**********/
//NODE* fun(NODE* h)
//{
//    NODE* p, * q, * r;
//    p = h;
//    if (p == NULL)
//        return NULL;
//    q = p->next;
//    p->next = NULL;
//    while (q)
//    {
//        /**********found**********/
//        r = q->next;
//        q->next = p;
//        p = q;
//        /**********found**********/
//        q = r;
//    }
//    return  p;
//}
//NODE* creatlist(int  a[])
//{
//    NODE* h, * p, * q;        int  i;
//    h = NULL;
//    for (i = 0; i < N; i++)
//    {
//        q = (NODE*)malloc(sizeof(NODE));
//        q->data = a[i];
//        q->next = NULL;
//        if (h == NULL)  h = p = q;
//        else { p->next = q;  p = q; }
//    }
//    return  h;
//}
//void outlist(NODE* h)
//{
//    NODE* p;
//    p = h;
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
//    head = fun(head);
//    printf("\nThe list after inverting :\n");
//    outlist(head);
//}

#include <stdio.h>
void fun(int(*s)[10], int* b, int* n, int mm, int nn)
{
    int i, j, k = 0;
    for (i = 0; i < nn; i++)
    {
        for (j = 0; j < mm; j++)
        {
            b[k++] = s[j][i];
        }
    }
    *n = k;
}
void main()
{
    int w[10][10] = { {33,33,33,33},{44,44,44,44},{55,55,55,55} }, i, j;
    int a[100] = { 0 }, n = 0;
    printf("The matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d", w[i][j]);
        printf("\n");
    }
    fun(w, a, &n, 3, 4);
    /******************************/
    printf("The A array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%3d", a[i]);
    }
    printf("\n\n");
    /******************************/
}
