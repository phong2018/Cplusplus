#include <iostream>
#include <fstream>
#include <string>
//-----
struct dinh{
   int p[800],r[800];
   int di;
};
//-----
using namespace std;
//-----
int a[801][801],t[801],n,m,p,vc=2000000000;
//-----
struct dinh d[801];
int countd;
int f[801],rf[801];
//------
void docfile(){
    int i,u,v;
    ifstream finp;
    /*Đọc từ file*/
    finp.open ("input.inp");
    finp >>p>>n>>m;
    for(i=1;i<=n;i++)finp>>t[i];
    //----
    for(u=1;u<=n;u++)
    for(v=1;v<=n;v++)a[u][v]=vc;
    //-----
    for(i=1;i<=m;i++){
        finp>>u>>v;
        finp>>a[u][v];
        a[v][u]=a[u][v];
    }
    finp.close();
}
//------
void push(int ii, int pi, int ri){
    d[ii].di++;
    d[ii].p[d[ii].di]=pi;
    d[ii].r[d[ii].di]=ri;
    countd++;
}
//-----
void pop(int u,int v){
   if(d[u].di>v){
      d[u].p[v]=d[u].p[d[u].di];
      d[u].r[v]=d[u].r[d[u].di];
   }
   d[u].di--;
   countd--;
}
//------
int maxab(int a,int b){
    if(a>b) return a;
    else return b;
}
//------
void xuly(){
    int i,j,u,v;
    countd=0;// tong so phan tu con trong d
    for(i=1;i<=n;i++) d[i].di=0;
    //------
    for(i=1;i<=n;i++) f[i]=vc;
    //-------
    push(1,0,t[1]);// pust vào đỉnh 1, chi phí đến 1=0; con rồng còn có thể bay t[1] đoạn
    f[1]=0;rf[1]=t[1];
    while(countd>0){
        // tìm đỉnh có chi phí min và rồng còn bay xa nhất
        int dmin=vc,rmax=0;
        u=-1;
        for(i=1;i<=n;i++)
        for(j=1;j<=d[i].di;j++)
        if(dmin>d[i].p[j] || (dmin==d[i].p[j]&& rmax<d[i].r[j])){
            dmin=d[i].p[j];rmax=d[i].r[j];
            u=i;v=j;
        }
        if(u>0){
          if(u==n)break;
           //xoa nut vừa chọn đi
           pop(u,v);
           // cập nhật lại mảng f lưu min và mảng d để tìm đường đi
           i=u;
           for(j=1;j<=n;j++)
           if(rmax>=a[i][j]){
                if(f[j]>f[i]+a[i][j]){
                   f[j]=f[i]+a[i][j];
                   rf[j]=maxab(t[j],rmax-a[i][j]);
                   push(j,f[j],maxab(t[j],rmax-a[i][j]));
                }
                else// nếu con rồng khỏe hơn thì cũng push vào
                if(maxab(t[j],rmax-a[i][j])>rf[j]){
                   push(j,f[i]+a[i][j],maxab(t[j],rmax-a[i][j]));
                }
           }
        }
    }
}
 void xuat(){
 }

//------
int main () {
   docfile();
   xuly();
   xuat();
}


