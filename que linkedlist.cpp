#include<iostream>
#include<string>

using namespace std;

struct node{
    int value;
    node *next;
};

node *head;
node *tail;

void enqueue(int nilai){
    node *cur;
    cur = new node;
    cur->value = nilai;
    cur->next = NULL;
    if(head == NULL){
        head = cur;
        tail = cur;
    }
    else{
        tail->next = cur;
        tail = cur;
    }
}

void peek(){
    if(head == NULL){
        cout<<"queue kosong\n";
    }
    else{
        cout<<"Nilainya "<<head->value<<"\n";
    }
}

void dequeue(){
    node *cur = head; 
    if(head == NULL){
        cout<<"queue kosong\n";
    }
    else{
        head = cur->next;
        delete cur;
        cout<<"dequeue berhasil\n";
    }
}

int main(){
    head = NULL;
    tail = NULL;
    int pilihan;
    do{
        cout<<"1. enqueue (nambah)\n";
        cout<<"2. dequeue (hapus)\n";
        cout<<"3. peek (lihat)\n";
        cin>>pilihan;
        if(pilihan == 1){
            int nilai;
            cout<<"masukkan nilai: ";
            cin>>nilai;
            enqueue(nilai);
        }

        else if(pilihan == 2){
            dequeue();
        }

        else if(pilihan == 3){
            peek();
        }

    } while (pilihan != 0);
    
    return 0;
}