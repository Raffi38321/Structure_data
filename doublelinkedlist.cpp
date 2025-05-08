#include<iostream>
#include<string>
using namespace std;

struct node{
    int value;
    node *prev;
    node *next;
};

node *head,*tail;

void tambahdepan(int nilai){
    node *nodebaru = new node;
    nodebaru->value = nilai;
    if(head == NULL){
        nodebaru->prev = NULL;
        nodebaru->next = NULL;
        head = nodebaru;
        tail = head;
    }
    else{
        nodebaru->prev = NULL;
        nodebaru->next = head;
        head->prev = nodebaru;
        head = nodebaru;
    }
}

void tambahbelakang(int nilai){
    node *nodebaru = new node;
    nodebaru->value = nilai;
    if(head == NULL){
        nodebaru->prev = NULL;
        nodebaru->next = NULL;
        head = nodebaru;
        tail = head;
    }
    else{
        nodebaru->next = NULL;
        nodebaru->prev = tail;
        tail->next = nodebaru;
        tail = nodebaru;
    }
}

void menampilkan_depan(){
    node *cur = head;
    while (cur != NULL){
        cout<< cur->value;
        cur = cur->next;
        cout<<" ";
    }
}

void menampilkan_belakang(){
    node *cir = tail;
    while (cir != NULL){
        cout<< cir->value;
        cir = cir->prev;
        cout<<" ";
    }

}

int panjangDoubleLink(){
    int count = 0;
    node *cur = head;
    while (cur != NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

void TambahUrut(int posisi,int nilai){
    if(head==NULL){
        cout<<"Cant do that shit";
    }
    else{
        if(posisi==1){
            tambahdepan(nilai);
        }
        else if(posisi==panjangDoubleLink()){
            tambahbelakang(nilai);
        }
        else if(posisi<0||posisi>panjangDoubleLink()){
            cout<<"YOu stupid or what";
        }
        else{
            node *nodebaru = new node;
            nodebaru->value = nilai;
            int count = 1;
            node *cur = head;
            while(count <posisi-1){
                count++;
                cur = cur->next;
            }
            node *tumbal = cur->next;
            nodebaru->prev = cur;
            nodebaru->next = tumbal;
            cur->next = nodebaru;
            tumbal->prev = nodebaru;

        }
    }
}

void Hapus_Belakang(){
    if(head==NULL){
        cout<<"Gak bisa tolol kosong listnya";
        return;
    }
    if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        node *nodeBaru = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete nodeBaru;
    }
}

void Hapus_Depan(){
    if(head==NULL){
        cout<<"Gak bisa tolol kosong listnya";
    }
    if(head==tail){
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else{
        node *nodeBaru = head;
        head = head->next;
        head->prev = NULL;
        delete nodeBaru;
    }
}

void Hapus_Urut(int posisi){
    if(head==NULL){
        cout<<"Cant do that shit";
    }
    else{
        if(posisi==1){
            Hapus_Depan();
        }
        else if(posisi==panjangDoubleLink()){
            Hapus_Belakang();
        }
        else if(posisi<0||posisi>panjangDoubleLink()){
            cout<<"YOu stupid or what";
        }
        else{
            node *nodeBaru = head;
            int cur = 1;
            while(cur<posisi){
                cur++;
                nodeBaru = nodeBaru->next;
            }

            node *sebelum = nodeBaru->prev;
            node *sesudah = nodeBaru->next;
            sebelum->next = sesudah;
            sesudah->prev = sebelum;
            delete nodeBaru;
        }
    }
}

bool find_number(int nilai){
    node *cur = head;
    while(cur != NULL){
        if(cur->value == nilai){
            return true;
        }
        cur = cur->next;
    }
    return false;
}
int main(){
    head = NULL;
    tail = NULL;
    int a;
    do
    {
        cout<<"Masukkan pilihan ";
        cin>>a;

        if(a==1){
            int p;
            cin>>p;
            tambahdepan(p);
        }
        else if(a==2){
            int p;
            cin>>p;
            tambahbelakang(p);
        }

        else if(a==3){
            menampilkan_depan();
        }
        else if(a==4){
            menampilkan_belakang();
        }
        else if(a == 5){
            cout<<"Panjang Linked List: "<<panjangDoubleLink();
        }
        else if(a==6){
            int p,m;
            cout<<"masukin posisi";
            cin>>p;
            cout<<"masukin nilai";
            cin>>m;
            TambahUrut(p,m);
        }
        else if(a==7){
            Hapus_Belakang();
        }
        else if(a==8){
            Hapus_Depan();
        }
        else if(a==9){
            int g;
            cin>>g;
            Hapus_Urut(g);
        }
        else if(a==10){
            int g;
            cin>>g;
            bool t = find_number(g);
            if(t){
                cout<<"Nomor ini: "<<g<<" ada di list";
            }
            else {
                cout<<"Nomor ini: "<<g<<" tidak ada di list";
            }
        }
        cout<<"\n";
    } while (a != 0);

    return 0;
}