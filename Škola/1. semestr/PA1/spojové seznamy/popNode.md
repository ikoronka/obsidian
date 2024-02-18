```c
// Deklarace funkce `pop`, která přijímá dvojitý ukazatel na první uzel spojového seznamu.
Node *pop(Node **list) {
    // Deklarace ukazatele `node` typu `Node*` a jeho inicializace na první uzel v seznamu.
    Node *node = *list;

    // Nastavení ukazatele na první uzel seznamu na druhý uzel v seznamu, čímž se efektivně odstraní první uzel ze seznamu.
    *list = node->next;

    // Nastavení ukazatele `next` odstraněného uzlu na NULL, čímž se uzel odpojí od zbytku seznamu.
    node->next = NULL;

    // Vrácení ukazatele na odstraněný uzel.
    return node;
}

```