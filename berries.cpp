#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int maxBaskets(vector<int> v, int b){
    int m=0;
    int i=0;
    while(v[i]>=b){
        m+=int(v[i]/b);
        i++;
    }
    return(m);
}
int maxKeep(int m, int i, int k, vector<int> v, int j){
    if(m>=k){
        return((k/2)*i);
    }else if(m>k/2){
        return((m-k/2)*i+v[k-m]-v[m]);
    }else{
        return(v[k-m]-v[k/2-m]);
    }
}
int main(){
    vector<int> t;
    vector<int> ts;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int nb;
        cin >> nb;
        t.push_back(-1*nb);
    }
    sort(t.begin(),t.end());
    t[0]=t[0]*-1;
    ts.push_back(t[0]);
    cout << t[0] << " " << ts[0] << endl;
    for(int i=1;i<t.size();i++){
        t[i]=t[i]*-1;
        ts.push_back(ts[i-1]+t[i]);
        cout << t[i] << " " << ts[i] << endl;
    }
    
    if(t[0]>t[1]*k){
        cout << int(t[0]/k);
    }else{
        int i=t[1];
        int j=1;
        int c=maxBaskets(t,i);
        int n=maxBaskets(t,i-1);
        cout << maxKeep(c,i,k,ts) << " " << i;
        while(maxKeep(c,i,k,ts,j)<maxKeep(n,i-1,k,ts,j)){
            cout << maxKeep(c,i,k,ts) << " " << i;
            i--;
            c=n;
            n=maxBaskets(t,i-1);
            if(i=t[j+1]){j++;}
        }
    }
    return(0);
}