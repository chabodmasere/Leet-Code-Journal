#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
#include <iostream>

/**
 * Definition for singly-linked list.
 * This is the standard ListNode structure used in LeetCode problems.
 */
struct ListNode {
    int val;
    ListNode *next;
    
    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Helper function to create a linked list from an array
 * Usage: ListNode* head = createList({1, 2, 3, 4, 5});
 */
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

/**
 * Helper function to print a linked list
 * Usage: printList(head);
 */
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

/**
 * Helper function to delete a linked list (free memory)
 * Usage: deleteList(head);
 */
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Helper function to get the length of a linked list
 * Usage: int len = getLength(head);
 */
int getLength(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

#endif // LISTNODE_H
