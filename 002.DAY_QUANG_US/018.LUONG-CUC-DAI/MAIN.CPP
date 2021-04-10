#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <fstream>

#define vc 2000000000

using namespace std;
int c[100][100],f[100][100],fc[100][100],vet[100],check[100],n,m,s,t;
queue<int> q;
void docfile(){
  ifstream finp;
  /*Đọc từ file*/
  finp.open ("input.inp");
  finp >>n>>m>>s>>t;
  int i,u,v;
  for(i=1;i<=m;i++){
    finp>>u>>v;
    finp>>c[u][v];
  }
  finp.close();
}
void khoitaofc(){
    int i,j,u,v;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) fc[i][j]=vc;
    for(u=1;u<=n;u++)
    for(v=1;v<=n;v++)
    if(c[u][v]>0){
        // cung thuan so giá trị luong có thể tăng lên khi đi qua cung này
        if(c[u][v]>f[u][v]) fc[u][v]=c[u][v]-f[u][v];
        // số giá trị luồng có thể giảm đi khi đi qua cung này
        if(f[u][v]>0) fc[u][v]=-f[u][v];
    }
}



bool timluong(){
    int i,j;
    for(i=1;i<=n;i++){
        check[i]=0;
        vet[i]=0;
    }
    q.push (s);check[s]=1;
    while(!q.empty()){
        i=q.front();q.pop();
        for(j=1;j<=n;j++)
        if(fc[i][j]!=vc && check[j]==0){
            q.push(j);
            vet[j]=i;
            if(j==t) break;
        }
        if(j==t) break;
    }
    if(j==t) return true;
    else return false;
}


void tangluong(){
    int i,j,minfc=vc;
    j=t;
    while(vet[j]>0){
        i=vet[j];
        if(minfc>fc[i][j])minfc=fc[i][j];
        j=i;
    }
    j=t;
    while(vet[j]>0){
        i=vet[j];

        if(fc[i][j]>0)
        f[i][j]=f[i][j]+minfc;
        else f[j][i]=f[j][i]-minfc;
        j=i;
    }
}

void luongcucdai(){
    int i,j;
    // khoi tao luong bang 0
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++) fc[i][j]=0;
    // tim luong
    while(1==1){
        khoitaofc();
        if(!timluong()) break;
        tangluong();
    }
}

void xuat(){
  ofstream fout;
  fout.open ("output.out");
  fout<<"";
  fout.close();
}

int main ()
{
  docfile();
  luongcucdai();
  xuat();

}
