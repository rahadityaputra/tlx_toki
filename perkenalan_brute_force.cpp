#include <iostream>

using namespace std;


void solution(string A, string B) {
    for (int i = 0; i < A.size(); i++)
    {
        string C = A;
        if (C.erase(i, 1) == B)
        {
            cout << "Tentu saja bisa!" << endl;
            return;
        }
        
    }

    cout << "Wah, tidak bisa :(" << endl;
}

string A, B;
int main(){

    cin >> A >> B;

    solution(A, B);
}