#include "insertion_sort.h"

#include <stdio.h>

#include "linked_list.h"

void sort(linked_list* llPtr) {
    linked_list* sorted = createLinkedList();  // Create the sorted list
    node_t* p_curr =
        llPtr->head;  // Keeps track of the current node in the usorted list
    node_t* curr;     // The current node to be inserted in the sorted list
    while (p_curr != NULL) {  // While we have not reached the end of the list
        curr = createNode(p_curr->data);  // Make a new node
        insertFront(curr, sorted);        // Place in the front
        // Swap the nodes while the curr.data is larger than the next
        while (curr->next != NULL && curr->data > curr->next->data) {
            int temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
            curr = curr->next;
        }

        // Get the next node from unsorted list
        p_curr = p_curr->next;
    }

    // Make the head of the list the sorted list
    llPtr->head = sorted->head;

    return;
}
