# include <iostream>
# include <stdlib.h>
# include <queue>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

int max(int a, int b){
    if(a < b) return b;
    else if(a > b) return a;
    else return a;
}

BstNode* CreatBstNode(int data){
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BstNode* insertNode(BstNode* root, int data){
    if(root == NULL){
        root = CreatBstNode(data);
        return root;
    }
    else if(data < root -> data){
        root -> left = insertNode(root -> left, data);
    }
    else {
        root -> right = insertNode(root -> right, data);
    }
    return root;
}

bool SEARCH(BstNode* root, int data){
    if(root == NULL) return false;
    else if(root -> data == data) return true;
    else if(data < root -> data) return SEARCH(root -> left, data);
    else return SEARCH(root -> right, data);
}

BstNode* findMin(BstNode* root){
    if(root -> left == NULL){
        return root;
    }
    return findMin(root -> left);
}

void LevelOrder(BstNode* root){
    if(root == NULL) {return;}
    queue <BstNode*> q;
    q.push(root);
    while(!q.empty()){
        BstNode* current = q.front();
        cout << current -> data << "  ";
        if(current -> left != NULL) q.push(current -> left);
        if(current -> right != NULL) q.push(current -> right);
        q.pop();
    }
}

void preOrder(BstNode* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << "  ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(BstNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    cout << root->data << "  ";
    inOrder(root->right);
}

void postOrder(BstNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "  ";
}

int findMax(BstNode* root){
    if(root == NULL){
        cout << "Tree is empty..." << endl;
        return -1;
    }
    else if(root -> right == NULL){
        return root -> data;
    }
    return findMax(root -> right);
}

int findHight(BstNode* root){
    if(root == NULL){
        return -1;
    }
    int lefthight = findHight(root -> left);
    int righthight = findHight(root -> right);
    return max(lefthight, righthight) + 1;
}

BstNode* Delete(BstNode* root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        else if(root->left==NULL){
            BstNode* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if(root->right==NULL){
            BstNode* tmp = root;
            root = root->left;
            delete tmp;
        }
        else{
            BstNode* tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
}

int main(){

    BstNode* root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 25);

    postOrder(root);
    root = Delete(root, 25);
    postOrder(root);

    return 0;

}
