#include<iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

node *linkedlist;
node *last;


// Fungsi untuk menambahkan elemen ke linked list
void insert(int newValue) {
    node *newNode = new node; // Alokasi memori untuk node baru
    newNode->value = newValue;
    newNode->next = NULL;

    if (linkedlist == NULL) { // Jika linked list kosong
        linkedlist = newNode;
        last = newNode;
    } else { // Jika linked list tidak kosong
        last->next = newNode;
        last = newNode;
    }
}

// fungsi length
int panjang (){
    node *hitung = linkedlist;
    int y = 0;
    while(hitung != NULL){
        y = y + 1;
        hitung = hitung->next;
    }
    return y;
}

// fungsi mencari
bool cari(int x){
    node *u = linkedlist;
    while(u != NULL){
        if(u->value == x){
            return true;
        }
        u = u->next;
    }
    return false;
}

//menghapus node 
void menghapus(){
    node *m;
    m = linkedlist;
    while(m->next != last){
        m =  m->next;
    }
    delete last;
    last = m;
    last->next = NULL;
}
int main() {
    linkedlist = NULL;
    last = linkedlist;

    // Contoh penggunaan fungsi insert
    int a;
    cout<<"Msukkan nilai a: ";
    cin >> a ;
    while(a--){
        int b;
        cout<<"Masukan nilai b";
        cin>> b;
        insert(b);
    }

    // Menampilkan elemen linked list
    node *current = linkedlist;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout<<'\n';
    cout << panjang();
    cout<<"\n";
    cout<< cari(9);
    cout<<"\n";
    menghapus();

    node *p = linkedlist;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
    }
    return 0;
}