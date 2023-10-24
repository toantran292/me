#define MaxLength 100
typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[MaxLength];
    Position Last;
} List;

void makenullList(List *pL){
    pL->Last = 0;
}

int emptyList(List L){
    return L.Last == 0;
}

int fullList(List L){
    return L.Last == MaxLength;
}

Position first(List L){
    return 1;
}

Position endList(List L){
    return L.Last + 1;
}

Position next(Position P, List L){
    return P+1;
}

Position previous(Position P, List L){
    return P-1;
}

void insertList(ElementType x, Position P, List *pL){
    if(fullList(*pL)) return;
    if(P < first(*pL) || P > endList(*pL)) return;
    for(Position Q = pL->Last; Q >= P; Q--)
        pL->Elements[Q] = pL->Elements[Q-1];
    pL->Elements[P-1] = x;
    pL->Last++;
}

void deleteList(Position P, List *pL){
    if(P < first(*pL) || P >= endList(*pL)){
        printf("Vi tri khong hop le\n");
        return;
    };
    if(emptyList(*pL)) return;
    for(Position Q = P; Q < pL->Last; Q++)
        pL->Elements[Q-1] = pL->Elements[Q];
    pL->Last--;
}

ElementType retrieve(Position P, List L){
    return L.Elements[P-1];
}

Position locate(ElementType x, List L){
    Position P = first(L);
    while(P != endList(L))
        if(retrieve(P, L) == x) return P;
        else P = next(P, L);
    return P;
}

