#include <bits/stdc++.h>
#define inf 9999
using namespace std;
int n, s = 1, t, c[100][100], f[100][100], e[100];

bool Findpath(){
    queue<int> q;
    q.push(s);
    memset(e, 0, sizeof(e));
    e[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 1; v <= n; v++){
            if(e[v] == 0 && c[u][v] > f[u][v]){
                e[v] = u;
                if(v == t){
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}
int FordFulkerson(){
    int lcd = 0;
    while(Findpath()){
        int delta = inf;
        for(int v = t; v != s; v = e[v]){
            int u = e[v];
            delta = min(delta, c[u][v] - f[u][v]);
        }
        for(int v = t; v != s; v = e[v]){
            int u = e[v];
            f[u][v] += delta;
        }
        lcd += delta;
    }
    return lcd;
}
int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    in >> n;
    t = n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            in >> c[i][j];
        }
    }
    int lcd = FordFulkerson();
    out << "Luong cuc dai: " << lcd << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            out << f[i][j] << " ";
        }
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}