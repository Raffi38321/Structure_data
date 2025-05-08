#include<iostream>
#include<string>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head;


void push(int nilai) {
    node *cur;
    cur = new node();
    cur->value = nilai;
    if (head == NULL) {
        cur->next = NULL;
        head = cur;
    }
    else{
        cur->next = head;
        head = cur;
    }
}

void peek() {
    if(head == NULL){
        cout<<"Stack kosong";
    }
    else{
        cout<<head->value;
    }
}

void pop() {
    if(head == NULL) {
        cout<<"Stack kosong";
    }
    else {
        node *cur;
        cur = head;

        head = cur->next;
        delete cur;
        cout<<"pop berhasil\n";
    }
}

int main() {
    head = NULL;
    int a;
    do {
        cout << "1. Push stack\n";
        cout << "2. Lihat nilai yang di atas\n";
        cout << "3. Pop stack\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> a;

        if (a == 1) {
            int b;
            cout << "Masukkan nilai: ";
            cin >> b;
            push(b);
        } 
        else if (a == 2) {
            cout << "Nilai yang di atas: ";
            peek();
            cout << "\n";
        } 
        else if (a == 3) {
            pop();
        } 
        else if (a != 0) {
            cout << "Pilihan tidak valid!\n";
        }

    } while (a != 0);

}