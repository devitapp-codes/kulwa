#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define max 7

using namespace std ;


int data[max];
int kepala = -1, ekor= -1, a;

bool IsFull()
{
        if (ekor == max - 1)
        return true;
        else
        return false;
}

bool IsEmpty()
{
        if (kepala == -1 && ekor == -1)
        return true;
        else
        return false;
}


void Enqueue()
{
  if (IsFull())
        {
           cout << "Data penuh";
        }
        else
        {
          if (IsEmpty())
            {
               kepala = ekor = 0;
               cout << "Masukkan data : "; cin >> data[ekor];
            }
            else
            {
               ekor++;
               cout << "Masukkan data : "; cin >> data[ekor];
            }
        }
}


void Dequeue()
{
        if (IsEmpty())
        {
          cout << "Data kosong";
          getch();
        }
        else
        {
          cout << "Ambil data: " << data[kepala];
          for (a = kepala; a <= ekor - 1; a++)
          data[a] = data[a + 1];
          ekor--;
          if (kepala == -1)
          kepala = -1;
        getch();
        }
}


void Clear()
{
     kepala = ekor = -1;
     cout << "Seluruh data sudah dihapus"; getch();
}


void View()
{
     if (IsEmpty())
        {
            cout << "Data kosong";
            getch();
        }
        else
        {
            for (a = kepala; a <= ekor; a++)
            cout << "Data pada antrian ke " << a << " = " << data[a] << endl;
            getch();
        }
}

int main()
{
        int pilih;
        do
        {
                if (system("CLS")) system("clear");
                cout << "1. Enqueue " << endl;
                cout << "2. Dequeue " << endl;
                cout << "3. Clear " << endl;
                cout << "4. View " << endl;
                cout << "5. Exit " << endl;
                cout << "Masukkan pilihan Anda : ";
                cin >> pilih;
                switch (pilih)
                {
                case 1:
                        Enqueue(); break;
                case 2:
                        Dequeue(); break;
                case 3:
                        Clear(); break;
                case 4:
                        View(); break;
                }
        } while (pilih != 5);
}
