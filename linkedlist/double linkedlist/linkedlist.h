#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>
#include <stdlib.h>

using namespace std;

struct data{
    string nama;
    int umur;
    data *next;
    data *prev;
};

data *depan, *belakang, *baru, *posisi, *hapus, *bantu;
char nama[100];
int umur;

void mulaiLinkedlist(){
    cout<<"Masukan Data Pertama Untuk Mebaru Linked List : "<<endl;
    cout<<"Masukan Nama = ";
    cin.getline(nama, 100);
    cout<<"Masukan Umur = ";
    cin>>umur;
    cin.ignore();

    baru = new data;
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    baru->prev = NULL;

    depan = baru;
    belakang = baru;
}

void tambahData(){
    baru = new data;
    cout<<"Masukan Nama = ";
    cin.getline(nama, 100);
    cout<<"Masukan Umur = ";
    cin>>umur;
    cin.ignore();
    baru->nama = nama;
    baru->umur = umur;
    baru->next = NULL;
    baru->prev = NULL;
}

void tambahDepan(){
    if(depan==NULL){
        belakang = baru;
    }
    else{
        baru->next = depan;
        depan->prev = baru;
    }
    depan = baru;
}

void tambahBelakang(){
    if(belakang==NULL){
        depan = baru;
    }
    else{
        belakang->next = baru;
        baru->prev = belakang;
    }
    belakang = baru;
}

void tambahTengah(){
    int i, kounter, letak ;
    cout<<"Posisi mana data ini akan ditaruh ";
    cin>>letak;

    posisi = depan;
    while (posisi != NULL){
        posisi = posisi->next;
        kounter++;
    }
    if (letak == 1){
        if (depan == NULL){
            depan = baru;
            belakang = baru;
            depan->next = NULL;
        }
        else{
            baru->next = depan;
            depan->prev = baru;
            depan = baru;
        }
    }
    else if (letak > 1  && letak <= kounter){
        posisi = depan;
        for (i = 1; i < letak; i++){
            bantu = posisi;
            posisi = posisi->next;
        }
            bantu->next = baru;
            baru->prev = bantu;

            baru->next = posisi;
            posisi->prev = baru;
        }
    else{
        cout<<"Melebihi Batas"<<endl;
    }
}

void hapusDepan(){
    hapus = depan;
    depan = hapus->next;
    depan->prev = NULL;
    hapus = NULL;
}

void hapusBelakang(){
    hapus = belakang;
    belakang = hapus->prev;

    hapus = NULL;

    belakang->next = NULL;
}

void hapusTengah(){
    int i, kounter, letak ;
    data *tujuan;
    cout<<"Posisi mana yang ingin dihapus ";
    cin>>letak;

    posisi = depan;
    while (posisi != NULL){
        posisi = posisi->next;
        kounter++;
    }
    if (letak == 1){
        if (depan == NULL){
            depan = baru;
            belakang = baru;
            depan->next = NULL;
        }
        else{
            baru->next = depan;
            depan->prev = baru;
            depan = baru;
        }
    }
    else if (letak > 1  && letak <= kounter){
        posisi = depan;
        for (i = 1; i < letak; i++){
            bantu = posisi;
            posisi = posisi->next;
        }
            hapus = posisi;
            tujuan = posisi->next;
            bantu->next = tujuan;
            tujuan->prev = bantu;

            hapus = NULL;
        }
    else{
        cout<<"Melebihi Batas"<<endl;
    }

}

void tampilDepan(){
posisi = depan;
char lihat;
int lokasi=1;
          while(posisi!=NULL){
           system("CLS");
           if(posisi == depan){
            cout<<"Data Pertama"<<endl;
           }
           if(posisi == belakang){
            cout<<"Data Terakhir"<<endl;
           }
           cout<<"Data ke- "<<lokasi<<" : \n";
           cout<<"Nama = "<<posisi->nama<<endl;
           cout<<"Umur = "<<posisi->umur<<endl;
           cout<<"Ingin Lihat Data ?"<<((posisi==belakang) ? " ": " y = selanjutnya ")<<((posisi==depan) ? " ": "k = sebelumnya ")<<"n = tidak ";
           cin>>lihat;
           if(lihat == 'y'){
           posisi=posisi->next;//beralih ke data selanjutnya
           lokasi++;
           }
           else if(lihat == 'k'){
           posisi=posisi->prev;//beralih ke data selanjutnya
           lokasi--;
           }
           else{
            break;
           }
        }
}

void tampilBelakang(){
   int kounter = 0;
   posisi = depan;
    while (posisi != NULL){
        posisi = posisi->next;
        kounter++;
    }

posisi = belakang;
char lihat;
int lokasi=kounter;
          while(posisi!=NULL){
           system("CLS");
           if(posisi == depan){
            cout<<"Data Pertama"<<endl;
           }
           if(posisi == belakang){
            cout<<"Data Terakhir"<<endl;
           }
           cout<<"Data ke- "<<lokasi<<" : \n";
           cout<<"Nama = "<<posisi->nama<<endl;
           cout<<"Umur = "<<posisi->umur<<endl;
           cout<<"Ingin Lihat Data ?"<<((posisi==belakang) ? " ": " y = selanjutnya ")<<((posisi==depan) ? " ": "k = sebelumnya ")<<"n = tidak ";
            cin>>lihat;
           if(lihat == 'y'){
                posisi=posisi->next;//beralih ke data selanjutnya
                lokasi++;
           }
           else if(lihat == 'k'){
                posisi=posisi->prev;//beralih ke data selanjutnya
                lokasi--;
           }
           else{
            break;
           }
        }
}
#endif // LINKEDLIST_H_INCLUDED
