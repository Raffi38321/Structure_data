#include<iostream>
#include<string>
using namespace std;

struct node{
    /* data */
    int value;
    node *next;
};

node *head;
node *tail;

void nambah_belakang(int nilai){
    node *linkbaru;
    linkbaru = new node();

    linkbaru->value = nilai;
    linkbaru->next = NULL;
    if(head == NULL){
        head = linkbaru;
        tail = head;
    }
    else {
        tail->next = linkbaru;
        tail = linkbaru;
    }
}

void nambah_depan(int nilai){
    node *linkbaru;
    linkbaru = new node();

    linkbaru->value=nilai;
    if(head == NULL){
        linkbaru->next = NULL;
        head = linkbaru;
        tail = head;
    }
    else {
        linkbaru->next = head;
        head = linkbaru;
    }
}

void hapus_belakang(){
    if(head == NULL){
        cout<<"List Kosong\n";
    }
    if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        node *cur;
        node *tumbal;
        
        tumbal = tail;
        cur = head;
        while (cur->next != tail){
            cur = cur->next;
        }
        tail = cur;
        tail->next = NULL;
        delete tumbal;
    }
}

void hapus_depan(){
    if(head == NULL){
        cout<<"List kosong\n";
    }
    else {
        node *cur;
        cur = head;

        head = cur->next;
        delete cur;
    }
}

void Menampilkan(){
    node *cur = head;
    while (cur != NULL){
        cout<< cur->value;
        cur = cur->next;
        cout<<" ";
    }
    
}

int liat_panjang(){
    int l = 0;
    node *cur = head;
    while (cur != NULL){
        l++;
        cur = cur->next;
    }
    return l;
    
}

bool cari(int u){
    node *cur = head;
    while (cur != NULL){
        if(cur->value == u){
            return true;
        }
        cur = cur->next;
    }
    return false;
}

void tambah_urutan(int urut,int nilai){
    int panjang = liat_panjang();
    if(urut==0||head == NULL){
        nambah_depan(nilai);
        return;
    }
    else if(urut == panjang){
        nambah_belakang(nilai);
        return;
    }
    else {
        node *ulang;
        ulang = head;
        int e = 1;

        node *ditambah;
        ditambah = new node();
        ditambah->value = nilai;

        while(e != urut){
            ulang = ulang->next;
            e++;
        }

        ditambah->next = ulang->next;
        ulang->next = ditambah;
    }
}

void hapusUrutan(int urut){
    if(head == NULL){
        cout<<"Linked list kosong\n";
        return;
    }
    else if(urut <= 0 ||urut > liat_panjang() ){
        cout<<"Urutan tidak valid\n";
        return;
    }
    else if(urut == 1){
        hapus_depan();
    }
    else if(urut == liat_panjang()){
        hapus_belakang();
    }
    else{
        node *cur = head;
        node *yangdihapus;
        node *sebelum;
        int i = 1;
        while(i <= urut){
            if(i == urut){
                yangdihapus = cur;
            }
            else if(i == urut-1){
                sebelum = cur;
            }
            cur = cur->next;
            i++;
        }
        sebelum->next = yangdihapus->next;
        delete(yangdihapus);
    }
    cout<<"This shit worked\n";
}

void cariHapus(int nilai){
    if(head == NULL){
        cout<<"Linked list kosong\n";
        return;
    }
    else if(cari(nilai)){
        node *cur = head;
        node *yangMauDiHapus;
        while(cur != NULL){
            if(cur->value == nilai){
                yangMauDiHapus = cur;
                break;
            }
            cur = cur->next;
        }
        if(yangMauDiHapus == head){
            hapus_depan();
        }
        else if(yangMauDiHapus == tail){
            hapus_belakang();
        }
        else {
            node *before;
            before = head;
            while(before->next != yangMauDiHapus){
                before = before->next;
            }
            before->next = yangMauDiHapus->next;
            delete yangMauDiHapus;
        }
        cout<<"This shit worked\n";
    }
    else{
        cout<<"Nilai tidak ada\n";
        return;
    }
}

int main(){
    int a = 9;
    head = NULL;
    tail = NULL;
    do{
        cout<<"\n";
        cout<<"1. Untuk Nambah Belakang\n";
        cout<<"2. Untuk Nambah Depan\n";
        cout<<"3. Untuk Hapus Belakang\n";
        cout<<"4. Untuk Hapus Depan\n";
        cout<<"5. Menampilkan list\n";
        cout<<"6. Melihat panjang list\n";
        cout<<"7. Mencari element pada list\n";
        cout<<"8. Menambahkan element pada urutan\n";
        cout<<"9. Menghapus element pada urutan\n";
        cout<<"10. Mencari lalu hapus\n";
        cout<<"Masukkan Pilihan(0 Untuk keluar): ";
        cin>>a;
        cout<<'\n';
        
        if(a == 1){
            int y;
            cout<<"Masukkan nilai: ";
            cin>>y;
            nambah_belakang(y);           
        }

        else if (a == 2){
            int y;
            cout<<"Masukkan nilai: ";
            cin>>y;
            nambah_depan(y);
        }
        
        else if(a==3){
            cout<<"Menghapus bagian belakang linked list\n";
            hapus_belakang();
        }

        else if(a==4){
            cout<<"Menghapus bagian depan linked list\n";
            hapus_depan();
        }

        else if(a==5){
            cout<<"Menampilkan linked list: ";
            Menampilkan();
        }

        else if(a==6){
            cout<<"panjang linked list: "<< liat_panjang();
        }

        else if(a==7){
            int m;
            cout<<"Masukkan nilai yang ingin dicari: ";
            cin>>m;
            bool t = cari(m);
            if(t == true){
                cout<<"Angka ini: "<<m<<" Ada\n";
            }
            else {
                cout<<"Angka ini tidak ada\n";
            }
        }

        else if(a == 8){
            int urutan,nilainya;
            cout<<"Masukkan urutan: ";
            cin>>urutan;
            cout<<"Masukkan nilai: ";
            cin>>nilainya;
            tambah_urutan(urutan,nilainya);
        }

        else if(a == 9){
            int urutan;
            cout<<"Masukan urutannya ";
            cin>>urutan;
            hapusUrutan(urutan);
        }

        else if(a == 10){
            int nomernya;
            cout<<"Masukan nilainya: ";
            cin>>nomernya;
            cariHapus(nomernya);
        }

        else {
            cout<<"Fitur belum ada jir\n";
        }

        cout<<"\n";
    }while(a != 0);

    return 0;
}