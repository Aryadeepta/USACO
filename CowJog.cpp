#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("cowjog.in","r",stdin);freopen("cowjog.out","w",stdout);
    int n,t;
    cin >> n >> t;
    vector<long> r;
    for(int i=0;i<n;i++){
        long p,s;
        cin >> p >> s;
        r.push_back(p+s*t);
    }
    int i=0;
    while(i+1<r.size()){
        if(r[i] >= r[i+1]){r.erase(r.begin()+i);if(i>0){i--;}}else{i++;}
    }
    cout << r.size() << "\n";
    fclose(stdin);fclose(stdout);
    return(0);
}