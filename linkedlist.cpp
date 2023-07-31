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
}

Node* add_at_end(Node* tail, int num) {
    Node *new_node = new Node();
    new_node->data = num;
    new_node->next = nullptr;
    tail->next = new_node;
    return new_node;
}

Node* add_at_beg(Node* head, int num) {
    Node* new_node = new Node();
    new_node->data = num;
    new_node->next = head;
    head = new_node;
    return head;
}

int main()
{
    Node *head = new Node();
    head->data = 45;
    head->next = nullptr;

    Node *tail = add_at_end(head,98);
    tail = add_at_end(tail,3);
    head = add_at_beg(head, 4);

    count_of_nodes(head);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
