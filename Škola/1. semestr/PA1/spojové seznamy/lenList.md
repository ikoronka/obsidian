```c
// Délka seznamu.  
size_t length(Node **list) {  
    size_t len = 0;  
    Node * current = * list;  
    while (current) {  
        len++;  
        current = current->next;  
    }  
    return len;  
}
```