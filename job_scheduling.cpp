#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
  string id;
  int deadline, profit;
};

vector<Job>jobFromClient = {{"a", 4, 70}, {"b", 2, 60}, {"c", 4, 50}, {"d", 3, 40}, {"e", 1, 30}, {"f", 4, 20}, {"g", 6, 100}, {"h", 6, 20}};
vector<Job>jobIdDipilih;

void urutkanByDeadline() {
  sort(jobFromClient.begin(), jobFromClient.end(), [](auto&a, auto&b) {
      return a.deadline < b.deadline;
      });
}


void pilihJobYangMasok() {
  int deadline = jobFromClient[0].deadline;
  int profit = jobFromClient[0].profit;
  string id = jobFromClient[0].id;

  for(auto &i : jobFromClient) {
    if (deadline == i.deadline ) {
      if (profit < i.profit) {
        profit = i.profit;
        id = i.id;
        profit = i.profit;
        deadline = i.deadline;
      }
    } else {
      jobIdDipilih.push_back({id, deadline, profit});
      id = i.id;
      profit = i.profit;
      deadline = i.deadline;
    }
  }

  jobIdDipilih.push_back({id, deadline, profit});

  
}

void cetak() {
  for(auto &i : jobFromClient) {
    cout << i.id << " --- " << i.deadline << " ---- " << i.profit << endl;
  }
}

void cetakYangBenar() {
  cout << "ini job yang aku pilih bro" << endl;
  for(auto &i : jobIdDipilih) {
    cout << i.id << " --- " << i.deadline << " ---- " << i.profit << endl;
  }
}


int main (int argc, char *argv[]) {
  cetak();
  urutkanByDeadline();
  cout << "setelah diurutkan " << endl;
  cetak();
  pilihJobYangMasok();
  cetakYangBenar();
  return 0;
}
