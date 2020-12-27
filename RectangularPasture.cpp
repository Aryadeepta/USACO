#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> point;
typedef long long ll;
int main(){
    int n;cin >> n;
    vector<point> v;
    for(int i=0;i<n;i++){point p; cin >> p.first >> p.second;v.push_back(p);}
    sort(v.begin(),v.end());
    ll c=0;
    for(int i=0;i<n;i++){
        set<int> s;s.insert(v[i].second);
        for(int j=i+1;j<n;j++){
            s.insert(v[j].second);
            // c+=(s.lower_bound(v[i].second)-s.begin()+1)*(s.end()-s.upper_bound(v[j].second)+1);
            c+=(distance(s.begin(), s.lower_bound(min(v[i].second,v[j].second)))+1)*(distance(s.upper_bound(max(v[i].second,v[j].second)),s.end())+1);
        }
    }
    cout << c + n + 1 << "\n";
    return(0);
}
