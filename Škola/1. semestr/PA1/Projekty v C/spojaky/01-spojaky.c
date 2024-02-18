#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LEVEL 0

typedef int T;

typedef struct Node Node;
struct Node {
  Node *next;
  T value;
};

// Vytvoří nový uzel s danou hodnotou, next nastaví
// na NULL.
Node *create_node(T value) {
  // TODO
}

// Smaže uzel, next musí být NULL.
void free_node(Node *node) {
  assert(node != NULL && node->next == NULL);
  free(node);
}

// Odebere uzel ze začátku seznamu a vrátího.
// Vrácenénu uzlu nastaví next na NULL.
Node *pop(Node **list) {
  assert(*list);
  // TODO
  assert(false);
}

// Smaže celý seznam.
void destroy_list(Node **list) {
  // TODO
  assert(false);
}

// Délka seznamu.
size_t length(Node **list) {
  // TODO
  assert(false);
}

// Vloží uzel na začátek seznamu, next vkládaného
// uzlu musí být NULL.
void push(Node **list, Node *node) {
  // TODO
  assert(false);
}

// Vloží uzel na konec seznamu. Vrátí ukazatel
// na konec seznamu.
Node** push_back(Node **list, Node *node) {
  // TODO
  assert(false);
}

// Zkopíruje seznam. Pokud je dest neprázdný, přidá
// nové hodnoty na jeho konec.
void dup(Node **dest, Node **src) {
  // TODO
  assert(false);
}

// Nalezne maximální prvek.
Node **max(Node **list) {
  // TODO
  assert(false);
}

// Nalezne první prvek s danou hodnotou.
Node **find(Node **list, T x) {
  // TODO
  assert(false);
}

// Vrátí i-tý prvek číslováno od 0. Pokud je
// i větší než délka seznamu, vrátí ukazatel
// na NULL na konci seznamu.
Node **at(Node **list, size_t i) {
  // TODO
  assert(false);
}

// Prohodí dva seznamy.
void swap(Node **a, Node **b) {
  // TODO
  assert(false);
}

// Otočí seznam.
void reverse(Node **list) {
  // TODO
  assert(false);
}

void print(Node **list) {
  for (Node *n = *list; n; n = n->next)
    printf("%d%s", n->value, n->next ? " -> " : "\n");
}

int main() {
  Node *a = NULL, *b = NULL;

  // Push & create_node
# if LEVEL >= 1
  push(&a, create_node(1));
  push(&a, create_node(2));
  push(&a, create_node(3));
  push(&a, create_node(4));

  // 4 -> 3 -> 2 -> 1
  print(&a);
# endif

  // at & length
#if LEVEL >= 3
  assert(length(&a) == 4);
  assert(at(&a, 0)[0]->value == 4);
  assert(at(&a, 1)[0]->value == 3);
  assert(at(&a, 2)[0]->value == 2);
  assert(at(&a, 3)[0]->value == 1);
  assert(at(&a, 4)[0] == NULL);
# endif

  // reverse
# if LEVEL >= 4
  reverse(&a);
  // 1 -> 2 -> 3 -> 4
  print(&a);
# endif

  // pop
# if LEVEL >= 5
  push(&b, pop(&a));
  push(&b, pop(&a));

  // 3 -> 4
  print(&a);
  // 2 -> 1
  print(&b);

  while (b) push(&a, pop(&b));
  assert(length(&a) == 4);
# endif

  // dup
# if LEVEL >= 10
  dup(&b, &a);
  // 1 -> 2 -> 3 -> 4
  print(&a);
  // 1 -> 2 -> 3 -> 4
  print(&b);
  assert(length(&a) == 4);
  assert(length(&b) == 4);
# endif

  // Pomalý push_back
# if LEVEL >= 6
  int values[] = { 165, 552, 460, 913, 7, 225, 456, 267, 802, 764 };
  for (size_t i = 0; i < sizeof(values)/sizeof(*values); i++)
    push_back(&a, create_node(values[i]));

  assert(at(&a, 0)[0]->value == 1);
  assert(at(&a, 11)[0]->value == 267);
# endif

  // find
# if LEVEL >= 8
  free_node(pop(find(&a, 913)));
  assert(length(&a) == 13);
# endif

  // max & swap
# if LEVEL >= 9
  assert(max(&a)[0]->value == 802);
  {
    Node *tmp = NULL;
    swap(max(&a), &tmp);
    assert(length(&a) == 11);
    assert(length(&tmp) == 2);
    destroy_list(&tmp);
  }
# endif

  // Rychlý push_back
# if LEVEL >= 7
  {
    Node **end = &a;
    for (int i = 0; i < 1'000'000; i++)
      end = push_back(end, create_node(i));
  }
# endif

  // Příliš velká data pro rekurzivní implementaci
# if LEVEL >= 999
  for (int i = 0; i < 10'000'000; i++) push(&a, create_node(i));
  reverse(&a);
  
  assert(at(&a, 3)[0]->value == 999'996);
  printf("at(&a, %d) = %d\n", 3, at(&a, 3)[0]->value);
  
  assert(max(&a)[0]->value == 9'999'999);
  printf("max: %d\n", max(&a)[0]->value);

  assert(length(&a) == 11'000'011);
  printf("lenght: %zu\n", length(&a));
# endif

# if LEVEL >= 2
  destroy_list(&b);
  destroy_list(&a);
# endif

  printf("Level %d completed!\n", LEVEL);
}

