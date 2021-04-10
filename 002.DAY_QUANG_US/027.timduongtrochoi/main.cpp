#include<bits/stdc++.h>
#include<fstream>
#define vc INT_MAX
using namespace std;
int n,m,a[300][300],a1,a2,a3,b1,b2,b3;

void docfile () {
    ifstream finp;
    finp.open ("input.inp");
    finp>>n>>m;
    finp>>a1>>b1>>a2>>b2>>a3>>b3;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    finp>>a[i][j];
    finp.close ();
}

bool hople(int x,int y){
    if(x>0 && x<=n && y>0 && y<=m) return true;
    else return false;
}

void timddmin(int f[5][300],int x,int y){
    int check[300][300],i,j,fmin;
    int arrx[5]={0,-1,0,1,0},arry[5]={0,0,1,0,-1};
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {f[i][j]=vc;check[i][j]=0;}
    f[x][y]=0;
    x=0;y=0;
    while(x>-1){
        x=-1;y=-1;fmin=vc;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if(check[i][j]==0 && f[i][j]<fmin){
            fmin=f[i][j];
            x=i;y=j;
        }
        if(x>0){
            check[x][y]=1;
            for(int e=1;e<=4;e++){
                i=x+arrx[e];j=y+arry[e];
                if(hople(i,j) && f[i][j]>f[x][y]+a[i][j])
                f[i][j]=f[x][y]+a[i][j];
            }
        }
    }
}

void xuly () {
    int f1[300][300],fa1b1[300][300],fa2b2[300][300],fa3b3[300][300];
    timddmin(f1,1,1);
    timddmin(fa1b1,a1,b1);
    timddmin(fa2b2,a2,b2);
    timddmin(fa3b3,a3,b3);
    int fmin=vc;
    //TH1 từ 1,1->a1b1->a2b2->n,m
    if(fmin>f1[a1][b1]+fa1b1[a2][b2]+fa2b2[n][m]) fmin=f1[a1][b1]+fa1b1[a2][b2]+fa2b2[n][m];
    //TH2 từ 1,1->a1b1->a3b3->n,m
    if(fmin>f1[a1][b1]+fa1b1[a3][b3]+fa3b3[n][m]) fmin=f1[a1][b1]+fa1b1[a3][b3]+fa3b3[n][m];
    //TH3 từ 1,1->a2b2->a1b1->n,m
    if(fmin>f1[a2][b2]+fa2b2[a1][b1]+fa1b1[n][m]) fmin=f1[a2][b2]+fa2b2[a1][b1]+fa1b1[n][m];
    //TH4 từ 1,1->a3b3->a1b1->n,m
    if(fmin>f1[a3][b3]+fa3b3[a1][b1]+fa1b1[n][m]) fmin=f1[a3][b3]+fa3b3[a1][b1]+fa1b1[n][m];


    //TH5 từ 1,1->a2b2->a3b3->n,m
    if(fmin>f1[a2][b2]+fa2b2[a3][b3]+fa3b3[n][m]) fmin=f1[a2][b2]+fa2b2[a3][b3]+fa3b3[n][m];
    //TH6 từ 1,1->a3b3->a2b2->n,m
    if(fmin>f1[a3][b3]+fa3b3[a2][b2]+fa2b2[n][m]) fmin=f1[a3][b3]+fa3b3[a2][b2]+fa2b2[n][m];

    ofstream fout;
    fout.open ("vuichoi_1.out");
    fout<<fmin+a[1][1];
    fout.close ();

}



int main () {
    docfile ();
    xuly();

}

