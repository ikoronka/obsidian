```c
Node *create_node(T value) {  
    Node *node = (Node*)malloc(sizeof(Node));;  
    node->value = value;  
    node->next = NULL;  
    return node;  
}
```
- nesmí se zapomenout na alokaci \*node