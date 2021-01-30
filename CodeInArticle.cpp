#include<bits/stdc++.h>
using namespace std;
#define arr_size 10
#define NIL -1

float X[] = { 12 , 16 , 5 , 9 , 6 , 5.5 , 7 , 11 , 10 };
// left1:    -1   -1    0   1   3    4   -1  -1    7
// left2: 	 -1    0   -1   2   2    2    5   6    6
//	L   :     1    2    1   2   2    2    3   4    4


//float a[] = { 12 , 16 , 5 , 9 , 6 , 4 , 7 , 11 , 5 };
int n = arr_size;
int L[arr_size];
int lMax;// Nhãn L lớn nhất 
float Out[arr_size]; // chứa dãy con thỏa mãn 
int iLast; // vị trí phần tử có Lmax cuối cũng của mảng 
int left1[arr_size];
int left2[arr_size];


// Liệt kê 
void Enumerate(int index){

	// khi phần tử tại vị trí index có nhãn L max 
	
	// Chọn các phần tử phù hợp vào mảng 
	if( L[index] == lMax || X[index] < Out[L[index]] ){
		Out[L[index]-1] = X[index];
	}else return; 

	//vị trí tiếp theo từ vị trí index 
	int z1 = left2[index];
	
	// khi vị trí cuối cùng -> xuất 
	if(z1 == NIL){
		for(int i = 0 ; i < lMax ; i++){
			cout << Out[i] << " ";
		}
		cout << endl;
	}else
		// đệ quy vị vị trí hiện tại là index = z1
		Enumerate(z1);
	

	if(left1[index] != NIL ) Enumerate(left1[index]);
}

// Tìm nhãn L max
int LMax(){
	int max = L[0];
	for(int i = 1 ; i < n ; i ++){
		if(L[i] >= max){
			iLast = i;
			max = L[i];
		}
	}
	return max;
}

// a : mảng X
// b : mảng L
int Max(float *a, int i, int *b){
	int index = 0 ;
    for(int j = i-1 ; j >= 0 ; j--){
		if( a[j] <= a[i]){
			index = max(b[j],index);
		}
	}
	return index;
}

// Tạo nhãn L
void GenerateL(){
	for(int i = 1 ; i < n ; i++){
		L[i]= Max(X,i,L) + 1;
	}
}
// Tạo left1 và left2 
void GenerateLeft1AndLeft2(){

	for(int j = 1 ; j < n ; j++){
		int i;
		// Tạo left1
		for( i = j-1 ; i>= 0 ; i--){
			if(L[i]==L[j]){
				//left1[j] = i;
				break;
			}
		}
		left1[j] = i;
		
		// tạo left2 
		for( i = j-1 ; i>= 0 ; i--){
			if(L[i]==L[j]-1){
				break;
			}
		}
		left2[j] = i;
	}

}

int main(){

	//Tạo mảng L 
	L[0] = 1;
	GenerateL();
	//Tạo left1 và left 2
	left1[0]=NIL;
	left2[0]=NIL;
	GenerateLeft1AndLeft2();

	// L max
	lMax = LMax();

	// Liệt kê
	Enumerate(iLast);

}

