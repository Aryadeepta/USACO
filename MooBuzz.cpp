#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
typedef long int li;
int main(){
    ifstream in("moobuzz.in");
    li i;
    in >> i;
    in.close();
    vector<li> ends = {1,2,4,7,8,11,13,14};
    ofstream out("moobuzz.out");
    out << std::to_string(15*li((i-1)/8)+ends[(i-1)%li(8)]) << endl;
    out.close();
    return(0);
}