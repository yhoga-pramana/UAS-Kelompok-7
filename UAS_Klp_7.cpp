#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

string jenis[MAX];
int jumlah[MAX];
int totalTransaksi = 0;

void setor(int saldo);
void tarik(int saldo);
void transfer(int saldo);
void cekSaldo(int saldo);
void riwayat();
void statusKeuangan(int saldo); 

int main() {
    int saldo = 0;
    int pilihan;

    cout << "=== PROGRAM MANAJEMEN KEUANGAN PRIBADI ===\n";
    cout << "Masukkan saldo awal: Rp ";
    cin >> saldo;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Setor Uang\n";
        cout << "3. Tarik Uang\n";
        cout << "4. Transfer\n";
        cout << "5. Riwayat Transaksi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            	cekSaldo(saldo);
            	break;
            case 2:
            	setor(saldo);
            	break;
            case 3:
            	tarik(saldo);
            	break;
            case 4:
            	transfer(saldo);
            	break;
            case 5:
            	riwayat();
            	break;
            case 6:
                cout << "Program selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}

void statusKeuangan(int saldo) {
    cout << "Status Keuangan : ";

    if (saldo < 100000) {
        cout << "PERLU PENGHEMATAN! Saldo sangat rendah.\n";
    }
    else if (saldo >= 100000 && saldo <= 500000) {
        cout << "Harap hemat, saldo mulai menipis.\n";
    }
    else {
        cout << "Aman. Keuangan stabil.\n";
    }
}

void cekSaldo(int saldo) {
    cout << "\nSaldo Anda saat ini: Rp " << saldo << endl;
    statusKeuangan(saldo);
}

void setor(int saldo) {
    int tambah;
    int saldoSebelum = saldo;

    cout << "\nMasukkan jumlah setor: Rp ";
    cin >> tambah;

    saldo += tambah;

    jenis[totalTransaksi] = "Setor";
    jumlah[totalTransaksi] = tambah;
    totalTransaksi++;

    cout << "\n=== HASIL TRANSAKSI SETOR ===\n";
    cout << "Jumlah disetor : Rp " << tambah << endl;
    cout << "Saldo sebelum  : Rp " << saldoSebelum << endl;
    cout << "Saldo sesudah  : Rp " << saldo << endl;

    statusKeuangan(saldo);
}

void tarik(int saldo) {
    int ambil;
    int saldoSebelum = saldo;

    cout << "\nMasukkan jumlah penarikan: Rp ";
    cin >> ambil;

    if (ambil > saldo) {
        cout << "Saldo tidak cukup!\n";
        return;
    }

    saldo -= ambil;

    jenis[totalTransaksi] = "Tarik";
    jumlah[totalTransaksi] = ambil;
    totalTransaksi++;

    cout << "\n=== HASIL TRANSAKSI PENARIKAN ===\n";
    cout << "Jumlah ditarik : Rp " << ambil << endl;
    cout << "Saldo sebelum  : Rp " << saldoSebelum << endl;
    cout << "Saldo sesudah  : Rp " << saldo << endl;

    statusKeuangan(saldo);
}

void transfer(int saldo) {
    int nominal;
    string rek;
    int saldoSebelum = saldo;

    cout << "\nMasukkan nomor rekening tujuan: ";
    cin >> rek;

    cout << "Jumlah yang ingin ditransfer: Rp ";
    cin >> nominal;

    if (nominal > saldo) {
        cout << "Saldo tidak cukup!\n";
        return;
    }

    saldo -= nominal;

    jenis[totalTransaksi] = "Transfer ke " + rek;
    jumlah[totalTransaksi] = nominal;
    totalTransaksi++;

    cout << "\n=== HASIL TRANSAKSI TRANSFER ===\n";
    cout << "Rekening tujuan: " << rek << endl;
    cout << "Jumlah transfer : Rp " << nominal << endl;
    cout << "Saldo sebelum   : Rp " << saldoSebelum << endl;
    cout << "Saldo sesudah   : Rp " << saldo << endl;

    statusKeuangan(saldo);
}

void riwayat() {
    cout << "\n=== RIWAYAT TRANSAKSI ===\n";

    if (totalTransaksi == 0) {
        cout << "Belum ada transaksi.\n";
        return;
        
    }

    for (int i = 0; i < totalTransaksi; i++) {
        cout << i + 1 << ". " << jenis[i] << " - Rp " << jumlah[i] << endl;
    }
}
