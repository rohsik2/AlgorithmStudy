#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int highest[524288*2];
int n_size;

int tree[524288*2];

void inserts(pair<int, int>& a){
  int cur = 524286+a.first;
  while(cur != 0){
    tree[cur] = min(tree[cur], a.second);
    cur = (cur-1)/2;
  }
}

int find2(pair<int,int>& a, int strt, int end, int cur){
  //cout<<a.first<<' '<<strt<<' '<<end<<' '<<cur<<' '<<endl;

  if(strt+1 == end)
    return tree[cur];
  int mid = (strt+end)/2;

  if(a.first > end)
    return tree[cur];

  if(a.first < strt)
    return 987654321;

  if(a.first > mid)
    return min(find2(a, strt,  mid, (cur+1)*2-1),
               find2(a, mid, end, (cur+1)*2));
  else
    return find2(a, strt, mid, (cur+1)*2-1);
}

void set(int idx, int num){
  auto a = make_pair(idx, num);
  inserts(a);
}

int find(int idx){
  auto a = make_pair(idx,0);
  return find2( a, 0 , 524288, 0);
}


struct Data{
  int rank[3];
};

bool comp1(Data& d1, Data&d2){
  return d1.rank[0] < d2.rank[0];
}

int main(){
  ios::sync_with_stdio(false);
  for(int i =0 ; i<524288*2; i++)
    tree[i] = 987654321;

  
  cin>>n_size;
  vector<Data> v;
  v.resize(n_size);
  for(int j =0; j<3; j++)
    for(int i = 0; i<n_size; i++){
      int temp;
      cin>>temp;
      v[temp-1].rank[j] = i+1;
    }
  sort(v.begin(), v.end(), comp1);
  int cnt = 0;
  for(auto& walker : v){
    //cout<<walker.rank[0]<<' '<<walker.rank[1]<<' '<<walker.rank[2]<<' '<<find(walker.rank[1])<<endl;
    if(walker.rank[2] < find(walker.rank[1]))
      cnt++;
    set(walker.rank[1], walker.rank[2]);
  }
  cout<<cnt;
  return 0;
}