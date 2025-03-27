#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Pegawai {
public:
    string nama;
    double gajiPokok = 3000000;
    double lembur = 0;
    int masaKerja;
    string golongan;
    Pegawai(string n, int m, string g) : nama(n), masaKerja(m), golongan(g) {}

    double hitungGaji() const {
        double totalGaji = gajiPokok;
        if (masaKerja > 10) {
            totalGaji += 3000000;
        }
        if (masaKerja >= 1) {
            if (golongan == "A1") {
                totalGaji += lembur * 10000;
            } else if (golongan == "A2") {
                totalGaji += lembur * 15000;
            } else if (golongan == "A3") {
                totalGaji += lembur * 20000;
            }
        }
        return totalGaji;
    }
};

class Dosen {
public:
    string nama;
    double gajiPokok = 4000000;
    int masaKerja;
    int sksDiajar;
    string jabatanFungsional;

    Dosen(string n, int m, int sks, string j) : nama(n), masaKerja(m), sksDiajar(sks), jabatanFungsional(j) {}

    double hitungGaji() const {
        double totalGaji = gajiPokok;
        if (masaKerja > 10) {
            totalGaji += 3000000;
        }
        if (sksDiajar > 12) {
            int kelebihanSks = sksDiajar - 12;
            if (jabatanFungsional == "AA") {
                totalGaji += kelebihanSks * 40000;
            } else if (jabatanFungsional == "Lektor") {
                totalGaji += kelebihanSks * 55000;
            } else if (jabatanFungsional == "Lektor Kepala") {
                totalGaji += kelebihanSks * 75000;
            } else if (jabatanFungsional == "GB") {
                totalGaji += kelebihanSks * 150000;
            }
        }
        return totalGaji;
    }
};


vector<Pegawai> pegawaiList;
vector<Dosen> dosenList;


Pegawai inputPegawai() {
    string nama, golongan;
    int masaKerja;
    cout << "Masukkan Nama Pegawai: ";
    cin >> nama;
    cout << "Masukkan Masa Kerja (tahun): ";
    cin >> masaKerja;
    cout << "Masukkan Golongan (A1/A2/A3): ";
    cin >> golongan;

    return Pegawai(nama, masaKerja, golongan);
}


Dosen inputDosen() {
    string nama, jabatanFungsional;
    int masaKerja, sksDiajar;
    cout << "Masukkan Nama Dosen: ";
    cin >> nama;
    cout << "Masukkan Masa Kerja (tahun): ";
    cin >> masaKerja;
    cout << "Masukkan SKS yang diajar: ";
    cin >> sksDiajar;
    cout << "Masukkan Jabatan Fungsional (AA/Lektor/Lektor Kepala/GB): ";
    cin >> jabatanFungsional;

    return Dosen(nama, masaKerja, sksDiajar, jabatanFungsional);
}


vector<pair<string, double>> gajian(int jenis) {
    vector<pair<string, double>> gajiList;

    if (jenis == 1) {
        for (const auto& pegawai : pegawaiList) {
            gajiList.push_back({pegawai.nama, pegawai.hitungGaji()});
        }
    } else if (jenis == 2) {
        for (const auto& dosen : dosenList) {
            gajiList.push_back({dosen.nama, dosen.hitungGaji()});
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    return gajiList;
}


void laporan() {
    cout << "=== Laporan ===" << endl;
    cout << left << setw(20) << "PEGAWAI/DOSEN"
         << setw(15) << "JABATAN"
         << setw(10) << "GAJIPOKOK"
         << setw(15) << "JAM LEBIH/SKS"
         << setw(10) << "GAJI DITERIMA" << endl;

    cout << string(70, '-') << endl;

    for (const auto& pegawai : pegawaiList) {
        cout << left << setw(20) << pegawai.nama
             << setw(15) << pegawai.golongan
             << setw(10) << pegawai.gajiPokok
             << setw(15) << pegawai.lembur
             << setw(10) << fixed << setprecision(2) << pegawai.hitungGaji() << endl;
    }

    for (const auto& dosen : dosenList) {
        cout << left << setw(20) << dosen.nama
             << setw(15) << dosen.jabatanFungsional
             << setw(10) << dosen.gajiPokok
             << setw(15) << dosen.sksDiajar
             << setw(10) << fixed << setprecision(2) << dosen.hitungGaji() << endl;
    }
}


int main() {
    int pilihan;

    while (true) {
        cout << "=== Menu Penggajian ===" << endl;
        cout << "1. Input Anggota" << endl;
        cout << "2. Input Data Buku" << endl;
        cout << "3. Peminjaman" << endl;
        cout << "4. Laporan" << endl;
        cout << "5. Exit" << endl;
        cout << "===================" << endl;
        cout << "Pilih [1..5]: ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (pegawaiList.size() < 2) {
                pegawaiList.push_back(inputPegawai());
                cout << "Pegawai berhasil ditambahkan!" << endl;
            } else {
                cout << "Jumlah pegawai sudah mencapai 2." << endl;
            }
        } else if (pilihan == 2) {
            if (dosenList.size() < 3) {
                dosenList.push_back(inputDosen());
                cout << "Dosen berhasil ditambahkan!" << endl;
            } else {
                cout << "Jumlah dosen sudah mencapai 3." << endl;
            }
        } else if (pilihan == 3) {
            cout << "Pilih jenis: 1. Pegawai 2. Dosen: ";
            int jenis;
            cin >> jenis;
            auto gajiList = gajian(jenis);
            for (const auto& [nama, gaji] : gajiList) {
                cout << "Nama: " << nama << ", Gaji: " << fixed << setprecision(2) << gaji << endl;
            }
        } else if (pilihan == 4) {
            laporan();
        } else if (pilihan == 5) {
            cout << "Terima kasih! Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    }

    return 0;
}
