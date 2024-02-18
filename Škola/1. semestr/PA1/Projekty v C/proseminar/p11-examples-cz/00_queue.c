#include <stdlib.h>
#include <stdio.h>



/* Fronta - datova struktura.
 * Tato implementace pouziva pole jako uloziste pro data ve fronte. Nevyhodou je,
 * ze max. velikost pole je omezena. Pripadne "natahovani" je mozne, ale za cenu
 * kopirovani rel. velkeho objemu dat.
 */

typedef struct TQueue
{
  int       m_Len;  /* kolik prvku je ve fronte */
  int       m_Max;  /* maximum prvku ve fronte */
  int       m_Rd;   /* cteci pozice */
  int       m_Wr;   /* zapisova pozice */
  int     * m_Data; /* kam se ukladaji data */
} TQUEUE;
/*---------------------------------------------------------------------------*/
/* Inicializace struktury fronty.
 */
TQUEUE           * QueueInit  ( int max )
{
  TQUEUE * q;

  q = (TQUEUE *) malloc ( sizeof ( *q ) );
  q -> m_Len = 0;
  q -> m_Max = max;
  q -> m_Rd  = 0;
  q -> m_Wr  = 0;
  q -> m_Data = (int *) malloc ( max * sizeof ( *q -> m_Data ) );
  return q;
}
/*---------------------------------------------------------------------------*/
/* Uvolneni alokovanych prostredku - zde pameti.
 */
void               QueueDone  ( TQUEUE  * q )
{
  free ( q -> m_Data );
  q -> m_Data = NULL;
  free ( q );
}
/*---------------------------------------------------------------------------*/
/* Vlozeni prvku do fronty. Vlozeni selze, pokud je fronta plna.
 * Selani je predavanao v navratove hodnoce (0 = chyba, 1 = ok)
 * Operace modulo zajistuje prechod z konce na zacatek bufferu.
 */
int                QueuePut   ( TQUEUE * q, int x )
{
  if ( q -> m_Len >= q -> m_Max ) return 0;
  q -> m_Data [ q -> m_Wr ] = x;
  q -> m_Wr = ( q -> m_Wr + 1 ) % q -> m_Max;
  q -> m_Len ++;
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Cteni prvku z fronty. Cteni selze, pokud je fronta prazdna.
 * Selani je predavanao v navratove hodnoce (0 = chyba, 1 = ok)
 */
int                QueueGet   ( TQUEUE * q, int * x )
{
  if ( ! q -> m_Len ) return 0;
 *x = q -> m_Data [q -> m_Rd ];
  q -> m_Rd = ( q -> m_Rd + 1 ) % q -> m_Max;
  q -> m_Len --;
  return 1;
}
/*---------------------------------------------------------------------------*/
/* Test prazdnosti fronty.
 */
int                QueueIsEmpty ( TQUEUE * q )
{
  return q -> m_Len == 0;
}
/*---------------------------------------------------------------------------*/
/* Zakladni a ne prilis dukladny test struktury.
 */
int main ( int argc, char * argv [] )
{
  TQUEUE * q;
  int val;

  q = QueueInit ( 5 );

  QueuePut ( q, 10 );
  QueuePut ( q, 20 );
  QueuePut ( q, 30 );
  QueuePut ( q, 40 );
  QueuePut ( q, 50 );
  QueuePut ( q, 60 ); /* pro kapacitu 5 prvku se jiz nevejde */

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
 
