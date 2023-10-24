typedef int ElementType;
struct Node{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node* Position;
typedef Position List;

void makenullList(List *pL){
    (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

int emptyList(List L){
    return L.Next == NULL;
}

ElementType retrieve(Position P, List L){
    if(P->Next != NULL)
        return P->Next->Element;
}

void insertList(ElementType x, Position P, List *pL){
    Position T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

void deleteList(Position P, List *pL){
    if(P->Next!=NULL){
        Position T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

Position first(List L){
    return L;
}

Position endList(List L){
    Position P = L;
    while(P->Next != NULL)
        P = P->Next;
    return P;
}

Position next(Position P, List L){
    return P->Next;
}

Position previous(Position P, List L){
    Position Q = L;
    while(Q->Next != P) Q = Q->Next;
    return Q;
}

Position locate(ElementType x, List L){
    Position P = first(L), E = endList(L);
    while(P != E){
        if(retrieve(P, L) == x) return P;
        else P = next(P, L);
    }
    return P;
}
