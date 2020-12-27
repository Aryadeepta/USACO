#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class node
{
public:
    vector<node> c;
    int n;
    bool t;
    node(int i, bool b)
    {
        n = i;
        t = b;
        c.push_back(*this);
    }
    void addToPath(node n)
    {
        c.push_back(n);
        for (int i = 0; i < n.c.size(); i++)
        {
            c.push_back(n.c[i]);
        }
        for (int i = 0; i < c.size() - n.c.size() - 1; i++)
        {
            c[i].c.push_back(n);
            for (int i = 0; i < n.c.size(); i++)
            {   
                c[i].c.push_back(n.c[i]);
            }
        }
    }
    bool connectedTo(int x)
    {
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i].n == x)
            {
                return (true);
            }
        }
        return (false);
    }
};
int main()
{
    ifstream in("milkvisits.in");
    int n, m;
    in >> n >> m;
    char s = ' ';
    vector<node> c;
    for (int i = 0; i < n; i++)
    {
        in >> s;
        c.push_back(node(i+1, (s == 'H')));
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        in >> x >> y;
        x--;
        y--;
        if (c[x].t ^ c[y].t)
        {
            c[x].addToPath(c[y]);
            c[y].addToPath(c[x]);
        }
    }
    string o;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        char t;
        in >> x >> y >> t;
        x--;
        bool b = (t == 'H');
        if (c[x].connectedTo(y) && (c[x].t ^ b))
        {
            o += "0";
        }
        else
        {
            o += "1";
        }
        cout << t << endl;
    }
    cout << o;
    in.close();
    ofstream out("milkvisits.out");
    out << o << endl;
    out.close();
    return (0);
}