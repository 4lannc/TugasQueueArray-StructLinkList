#include <iostream>
using namespace std;

struct Lagu {
    string judulLagu;
    string artisLagu;
    int durasiLagu;
};

// array Antrian
int maksimalAntrianArray = 3, front = 0, back = 0;
// ruang antrian array
Lagu antrianLagu[3];

// isFull / cek data antrian penuh atau tidak
bool isFull() {
    return back == maksimalAntrianArray;
}

// isEmpty
bool isEmpty() {
    return back == 0;
}

// tambahLagu / penambahan data antrian
void tambahLagu(Lagu data) {
    if (isFull()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianLagu[back] = data;
        back++;
    }
}

// hapusLaguAwal / penghapusan data depan
void hapusLaguAwal() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            antrianLagu[i] = antrianLagu[i + 1];
        }
        back--;
    }
}

// menghitung / menghitung banyak data yg ngantri
int menghitung() {
    return back;
}

// hapusLagu / clear
void hapusLagu() {
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        back = 0;
        front = 0;
    }
}

// cetakLagu / View
void cetakLagu() {
    cout << "Jumlah data yg ngantri : " << menghitung() << " data." << endl;
    cout << "Data Antrian Lagu : " << endl;
    if (isEmpty()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        for (int i = 0; i < maksimalAntrianArray; i++) {
            // cek apakah ruang kosong atau tidak
            if (i < back) {
                cout << i + 1 << ". " << antrianLagu[i].judulLagu << " - " << antrianLagu[i].artisLagu << " - " << antrianLagu[i].durasiLagu << " detik" << endl;
            } else {
                cout << i + 1 << ". (kosong)" << endl;
            }
        }
    }
    cout << "\n" << endl;
}

int main() {
    Lagu lagu1 = {"Lagu1", "Artis1", 180};
    Lagu lagu2 = {"Lagu2", "Artis2", 210};
    Lagu lagu3 = {"Lagu3", "Artis3", 240};
    Lagu lagu4 = {"Lagu4", "Artis4", 150};
    Lagu lagu5 = {"Lagu5", "Artis5", 200};

    tambahLagu(lagu1);
    cetakLagu();

    tambahLagu(lagu2);
    tambahLagu(lagu3);
    tambahLagu(lagu4);
    tambahLagu(lagu5);
    cetakLagu();

    Lagu lagu6 = {"Lagu6", "Artis6", 220};
    tambahLagu(lagu6);
    cetakLagu();

    hapusLaguAwal();
    cetakLagu();

    hapusLagu();
    cetakLagu();

    cout << "Jumlah lagu dalam antrian: " << menghitung() << endl;

    return 0;
}
