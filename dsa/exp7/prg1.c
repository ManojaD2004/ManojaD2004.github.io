#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char usn[11];
    char name[25];
    int sem;
    char branch[5];
    unsigned long long phno;
};
typedef struct student STUD;
struct node
{
    char usn[11];
    char name[25];
    int sem;
    char branch[5];
    unsigned long long phno;
    struct node *next;
};
typedef struct node NODE;
NODE *first;
NODE *copyNode(STUD s)
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        strcpy(temp->usn, s.usn);
        strcpy(temp->name, s.name);
        strcpy(temp->branch, s.branch);
        temp->sem = s.sem;
        temp->phno = s.phno;
        temp->next = NULL;
        return temp;
    }
}
void addrear(STUD s)
{
    NODE *temp, *cur;
    temp = copyNode(s);
    if (first == NULL)
    {
        temp = first;
        return;
    }
    cur = first;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    return;
}
void addfront(STUD s)
{
    NODE *temp;
    temp = copyNode(s); // ssn,name, dept, design,salary, pno);
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
    return;
}
void display(NODE *temp)
{
    printf("%s \t", temp->usn);
    printf("%s \t", temp->name);
    printf("%s \t", temp->branch);
    printf("%d \t", temp->sem);
    printf("%llu \n", temp->phno);
}
void deletefront()
{
    NODE *temp;
    int num;
    temp = first;
    if (first == NULL)
    {
        printf("List is Empty");
        return;
    }
    if (first->next == NULL)
        first = NULL;
    else
    {
        first = first->next;
    }
    printf("Deleted Node is:\n");
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
        printf("List is Empty");
        return;
    }
    if (first->next == NULL)
    {
        display(cur);
        first = NULL;
        free(cur);
        return;
    }
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    printf("Deleted Node is:\n");
    display(cur);
    free(cur);
    return;
}
void displayList()
{
    NODE *r;
    r = first;
    printf("USN\tName\tBrh\tSem\tPhone\n");
    if (r == NULL)
        return;
    while (r != NULL)
    {
        display(r);
        r = r->next;
    }
    printf("\n");
}
STUD input()
{
    STUD s;
    printf("Enter USN: ");
    scanf("%s", s.usn);
    printf("Enter Name : ");
    scanf("%s", s.name);
    printf("Enter Branch: ");
    scanf("%s", s.branch);
    printf("Enter Sem:");
    scanf("%d", &s.sem);
    printf("Enter Phone no : ");
    scanf("%llu", &s.phno);
    return s;
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
int main()
{
    STUD s;
    int i, ch, n;
    first = NULL;
    while (1)
    {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.Create List of n students by using front Insert\n");
        printf("2.Display the status and count the nodes\n");
        printf("3.Perform Insertion and Deletion at End of SLL\n");
        printf("4.Perform Insertion and Deletion at Front of SLL\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter the number of students\n");
            scanf("%d", &n);
            for (i = 1; i <= n; i++)
            {
                printf("\nEnter the details of student %d\n", i);
                s = input();
                addfront(s);
            }
            break;
        case 2:
            if (first == NULL)
            {
                printf("List is Empty\n");
            }
            else
                printf(" Node Count=%d\t & Elements in the list are : \n", count());
            displayList();

            break;
        case 3:
            printf(" 1. Insert at End and 2 Delete From End=");
            scanf("%d", &ch);
            if (ch == 1)
            {
                s = input();
                addrear(s);
            }
            else if (ch == 2)
                deleterear();
            else
                printf(" Sorry wrong operation\n");
            break;
        case 4:
            printf(" 1. Insert at Front and 2.Delete From Front=");
            scanf("%d", &ch);
            if (ch == 1)
            {
                s = input();
                addfront(s);
            }
            else if (ch == 2)
                deletefront();
            else
                printf(" Sorry wrong operation\n");
        case 5:
            exit(0);
        default:
            printf("Invalid option\n");
        }
    }
}