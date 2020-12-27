#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;
vector<int> wormHole(vector<int>v, int i, int j){
    int a = v[i];
    v[i]=v[j];
    v[j]=a;
    return(v);
}
bool isSorted(vector<int>v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            return(false);
        }
    }return(true);
}
int main(){
    int n,m;
    vector<int> v;
    vector<pair<int,pair<int,int>>> w;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        int a,b,r;
        cin >> a >> b >> r;
        if(a>b){
            swap(a,b);
        }
        pair<int, pair<int,int>> p;
        p.first=0-r;
        p.second.first=a;
        p.second.second=b;
        w.push_back(p);
    }
    sort(w.begin(),w.end());
    if(isSorted(v)){
        cout << -1;
        return(0);
    }
    int i=-1;
    while(!isSorted(v)){
        m=w[i+1].first;
        i++;
        while(w[i+1].first==m){
            i++;
            if(i=w.size()){
                cout << "wrong";
                return(0);
            }
        }
        cout << i << " " << m << endl;
        bool b=true;
        while(b){
            b=false;
            for(int j=0;j<i;j++){
                if(v[w[j].second.first]>v[w[j].second.second]){
                    v = wormHole(v,w[j].second.first,w[j].second.second);
                    b=true;
                    for(int j:v){
                        cout << j << ", ";
                    }cout << endl;
                }
            }
        } 
    }
    cout << m << endl;
    for(int j:v){
        cout << j << ", ";
    }
    return(0);
}