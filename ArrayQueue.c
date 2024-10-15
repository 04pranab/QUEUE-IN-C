#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{

    int front;
    int rear;
    unsigned capacity;
    int *array;
} qw;


// initialize the a queue

qw *createQW(unsigned capacity)
{
    qw *queue = (qw *)malloc(sizeof(qw));
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(qw *queue)
{
    return (queue->front == -1);
}

int isFull(qw *queue)
{
    if (queue->front == queue->rear && queue->front != -1 && queue->rear != -1)
    {
        return 1;
    }

    else if (queue->front == (queue->rear - 1))
    {
        return 1;
    }

    else if (queue->front == 0 && queue->rear == (queue->capacity) - 1)

    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void Enqueue(qw *queue, int x)
{
    if (isFull(queue))
    {
        printf("Queue is full.\n");
    } 

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->array[queue->rear] = x;

    printf("Enqueued : %d\n", x);
}

int Dequeue(qw *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty.\n");
    }

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
        
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
}

void displayQueue(qw *queue) {
    if (isEmpty(queue)){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue elements are: \n");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("%d\n", queue->array[queue->rear]);
}

int main() {
    qw *queue = createQW(5);  // Create a queue with a capacity of 5

    Enqueue(queue, 10);
    Enqueue(queue, 20);
    Enqueue(queue, 30);
    Enqueue(queue, 40);
    Enqueue(queue, 50);

    displayQueue(queue);

    Dequeue(queue);
    Dequeue(queue);

    displayQueue(queue);

    Enqueue(queue, 60);
    Enqueue(queue, 70);

    displayQueue(queue);

    return 0;
}