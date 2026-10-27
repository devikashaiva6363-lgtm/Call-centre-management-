/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int customer)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full!\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = customer;
        printf("Customer %d added to queue.\n", customer);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("No customers waiting.\n");
    }
    else
    {
        printf("Customer %d is being served.\n",
               queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Waiting customers: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    int choice, customer = 1;

    while (1)
    {
        printf("\n--- Call Centre Management ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue(customer++);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}