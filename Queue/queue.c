        #include "queue.h"
        #include "fatal.h"
        #include <stdlib.h>

        #define MinQueueSize ( 5 )

struct Node
{
	ElementType_list Element;
	Position    Next;
};

        struct QueueRecord
        {
            int Capacity;
			List Front;
			List Rear;
			List START;
			List LAST;
            int Size;
        };
		
/* START: fig3_58.txt */
        int
        IsEmpty( Queue Q )
        {
            return Q->Size == 0;
        }
/* END */

        int
        IsFull( Queue Q )
        {
            return Q->Size == Q->Capacity;
        }

        Queue
        CreateQueue( int MaxElements )
        {
            Queue Q;
			int i = 0;

/* 1*/      if( MaxElements < MinQueueSize )
/* 2*/          Error( "Queue size is too small" );

/* 3*/      Q = (struct QueueRecord *)malloc( sizeof( struct QueueRecord ) );
/* 4*/      if( Q == NULL )
/* 5*/          FatalError( "Out of space!!!" );
	
				Q->START =  (List)malloc( sizeof(  struct Node ) );
				Q->START->Element = 0;
				/*Q->START->Next = NULL;*/
				Q->Front = Q->START;
				 i = 1;
				while (i < MaxElements)
				{
					Q->Front->Next =  (List)malloc( sizeof( struct Node ) );
					Q->Front = Q->Front->Next;
					Q->Front->Element = 55;
					Q->Front->Next = NULL;
					Q->LAST = Q->Front;
					++i;
				}
				Q->Front = NULL;
				/*Q->curr = Q->Front;*/

/* 6*/      /*Q->list = malloc( sizeof( ElementType ) * MaxElements );*/
/* 7*/      /*if( Q->curr == NULL )
/ * 8* /          FatalError( "Out of space!!!" );*/
/* 9*/      Q->Capacity = MaxElements;
/*10*/      MakeEmpty( Q );

/*11*/      return Q;
        }

/* START: fig3_59.txt */
        void
        MakeEmpty( Queue Q )
        {
            Q->Size = 0;
			Q->Front = Q->START;
			Q->Rear = Q->START;
        }
/* END */

        void
        DisposeQueue( Queue Q )
        {
            if( Q != NULL )
            {
                /*free( Q->list );*/
				DeleteList(Q->START);
                free( Q );
            }
        }

/* START: fig3_60.txt */
		/* check if reach the last*/
		static int Succ( List Value, Queue Q )
        {
            if( Value == Q->Rear->Next )
                Value = 0;
            return 1;
        }

        void
        Enqueue( ElementType X, Queue Q )
        {
            if( IsFull( Q ) )
                Error( "Full queue" );
            else
            {
                Q->Size++;
				if (Q->Rear == Q->LAST)
				{
					Q->Rear->Element = X;
					Q->Rear = Q->START;
				}
				else
				{
					Q->Rear->Element = X;
					Q->Rear = Q->Rear->Next;
				}
            }
        }
/* END */



        ElementType
        Front( Queue Q )
        {
            if( !IsEmpty( Q ) )
                return Q->Front->Element;
            Error( "Empty queue" );
            return 0;  /* Return value used to avoid warning */
        }

        void
        Dequeue( Queue Q )
        {
            if( IsEmpty( Q ) )
                Error( "Empty queue" );
            else
            {
                Q->Size--;
				if (Q->Front == Q->LAST)
				{
					Q->Front = Q->START;
				}
				else
				{
					Q->Front = Q->Front->Next;
				}
                /*Q->Front = Succ( Q->Front, Q );*/
            }
        }

        ElementType
        FrontAndDequeue( Queue Q )
        {
            ElementType X = 0;

            if( IsEmpty( Q ) )
                Error( "Empty queue" );
            else
            {
                Q->Size--;
                X = Q->Front->Element;
				if (Q->Front == Q->LAST)
				{
					Q->Front = Q->START;
				}
				else
				{
					X = Q->Front->Element;
					Q->Front = Q->Front->Next;
				}
            }
            return X;
        }
