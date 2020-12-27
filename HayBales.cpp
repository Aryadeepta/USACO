#include <iostream>
#include <set>
using namespace std;
int main(){
    freopen("haybales.in","r",stdin);freopen("haybales.out","w",stdout);
    int n,q;cin >> n >> q;
    set<int> s;
    for(int i=0;i<n;i++){int j;cin >> j;s.insert(j);}
    int max=*s.rbegin();
    int h[max+2];
    int hs=0;int ci=0;
    while(s.size()>0){if(ci==*s.begin()){hs++;s.erase(s.begin());}h[ci+1]=hs;ci++;}
    for(int i=0;i<q;i++){
        int a,b;cin >> a >> b;
        if(a>max){cout << 0 << "\n";}else{
            if(b>max){b=max;}
            cout << h[b+1]-h[a] << "\n";
        }
    }
    fclose(stdin);fclose(stdout);
}