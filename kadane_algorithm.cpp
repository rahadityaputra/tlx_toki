#include <iostream>
#include <vector>

using namespace std;


vector<int>arr = {2, -5, -1, -3, 7, -5, -6, 10};

void kadane() {
  int max_ending_here = 0;
  int max_so_far = 0;
  int start = 0;
  int finish = 0;
  for (int i = 0; i < arr.size(); i++) {
    max_ending_here += arr[i];

    if(max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
      finish = i;
    } else if(max_ending_here < 0) {
      max_ending_here = 0;
      start = i + 1;
    }
  }
  
  cout << max_so_far << endl;

  cout << "start" << endl;
  for (int i = start; i <= finish; i++) {
    cout << arr[i] << endl;
    
  }
  cout << "finish" << endl;
}


int main() {
  kadane();
}

