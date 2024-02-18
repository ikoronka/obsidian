všechny funkce - [[0 Index funkcí spojové seznamy]]
### Základy spojových seznamů

- **Spojový seznam** je datová struktura složená z uzlů, kde každý uzel obsahuje data a ukazatel na další uzel v seznamu.
- Poslední uzel seznamu ukazuje na `NULL`, což značí konec seznamu.

### Pointery a dvojité pointery

- **Pointer** je proměnná, která uchovává adresu paměti jiné proměnné nebo objektu.
- **Dvojitý pointer** (např. `Node **list`) je pointer na pointer, což umožňuje měnit, kam vnější pointer ukazuje.

### Práce s uzly

- **Vytvoření uzlu**: Uzel je typicky definován jako struktura s alespoň dvěma členy: datovým polem a pointerem na další uzel.
    
    ```c 
    typedef struct Node {     
	    int value;      // Data uzlu     
	    struct Node *next; // Ukazatel na další uzel
	} Node;
    ```
    
- **Inicializace uzlu**: Uzel lze vytvořit dynamicky pomocí `malloc` a inicializovat jeho hodnoty.
    
    ```c
    Node *create_node(int value) {
	    Node *newNode = malloc(sizeof(Node));
	    newNode->value = value;
	    newNode->next = NULL;
	    return newNode; 
	}
    ```
    

### Manipulace se seznamem

- **Přidání uzlu na začátek**: Použijeme `*list` k manipulaci s daty nebo ukazateli v prvním uzlu, aniž bychom měnili hlavu seznamu.
    
    cCopy code
    
    ```c
    void push(Node **list, Node *node) {     
	    node->next = *list;     
	    *list = node; 
	}
    ```

    
- **Přidání uzlu na konec**: Použijeme `**list` k procházení seznamem a přidání nového uzlu, což může zahrnovat změnu hlavy seznamu.
    
    ```c
    void push_back(Node **list, Node *newNode) {     
	    Node **cur = list;     
		    while (*cur) {         
			    cur = &(*cur)->next;     
			}     
		*cur = newNode; 
	}
    ```
    
- **Obrácení seznamu**: Ukazuje, jak lze změnit směr ukazatelů mezi uzly, efektivně obrátit pořadí uzlů v seznamu.
    
    ```c
	void reverse(Node **list) {     
		Node *prev = NULL, *current = *list, *next = NULL;     
		while (current) {         
			next = current->next;         
			current->next = prev;         
			prev = current;         
			current = next;     
		}     
		*list = prev; 
	}
	```
    

### Důležité koncepty

- **Dereferencování pointeru**: Získání hodnoty nebo objektu, na který pointer ukazuje, pomocí operátoru `*`.
- **Změna ukazatele**: Změna, kam pointer ukazuje, což může být provedeno pomocí dvojitého pointeru.
- **Procházení seznamu**: Iterace přes uzly v seznamu pomocí `while` cyklu a postupného posouvání pointeru `current`.