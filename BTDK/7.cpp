//EULER(int a[][])

#include<bits/stdc++.h>

using namespace std;

int n;
int a[100][100];
int a_copy[100][100];
vector<int> CE;

void EULER(int a[][100])
{
    bool chutrinh=true;
    stack<int> st;
    st.push(1);
    while(!st.empty())
    {
        int v=st.top();
        bool ok=true;
        for(int i=1; i<=n; i++) {
            if(a[v][i]==1) {
                ok=false;
                st.push(i);
                a[v][i]=0;
                a[i][v]=0;
                break;
            }
        }
        if(ok) {
            CE.push_back(v);
            st.pop();
        }
    }
    int siz=CE.size();
    if(a_copy[1][CE[0]]==0) chutrinh=false;
    if(chutrinh) {
        cout << "Chu trinh Euler la: ";
        for(int i=siz-1; i>=0; i--) cout << CE[i] << " ";
    }
    else {
        cout << "Duong di Euler la: ";
        for(int i=siz-1; i>=0; i--) cout << CE[i] << " ";
    }
}

int main()
{
    // Nhap so dinh va ma tran ke, khoi tao ham vis
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {   
            cin >> a[i][j];
            a_copy[i][j]=a[i][j];
        }
    }
    EULER(a);
}