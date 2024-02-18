```c
// Prohodí dva seznamy.  
void swap(Node **a, Node **b) {  
    Node * tmp = b;  
    *b = *a;  
    *a = tmp;  
}
```
- pozor na pointery, jinak se změna neprojeví mimo funkci