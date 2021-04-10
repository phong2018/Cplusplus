#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int n,a[10000];
//----------
void docfile(){
  ifstream finp;
  finp.open ("input.inp");
  finp >>n;
  for(int i=1;i<=n;i++) finp>>a[i];
  finp.close();
}
void swap(int &a, int &b){
    int t = a;a = b; b = t;
}
// Hàm selection sort
/*
Bước 1: Thiết lập MIN về vị trí 1
Bước 2: Tìm kiếm phần tử nhỏ nhất trong danh sách từ vị trí MIN trở đi
Bước 3: Tráo đổi với giá trị tại vị trí MIN
Bước 4: Tăng MIN để trỏ tới phần tử tiếp theo
Bước 5: Lặp lại cho tới khi toàn bộ danh sách đã được sắp xếp
https://vietjack.com/cau-truc-du-lieu-va-giai-thuat/giai-thuat-sap-xep-chon.jsp
*/
void selectionSort()
{
    int i, j, min_idx, temp;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 1; i < n-1; i++)
    {
    // Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
    min_idx = i;
    for (j = i+1; j <= n; j++)
        if (a[j] < a[min_idx])
        min_idx = j;

    // Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;

    }
}

/*
===========insertion sort
Bước 1: Kiểm tra nếu phần tử đầu tiên đã được sắp xếp. trả về 1
Bước 2: Lấy phần tử kế tiếp
Bước 3: So sánh với tất cả phần tử trong danh sách con đã qua sắp xếp
Bước 4: Dịch chuyển tất cả phần tử trong danh sách con mà lớn hơn giá trị để được sắp xếp
Bước 5: Chèn giá trị đó
Bước 6: Lặp lại cho tới khi danh sách được sắp xếp
https://vietjack.com/cau-truc-du-lieu-va-giai-thuat/giai-thuat-sap-xep-chen.jsp
*/
void insertionSort()
{
   int i, key, j;
   for (i = 1; i <= n; i++){
       key = a[i];
       j = i-1;
       // dời hết đoạn lớn hơn nó ra phía sau 1 đơn vị
       while (j > 0 && a[j] > key){
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}

//----------A function implementing Shell sort.
/*
- Shell Sort là một giải thuật sắp xếp mang lại hiệu quả cao dựa trên giải thuật sắp xếp chèn (Insertion Sort).
Giải thuật này tránh các trường hợp phải tráo đổi vị trí của hai phần tử xa nhau trong giải thuật sắp xếp chọn
(nếu như phần tử nhỏ hơn ở vị trí bên phải khá xa so với phần tử lớn hơn bên trái).
- Đầu tiên, giải thuật này sử dụng giải thuật sắp xếp chọn trên các phần tử có khoảng cách xa nhau,
sau đó sắp xếp các phần tử có khoảng cách hẹp hơn. Khoảng cách này còn được gọi là khoảng (interval) –
là số vị trí từ phần tử này tới phần tử khác. Khoảng này được tính dựa vào công thức Knuth như sau:

Bước 1: Khởi tạo giá trị h
Bước 2: Chia list thành các sublist nhỏ hơn tương ứng với h
Bước 3: Sắp xếp các sublist này bởi sử dụng sắp xếp chèn (Insertion Sort)
Bước 4: Lặp lại cho tới khi list đã được sắp xếp
https://vietjack.com/cau-truc-du-lieu-va-giai-thuat/giai-thuat-shell-sort.jsp
*/
void ShellSort(){
	int h, j, k, temp;
	for(h = n/2; h > 0; h = h/2){// đặt các giá trị h; khi h=1=> insertion sort
		for(j = h; j <= n; j++){ // sử dụng các insertion để sắp xếp các phần tử j, j+h, j+2h, j+3h...
			for(k = j-h; k > 0; k = k-h){
				if(a[k+h] >= a[k]) break;
				else{
					temp = a[k];
					a[k] = a[k+h];
					a[k+h] = temp;
				}
			}
		}
	}
}
/*
https://nguyenvanhieu.vn/thuat-toan-sap-xep-quick-sort/
Quy trình của thuật toán sắp xếp quick sort
Bước 1: Lấy phần tử chốt là phần tử ở giữa danh sách.
Bước 2: Chia mảng theo phần tử chốt bằng thuật toán phân đoạn
Bước 3: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên trái.
Bước 4: Sử dụng sắp xếp nhanh một cách đệ qui với mảng con bên phải.
*/
// Code from https://nguyenvanhieu.vn
void quickSort(int left, int right) {
      int pivot = a[(left + right) / 2];
      int i = left, j = right;
      /* partition */
      while (i <= j) {
            while (a[i] < pivot)i++;
            while (a[j] > pivot)j--;
            if (i <= j) {
                  swap(a[i], a[j]);
                  i++; j--;
            }
      };
      /* recursion */
      if (left < j) quickSort(left, j);
      if (i < right) quickSort(i, right);
}
/*
mergeSort(a[], l,  r)
If r > l
 1. Tìm chỉ số nằm giữa mảng để chia mảng thành 2 nửa:
         middle m = (l+r)/2
 2. Gọi đệ quy hàm mergeSort cho nửa đầu tiên:
         mergeSort(a, l, m)
 3. Gọi đệ quy hàm mergeSort cho nửa thứ hai:
         mergeSort(a, m+1, r)
 4. Gộp 2 nửa mảng đã sắp xếp ở (2) và (3):
         merge(a, l, m, r)
*/
void merge( int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    /* Tạo các mảng tạm */
    int L[n1], R[n2];
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[m + 1+ j];
    /* Gộp hai mảng tạm vừa rồi vào mảng a*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy các phần tử còn lại của mảng L vào a nếu có */
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    /* Copy các phần tử còn lại của mảng R vào a nếu có */
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int l, int r){
    if (l < r){
        int m = (l+r)/2;
        mergeSort(l, m);// sắp xếp mảng từ l->m
        mergeSort(m+1, r);// sắp xếp mảng từ m+1->r
        merge(l, m, r);// nối 2 mảng trên lại
    }
}
/*
Giải Thuật Radix Sort/ Postmans sort
Bước 1 :// exp cho biết chữ số dùng để phân loại hiện hành
exp = 0; // exp = 0: hàng đơn vị; exp = 1: hàng chục; …
Bước 2 : //Tạo các lô chứa các loại phần tử khác nhau
Khởi tạo 10 lô B0, B1, …, B9 rỗng;
Bước 3 :
For i = 1 .. n do
Đặt ai vào lô Bt với t: chữ số thứ exp của ai;
Bước 4 :
Nối B0, B1, …, B9 lại (theo đúng trình tự) thành a.
Bước 5 :
k = k+1;Nếu exp < m thì trở lại bước 2. Ngược lại: Dừng
vd:  49 23 48 241 17
đơn vị: 241 23 17 48 49
chuc  : 17 23 241 48 49
trăm  : 17 23 48 49 241
*/
// A utility function to get maximum value in a[]
int getMax( ){
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
// A function to do counting sort of a[] according to
// the digit represented by exp.
void countSort(int n, int exp){
    int output[n]; // output aay
    int i, count[10] = {0};
    // tính lô i có bao nhiêu số
    for (i = 1; i <= n; i++)
        count[ (a[i]/exp)%10 ]++;
    // tính vào lô i có bao nhiêu số
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // sắp xếp theo từng lo: đơn vị->chục->trăm->ngàn
    for (i = n; i >0; i--){
        output[count[ (a[i]/exp)%10 ]] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }
    for (i = 1; i <= n; i++)
        a[i] = output[i];

}
// The main function to that sorts a[] of size n using
// Radix Sort
void radixsort(){
    int m = getMax();
    // sắp xếp theo hàng đơn vị, hàng chục, hàng trăm, hàng ngàn, hàng chục ngàn.... hàng tỉ...
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(n, exp);
}

//--------


//--------
int main(){
    docfile();
    //selectionSort();
    //insertionSort();
	//ShellSort();
	//quickSort(1,n);
	//mergeSort(1,n);
    radixsort();
	xuatfile();
}
