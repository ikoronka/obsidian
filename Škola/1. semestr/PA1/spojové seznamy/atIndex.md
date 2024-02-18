```c
// Vrátí i-tý prvek číslováno od 0. Pokud je  
// i větší než délka seznamu, vrátí ukazatel  
// na NULL na konci seznamu.  
Node **at(Node **list, size_t i) {  
    size_t myIdx = 0;  
    Node **cur = list;  
  
    while (*cur && myIdx < i){  
        myIdx++;  
        cur = &(*cur)->next;  
    }  
      
    return cur;  
}
```