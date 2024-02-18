```c
// Zkopíruje seznam. Pokud je dest neprázdný, přidá  
// nové hodnoty na jeho konec.  
void dup(Node **dest, Node **src) {  
    Node ** cur = dest;  
    Node * current = *src;  
    while (cur){  
        cur = &(*cur)->next;  
    }  
    while (current){  
        *cur = create_node(current->value);  
        cur = &(*cur)->next;  
        current = current->next;  
    }  
}
```