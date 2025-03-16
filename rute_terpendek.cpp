#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int calculateTotalDistance(const vector<int>& route, const vector<vector<int>>& dist) {
    int totalDistance = 0;
    int n = route.size();

    for (int i = 0; i < n - 1; i++) {
        totalDistance += dist[route[i]][route[i + 1]];
    }

    totalDistance += dist[route[n - 1]][route[0]];

    return totalDistance;
}

void tampilkanRoute(const vector<int>& route) {
  for (int i = 0; i < route.size(); i++) {
   cout << route[i] << " ===> "; 
  }
}


// Fungsi untuk mencari rute terpendek menggunakan exhaustive search
vector<int> tspExhaustiveSearch(const vector<vector<int>>& dist) {
    int n = dist.size();
    vector<int> route(n);
    for (int i = 0; i < n; i++) {
        route[i] = i;  // Inisialisasi rute: 0, 1, 2, ..., n-1
    }

    vector<int> bestRoute = route;
    int minDistance = INT_MAX;

    // Coba semua permutasi rute
    do {
        int currentDistance = calculateTotalDistance(route, dist);
        tampilkanRoute(route);
        cout << currentDistance << endl;
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestRoute = route;
        }
    } while (next_permutation(route.begin() + 1, route.end()));  // Hindari permutasi yang redundan

    return bestRoute;
}




int main() {
    // Matriks jarak antara kota
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Cari rute terpendek
    vector<int> bestRoute = tspExhaustiveSearch(dist);

    // Output hasil
    cout << "Rute terpendek: ";
    for (int city : bestRoute) {
        cout << city << " ";
    }
    cout << bestRoute[0] << endl;  // Kembali ke kota asal

    // Hitung total jarak
    int totalDistance = calculateTotalDistance(bestRoute, dist);
    cout << "Total jarak: " << totalDistance << endl;

    return 0;
}
