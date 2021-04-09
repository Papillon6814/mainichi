#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void init(int n, vector<int>& v){
  v.resize(n);
  for(int i = 0; i < n; i++){
    v[i] = i;
  }
}
int root(int a, vector<int>& v){
  if(v[a] == a) return a;
  return (v[a] = root(v[a], v));
}

bool same(int a, int b, vector<int>& v){
  return root(a,v) == root(b,v);
}

void unite(int a, int b, vector<int>& v){
  v[root(a,v)] = root(b,v);
}


int main(){
  int N;
  cin >> N;
  int K,L;
  cin >> K >> L;
  vector<int> road,train;
  init(N, road); init(N, train);
  for(int i = 0; i < K; i++){
    int p,q;
    cin >> p >> q;
    unite(p-1, q-1, road);
  }

  for(int i = 0; i < L; i++){
    int r,s;
    cin >> r >> s;
    unite(r-1, s-1, train);
  }

  map<pair<int, int>, int> mp;

  for(int i = 0; i < N; i++){
    pair<int, int> nRoot = { root(i, road), root(i, train) };
    auto itr = mp.find(nRoot);
    if(itr != mp.end()){
      mp[nRoot]++;
    }else{
      mp[nRoot] = 1;
    }
  }

  // vector<int> ans(N, 1);
  for(int i = 0; i < N; i++){
  //   for(int j = i+1; j < N; j++){
  //     if(same(i, j, road) && same(i, j, train)){
  //       ans[i]++;
  //       ans[j]++;
  //     }
  //   }
    // cout << ans[i];
    cout << mp[{root(i, road), root(i, train)}];
    if(i < N-1)
      cout << " ";
  }
  // for(int i = 0; i < N; i++){
  //   cout << ans[i];
  //   if(i < N-1)
  //     cout << " ";
  // }
  cout << endl;
  return 0;
}
