#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void printList (Node* n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;

    return;
}

void push (class Node** head, int new_data)
{
    Node* new_head = new Node();

    new_head->data = new_data;
    new_head->next = *head;

    *head = new_head;
    return;
}

void insertAfter ( class Node* prev_node, int new_data)
{

    if (!prev_node)
    {
        cout << "The given previous node is NULL" << endl;
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = prev_node->next;

    prev_node->next = new_node;

    return;
}

void append (class Node** head, int new_data)
{
    Node* new_node = new Node();
    Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (!head)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;

    return;
}

void delete_by_key (class Node** head, int key)
{
    Node* temp = *head;
    Node* prev = new Node();

    // No valid linked list provided
    if (temp == NULL)
    {
        cout << "Povided linked list does not exist" << endl;
        return;
    }

    // head is the target
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // reached the end of the linked list
    if (temp == NULL) return;

    // unlink node from linked list
    prev->next = temp->next;
    delete temp;

    return;
}

void delete_pos (class Node** head, int pos)
{
    // linked list doesn't exist
    if (*head == NULL)
    {    
        cout << "No valid linked list provided" << endl;
        return;
    }

    class Node* temp = *head;
    // position at the head
    if (pos == 0)
    {
        *head = temp->next;
        delete temp;
        return;
    }

    // Find the node just before the provided pos
    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    // reached the end of the linked list before the provided position
    if (temp == NULL || temp->next == NULL)
    {
        cout << "No such position found" << endl;
        return;
    }

    Node* next = temp->next->next;
    delete temp->next;

    temp->next = next;
    return;
}

int main ()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);
    push(&head, 0);
    printList(head);
    append(&head, 5);
    printList(head);
    insertAfter(head->next, 4);
    printList(head);   
    delete_by_key(&head, 4);
    printList(head);
    delete_pos(&head, 3);
    printList(head);

    return 0;
}