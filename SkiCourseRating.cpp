#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> point;
vector<int> pa;
vector<int> sz;
int get(int x){
    return((pa[x]==x)?x:pa[x]=get(pa[x]));
}
void unite(int a, int b){
    a=get(a);b=get(b);
    if(a==b){return;}
    if(sz[a]>sz[b]){int c=a;a=b;b=c;}
    pa[a]=b;sz[b]+=sz[a];
    return;
}
int main(){
    freopen("skilevel.in","r",stdin);freopen("skilevel.out","w",stdout);
    int n,m,t;
    cin >> m >> n >> t;
    int g[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
            pa.push_back(i*n+j);sz.push_back(1);
        }
    }
    vector<point> s;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int k;cin >> k;
            if(k==1){s.push_back(make_pair(i,j));}
        }
    }
    unsigned long long ts=0;int d=-1;
    while(s.size()>0){
        d++;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]-g[i+1][j]==d || g[i+1][j]-g[i][j]==d){unite(i*n+j,(i+1)*n+j);}
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                if(g[i][j]-g[i][j+1]==d || g[i][j+1]-g[i][j]==d){unite(i*n+j,i*n+j+1);}
            }
        }
        vector<point>::iterator ptr = s.begin();
        while(ptr!=s.end()){
            if(sz[get((*ptr).first * n + (*ptr).second)]>=t){
                ts+=d;
                ptr=s.erase(ptr);
            }else{ptr++;}
        }
    }
    cout << ts << "\n";
    fclose(stdin);fclose(stdout);
    return(0);
}
