#include <stdlib.h>
#include <stdio.h>


/* Fronta - datova struktura.
 *
 * Tato implementace pouziva spojovy seznam jako uloziste pro data ve fronte.
 * Vyhodou je, ze spoj. seznam lze bez omezeni natahovat (do kapacity pameti),
 * vlozeni/odebrani prvku ma minimalni casovou rezii.
 */

typedef struct TItem
{
  struct TItem    * m_Next;
  int               m_Val;
} TITEM;

typedef struct TQueue
{
  TITEM           * m_Head;
  TITEM           * m_Tail;
} TQUEUE;

/*---------------------------------------------------------------------------*/
/* Inicializace struktury fronty.
 */
TQUEUE  *          QueueInit  ( void )
{
  TQUEUE * q;

  q = (TQUEUE *) malloc ( sizeof ( *q ) );

  q -> m_Head = NULL;
  q -> m_Tail = NULL;
  return q;
}
/*---------------------------------------------------------------------------*/
/* Uvolneni alokovanych prostredku - zde pameti.
 */
void               QueueDone  ( TQUEUE  * q )
{
  TITEM  * tmp;

  while ( q -> m_Head )
   {
     tmp = q -> m_Head -> m_Next;   /* ulozit kopii ... */
     free  ( q -> m_Head );
     q -> m_Head = tmp;           /* ... abychom z uvolnene pameti jiz necetli */
   }
  q -> m_Tail = NULL;
  free ( q );
}
/*---------------------------------------------------------------------------*/
/* Vlozeni prvku do fronty. Vlozeni selze, pokud selze alokace prvku.
 * Selani je predavanao v navratove hodnoce (0 = chyba, 1 = ok)
 * Vkladame na konec spojoveho seznamu, vyuzivame ukazatele m_Tail.
 */
int                QueuePut   ( TQUEUE * q, int x )
{
  TITEM * n;

  n = (TITEM * ) malloc ( sizeof ( *n ) );
  if ( ! n ) return 0;
  n -> m_Val  = x;
  n -> m_Next = NULL;

  if ( q -> m_Tail )        /* pokud je jiz ve fornte nejaky prvek - pridame za posledni */
    q -> m_Tail -> m_Next = n;
  else                      /* prazdna fronta = posledni prvek je zaroven i prvni */
    q -> m_Head = n;
  q -> m_Tail = n;          /* nove vlozeny je urcite posledni */
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Cteni prvku z fronty. Cteni selze, pokud je fronta prazdna.
 * Selani je predavanao v navratove hodnoce (0 = chyba, 1 = ok)
 */
int                QueueGet   ( TQUEUE * q, int * x )
{
  TITEM * tmp;
  
  if ( ! q -> m_Head ) return 0;
 *x = q -> m_Head -> m_Val;
  tmp = q -> m_Head -> m_Next;  /* opet kopie, abychom necetli z jiz uvolnene pameti */
  free ( q -> m_Head );
  q -> m_Head = tmp;
  if ( ! tmp )
    q -> m_Tail = NULL;         /* prazdna fronta - upravime i ukazatel na posledni prvek */
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Test prazdnosti fronty.
 */
int                QueueIsEmpty ( TQUEUE * q )
{
  return q -> m_Head == NULL;
}
/*---------------------------------------------------------------------------*/
/* Zakladni a ne prilis dukladny test struktury.
 */
int main ( int argc, char * argv [] )
{
  TQUEUE * q;
  int val;

  q = QueueInit ( );

  QueuePut ( q, 10 );
  QueuePut ( q, 20 );
  QueuePut ( q, 30 );
  QueuePut ( q, 40 );
  QueuePut ( q, 50 );
  QueuePut ( q, 60 );

  QueueGet ( q, &val );
  printf ( "read: %d\n", val );

  QueuePut ( q, 70 );
  
  while ( ! QueueIsEmpty ( q ) )
  {
    QueueGet ( q, &val );
    printf ( "read: %d\n", val );
  }
  QueueDone ( q );
  return 0;
}
