#include "linkedlist.h"

int main()
{
    int pilihan;
    char ulang;
    mulaiLinkedlist();
    do{
    cout<<"Selamat Datang Di Single Linked List"<<endl;
    cout<<"Menu :"<<endl;
    cout<<"1. Tambah Data di Depan"<<endl;
    cout<<"2. Tambah Data di Belakang"<<endl;
    cout<<"3. Tambah Data di Tengah"<<endl;
    cout<<"4. Tampilkan Data dari Depan"<<endl;
    cout<<"5. Tampilkan Data dari Belakang"<<endl;
    cout<<"6. Hapus Depan"<<endl;
    cout<<"7. Hapus Belakang"<<endl;
    cout<<"8. Hapus Tengah"<<endl;
    cout<<"Masukan Pilihan Anda = ";
    cin>>pilihan;
    cin.ignore();

    switch(pilihan){
        case 1 :
            tambahData();
            tambahDepan();
            break;

        case 2:
            tambahData();
            tambahBelakang();
            break;

        case 3:
            tambahData();
            tambahTengah();
            break;

        case 4:
            tampilDepan();
            break;

        case 5:
            tampilBelakang();
            break;

        case 6:
            hapusDepan();
            break;

        case 7:
            hapusBelakang();
            break;

        case 8:
            hapusTengah();
            break;
    }
    cout<<"Anda Ingin Menambah Data atau menampilkan isi data [y/n]= ";
    cin>>ulang;
    system("CLS");
    }while(ulang == 'y');
}
