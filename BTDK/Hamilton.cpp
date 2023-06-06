#include<bits/stdc++.h>

using namespace std;

int a[100][100], n, s;
int vs[100], x[100];

void Hamilton(int k)
{
    for(int v=1; v<=n; v++) {
        if(k==n+1) {
            if(a[x[k-1]][v]==1 && v==x[1]) {
                cout << "Chu trinh Ham: " << endl;
                for(int i=1; i<=n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
            }
        }
        else {
            if(vs[v]==0 && a[x[k-1]][v]==1) {
                x[k]=v;
                vs[v]=1;
                Hamilton(k+1);
                vs[v]=0;
            }
        }
    }
}

void chutrinhHamilton(int s)
{
    x[1]=s;
    vs[s]=1;
    Hamilton(2);
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cin >> a[i][j];
    }
    chutrinhHamilton(1);
}