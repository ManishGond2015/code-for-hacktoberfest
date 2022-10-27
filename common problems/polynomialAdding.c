// Name : Manish Kumar Gond
// Reg. No. = 791     Roll No. = ECE/21131
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *link;
};
struct node *insert(struct node *head, int co, int ex)
{
    struct node *temp = NULL;
    struct node *newp = (struct node *)malloc(sizeof(struct node));
    newp->expo = ex;
    newp->coeff = co;
    newp->link = NULL;
    if (newp == NULL)
    {
        printf("Overflow");
        return NULL;
    }
    if (head == NULL || ex > head->expo)
    {
        newp->link = head;
        head = newp;
    }
    else
    {
        temp = head;
        while(temp->link != NULL && temp->link->expo >= ex)
        {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}
struct node *displayheadpol(struct node *head)
{
    if (head == NULL)
    {
        printf("No Polynomial");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("(%dx^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
    return head;
}
struct node *createheadpol(struct node *head)
{
    int n, i, coeff, expo;
    printf("\nEnter the number of terms:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Coefficient of term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}
struct node *addheadpol(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        if (ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    return head3;
}
int main()
{
    int x;
    struct node *start1 = NULL;
    struct node *start2 = NULL;
    struct node *start3 = NULL;
    printf("Enter Your Choice:");
    while (1)
    {

        printf("\n1.Create first Polynomial");
        printf("\n2.Create second Polynomial");
        printf("\n3.Add Two Polynomials");
        printf("\n4. Exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\n-------------Enter the First Polynomial---------------");
            start1 = createheadpol(start1);
            printf("First polynomial is:\n");
            start1 = displayheadpol(start1);
            break;

        case 2:
            printf("\n-------------Enter the Second Polynomial---------------");
            start2 = createheadpol(start2);
            printf("Second polynomial is:\n");
            start2 = displayheadpol(start2);
            break;
        case 3:
            start3 = addheadpol(start1, start2);
            printf("\n-------------Adding Two Polynomials---------------\n");
            start3 = displayheadpol(start3);
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("Invalid Input");
            break;
        }
    }
}