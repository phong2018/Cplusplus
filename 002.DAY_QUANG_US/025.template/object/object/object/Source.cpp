#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;
//------------------
template <class TempClassTest>
class Stack { 
  private: 
	// cac phan tu 
    vector<TempClassTest> phantu;    
  public: 
    // hoat dong push phan tu
    void push(TempClassTest const&); 
	// hoat dong pop phan tu
    void pop();   
	// tra ve phan tu tren cung 
    TempClassTest top() const;      
	// tra ve true neu la trong.
    bool empty() const{       
        return phantu.empty(); 
    } 
}; 
//------------------
template <class TempClassTest>
void Stack<TempClassTest>::push (TempClassTest const& elem) 
{ 
    // phu them ban sao cua phan tu da truyen 
    phantu.push_back(elem);    
} 
//----------
template <class TempClassTest>
void Stack<TempClassTest>::pop () 
{ 
    if (phantu.empty()) { 
        throw out_of_range("Stack<>::pop(): stack da trong!"); 
    }
	// xoa phan tu cuoi cung 
    phantu.pop_back();         
} 
//----------
template <class TempClassTest>
TempClassTest Stack<TempClassTest>::top () const 
{ 
    if (phantu.empty()) { 
        throw out_of_range("Stack<>::top(): stack da trong!"); 
    }
	// tra ve ban sao cua phan tu cuoi cung 
    return phantu.back();      
} 
//----------
int main() 
{ 
    try { 
	 // mot stack cua cac so nguyen
        Stack<int> stackSoNguyen;  
	 // mot stack cua cac chuoi
        Stack<string> stackChuoi; 

        // thao tac tren stack cac so nguyen 
        stackSoNguyen.push(10); 
        cout << stackSoNguyen.top() <<endl; 

        // thao tac tren stack cua chuoi
        stackChuoi.push("TempClassTestXinChaoCacBan"); 
        cout << stackChuoi.top() << std::endl; 
        stackChuoi.pop(); 
        stackChuoi.pop(); 
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
    } 

    int n;
    cin>>n;
}  
