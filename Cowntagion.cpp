#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
map<int,set<int>> m;
vector<bool> v;
int cow(int s){
    v[s]=false;
    int d = 0;int t=0;
    for(int i:m[s]){if(v[i]){d++;}}
    if(d==0){return(0);}
    for(int i:m[s]){if(v[i]){t+=cow(i);}}
    // cout << d << "\n";
    return(int(ceil(log2(d+1)))+d+t);
}
int main(){
    int n;cin >> n;
    for(int i=0;i<n-1;i++){v.push_back(true);int a,b;cin >> a >> b;m[a-1].insert(b-1);m[b-1].insert(a-1);}v.push_back(true);
    // for(int i=0;i<n;i++){cout << i << ": ";for(int j:m[i]){cout << j << " ";}cout << "\n";}
    cout << cow(0) << "\n";
    return(0);
}