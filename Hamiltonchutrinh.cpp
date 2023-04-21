#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100];
int x[100];
bool vis[100];

void Hamilton(int k)
{
    for(int i=1; i<=n; i++) {
        if(a[i][x[k-1]]==1) {
            if(k==n+1) {
                if(a[x[n]][x[1]]==1) {
                    cout << "Chu trinh Hamilton: ";
                    for(int id=1; id<=n; id++) cout << x[id] << " ";
                    cout << endl;
                    break;
                }
                else {
                    cout << "Duong di Hamilton: ";
                    for(int id=1; id<=n; id++) cout << x[id] << " ";
                    cout << endl;
                    break;
                }
            }
            else {
                if(!vis[i]) {
                    x[k]=i;
                    vis[i]=true;
                    Hamilton(k+1);
                    vis[i]=false;
                }
            }
        }
    }
}

void solve(int s)
{
    for(int i=1; i<=n; i++) {
        vis[i]=false;
    }
    x[1]=s; vis[s]=true;
    Hamilton(2);
}

int main()
{
    cin >> n;
    int s;
    cin >> s;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> a[i][j];
    solve(s);

    return 0;
}