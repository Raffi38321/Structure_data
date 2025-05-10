#include<iostream>
#include<string>
using namespace std;

//node
struct node{
    char value;
    node *parent;
    node *left;
    node *right;
};

//ini root nya
node *root;


//ini ngebut tree kalo ga ada 
void buatTree(char label){
    if(root != NULL){
        cout<<"Udah ada tree tolol";
    }
    else{
        node *newnode = new node;
        newnode->value = label;
        newnode->parent = NULL;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
        cout<<"Berhasil buat root kong \n";
    }
}


void tambahkiri(char label,node *target){
    if(root == NULL){
        cout<<"ndak bisa \n";
    }
    else{
        if(target->left != NULL){
            cout<<"ada isinya njir\n";
        }
        else{
            node *newnode = new node;
            newnode->value = label;
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->parent = target;
            target->left = newnode;
            cout<<"berhasil kong\n";
        }
    }
}

void tambahkanan(char label,node *target){
    if(root == NULL){
        cout<<"ndak bisa \n";
    }
    else{
        if(target->left != NULL){
            cout<<"ada isinya njir\n";
        }
        else{
            node *newnode = new node;
            newnode->value = label;
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->parent = target;
            target->right = newnode;
            cout<<"berhasil kong\n";
        }
    }
}

int main(){
    root = NULL;
    buatTree('a');
    cout<<"nilai root "<< root->value<<"\n";
    tambahkiri('b',root);
    cout<<"nilai left "<<root->left->value;
    return 0;

}