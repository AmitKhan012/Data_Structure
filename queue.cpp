# include <iostream>
# include <cstdio>
# include <stdlib.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *node, *tmp;

struct Head{
    int count;
    struct Node *front, *rear;
} *head;

void creat_head(){
    head = (struct Head*) malloc(sizeof(struct Head));
    head -> count = 0;
    head -> front = NULL;
    head -> rear = NULL;
}
void enqueue(int x){
    node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = x;
    node -> next = NULL;
    if(head -> count == 0){
        head -> front = node;
        head -> rear = node;
    }
    else{
        head -> rear -> next = node;
        head -> rear = node;
    }
    head -> count++;
}
void dequeue(){
    if(head -> count == 0){
        cout << "Queue is empty" << endl;
        return;
    }
    else{
        tmp = head -> front;
        head -> front = tmp -> next;
        free(tmp);
    }
    head -> count--;
    if(head -> count == 0){
        head -> rear = NULL;
    }
}
void queuesize(){
    cout << "Queue size is " << head -> count << endl;
}
void frontelement(){
    if(head -> count == 0){
        cout << "Queue is empty so no front element...;)" << endl;
    }
    else{
        cout << head -> front -> data << endl;
    }
}
void print(){
    if(head -> count == 0){
        cout << "Queue empty" << endl;
        return;
    }
    tmp = head -> front;
    while(tmp -> next != NULL){
        cout << tmp -> data << ' ';
        tmp = tmp -> next;
    }
    cout << tmp -> data << endl;
}
int main(){
    creat_head();
    while(true){
        cout << "Press...1...for enqueue" << endl;
        cout << "Press...2...for dequeuq" << endl;
        cout << "Press...3...for size" << endl;
        cout << "Press...4...for print" << endl;
        cout << "Press...5...for front element" << endl;
        cout << "Press...6...for quit" << endl;
        int choise;
        cout << endl << endl << "Enter your Choise..."<< endl;
        cin >> choise;
        switch(choise){
            case 1:
                int data;
                cout << "Enter data..."<< endl;
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                queuesize();
                break;
            case 4:
                print();
                break;
            case 5:
                frontelement();
                break;
            case 6:
                return 0;
        }

    }
    return 0;
}
