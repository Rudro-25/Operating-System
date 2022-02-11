#include <bits/stdc++.h>
using namespace std;

int main()
{
  int pr;  // number of processes
  int re;  // number of resources type
  cin >> pr >> re;

  int alloc[pr][re]; // allocated resources for every process of every resource type
  int mx[pr][re];    // maximum resources needed for every process of every resource type
  int need[pr][re];
  int avail[re];     // remaining available resources right now

  queue <int> rp;    // remaining processes

  for(int i = 0; i < pr; i++) {
    rp.push(i);
    for(int j = 0; j < re; j++) {
      cin >> alloc[i][j];
    }
  }

  for(int i = 0; i < pr; i++) {
    for(int j = 0; j < re; j++) {
      cin >> mx[i][j];
      need[i][j]= mx[i][j]-alloc[i][j];
    }
  }

  for(int i = 0; i < re; i++) {
    cin >> avail[i];
  }

  vector <int> safe_sequence;
  int ct = 0;
  // to find which processes are executable
  while(!rp.empty() and ct <= rp.size()) {
    ++ct;
    int x = rp.front(), flag = 0;
    rp.pop();
    for(int i = 0; i < re; i++) {
      if(need[x][i] > avail[i]) {
        flag = 1;
        break;
      }
    }

    if(flag == 0) {
      ct = 0;
      for(int i = 0; i < re; i++) {
        avail[i] += alloc[x][i];
      }
      safe_sequence.push_back(x);
    }
    else rp.push(x);
  }

  // to check if the system is safe or not
  if(safe_sequence.size() < pr) {
    cout << "the system is not safe" << endl;
  }
  else {
    cout << "the safe sequence is:" << endl;
    for(int i = 0; i < safe_sequence.size(); i++) {
      cout << safe_sequence[i] << ' ';
    }
  }


  return 0;
}
/*
5 4
0 0 1 2
1 0 0 0 
1 3 5 4
0 6 3 2
0 0 1 4

0 0 1 2
1 7 5 0
2 3 5 6
0 6 5 2
0 6 5 6

1 5 2 0

ans:
the safe sequence is:
0 2 3 4 1

*/