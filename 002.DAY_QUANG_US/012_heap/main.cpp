// range heap example
#include <iostream>     // cout
#include <algorithm>    // make_heap, pop_heap, push_heap, sort_heap
#include <vector>       // vector
using namespace std;

int main () {
  int myints[] = {-200000};
  vector<int> v(myints,myints+1);
 /*
 v.push_back(4); push_heap (v.begin(),v.end());
  v.push_back(5); push_heap (v.begin(),v.end());
  v.push_back(6); push_heap (v.begin(),v.end());
  v.push_back(7); push_heap (v.begin(),v.end());
  v.push_back(8); push_heap (v.begin(),v.end());
  pop_heap (v.begin(),v.end()); v.pop_back();
  pop_heap (v.begin(),v.end()); v.pop_back();
  pop_heap (v.begin(),v.end()); v.pop_back();
  cout <<  v.front() << '\n';
 */
    int t,x,i;
    cin >>t;
    for(i=1;i<=t;i++){
        cin>>x;
        v.push_back(x); push_heap (v.begin(),v.end());;
        //---------
        int m1=-200000,m2=-200000,m3=-200000;
        //---------
        m1=v.front();
        pop_heap (v.begin(),v.end()); v.pop_back();
        if(i>1){
            m2=v.front();
            pop_heap (v.begin(),v.end()); v.pop_back();
        }
        if(i>2){
            m3=v.front();
            pop_heap (v.begin(),v.end()); v.pop_back();
        }
        //----
        v.push_back(m1); push_heap (v.begin(),v.end());;
        if(i>1)v.push_back(m2); push_heap (v.begin(),v.end());;
        if(i>2)v.push_back(m3); push_heap (v.begin(),v.end());;
        if(i==1) cout<<-1<<endl;
        if(i==2) cout<<-1<<endl;
        if(i>2)
        cout<<m1<<" "<<m2<<" "<<m3<<endl;
    }

  return 0;
}
