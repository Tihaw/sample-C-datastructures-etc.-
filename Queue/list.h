        typedef int ElementType_list;

/* START: fig3_6.txt */
        #ifndef _List_H
        #define _List_H

        struct Node;
        typedef struct Node *PtrToNode;
        typedef PtrToNode List;
        typedef PtrToNode Position;

        List MakeEmpty_list( List L );
        int IsEmpty_list( List L );
        int IsLast( Position P, List L );
        Position Find( ElementType_list X, List L );
        void Delete( ElementType_list X, List L );
        Position FindPrevious( ElementType_list X, List L );
        void Insert( ElementType_list X, List L, Position P );
        void DeleteList( List L );
        Position Header( List L );
        Position First( List L );
        Position Advance( Position P );
        ElementType_list Retrieve( Position P );

        #endif    /* _List_H */
/* END */
