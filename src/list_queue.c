#include "list_queue.h"

#include <malloc.h>
#include <stdio.h>

void init_queue(queue *q) {
    // Makes the queue empty
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return;
}

int empty(queue *q) {
    // The queue is empty if the size is 0
    return q->size == 0;
}

void enqueue(queue *q, int x) {
    qnode *new = (qnode *)malloc(sizeof(qnode));  // Make new emptry node
    new->data = x;                                // Assign correct values
    new->next = NULL;
    if (q->size == 0) {  // If the queue is empty the front is the new node
        q->front = new;
    } else {
        q->rear->next = new;
    }
    ++q->size;      // Increment size of queue
    q->rear = new;  // Update the rear of the queue
    return;
}

int dequeue(queue *q) {
    assert(!empty(q));      // Make sure the queue is not empty
    qnode *foo = q->front;  // Save the front node
    int value = foo->data;  // Get the value of the front node
    q->front = foo->next;   // Set a new front of queue
    free(foo);              // Free memory
    --q->size;              // Decrease size
    return value;           // Return value
}
