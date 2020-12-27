#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii, pii> collision;
map<int,set<int>> m;
map<int, int> c;
int children(int s){
    if(c.find(s)!=c.end()){return(c[s]);}
    if(m[s].size()==0){c[s]=0;return(0);}
    int tc=0;
    for(int i:m[s]){tc+=children(i)+1;}
    c[s]=tc;return(tc);
}
bool colComp(collision a, collision b){
    return(a.first.second<b.first.second);
}
int main(){
    int n;
    cin >> n;
    vector<pii> nc;vector<pii> ec;
    vector<int> l;vector<int>el;
    for(int i=0;i<n;i++){
        char dir;pii p;
        cin >> dir >> p.first >> p.second;
        if(dir=='N'){nc.push_back(p);l.push_back(i);}else{ec.push_back(p);el.push_back(i);}
    }
    for(int i:el){l.push_back(i);}
    vector<collision> collisions;
    for(int i=0;i<nc.size();i++){
        for(int j=0;j<ec.size();j++){
            int tn=ec[j].second-nc[i].second;
            int te=nc[i].first-ec[j].first;
            if(tn<te && tn>0){
                collision col;
                col.first.first=tn;col.first.second=te;col.second.first=i;col.second.second=j+nc.size();
                collisions.push_back(col);
            }
            if(tn>te && te>0){
                collision col;
                col.first.first=te;col.first.second=tn;col.second.first=j+nc.size();col.second.second=i;
                collisions.push_back(col);
            }
        }
    }
    sort(collisions.begin(),collisions.end(),colComp);
    int stop[n];int stopped[n];
    for(int i=0;i<n;i++){stop[i]=2147483647;stopped[i]=n;}
    for(collision col:collisions){
        if(stop[col.second.first]>col.first.first && stop[col.second.second]>col.first.second){stop[col.second.second]=col.first.second;stopped[col.second.second]=col.second.first;}
    }
    for(int i=0;i<n;i++){m[stopped[i]].insert(i);}
    // for(int i=0;i<n;i++){cout << l[i] << ": ";for(int j:m[i]){cout << l[j] << " ";}cout << "\n";}
    vector<int> finC (n,0);
    for(int i=0;i<n;i++){finC[l[i]]=children(i);}
    for(int i=0;i<n;i++){cout << finC[i] << "\n";}
}
