# Program Penggajian Pegawai dan Dosen

## Deskripsi
Program ini adalah sistem sederhana untuk mengelola penggajian pegawai dan dosen berdasarkan masa kerja, golongan, dan jumlah SKS yang diajar oleh dosen.

## Fitur Utama
- **Input Data Pegawai**: Menambahkan pegawai dengan nama, masa kerja, dan golongan.
- **Input Data Dosen**: Menambahkan dosen dengan nama, masa kerja, SKS yang diajar, dan jabatan fungsional.
- **Perhitungan Gaji**:
  - Pegawai mendapatkan gaji pokok sebesar 3.000.000.
  - Jika masa kerja lebih dari 10 tahun, pegawai mendapatkan tambahan 3.000.000.
  - Gaji lembur dihitung berdasarkan golongan: A1 (10.000/jam), A2 (15.000/jam), A3 (20.000/jam).
  - Dosen mendapatkan gaji pokok sebesar 4.000.000.
  - Jika masa kerja lebih dari 10 tahun, dosen mendapatkan tambahan 3.000.000.
  - Kelebihan SKS diajar dihitung berdasarkan jabatan: AA (40.000/SKS), Lektor (55.000/SKS), Lektor Kepala (75.000/SKS), GB (150.000/SKS).
- **Laporan Gaji**: Menampilkan daftar pegawai dan dosen beserta gaji yang diterima.

## Cara Menggunakan
1. **Kompilasi kode**:
   ```sh
   g++ -o penggajian penggajian.cpp
   ```
2. **Jalankan program**:
   ```sh
   ./penggajian
   ```
3. **Pilih menu yang tersedia**:
   - 1: Input Pegawai
   - 2: Input Dosen
   - 3: Hitung Gaji Pegawai/Dosen
   - 4: Laporan Gaji
   - 5: Keluar

## Struktur Data
- `class Pegawai`:
  - Atribut: `nama`, `gajiPokok`, `lembur`, `masaKerja`, `golongan`.
  - Metode: `hitungGaji()` untuk menghitung total gaji pegawai.
- `class Dosen`:
  - Atribut: `nama`, `gajiPokok`, `masaKerja`, `sksDiajar`, `jabatanFungsional`.
  - Metode: `hitungGaji()` untuk menghitung total gaji dosen.

## Kontributor
Program ini dibuat oleh:
- **Aditya Eka Narayan**
- **NIM: A11.2024.15940**
- **Kelas: 4110**

## Lisensi
Program ini bersifat open-source dan dapat digunakan serta dimodifikasi sesuai kebutuhan.

---
Terima kasih telah menggunakan program ini!

