```c
// Nalezne maximální prvek.  
Node **max(Node **list) {  
    Node ** cur = list;  
    Node ** max = cur;  
  
    while (cur){  
        if ((*cur)->value > (*max)->value){  
            max = cur;  
        }  
        cur = &(*cur)->next;  
    }  
  
    return max;  
}
```