typedef List Stack;
void makenullStack (Stack *pS){
    makenullList(pS);
}
int emptyStack(Stack S){
    return emptyList(S);
}
void top(Stack S) {
    retrieve(first(S),S);
}
void pop(Stack *pS) {
    deleteList(first(*pS),pS);
}
void push(Elementtype x, Stack *pS) {
    insertList(x,first(*pS),pS);
}