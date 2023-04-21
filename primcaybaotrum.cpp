#include<bits/stdc++.h>
#define inf 100    // tuy theo gia tri dau vao cua de bai

using namespace std;

int n;
int a[100][100];
bool vis[100], d[100], e[100];
void Prim(int s)
{
	for(int v=1; v<=n; v++) {
		vis[v]=false;
		d[v]=a[s][v];
		e[v]=s;	
	}
	vis[s]=true; d[s]=0; e[s]=0;
	int wt=0, cnt=1;
	while(cnt<n) {
		int u=0;
		int min=inf;
		for(int v=1; v<=n; v++) {
			if(vis[v]==false && d[v]<min) {
				min=d[v];
				u=v;
			}
		}
		if(u==0) {
			cout << "Do thi khong lien thong" << endl;
			return;
		}
		cnt++;
		vis[u]=1; wt=wt+a[u][e[u]];
		for(int v=1; v<=n; v++) {
			if(vis[v]==false && d[v] > a[u][v]) {
				d[v]=a[u][v];
				e[v]=u;
			}
		}
	}
	cout << wt << endl;
	for(int v=1; v<=n; v++) {
		if(e[v]!=0) {
			cout << v << " " << e[v] << endl;
		}
	}
}

int main(){
	cin >> n;
	int s;
	cin >> s;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) cin >> a[i][j];
	Prim(s);		
}

