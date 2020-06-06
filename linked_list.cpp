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
    struct Node *p;
} *head;

void creat_head(){
    head = (struct Head*) malloc (sizeof(struct Head));
    head -> count = 0;
    head -> p = NULL;
}

void creat_node(){
    node = (struct Node*) malloc (sizeof(struct Node));
    scanf("%d", &node -> data);
}

void add_node(){
    creat_node();
    node -> next = head -> p;
    head -> p = node;
    head -> count++;
}

void add_last(){
    tmp = head -> p;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    creat_node();
    node -> next = NULL;
    tmp -> next = node;
    head -> count++;
}

void display(){
    tmp = head -> p;
    for(int i = 1; i <= head -> count; i++){
        printf("%d  ", tmp -> data);
        tmp = tmp -> next;
    }
    cout << endl;
}

void insert_anywhere(){
    int x, flag = 0;
    cin >> x;
    tmp = head -> p;
    for(int i = 1; i <= head -> count - 1; i++){
        if(tmp -> data == x){
            flag = 1; break;
        }
        tmp = tmp -> next;
    }
    if(flag == 1){
        creat_node();
        node -> next = tmp -> next;
        tmp -> next = node;
        head -> count++;
    }
    else{
        cout << "X is not in the list" << endl;
    }
}

void delete_first(){
    if(head -> p != NULL){
        tmp = head -> p;
        head -> p = tmp -> next;
        free(tmp);
        head -> count--;
        if(head -> count == 0){
            head -> p = NULL;
        }
    }
    else{
        cout << "The list is empty" << endl;
    }
}

void delete_last(){
    if(head -> p == NULL){
        cout << "List is empty" << endl;
    }
    else if(head -> count < 2){
        delete_first();
    }
    else{
        tmp = head -> p;
        while(tmp -> next -> next != NULL){
            tmp = tmp -> next;
        }
        free(tmp -> next);
        tmp -> next = NULL;
        head -> count--;
    }

}

int main(){
    creat_head();
    delete_first();
    int i;
    cin >> i;
    add_node();
    while(i--){
        add_last();
    }
    display();
    insert_anywhere();
    display();
    cin >> i;
    while(i--){
        delete_first();
    }
    display();
    delete_last();
    display();
    return 0;
}
