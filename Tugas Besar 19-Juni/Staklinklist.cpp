#include <iostream>
using namespace std;

// Stack Linked List menggunakan struct
struct Lagu {
    string judulLagu;
    string artisLagu;
    int durasiLagu;

    Lagu* prev;
    Lagu* next;
};

Lagu* head = nullptr;
Lagu* tail = nullptr;
Lagu* cur = nullptr;
Lagu* newNode = nullptr;
Lagu* del = nullptr;

int maksimalLagu = 5;

// Fungsi untuk menghitung jumlah lagu dalam stack
int countLagu() {
    if (head == nullptr) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

// Cek apakah stack penuh
bool isFullLagu() {
    return countLagu() == maksimalLagu;
}

// Cek apakah stack kosong
bool isEmptyLagu() {
    return countLagu() == 0;
}

// Menambahkan lagu ke dalam stack
void pushLagu(string judulLagu, string artisLagu, int durasiLagu) {
    if (isFullLagu()) {
        cout << "Stack penuh!" << endl;
    } else {
        if (isEmptyLagu()) {
            head = new Lagu();
            head->judulLagu = judulLagu;
            head->artisLagu = artisLagu;
            head->durasiLagu = durasiLagu;
            head->prev = nullptr;
            head->next = nullptr;
            tail = head;
        } else {
            newNode = new Lagu();
            newNode->judulLagu = judulLagu;
            newNode->artisLagu = artisLagu;
            newNode->durasiLagu = durasiLagu;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
        }
    }
}

// Menghapus lagu dari stack
void popLagu() {
    if (isEmptyLagu()) {
        cout << "Stack kosong!" << endl;
    } else {
        del = tail;
        if (tail->prev != nullptr) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = nullptr;
            tail = nullptr;
        }
        delete del;
    }
}

// Menampilkan lagu dalam stack
void displayLagu() {
    if (isEmptyLagu()) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "\nData lagu dalam stack:" << endl;
        cur = tail;
        while (cur != nullptr) {
            cout << "Judul Lagu: " << cur->judulLagu << ", Artis Lagu: " << cur->artisLagu << ", Durasi Lagu: " << cur->durasiLagu << " detik" << endl;
            cur = cur->prev;
        }
    }
}

// Mengintip lagu pada posisi tertentu
void peekLagu(int posisi) {
    if (isEmptyLagu()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cout << "Lagu pada posisi ke-" << posisi << ": " << cur->judulLagu << ", Artis Lagu: " << cur->artisLagu << ", Durasi Lagu: " << cur->durasiLagu << " detik" << endl;
        } else {
            cout << "Posisi lagu tidak valid!" << endl;
        }
    }
}

// Mengubah lagu pada posisi tertentu
void changeLagu(string judulLagu, string artisLagu, int durasiLagu, int posisi) {
    if (isEmptyLagu()) {
        cout << "Stack kosong!" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi && cur != nullptr) {
            cur = cur->prev;
            nomor++;
        }
        if (cur != nullptr) {
            cur->judulLagu = judulLagu;
            cur->artisLagu = artisLagu;
            cur->durasiLagu = durasiLagu;
        } else {
            cout << "Posisi lagu tidak valid!" << endl;
        }
    }
}

// Menghapus semua lagu dalam stack
void destroyLagu() {
    cur = head;
    while (cur != nullptr) {
        del = cur;
        cur = cur->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
}

int main() {
    // Contoh penggunaan fungsi-fungsi stack lagu
    pushLagu("Lagu1", "Artis1", 180);
    displayLagu();
    pushLagu("Lagu2", "Artis2", 210);
    pushLagu("Lagu3", "Artis3", 240);
    pushLagu("Lagu4", "Artis4", 150);
    pushLagu("Lagu5", "Artis5", 200);
    displayLagu();

    pushLagu("Lagu6", "Artis6", 220); // Akan gagal karena stack penuh
    displayLagu();

    popLagu();
    displayLagu();

    cout << "Apakah stack lagu penuh? " << (isFullLagu() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack lagu kosong? " << (isEmptyLagu() ? "Ya" : "Tidak") << endl;

    peekLagu(3);

    cout << "Jumlah lagu dalam stack: " << countLagu() << endl;

    changeLagu("LaguUbah", "ArtisUbah", 260, 2);
    displayLagu();

    destroyLagu();
    cout << "Apakah stack lagu penuh? " << (isFullLagu() ? "Ya" : "Tidak") << endl;
    cout << "Apakah stack lagu kosong? " << (isEmptyLagu() ? "Ya" : "Tidak") << endl;
    cout << "Jumlah lagu dalam stack: " << countLagu() << endl;

    displayLagu(); // Tampilkan lagu setelah destroy untuk memastikan semua terhapus

    return 0;
}
