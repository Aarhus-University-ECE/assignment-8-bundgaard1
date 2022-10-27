#include <stdio.h>

extern "C" {
// Add the header files required to run your main
#include "insertion_sort.h"
#include "linked_list.h"
#include "list_queue.h"
}

void print_queue(queue q) {
    qnode* p = q.front;
    for (int i = 0; p != NULL; i++) {
        printf("%d, %d\n", i, p->data);

        p = p->next;
    }
}
void test_passed(char test, int passed) {
    printf("Test %c: ", test);
    if (passed) {
        printf("Passed\n");

    } else {
        printf("Failed\n");
    }
}

void queue_test_a() {
    int passed = 1;
    queue q;
    init_queue(&q);
    passed = empty(&q);
    test_passed('A', passed);
    return;
}

void queue_test_b() {
    int passed = 1;
    queue qq;

    init_queue(&qq);
    int x = 3;
    enqueue(&qq, x);
    int y = dequeue(&qq);
    passed = (x == y);

    test_passed('B', passed);
    return;
}

void queue_test_c() {
    int passed = 1;
    queue qqq;

    int x0 = 4;
    int x1 = 3;

    enqueue(&qqq, x0);
    enqueue(&qqq, x1);

    int y0 = dequeue(&qqq);
    int y1 = dequeue(&qqq);

    passed = (passed && x0 == y0 && x1 == y1);

    test_passed('C', passed);
    return;
}
void sort_test() {
    int passed = 1;

    linked_list* LL = createLinkedList();

    insertFront(createNode(40), LL);
    insertFront(createNode(15), LL);
    insertFront(createNode(50), LL);
    insertFront(createNode(20), LL);
    insertFront(createNode(10), LL);
    insertFront(createNode(47), LL);
    insertFront(createNode(50), LL);
    insertFront(createNode(94), LL);
    insertFront(createNode(26), LL);

    sort(LL);

    node_t* n = LL->head;

    while (n != NULL && n->next != NULL && passed) {
        passed = (n->data <= n->next->data);
        n = n->next;
    }

    test_passed('S', passed);
    return;
}

int main(int argc, char** argv) {
    // Test sort
    sort_test();

    // Test queue
    queue_test_a();
    queue_test_b();
    queue_test_c();

    return 0;
}