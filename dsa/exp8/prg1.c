#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee
{
    char ssn[11];
    char name[21];
    char dept[15];
    char design[15];
    int salary;
    unsigned long long phno;
};
typedef struct employee EMP;
struct node
{
    char ssn[11];
    char name[21];
    char dept[15];
    char design[15];
    int salary;
    unsigned long long phno;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
NODE *first;
NODE *copyNode(EMP e)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        strcpy(temp->ssn, e.ssn);
        strcpy(temp->name, e.name);
        strcpy(temp->dept, e.dept);
        strcpy(temp->design, e.design);
        temp->salary = e.salary;
        temp->phno = e.phno;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
}
void addrear(EMP e)
{
    NODE *temp, *cur, *prev;
    temp = copyNode(e);
    if (first == NULL)
    {
        first = temp;
        return;
    }
    cur = first;
    prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    cur->next = temp;
    temp->prev = prev;
    return;
}
void addfront(EMP e)
{
    NODE *temp;
    temp = copyNode(e);
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    return;
}
void display(NODE *r)
{
    printf("%s\t ", r->ssn);
    printf("%s\t ", r->name);
    printf("%s\t ", r->dept);
    printf("%s\t ", r->design);
    printf("%d\t ", r->salary);
    printf("%llu\n ", r->phno);
}
void deletefront()
{
    NODE *temp;
    int num;
    temp = first;
    if (first == NULL)
    {
        printf(" List is Empty\n");
        return;
    }
    if (first->next == NULL)
        first = NULL;
    else
    {
        first = first->next;
        first->prev = NULL;
    }
    printf("SSN\tName\tDept\tDesignation\tSalary\tPhone\n");
    display(temp);
    free(temp);
    return;
}
void deleterear()
{
    NODE *cur, *prev;
    cur = first;
    prev = NULL;
    if (first == NULL)
    {
        printf(" List is Empty \n");
        return;
    }
    if (first->next == NULL)
    {
        first = NULL;
    }
    else
    {
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
    }
    printf("SSN\tName\tDept\tDesignation\tSalary\tPhone\n");
    display(cur);
    free(cur);
    return;
}
void displayList()
{
    NODE *r;
    r = first;
    if (r == NULL)
    {
        return;
    }
    printf("SSN\t Name\t Dept\t Designation\t salary\tPhone\n");
    while (r != NULL)
    {
        display(r);
        r = r->next;
    }
    printf("\n");
}
int count()
{
    NODE *n;
    int c = 0;
    n = first;
    while (n != NULL)
    {
        n = n->next;
        c++;
    }
    return c;
}
EMP input()
{
    EMP e;
    printf("Enter SSN: ");
    scanf("%s", e.ssn);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter dept: ");
    scanf("%s", e.dept);
    printf("Enter Designation :");
    scanf("%s", e.design);
    printf("Enter Salary:");
    scanf("%d", &e.salary);
    printf("Enter Phone no : ");
    scanf("%llu", &e.phno);
    return e;
}
int main()
{
    EMP e;
    int i, ch, n;
    first = NULL;
    while (1)
    {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.Create a DLL of N Employees Data by using end insertion\n");
        printf("2.Display the status of DLL and count the number of nodes in it\n");
        printf("3.Perform Insertion and Deletion at End of DLL\n");
        printf("4.Perform Insertion and Deletion at Front of DLL\n");
        printf("5.Demonstration of this DLL as Double Ended Queue\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the number of Employees\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("\nEnter the details of Employee %d\n", i);
                e = input();
                addrear(e);
            }
            break;
        case 2:
            if (first == NULL)
            {
                printf("List is Empty\n");
            }
            else
            {
                printf(" Node Count=%d\t & Elements in the list are : \n", count());
                displayList();
            }
            break;
        case 3:
            printf(" 1. Insert at End and 2 Delete From End=");
            scanf("%d", &ch);
            if (ch == 1)
            {
                e = input();
                addrear(e);
            }
            else if (ch == 2)
                deleterear();
            else
                printf(" Sorry wrong operation\n");
            break;
        case 4:
            printf(" 1. Insert at Front and 2 Delete From Front=");
            scanf("%d", &ch);
            if (ch == 1)
            {
                e = input();
                addfront(e);
            }
            else if (ch == 2)
                deletefront();
            else
                printf(" Sorry wrong operation\n");
            break;
        case 5:
            printf("This DLL can be used as Double Ended Queue by inserting and deleting from both ends \n");
            break;
        case 6:
            return 0;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}