#include<bits/stdc++.h>
#include<fstream>
#define vc INT_MAX
using namespace std;
int n,m,a,b,h,f,grid[1001],fgrid[1001],d[10001][10001],g[1001],kmin=vc;

void docfile() {
    ifstream finp;
    finp.open ("festival.inp");
    finp>>n>>m;
    finp>>a>>b>>h>>f;
    for (int i=1;i<=f;i++) finp>>grid[i];

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            finp>>d[i][j];
            d[j][i]=d[i][j];
        }
    }
    //===========
    fgrid[grid[1]]=0;
    for(int i=2;i<=f;i++)
    fgrid[grid[i]]=fgrid[grid[i-1]]+ d[grid[i-1]][grid[i]];
    finp.close ();
}

void xuly () {
    int check[10001];
    for (int i=1;i<=n;i++) {
        g[i]=vc;
        check[i]=0;
    }
    int i=0;
    g[1]=0;
    while (i>-1) {
        i=-1;
        int fmin=vc;
        for (int j=1;j<=n;j++)
        if (check[j]==0 && g[j]<fmin) {
            i=j;
            fmin=g[i];
        }
        if (i>-1) {
            check[i]=1;
            for (int j=1;j<=n;j++) {
                if (d[i][j]!=vc && g[j]>g[i]+d[i][j]) {
                    if(g[i]+d[i][j]>=a && g[i]+d[i][j]<=b) {
                        //if (g(j)>=(b+1))
                        //else  so sánh với f[i]+a[i][j];
                    }
                }
            }
        }
    }
}

void xuat () {
    ofstream fout;
    fout.open ("festival.out");
    fout<<kmin;
    fout.close ();
}

int main () {
    docfile();
    xuly ();
    xuat ();
}
