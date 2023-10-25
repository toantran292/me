#define MaxLength 100
typedef int ElementType; 
typedef struct {
    ElementType Elements[MaxLength]; 
    int Front, Rear; 
} Queue;    
void makenullQueue(Queue *pQ){
    pQ->Front=-1;
    pQ->Rear=-1;
}
int emptyQueue(Queue Q){
    return Q.Front==-1;
}
int fullQueue(Queue Q){
    return (Q.Rear-Q.Front+1) == MaxLength;
}
ElementType front(Queue Q){
    if (emptyQueue(Q)) 
        printf("Hang rong");
    else 
        return Q.Elements[Q.Front];
}
void deQueue(Queue *pQ){
    if (!emptyQueue(*pQ)){
        if (pQ->Front == pQ->Rear)
            makenullQueue(pQ);
        else pQ->Front = pQ->Front + 1;
    } else printf("Loi: Hang rong!");
}
void enQueue(ElementType x,Queue *pQ){
    if (!fullQueue(*pQ)){
        if (emptyQueue(*pQ)) pQ->Front = 0;
        if (pQ->Rear == MaxLength - 1){
            for(int i = pQ->Front;i <= pQ->Rear; i++)
                pQ->Elements[i - pQ->Front] = pQ->Elements[i];
            pQ->Rear = MaxLength - 1 - pQ->Front;
            pQ->Front = 0;
        }
        pQ->Rear=pQ->Rear+1; 
        pQ->Elements[pQ->Rear] = x; 
    } else printf("Loi: Hang day!");
}
