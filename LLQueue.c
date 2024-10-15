#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} qw;

// Create a node
qw *getnode()
{
    qw *a;
    a = (qw *)malloc(sizeof(qw));

    if (a == NULL)
    {
        printf("Memory Allocating Failed.\n");
        return NULL;
    }
    else
    {
        a->next = NULL;
        a->prev = NULL;
        return a;
    }
}

// Check if the queue is empty
int isEmpty(qw *front)
{
    return front == NULL;
}

// Enqueue function
void enque(qw **front, qw **rear, int x)
{
    qw *temp = getnode();
    if (temp == NULL)
        return;

    temp->data = x;

    if (*front == NULL)
    {
        *front = temp;
        *rear = temp;
    }
    else
    {
        (*rear)->next = temp;
        temp->prev = *rear;
        *rear = temp;
    }

    printf("Enqued : %d\n", x);
}

// Dequeue function
int dequeue(qw **front, qw **rear)
{
    if (isEmpty(*front))
    {
        return -1;
    }
    else
    {
        qw *temp = *front;
        int x = temp->data;

        if (*front == *rear)
        {
            *front = NULL;
            *rear = NULL;
        }
        else
        {
            *front = (*front)->next;
            (*front)->prev = NULL;
        }

        free(temp);
        return x;
    }
}

void PrintQueue(qw *front, qw *rear)
{
    if (isEmpty(front))
    {
        printf("Queue Is Empty\n");
    }

    else if (front == rear)
    {
        printf("%d <--- Front\\Rear\n", front->data);
    }

    else
    {
        printf("%d <--- Front\n", front->data);
        front = front->next;
        while (front != rear)
        {
            printf("%d\n", front->data);
            front = front->next;
        }

        printf("%d <--- Rear\n", rear->data);
    }
}

int main() {
    qw *front = NULL;
    qw *rear = NULL;

    enque(&front, &rear, 10);
    enque(&front, &rear, 20);
    enque(&front, &rear, 30);
    enque(&front, &rear, 40);


    printf("Queue after enqueuing 10, 20, 30, 40:\n");
    PrintQueue(front, rear);

   
    printf("\nDequeued: %d\n", dequeue(&front, &rear)); 
    printf("\nQueue after dequeuing:\n");
    PrintQueue(front, rear);

    printf("\nDequeued: %d\n", dequeue(&front, &rear));
    printf("\nQueue after dequeuing:\n");
    PrintQueue(front, rear);

    printf("\nDequeued: %d\n", dequeue(&front, &rear)); 
    printf("\nQueue after dequeuing:\n");
    PrintQueue(front, rear);

    printf("\nDequeued: %d\n", dequeue(&front, &rear)); 
    printf("\nQueue after dequeuing:\n");
    PrintQueue(front, rear);

  
    int result = dequeue(&front, &rear);
    if (result == -1) {
        printf("\nQueue is empty. Dequeue failed.\n");
    } else {
        printf("Dequeued: %d\n", result);
    }

    return 0;
}