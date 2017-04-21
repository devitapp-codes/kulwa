#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int i, j;
int banyakData;
int simpan;
int terkecil;

int* generateNumber(int jml){
    int* number= new int[jml];
    for(int i=0;i<jml;i++){
        number[i] = rand() % 100;
    }
    return number;
}

void tampilanData(int i , int* data){
    cout << "\nIterasi ke " << (i+1) << " :" << endl;

    for(i=0; i<banyakData; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void garis(){
    cout << "=========================================" << endl;
}

int* dataAwal(){
    cout << "Berapa data yang ingin di input = ";
    cin >> banyakData;

    int *data = generateNumber(banyakData);

    cout << endl;
    cout << "Data sebelum diurutkan : "<< endl;

    for(i=0; i<banyakData; i++){
        cout << data[i] << " ";
    }
    cout << endl;

    return data;
}

void bubbleSort_Terkecil(int* data){
    for(i=0; i<banyakData; i++){
        for(j=i+1; j<banyakData; j++){
            if(data[i]>data[j]){
                simpan=data[i];
                data[i]=data[j];
                data[j]=simpan;
            }
        }

        tampilanData(i , data);
    }
}

void bubbleSort_Terbesar(int* data){
    for(i=0; i<banyakData; i++){
        for(j=i+1; j<banyakData; j++){
            if(data[i]<data[j]){
                simpan=data[i];
                data[i]=data[j];
                data[j]=simpan;
            }
        }

        tampilanData(i , data);
    }
}

void selectionSort_Terkecil(int* data){
    for(i=0; i<banyakData-1; i++){
        terkecil=i;
        for(j=i+1; j<banyakData; j++){
            if(data[terkecil]>data[j]){
                terkecil=j;
            }

        }
        simpan=data[terkecil];
        data[terkecil]=data[i];
        data[i]=simpan;

        tampilanData(i , data);
    }
}


void selectionSort_Terbesar(int* data){
    for(i=0; i<banyakData-1; i++){
        terkecil=i;
        for(j=i+1; j<banyakData; j++){
            if(data[terkecil]<data[j]){
                terkecil=j;
            }
        }
        simpan=data[terkecil];
        data[terkecil]=data[i];
        data[i]=simpan;

        tampilanData(i , data);
    }
}

void insertionSort_Terkecil(int* data){
    for(i=0; i<banyakData; i++){
        simpan=data[i];
        j=i-1;
        while((simpan<data[j]) && (j>=0)){
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=simpan;
        tampilanData(i , data);
    }
}

void insertionSort_Terbesar(int* data){
    for(i=0; i<banyakData; i++){
        simpan=data[i];
        j=i-1;
        while((simpan>data[j]) && (j>=0)){
            data[j+1]=data[j];
            j--;
        }
        data[j+1]=simpan;
        tampilanData(i , data);
    }
}

void menuUtama(){
    int pilih;
    char ulang;

    do{
        cout << "               Sorting" << endl;
        garis();
        cout << endl;
        cout << "1. Bubble Sort [ascending(terkecil)]" << endl;
        cout << "2. Bubble Sort [descending(terbesar)]" << endl;
        cout << "3. Selection Sort [ascending(terkecil)]" << endl;
        cout << "4. Selection Sort [descending(terbesar)]" << endl;
        cout << "5. Insertion Sort [ascending(terkecil)]" << endl;
        cout << "6. Insertion Sort [descending(terbesar)]" << endl;
        cout << "7. Menampilkan Data" << endl;
        cout << endl;
        cout << "Masukan pilihan anda [input angka] = ";
        cin >> pilih;

        switch(pilih){
            case 1:
                bubbleSort_Terkecil(dataAwal());
                break;
            case 2:
                bubbleSort_Terbesar(dataAwal());
                break;
            case 3:
                selectionSort_Terkecil(dataAwal());
                break;
            case 4:
                selectionSort_Terbesar(dataAwal());
                break;
            case 5:
                insertionSort_Terkecil(dataAwal());
                break;
            case 6:
                insertionSort_Terbesar(dataAwal());
                break;
            default:
                cout << "maaf kamu salah pilih, karena yang setia ga akan pergi begitu saja " << endl;
                break;
        }
    cout << endl;
    cout << "Ingin kembali ke menu utama [y/t] = ";
    cin >> ulang;

    system("CLS");

    }while(ulang=='y');
}

#endif // SORTING_H_INCLUDED
