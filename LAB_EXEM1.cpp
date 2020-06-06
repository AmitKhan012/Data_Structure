# include <iostream>
# include <cstdio>
# include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *snode, *qnode, *tmp;
struct SHead{
    int count;
    struct Node *top;
} *shead;
struct QHead{
    int count;
    struct Node *front, *rear;
} *qhead;
void creat_shead(){
    shead = (struct SHead*) malloc (sizeof(struct SHead));
    shead -> count = 0;
    shead -> top = NULL;
}
void creat_qhead(){
    qhead = (struct QHead*) malloc (sizeof(struct QHead));
    qhead -> count = 0;
    qhead -> front = NULL;
    qhead -> rear = NULL;
}
void pushStack(int x){
    snode = (struct Node*) malloc (sizeof(struct Node));
    snode -> data = x;
    snode -> next = shead -> top;
    shead -> top = snode; //null hobe na?
    shead -> count++;
}
int popStack(){
    int x;
    if(shead -> top == NULL){
        return 0;
    }
    else{
        tmp = shead -> top;
        shead -> top = tmp -> next;
        x = tmp -> data;
        free(tmp);
        shead -> count--;
        return x;
    }
}
void enqueue(int x){
    qnode = (struct Node*) malloc (sizeof(struct Node));
    qnode -> data = x;
    qnode -> next = NULL;
    if(qhead -> count == 0){
        qhead -> front = qnode;
        qhead -> rear = qnode;
    }
    else{
        qhead -> rear -> next = qnode;
    }
    qhead -> count++;
}
int main(){
    creat_shead();
    creat_qhead();
    int num;
    while(scanf("%d", &num) != EOF){
        if(num != 0){
            pushStack(num);
        }
        else{
            popStack();
            popStack();
            while(shead -> count != 0){
                int x = popStack();
                enqueue(x);
                cout << x << endl;
            }
        }
    }

    return 0;
}
