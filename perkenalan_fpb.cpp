#include <iostream>
#include <numeric>
#define ull unsigned long long


using namespace std;

// melakukan operasi penjumlahan terlebih antara kedua bilangan, dengan mengecek penyebut apakah sudah sama , jika sudah sama kita hanya perlu menambahkan pembilangnya, tapi jika belum sama berarti mencari kpk antara penyebut tersebut (dengan euclid) setelah mendapatkan nilai kpk , tinggal menyesuaikan pembilangnya masing masing,dan jumlahkan pembilangnya 
// setelah mendapatkan hasil penjumlahan maka tinggal proses penyerdehanaan dengan mencari fpb antara pembilang dan penyebut hasil penjumlahan tersebut. dan output kan hasilnya ....


void jumlah(ull a,ull b,ull c,ull d) {
	
	long long pembilang, penyebut;
	if(b == d) {
		pembilang = a + c;
		penyebut = b;
	
	} else {
		ull fpb = gcd(b, d);
		long long  kpk = (b * d) / fpb;
		penyebut = kpk;
		pembilang = (kpk / b * a) + (kpk / d * c);
	
	}


	ull fpbHasil = gcd(pembilang, penyebut);

	pembilang = pembilang / fpbHasil;
	penyebut = penyebut / fpbHasil;

	cout << pembilang << " " << penyebut << endl;

}



int main() {

ull a, b, c, d;

cin >> a >> b >> c >> d;

jumlah(a, b, c, d);

}
