#include <iostream>
#include <cmath>
#include <algorithm> // Untuk fungsi reverse()

using namespace std;

void solution(string chars)
{

    
    int N;
    int charsLength = chars.length();
    //cek dulu jumlah karakter <= 255
    if(charsLength > 255) {
        return;
    }

    int x = sqrt(charsLength);

    if (x * x == charsLength)
    {
        N = x;
    }
    else
    {
        N = x + 1;
    }


    string result[N];
    string row = "";
    for (int i = 0; i < (N * N); i++)
    {
       if(!isalnum(chars[i])) {
	       return;
       }

	//cek apakah i itu lebih kecil dari charsLength 
	if(i < charsLength) {
	   row += chars[i];
	} else {
		row += ".";
	}

	if((i + 1) % N == 0) {
				
		if((i / N)  % 2 == 1) {
			reverse(row.begin(), row.end());
		}
				
		result[i / N] = row;
		row = "";
	}

    }


    //cetak array yang sudah terisi
    for (int i = 0; i < N; i++)
    {
	cout << result[i] << endl;
    }
    
}

int main()
{
    string chars;

    cin >> chars;

    solution(chars);
}
