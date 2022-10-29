#include "insertion_sort.h"

#include <stdio.h>

#include "linked_list.h"

void sort(linked_list* llPtr) {
    node_t* curr = llPtr->head;  // The current node to be inserted correctly
    node_t* next = curr->next;   // The next node to be inserted
    node_t* insert;  // Pointer to the node which curr whould be inserted after

    curr->next = NULL;  // the first node is correct

    // This loop runs for every node in the list
    while (next != NULL) {
        curr = next;  // update the current node to next
        next = curr->next;
        // If curr.data is smaller than head, make curr the new head
        if (curr->data < llPtr->head->data) {
            curr->next = llPtr->head;
            llPtr->head = curr;
        } else {
            // Else find the node which to insert the current node
            insert = llPtr->head;
            while (insert->next != NULL && curr->data > insert->next->data) {
                insert = insert->next;
            }
            // Insert the current node
            curr->next = insert->next;
            insert->next = curr;
        }
    }
}
