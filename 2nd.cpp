# include <iostream>
# include <cstdio>
# include <stdlib.h>
# include <cstring>
# include <string>
using namespace std;

struct Node{
    char name[20];
    char id[10];
    char Rank[10];
    struct Node *next;
} *node, *tmp, *tmp2, *snode;

struct SHead{
    int count;
    struct Node *top;
} *shead;

void creat_shead(){
    shead = (struct SHead*) malloc (sizeof(struct SHead));
    shead -> count = 0;
    shead -> top = NULL;
}

void pushStack(char Name[20], char Id[10], char RAnk[10]){
    snode = (struct Node*) malloc (sizeof(struct Node));
    strcpy(snode -> name, Name);
    strcpy(snode -> id, Id);
    strcpy(snode ->Rank, RAnk);
    snode -> next = shead -> top;
    shead -> top = snode;
    shead -> count++;
}

void popStack(){
    if(shead -> top == NULL){
        cout << "There is no history." << endl;
    }
    else{
        while(shead -> top != NULL){
            tmp = shead -> top;
            shead -> top = tmp -> next;
            free(tmp);
            shead -> count--;
        }
    }
}

struct LHead{
    int count;
    struct Node *p;
} *lhead;

struct QNode{
    char id[10];
    struct QNode* next;
} *qnode, *qtmp;

struct QHead{
    int count;
    struct QNode *front, *rear;
} *qhead;

void creat_qhead(){
    qhead = (struct QHead*) malloc(sizeof(struct QHead));
    qhead -> count = 0;
    qhead -> front = NULL;
    qhead -> rear = NULL;
}

void enqueue(){
    cout << "Input The Employee's ID who have entered the industry....";
    qnode = (struct QNode*) malloc (sizeof(struct QNode));
    scanf(" %[^\t\n]s", qnode -> id);
    node -> next = NULL;
    if(qhead -> count == 0){
        qhead -> front = qnode;
        qhead -> rear = qnode;
    }
    else{
        qhead -> rear -> next = qnode;
        qhead -> rear = qnode;
    }
    qhead -> count++;
}

void dequeue(){
    if(qhead -> count == 0){
        cout << "Queue is empty" << endl;
        return;
    }
    else{
        qtmp = qhead -> front;
        qhead -> front = qtmp -> next;
        free(qtmp);
    }
    qhead -> count--;
    if(qhead -> count == 0){
        qhead -> rear = NULL;
    }
}
void check_employee(){
    cout << "Input the ID no you want to check...";
    char ID[10];
    scanf(" %[^\t\n]s", ID);
    qtmp = qhead -> front;
    while(qtmp != qhead -> rear){
        if(strcmp(qtmp->id, ID) == 0){
            cout << "Yes, This ID holder is currently present in the industry." << endl;
            return;
        }
    }
    if(strcmp(qtmp->id, ID) == 0){
        cout << "Yes, This ID holder is currently present in the industry." << endl;
    }
    else{
        cout << "No, This ID holder is not currently present in the industry." << endl;
    }
}

void creat_lhead(){
    lhead = (struct LHead*) malloc (sizeof(struct LHead));
    lhead -> count = 0;
    lhead -> p = NULL;
}

void creat_node(){
    node = (struct Node*) malloc (sizeof(struct Node));
    cout << "Input the name of the employee: ";
    scanf(" %[^\t\n]s", node -> name);
    cout << "Input the ID of the employee: ";
    scanf(" %[^\t\n]s", node -> id);
    cout << "Input the rank of the employee: ";
    scanf(" %[^\t\n]s", node -> Rank);
}

void add_node(){
    creat_node();
    node -> next = lhead -> p;
    lhead -> p = node;
    lhead -> count++;
}

void add_last(){
    if(lhead -> p == NULL){
        add_node();
        return;
    }
    tmp = lhead -> p;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    creat_node();
    node -> next = NULL;
    tmp -> next = node;
    lhead -> count++;
}

void delete_employee(){
    if(lhead -> p != NULL){
        cout << "Which employee do u want to delete from the list? ";
        char Name[20];
        scanf(" %[^\t\n]s", Name);
        int flag = 1;
        tmp = lhead -> p;
        if(strcmp(tmp -> name, Name) == 0)
        {
            pushStack(tmp -> name, tmp -> id, tmp -> Rank);
            flag = 0;
            lhead -> p = tmp -> next;
            free(tmp);
            lhead -> count--;
            return;
        }
        while(tmp -> next -> next != NULL)
        {
            if(strcmp(tmp -> next -> name, Name) == 0)
            {
                pushStack(tmp -> next -> name, tmp -> next -> id, tmp -> next -> Rank);
                flag = 0;
                tmp2 = tmp -> next;
                tmp -> next = tmp2 -> next;
                free(tmp2);
                lhead -> count--;
                return;
            }
            tmp = tmp -> next;
        }
        if(flag == 1)
        {
            if(strcmp(tmp -> next -> name, Name) == 0)
            {
                pushStack(tmp -> next -> name, tmp -> next -> id, tmp -> next -> Rank);
                tmp2 = tmp -> next;
                free(tmp2);
                tmp -> next = NULL;
                lhead -> count--;
            }
            else
            {
                cout << Name << " is not exist in the list. " << endl;
            }
        }
    }
    else{
        cout << "List is empty, there is nothing to Delete." << endl;
    }
}



void display_list(){
    if(lhead -> p == NULL){
        cout << "List is empty." << endl;
        return;
    }
    tmp = lhead -> p;
    for(int i = 1; i <= lhead -> count; i++){
        printf("NAME: %s,  ID: %s,  RANK: %s\n", tmp -> name, tmp -> id, tmp -> Rank);
        tmp = tmp -> next;
    }
    cout << endl;
}

void display_stack(int num){
    if(shead -> top == NULL){
        cout << "There is no history." << endl;
        return;
    }
    tmp = shead -> top;
    int i = 1;
    while(tmp -> next != NULL && i <= num){
        i++;
        printf("NAME: %s,  ID: %s,  RANK: %s\n", tmp -> name, tmp -> id, tmp -> Rank);
        tmp = tmp -> next;
    }
    if(num == shead -> count || num > shead -> count){
        printf("NAME: %s,  ID: %s,  RANK: %s\n", tmp -> name, tmp -> id, tmp -> Rank);
    }
}

int main(){

    cout << "**********EMPLOYEE MANAGMENT**********"<< endl;
    cout << endl;
    creat_lhead();
    creat_shead();
    creat_qhead();
    bool loop = true;
    while(loop){
        cout << "Option 1: Create a Employee List." << endl;
        cout << "Option 2: View the History of previous employee." << endl;
        cout << "Option 3: Manage a working day." << endl;
        cout << "Option 4: Exit the program." << endl;
        cout << "Enter your choice...";
        int option, num;
        string decision, decision2;
        cin >> option;
        switch(option){
            case 1:
                cout << "Do you want to recruit employee for the industry? yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    cout << "How many employees u want to recruit? " << endl;
                    cin >> num;
                    while(num--){
                        cout << "Where do u add new employee? first/last...";
                        cin >> decision2;
                        if(decision2 == "first"){
                            add_node();
                        }
                        else if(decision2 == "last"){
                            add_last();
                        }
                    }
                }
                cout << "Do you want to dismiss any employee from the list?  yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    cout << "How many employees you want to dismiss...";
                    cin >> num;
                    while(num--){
                        delete_employee();
                    }
                }
                cout << "Do you want to watch the Employee list?  yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    display_list();
                }
                break;
            case 2:
                cout << shead -> count << " employees worked in this industry before." << endl;
                cout << "How many previous worker's information do you need?" << endl;
                cin >> num;
                display_stack(num);
                cout << "Do you want to delete the history?  yes/no....";
                cin >> decision;
                if(decision == "yes"){
                    popStack();
                }
                break;
            case 3:
                cout << "Is there any Employee who have entered the industry? yes/no..";
                cin >> decision;
                if(decision == "yes"){
                    cout << "How many Employees have entered the industry?" << endl;
                    cin >> num;
                    while(num--){
                        enqueue();
                    }
                }
                cout << "Is there any employee who have left the industry? yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    cout << "How many employees have left the industry?" << endl;
                    cin >> num;
                    while(num--){
                        dequeue();
                    }
                }
                cout << "Do you want to check any employee if he/she is present? yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    cout << "How many employees you want to check?" << endl;
                    cin >> num;
                    while(num--){
                        check_employee();
                    }
                }
                cout << "Do you want to close the industry today? yes/no...";
                cin >> decision;
                if(decision == "yes"){
                    num = qhead -> count;
                    while(num--){
                        dequeue();
                    }
                }
                break;
            case 4:
                loop = false;

        }
    }
    return 0;
}
