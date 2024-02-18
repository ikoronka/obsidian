```c
// Funkce pro obrácení spojového seznamu. Přijímá dvojitý pointer na hlavu seznamu,
// což umožňuje měnit, na co hlavní pointer ukazuje.
void reverse(Node **list) {
  // Inicializuje pointer `prev` na NULL. Tento pointer bude sledovat předchozí uzel,
  // když budeme procházet seznamem. Na začátku není žádný předchozí uzel, proto je `NULL`.
  Node *prev = NULL;

  // Inicializuje pointer `current` na první uzel v seznamu. Tento pointer bude
  // použit k procházení seznamem od začátku do konce.
  Node *current = *list;

  // Inicializuje pointer `next` na NULL. Tento pointer bude použit k dočasnému
  // ukládání následujícího uzlu, abychom při procházení seznamem neztratili jeho referenci.
  Node *next = NULL;

  // Tento cyklus se opakuje, dokud `current` není NULL, což znamená, dokud jsme na konci seznamu.
  while (current) {
    // Uloží pointer na následující uzel do `next`. To nám umožní posunout se vpřed
    // v seznamu bez ztráty referencí na uzly.
    next = current->next;

    // Mění `next` pointer aktuálního uzlu tak, aby ukazoval na předchozí uzel.
    // Při první iteraci toto nastaví `next` prvního uzlu na NULL, což je správně,
    // protože po obrácení seznamu bude první uzel posledním.
    current->next = prev;

    // Posune `prev` na aktuální uzel, připraví jej na další iteraci jako "předchozí uzel"
    // pro následující uzel v seznamu.
    prev = current;

    // Posune `current` na následující uzel v seznamu, který jsme dočasně uložili do `next`.
    // To nás posune vpřed v seznamu.
    current = next;
  }

  // Po dokončení cyklu je celý seznam obrácený a `prev` ukazuje na novou hlavu seznamu.
  // Nastavíme hlavní pointer seznamu (`list`) na `prev`, čímž aktualizujeme hlavu seznamu.
  *list = prev;
}

```