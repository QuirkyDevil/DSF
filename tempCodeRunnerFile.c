void deletion(){
    struct node *temp;
    temp = head->next;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp;
}