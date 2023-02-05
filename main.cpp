#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <sstream>

using namespace std;

void fakeLoadingResource(); // Membuat Fake Loading
void perkenalan(); // Membuat tampilan perkenalan
int pilihGenre(int pil); // Tampilan pilih genre buku
void programUtama(); // Program utama
string tanggal(int jmlhMinggu); // membuat tanggal lokal sekarang dan + jumlah minggu pemesanan
void listHarga(); // Tampilan list harga
int jmlhDiskon(int waktu, int tHarga); // membuat nilai disoko
string displayDiskon(int waktu); // menampilkan presentase diskon
void showBon(string nama, string alamat, string noHp, string judul, string tanggalSewa, int lamaSewa, string tanggalPengembalian, int hargaPerMinggu, int harga, string diskon, int hargaBayar); // menampilkan bon
void terimakasih(); // animasi terimakasih di akhir program

int main(){
	char konfirmasi;

	system("cls");
	perkenalan();
	fakeLoadingResource();
	program:	
	programUtama();
	
	cout << endl;
	sewalagi:
	cout << "Apakah anda ingin menyewa lagi (y/n) ? ";
	cin >> konfirmasi;
	if(konfirmasi == 'Y' || konfirmasi == 'y'){
		system("cls");
		goto program;
	}else if(konfirmasi == 'N' || konfirmasi == 'n'){
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t";
		terimakasih();
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		getch();
	}else{
		system("cls");
		cout << "Input tidak valid!" << endl;
		system("pause");
		system("cls");
		goto sewalagi;
	}
}

void programUtama(){
	int pil, pilBook, waktu, tHarga, uang, diskon, tBayar, kembalian;
	char konfirmasi;
	string dDiskon, nama, alamat, noHp;
	string pendidikan[3] = {"Pendidikan Agama Islam", "Matematika", "Algoritma Pemrograman 1"};
	string novel[4] = {"Dilan 1945", "Azab Kubur", "Tukang Bubur Naik Haji", "Narto Siudin"};
	string komik[3] = {"Sword Candy", "Hallo Mama", "Shaun The Cow"};
	string tipsnTrik[3] = {"Tips Berdiri di Bawah Meja", "Tips Lulus SMP 1 Tahun", "Tips Push Rank Solo Anti Stress"};
	
	system("cls");

	cout <<"====================================================================="<<endl;
	cout <<"                       SELAMAT DATANG DI E-LIBRARY                   "<<endl;
	cout <<"====================================================================="<<endl;
	cout <<" Masukkan data diri anda"<< endl;
	cout <<" Nama    : "; cin >> nama;
	cout <<" Alamat  : "; cin >> alamat;
	cout <<" No Hp   : "; cin >> noHp;
	cout <<"====================================================================="<<endl;
	system("pause");
	system("cls");

	pilihGenre:
	switch (pilihGenre(pil))
	{
	case 1:
		pilbukuc1:
		cout <<"====================================================================="<<endl;
		cout <<"|                            PENDIDIKAN                             |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"|No.|            Judul Buku                  |     Halaman Buku     |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| 1 | Pendidikan Agama Islam                 | 999 Halaman          |"<<endl;
		cout <<"| 2 | Matematika                             | 666 Halaman          |"<<endl;
		cout <<"| 3 | Algoritma Pemrograman 1                | 123 Halaman          |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| Harga Sewa : Rp.5000/Minggu                                       |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"Masukan pilihan (1-3) : ";
		cin >> pilBook;
		if(pilBook == 1 || pilBook == 2 || pilBook == 3){
			goto lanjutc1;
		}else{
			system("cls");
			cout << "Input tidak valid!" << endl;
			system("pause");
			system("cls");
			goto pilbukuc1;
		}
		lanjutc1:
		cout <<"Waktu Sewa (Minggu)   ? ";
		cin >> waktu;
		cout << endl;
		tHarga = 5000 * waktu;
		for(int i = 0; i < 3; i++){
			if(pilBook-1 == i){
				konfirmasic1:
				cout << "Apakah anda yakin dengan pilihan anda (y/n) ? " ; 
				cin >> konfirmasi; 
				if(konfirmasi == 'Y' || konfirmasi == 'y'){
					system("cls");
					tBayar = tHarga - jmlhDiskon(waktu, tHarga);
					showBon(nama, alamat, noHp, pendidikan[i], tanggal(0), waktu, tanggal(waktu), 5000, tHarga, displayDiskon(waktu), tBayar);
				}else if(konfirmasi == 'N' || konfirmasi == 'n'){
					system("cls");
					goto pilihGenre;
				}else{
					system("cls");
					cout << "Input tidak valid!" << endl;
					system("pause");
					system("cls");
					goto konfirmasic1;
				}
			}
		}
		break;

	case 2:
		pilbukuc2:
		cout <<"====================================================================="<<endl;
		cout <<"|                              NOVEL                                |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"|No.|        Judul Buku                      |     Halaman Buku     |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| 1 | Dilan 1945                             | 178 Halaman          |"<<endl;
		cout <<"| 2 | Azab Kubur                             | 299 Halaman          |"<<endl;
		cout <<"| 3 | Tukang Bubur Naik Haji Season 13       | 3021 Halaman         |"<<endl;
		cout <<"| 4 | Narto Siudin                           | 500 Halaman          |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| Harga Sewa : Rp.10000/Minggu                                       |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"Masukan pilihan (1-4) : ";
		cin >> pilBook;
		if(pilBook == 1 || pilBook == 2 || pilBook == 3 || pilBook ==4){
			goto lanjutc2;
		}else{
			system("cls");
			cout << "Input tidak valid!" << endl;
			system("pause");
			system("cls");
			goto pilbukuc2;
		}
		lanjutc2:
		cout <<"Waktu Sewa (Minggu)   ? ";
		cin >> waktu;
		cout << endl;
		tHarga = 10000 * waktu;

		for(int i = 0; i < 4; i++){
			if(pilBook-1 == i){
				konfirmasic2:
				cout << "Apakah anda yakin dengan pilihan anda (y/n) ? " ; 
				cin >> konfirmasi; 
				if(konfirmasi == 'Y' || konfirmasi == 'y'){
					system("cls");
					tBayar = tHarga - jmlhDiskon(waktu, tHarga);
					showBon(nama, alamat, noHp, novel[i], tanggal(0), waktu, tanggal(waktu), 10000, tHarga, displayDiskon(waktu), tBayar);
				}else if(konfirmasi == 'N' || konfirmasi == 'n'){
					system("cls");
					goto pilihGenre;
				}else{
					system("cls");
					cout << "Input tidak valid!" << endl;
					system("pause");
					system("cls");
					goto konfirmasic2;
				}
			}
		}
		break;

	case 3:
		pilbukuc3:
		cout <<"====================================================================="<<endl;
		cout <<"|                              KOMIK                                |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"|No.|        Judul Buku                      |     Halaman Buku     |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| 1 | Sword Candy                            | 111 Halaman          |"<<endl;
		cout <<"| 2 | Hello Mama                             | 92 Halaman           |"<<endl;
		cout <<"| 3 | Shaun The Cow                          | 121 Halaman          |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| Harga Sewa : Rp.3000/Minggu                                       |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"Masukan pilihan (1-3) : ";
		cin >> pilBook;
		if(pilBook == 1 || pilBook == 2 || pilBook == 3){
			goto lanjutc3;
		}else{
			system("cls");
			cout << "Input tidak valid!" << endl;
			system("pause");
			system("cls");
			goto pilbukuc3;
		}
		lanjutc3:
		cout <<"Waktu Sewa (Minggu)   ? ";
		cin >> waktu;
		cout << endl;
		tHarga = 3000 * waktu;

		for(int i = 0; i < 4; i++){
			if(pilBook-1 == i){
				konfirmasic3:
				cout << "Apakah anda yakin dengan pilihan anda (y/n) ? " ; 
				cin >> konfirmasi; 
				if(konfirmasi == 'Y' || konfirmasi == 'y'){
					system("cls");
					tBayar = tHarga - jmlhDiskon(waktu, tHarga);
					showBon(nama, alamat, noHp, komik[i], tanggal(0), waktu, tanggal(waktu), 3000, tHarga, displayDiskon(waktu), tBayar);
				}else if(konfirmasi == 'N' || konfirmasi == 'n'){
					system("cls");
					goto pilihGenre;
				}else{
					system("cls");
					cout << "Input tidak valid!" << endl;
					system("pause");
					system("cls");
					goto konfirmasic3;
				}
			}
		}
		break;

	case 4:
		pilbukuc4:
		cout <<"====================================================================="<<endl;
		cout <<"|                           Tips dan Trik                           |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"|No.|        Judul Buku                      |     Halaman Buku     |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| 1 | Tips Berdiri di Bawah Meja             | 111 Halaman          |"<<endl;
		cout <<"| 2 | Tips Lulus SMP 1 Tahun                 | 92 Halaman           |"<<endl;
		cout <<"| 3 | Tips Push Rank Solo Anti Stress        | 121 Halaman          |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"| Harga Sewa : Rp.4000/Minggu                                       |"<<endl;
		cout <<"====================================================================="<<endl;
		cout <<"Masukan pilihan (1-3) : ";
		cin >> pilBook;
		if(pilBook == 1 || pilBook == 2 || pilBook == 3){
			goto lanjutc4;
		}else{
			system("cls");
			cout << "Input tidak valid!" << endl;
			system("pause");
			system("cls");
			goto pilbukuc4;
		}
		lanjutc4:
		cout <<"Waktu Sewa (Minggu)   ? ";
		cin >> waktu;
		cout << endl;
		tHarga = 4000 * waktu;

		for(int i = 0; i < 4; i++){
			if(pilBook-1 == i){
				konfirmasic4:
				cout << "Apakah anda yakin dengan pilihan anda (y/n) ? " ; 
				cin >> konfirmasi; 
				if(konfirmasi == 'Y' || konfirmasi == 'y'){
					system("cls");
					tBayar = tHarga - jmlhDiskon(waktu, tHarga);
					showBon(nama, alamat, noHp, tipsnTrik[i], tanggal(0), waktu, tanggal(waktu), 4000, tHarga, displayDiskon(waktu), tBayar);
				}else if(konfirmasi == 'N' || konfirmasi == 'n'){
					system("cls");
					goto pilihGenre;
				}else{
					system("cls");
					cout << "Input tidak valid!" << endl;
					system("pause");
					system("cls");
					goto konfirmasic4;
				}
			}
		}
		break;

	default:
		system("cls");
		cout << "Input Tidak Valid !" << endl;
		system("pause");
		system("cls");
		goto pilihGenre;
		break;
	}
}

void perkenalan(){
	cout << "=====================================================================" << endl; Sleep(100);
	cout << "||                   Program Sewa Buku Perpustakaan                ||" << endl; Sleep(100);
	cout << "=====================================================================" << endl; Sleep(100);
	cout << "||                       Dibuat oleh Kelompok 4                    ||" << endl; Sleep(100);
	cout << "||                     \\\\----------------------//                  ||" << endl; Sleep(100);
	cout << "||                                                                 ||" << endl; Sleep(100);
	cout << "||  Dengan Anggota : Aridwan               22552011189             ||" << endl; Sleep(100);
	cout << "||                   Ega Sulanjana         22552011171             ||" << endl; Sleep(100);
	cout << "||                                                                 ||" << endl; Sleep(100);
	cout << "=====================================================================" << endl; Sleep(100);
	system("pause");
	system("cls");
}

void fakeLoadingResource(){
cout << "\n\n\n\t\tLoading Resources, Please Wait";
	for(int i = 0; i < 6; i++){
		cout << "."; 
		Sleep(200);
	}
	system("cls");
}

int pilihGenre(int pil){
	cout <<"====================================================================="<<endl;
	cout <<"                       SELAMAT DATANG DI E-LIBRARY                   "<<endl;
	cout <<"====================================================================="<<endl;
	cout <<"                              ~Genre buku~                           "<<endl;
	cout <<"                         \\\\------------------//                    "<<endl;
	cout <<" ___________________________________________________________________ "<<endl;
	cout <<"|   Pendidikan   |     Novel      |     Komik      | Tips and Trik  |"<<endl;
	cout <<"|______(1)_______|______(2)_______|______(3)_______|______(4)_______|"<<endl<<endl;
	listHarga();
	cout <<"Pilih Genre buku yang mau di sewa (1-4): ";
	cin >>pil;
	system("cls");
	return pil;
}

void listHarga(){
	cout << " List Harga Sewa/Minggu                                              " << endl;
	cout << " Buku Pendidikan    : Rp. 5000                                       " << endl;
	cout << " Buku Novel         : Rp. 10000                                      " << endl;
	cout << " Buku Komik         : RP. 3000                                       " << endl;
	cout << " Buku Tips & Trick  : Rp. 4000                                       " << endl << endl;
	cout << " Diskon Akhir Tahun                                                  " << endl;
	cout << " Sewa lebih dari 2 Minggu diskon 3%                                            " << endl;
	cout << " Sewa lebih dari 4 Minggu diskon 10%                                           " << endl;
	cout << " Sewa lebih dari 8 Minggu diskon 15%                                           " << endl;
	cout << "=====================================================================" << endl;
}


void showBon(string nama, string alamat, string noHp, string judul, string tanggalSewa, int lamaSewa, string tanggalPengembalian, int hargaPerMinggu, int harga, string diskon, int hargaBayar){
	int uang, kembalian;

	cout << "=====================================================================" << endl;
	cout << "                              E-Library                              " << endl;
	cout << "=====================================================================" << endl;
	cout << " Identitas Customer" << endl;
	cout << " Nama                 : " << nama << endl;
	cout << " Alamat               : " << alamat << endl;
	cout << " No HP                : " << noHp << endl;
	cout << endl;
	cout << " Informasi Buku" << endl;
	cout << " Judul Buku           : " << judul << endl;
	cout << " Tanggal Sewa         : " << tanggalSewa << endl;
	cout << " Lama Sewa            : " << lamaSewa << " Minggu" << endl;
	cout << " Tanggal Pengembalian : " << tanggalPengembalian << endl;
	cout << endl;
	cout << " Informasi Harga" << endl;
	cout << " Harga Per Minggu     : Rp." << hargaPerMinggu << endl;
	cout << " Harga Total          : Rp." << harga << endl;
	cout << " Diskon               : " << diskon << endl;
	cout << " Harga bayar          : Rp." << hargaBayar << endl;
	cout << endl;
	cout << " Uang Anda            : Rp."; cin >> uang;
	kembalian = uang - hargaBayar;
	cout << " Kembalian            : Rp." << kembalian << endl;
	cout << "=====================================================================" << endl;
}


int jmlhDiskon(int waktu, int tHarga){
	float diskon;
	if(waktu >= 2 && waktu < 4){
		diskon = 0.03 * tHarga;
	}else if(waktu >= 4 && waktu <8){
		diskon = 0.10 * tHarga;
	}else if(waktu >= 8){
		diskon = 0.15 * tHarga;
	}else{
		diskon = 0 * tHarga;
	}
	return diskon;
}

string displayDiskon(int waktu){
	string dDiskon;
	if(waktu >= 2 && waktu < 4){
		dDiskon = "3%";
	}else if(waktu >= 4 && waktu <8){
		dDiskon = "10%";
	}else if(waktu >= 8){
		dDiskon = "15%";
	}else{
		dDiskon = "0%";
	}
	return dDiskon;
}

string tanggal(int jmlhMinggu){
  string date;
  time_t now = time(0) + (604800 * jmlhMinggu);// mendapatkan jumlah detik sejak dari 1 januari 1970
  tm *gotTime = localtime(&now); // mengembalikan pointer ke tm struktur untuk merepresentasikan waktu lokal

  
  int hari = gotTime->tm_mday; // mendapatkan tanggal hari sekarang
  int bulan = 1 + gotTime->tm_mon; // mendapatkan bulan sekarang
  int tahun = 1900 + gotTime->tm_year; // mendapatkan tahun sekarang

  string namaBulan;
  switch (bulan) // untuk convert bulan menjadi namanya
  {
  case 1:
    namaBulan = "Januari";
    break;
  case 2:
    namaBulan = "Februari";
    break;
  case 3:
    namaBulan = "Maret";
    break;
  case 4:
    namaBulan = "April";
    break;
  case 5:
    namaBulan = "Mei";
    break;
  case 6:
    namaBulan = "Juni";
    break;
  case 7:
    namaBulan = "Juli";
    break;
  case 8:
    namaBulan = "Agustus";
    break;
  case 9:
    namaBulan = "September";
    break;
  case 10:
    namaBulan = "Oktober";
    break;
  case 11:
    namaBulan = "November";
    break;
  case 12:
    namaBulan = "Desember";
    break;
  
  default:
    break;
  }
  
  // mengubah hari dan tahun menjadi string agar bisa dilakukan concation
  stringstream ss;
  ss << hari;
  string hariS;
  ss >> hariS;
  
  stringstream sso;
  sso << tahun;
  string tahunS;
  sso >> tahunS;
  
  // penyatuan variabel menjadi format hari bulan tanggal 
  return hariS + " " + namaBulan + " " + tahunS;
}

void terimakasih(){
		cout << 'T'; Sleep(100);
		cout << 'e'; Sleep(100);
		cout << 'r'; Sleep(100);
		cout << 'i'; Sleep(100);
		cout << 'm'; Sleep(100);
		cout << 'a'; Sleep(100);
		cout << 'k'; Sleep(100);
		cout << 'a'; Sleep(100);
		cout << 's'; Sleep(100);
		cout << 'i'; Sleep(100);
		cout << 'h'; Sleep(100);
		cout << ' '; Sleep(100);
		cout << 'T'; Sleep(100);
		cout << 'e'; Sleep(100);
		cout << 'l'; Sleep(100);
		cout << 'a'; Sleep(100);
		cout << 'h'; Sleep(100);
		cout << ' '; Sleep(100);
		cout << 'B'; Sleep(100);
	cout << 'e'; Sleep(100);
	cout << 'r'; Sleep(100);
	cout << 'k'; Sleep(100);
	cout << 'u'; Sleep(100);
	cout << 'n'; Sleep(100);
	cout << 'j'; Sleep(100);
	cout << 'u'; Sleep(100);
	cout << 'n'; Sleep(100);
	cout << 'g'; Sleep(100);
	cout << ' '; Sleep(100);
	cout << ':'; Sleep(100);
	cout << 'D'; Sleep(100);
}
