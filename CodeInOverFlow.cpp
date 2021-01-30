#include<bits/stdc++.h>
using namespace std;
#define arr_size 9

//float X[] = { 12 , 16 , 5 , 9 , 6 , 4 , 7 , 11 , 5 };

int n = arr_size;
int L[arr_size];
int lMax;
float Out[arr_size];


float X[] = { 12 , 16 , 5 , 9 , 6 , 5.5 , 7 , 11 , 10 };
//	L   :     1    2    1   2   2    2    3   4    4

vector<int> first;//vector chứa các phần tử i có L[i] = lMax
int arr_index;////vị trí của phần tử đang xét trong mảng 


void DeQuy(int index){
	if( L[index] == 1 ){
		Out[--arr_index] = X[index];
		++arr_index;
		for(int i = 0 ; i < lMax ; i++){
			cout << Out[i] << " ";
		}
		cout << endl;
	}
	
	// tìm các phần từ vị trí index trong mảng về trước phù hợp
	// Các phần tử i có nhãn L[i] phía trc = nhãn tại vị trí xét - 1
	// và có giá trị trong mảng bé hơn phần tử xét 
	for(int j = index-1 ; j >= 0 ; j--){
		if(L[j] == L[index] -1 && X[j] <= X[index]){
			Out[--arr_index] = X[index];
			DeQuy(j);
			++arr_index;
		}
	}
}


int Max(float *a, int i, int *b){
	int index = 0 ;
    for(int j = i-1 ; j >= 0 ; j--){
		if( a[j] <= a[i]){
			index = max(b[j],index);
		}
	}
	return index;
}

int main(){
	L[0] = 1;
	// Tìm nhãn cho tất cả các phần tử trong mảng 
	// Nhãn các phần tử  = nhãn lớn nhất trong các phần tử bé hơn nó + 1
	for(int i = 1 ; i < n ; i++){
		L[i]= Max(X,i,L) + 1;
	}
	// Tìm các phần tử i có L[i] = lMax
	lMax = L[0];
	for(int i = 1 ; i < n ; i ++){
		if(L[i] > lMax){
			first.clear();
			first.push_back(i);
			lMax = L[i];
		}else if(lMax == L[i]) first.push_back(i);
	}

	// Tìm tất cả các dãy có kết thúc là phần tử i có L[i] = lMax
	for(int i = 0 ; i < first.size() ; i++){
		arr_index = lMax;
		DeQuy(first[i]);
	}
}

