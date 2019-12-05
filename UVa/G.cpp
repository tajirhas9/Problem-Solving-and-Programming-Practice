Node* Reverse(Node *head)
{
    Node *prev   = NULL;
    Node *current = head;
    Node *next;
    while (current != NULL) {
        next = current -> next;  
        current -> next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
