```c
// Smaže celý seznam.  
void destroy_list(Node **list) {  
    while (*list) {  
        Node *temp = *list;  
        *list = (*list)->next;  
        temp->next = NULL;  
        free_node(temp);  
    }  
}
```