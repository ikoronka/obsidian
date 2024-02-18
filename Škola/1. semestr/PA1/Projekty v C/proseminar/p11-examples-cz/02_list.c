#include <stdio.h>
#include <stdlib.h>

/* Seznam hodnot - datova struktura, kde si udrzujeme hodnoty v zadanem poradi.
 * V seznamu si pamatujeme vybranou hodnotu, ukazovatko se muze pohybovat vpred
 * a vzad (Succ/Pred), muzeme cist hodnotu pod ukazovatkem (Read), muzeme vkladat
 * do seznamu (pred a za aktualni prvek) a muzeme mazat aktualni prvek.
 *
 * Impelmentace vyuziva dvojsmerne zretezeneho spoj. seznamu, aby dosahla
 * snadneho pohybu obema smery (vpred/vzad) a aby snadno mohla pridavat/odebirat
 * prvky.
 *
 * V OO reseni by seznam byl tridou a volane funkce metodami.
 *
 */

typedef struct TItem
{
  struct TItem  * m_Next;  /* predchudce a naslednik ve spoj seznamu */
  struct TItem  * m_Prev;
  int             m_Val;   /* ukladana hodnota */
} TITEM;

typedef struct TList
{
  struct TItem  * m_First; /* prvni, posledni prvek seznamu */
  struct TItem  * m_Last;
  struct TItem  * m_Cur;   /* aktualni prvek v seznamu */
} TLIST;
/*---------------------------------------------------------------------------*/
/* Vytvori prazdny seznam.
 */
TLIST            * ListInit      ( void )
{
  TLIST * l;

  l = (TLIST*) malloc ( sizeof ( *l ) );
  l -> m_First = NULL;     /* prazdny seznam - vse NULL */
  l -> m_Last  = NULL;
  l -> m_Cur   = NULL;
  return l;
}
/*---------------------------------------------------------------------------*/
/* Vymaz seznamu vcetne pripadnych prvku v nem obsazenych.
 */
void               ListDone      ( TLIST * l )
{
  TITEM  * tmp;

  while ( l -> m_First )       /* vymaz obsahu */
  {
    tmp = l -> m_First -> m_Next;  /* necteme z jiz uvolnene pameti - zaloha */
    free ( l -> m_First );
    l -> m_First = tmp;
  }
  l -> m_Last  = NULL;
  l -> m_Cur   = NULL;
  free ( l );
}
/*---------------------------------------------------------------------------*/
/* Posun v seznamu: aktualni prvek bude ten o jednu pozici vpred.
 */
int                ListSucc      ( TLIST * l )
{
  if ( ! l -> m_Cur ) return 0;        /* posun vpred, pouze pokud to lze */
  if ( ! l -> m_Cur -> m_Next ) return 0;
  l -> m_Cur = l -> m_Cur -> m_Next;
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Posun v seznamu: aktualni prvek bude ten o jednu pozici vzad.
 */
int                ListPred      ( TLIST * l )
{
  if ( ! l -> m_Cur ) return 0;       /* posun vzad, pokud lze */
  if ( ! l -> m_Cur -> m_Prev ) return 0;
  l -> m_Cur = l -> m_Cur -> m_Prev;
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Vlozeni do seznamu za aktualni prvek. Vyjimka je prazdny seznam, kdy proste
 * prvek vlozime.
 */
int                ListInsAfter  ( TLIST * l, int val )
{
  TITEM * n;

  n = (TITEM *) malloc ( sizeof ( *n ) );
  if ( ! n ) return 0;
  
  n -> m_Val  = val;
  n -> m_Prev = n -> m_Next = NULL;

  if ( ! l -> m_Cur )     /* prazdny seznam = prvni je posleni je vybrany */
   {
     l -> m_First =
     l -> m_Last  =
     l -> m_Cur   = n;
     return 1;
   }

  n -> m_Prev = l -> m_Cur;       /* preruseni spoju, vlozeni n */
  n -> m_Next = l -> m_Cur -> m_Next;
  l -> m_Cur -> m_Next = n;

  if ( n -> m_Next )               /* aktualni prvek nebyl posledni */
    n -> m_Next -> m_Prev = n;
  else               /* aktualni byl posledni, vlozeny za bude novy psledni */
    l -> m_Last = n;

  return 1;
}
/*---------------------------------------------------------------------------*/
/* Vlozeni do seznamu pred aktualni prvek. Vyjimka je prazdny seznam, kdy proste
 * prvek vlozime.
 */
int                ListInsBefore  ( TLIST * l, int val )
{
  TITEM * n;

  n = (TITEM *) malloc ( sizeof ( *n ) );
  if ( ! n ) return 0;
  
  n -> m_Val  = val;
  n -> m_Prev = n -> m_Next = NULL;

  if ( ! l -> m_Cur )  /* prazdny seznam */
   {
     l -> m_First =
     l -> m_Last  =
     l -> m_Cur   = n;
     return 1;
   }

  n -> m_Next = l -> m_Cur;     /* napojeni linku */
  n -> m_Prev = l -> m_Cur -> m_Prev;
  l -> m_Cur -> m_Prev = n;

  if ( n -> m_Prev )   /* nebyl prvni -> upravime odkaz z predchudce. */
    n -> m_Prev -> m_Next = n;
  else                 /* vkladame pred prvni prvek -> upravime odkaz m_First */
    l -> m_First = n;

  return 1;
}
/*---------------------------------------------------------------------------*/
/* Cteni hodnoty z aktualni pozice.
 */
int                ListRead       ( TLIST * l, int * x )
{
  if ( ! l -> m_Cur ) return 0;
 *x = l -> m_Cur -> m_Val;
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Vymaz prvku na aktualni pozici.
 */
int                ListDel        ( TLIST * l )
{
  TITEM  * tmp;

  tmp = l -> m_Cur;

  if ( ! tmp ) return 0;

  if ( tmp -> m_Prev )       /* aktualni nebyl prvni */
    tmp -> m_Prev -> m_Next = tmp -> m_Next;
  else                     /* byl prvni, opravit v L */
    l -> m_First = tmp -> m_Next;

  if ( tmp -> m_Next )       /* aktualn nebyl posledni */
    tmp -> m_Next -> m_Prev = tmp -> m_Prev;
  else                     /* byl posleni, opravit v L */
    l -> m_Last = tmp -> m_Prev;

  /* ktery bude aktualni po vymazu? */
  if ( tmp -> m_Next )      /* naslednik, je-li */
    l -> m_Cur = tmp -> m_Next;
  else                   /* jinak predchudce */
    l -> m_Cur = tmp -> m_Prev;
  /* pokud oba byli NULL, pak je seznam prazdny a Cur bude take NULL, coz je ok */
  free ( tmp );
  return 1;
}
/*---------------------------------------------------------------------------*/
int main ( int argc, char * argv [] )
{
  TLIST   * l;
  int       val;

  l = ListInit ( );

  ListInsAfter ( l, 20 );
  ListInsBefore ( l, 10 );
  ListInsAfter ( l, 30 );

  ListPred ( l );
  while ( 1 )
  {
    ListRead ( l, &val );
    printf ( "%d\n", val );
    if ( ! ListSucc ( l ) ) break;
  }

  ListDel ( l );

  while ( 1 )
  {
    ListRead ( l, &val );
    printf ( "%d\n", val );
    if ( ! ListPred ( l ) ) break;
  }

  ListDone ( l );
  return 0;
}
