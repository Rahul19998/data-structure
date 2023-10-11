// linkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    int data;
    Node *next;
};

void count_of_nodes(Node* node) {
    Node *temp = node;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std:: endl;
}

Node* add_at_end(Node* tail, int num) {
    Node *new_node = new Node();
    new_node->data = num;
    new_node->next = nullptr;
    tail->next = new_node;
    return new_node;
}

void add_at_beg(Node** head, int num) {
    Node* new_node = new Node();
    new_node->data = num;
    new_node->next = *head;
    *head = new_node;
}

void add_at_pos(Node* head, int position, int data) {
    Node* ptr = head;
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    position--;
    while(position!=1) {
        ptr = ptr->next;
        position--;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

Node* delete_at_beg(Node *head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delete_at_end(Node* head) {
    Node* temp2 = head;
    Node* temp = head;
    while(temp->next!=nullptr) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = nullptr;
    free(temp);
    temp = nullptr;
    return head;
}

void del_at_pos(Node* head, int position) {
    // Node* temp2 = head;
    Node *temp = head;
    position-=2;
    while(position != 0) {
        temp = temp->next;
        position--;
    }
    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}

int main()
{
    Node *head = new Node();
    head->data = 45;
    head->next = nullptr;

    Node *tail = add_at_end(head,98);
    tail = add_at_end(tail,3);
    add_at_beg(&head, 4);
    add_at_pos(head, 2, 23);
    auto* new_head = delete_at_beg(head);
    new_head = delete_at_end(new_head);
    del_at_pos(new_head,2);
    Node* ptr = new_head;

    count_of_nodes(ptr);
    return 0;
}
