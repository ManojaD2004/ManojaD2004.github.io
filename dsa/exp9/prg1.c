#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int coef, px, py, pz, x, y, z, i;
int val;
struct node
{
    int coef, px, py, pz;
    struct node *next;
};
typedef struct node NODE;
NODE *first;
void insert(int coef, int px, int py, int pz)
{
    NODE *temp, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->coef = coef;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    if (first == NULL)
    {
        temp->next = temp;
        first = temp;
        return;
    }
    if (first->next == first)
    {
        first->next = temp;
        temp->next = first;
    }
    cur = first;
    while (cur->next != first)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = first;
    return;
}
void display()
{
    NODE *cur;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur = first;
    while (cur->next != first)
    {
        printf("%d ", cur->coef);
        printf(" x^%d", cur->px);
        printf(" y^%d", cur->py);
        printf(" z^%d + ", cur->pz);
        cur = cur->next;
    }
    printf("%d ", cur->coef);
    printf(" x^%d", cur->px);
    printf(" y^%d", cur->py);
    printf(" z^%d\n ", cur->pz);
    return;
}
int evaluate(int x, int y, int z)
{
    NODE *cur;
    int v, s = 0, v1, v2, v3;
    if (first == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    cur = first;
    while (cur->next != first)
    {
        v = cur->coef * pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
        s = s + v;
        cur = cur->next;
    }
    v = cur->coef * pow(x, cur->px) * pow(y, cur->py) * pow(z, cur->pz);
    s = s + v;
    return s;
}
int main()
{
    int coef, px, py, pz, x, y, z, i;
    int val;
    first = NULL;
    while (1)
    {
        printf("1. Insert polynomial at end\n");
        printf("2. Display\n");
        printf("3. Evaluate\n");
        printf("4. Exit\n");
        printf("Enter Choice= \t");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter Coefficient= \t");
            scanf("%d", &coef);
            printf("Enter powers of x y z values= \t");
            scanf("%d%d%d", &px, &py, &pz);
            insert(coef, px, py, pz);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\n Enter x y & z values for evaluation: \t");
            scanf("%d%d%d", &x, &y, &z);
            val = evaluate(x, y, z);
            printf("\nValue=%d\n", val);
            break;
        case 4:
            return 0;
        default:
            printf(" Wrong choice. Enter 1,2 3\n");
            break;
        }
    }
}