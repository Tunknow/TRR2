// KRUSKAL(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100];
int parent[100];
int num[100];

struct canh
{
    int d, c, ts;
};

vector<canh> ds;

bool comp(canh a, canh b)
{
    return a.ts < b.ts;
}

int Find(int u)
{
    if(u!=parent[u]) parent[u]=Find(parent[u]);
    return parent[u];
}

bool Union(int u, int v)
{
    int a=Find(u), b=Find(v);
    if(a==b) return false;
    if(num[a]<num[b]) swap(a, b);
    parent[b]=a;
    num[a]+=num[b];
    return true;
}

void KRUSKAL(int a[][100]) {
    for(int i=1; i<=n; i++) {
            parent[i]=i;
            num[i]=1;
        }
    int inf=9999;
    for(int i=1; i<=n-1; i++) {
        for(int j=i+1; j<=n; j++) {
            if(a[i][j]<inf) {
                ds.push_back({i, j, a[i][j]});
            }
        }
    }
    sort(ds.begin(), ds.end(), comp);
    int wt=0;
    vector<canh> T;
    for(int i=0; i<ds.size(); i++) {
        if(Union(ds[i].d, ds[i].c)) {
            wt+=ds[i].ts;
            T.push_back(ds[i]);
        }
    }
    if(T.size()<n-1) cout << "Khong co cay khung" << endl;
    else {
        cout << "Trong so: " << wt << endl;
        cout << "Cay khung: " << endl;
        for(int i=0; i<T.size(); i++) {
            cout << T[i].d << " " << T[i].c << endl;
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=n; j++) cin >> a[i][j];
    
    KRUSKAL(a);
}