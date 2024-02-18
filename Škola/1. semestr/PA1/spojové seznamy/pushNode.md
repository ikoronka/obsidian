```c
// Vloží uzel na začátek seznamu, next vkládaného  
// uzlu musí být NULL.  
void push(Node **list, Node *node) {  
    assert(node->next == NULL);  
    node->next = *list;  
    *list = node;  
}
```