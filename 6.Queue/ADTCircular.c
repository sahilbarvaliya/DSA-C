#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int Front;
    int Rear;
    int *Q;
};

int isEmpty(struct Queue q)
{
    return q.Front == q.Rear;
}

int isFull(struct Queue q)
{
    return (q.Rear + 1) % q.size == q.Front;
}

void enqueue(struct Queue *q, int x)
{
    if (isFull(*q))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->Rear = (q->Rear + 1) % q->size;
        q->Q[q->Rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    if (isEmpty(*q))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        q->Front = (q->Front + 1) % q->size;
        return q->Q[q->Front];
    }
    return -1;
}

void Display(struct Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    int i = q.Front + 1;

    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i!=(q.Rear+1)%q.size);
    


    printf("\n");
}

int main()
{

    struct Queue q;
    q.size = 5;
    q.Front = q.Rear = 0;
    q.Q = (int *)malloc(q.size * sizeof(int));

    // Inserting elements in Queue
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    Display(q);

    // Deleting elements from Queue
    printf("\ndelete %d \n", dequeue(&q));
    printf("\ndelete %d \n", dequeue(&q));
    enqueue(&q, 50);
    enqueue(&q, 60);
    Display(q);

    return 0;
}
