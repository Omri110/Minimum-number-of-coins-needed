
//Written By Omri Weiss
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

#define INF  9999;

int min(int, int);
int max(int, int);
int CreateC(int *,int *, int , int);
void RestoreC(int *, int *, int );

	

int min(int x, int y)
{
if(x>y)
	return y;
else
	return x;

}

int max(int x, int y)
{
if(x>y)
	return x;
else
	return y;

}




void sortArray(int array[], int size)
{
	bool swap;
	int temp;
	do {
		swap = false;
		for (int count = 0;count < size - 1;count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}



/*

int CreateC(int *array,int *C, int size, int K)
{

	C[0]=0;
	for(int i=1; i<K+1;i++)
	{
	if(i>=6)
	C[i]= min( min(C[i-1],C[i-4]), C[i-6] ) +1;

	else if(i>=4 && i<6)
		C[i]= min(C[i-1],C[i-4]) +1;

	else
		C[i]= C[i-1]+1;

	
	}

	*/

int CreateC(int *array,int *C, int size, int K)
{

	C[0]=0;
	for(int i=1; i<K+1;i++)
	{
	if(i>=array[2])
	C[i]= min( min(C[i-array[0]],C[i-array[1]]), C[i-array[2]] ) +1;

	else if(i>=array[1] && i<array[2])
		C[i]= min(C[i-array[0]],C[i-array[1]]) +1;

	else
		C[i]= C[i-array[0]]+1;
		
	}	

	return *C;
}

void RestoreC(int *array, int *C, int K)
{
	int maximum;
	int tempK= K;
	for(int i=C[K]; i>0;i--)
	{
		maximum=array[0];
		for(int j=K; j>-1;j--)
		{
		if( (C[j]==i-1 )&& ( (tempK-j== array[0]) || (tempK-j== array[1]) || (tempK-j== array[2]) ) )
			maximum= max(tempK-j,maximum);//K-j= the coin we used
		
		}
		tempK=tempK-maximum; // decreasing the coin we found from what is left
		cout << maximum << " , " ;

	}
	
}







void main() {
	srand(time(NULL));
	//int *arr1 ,*sum;
	int N = 3;
	
	int Coin1 = 1;
	int Coin2 = rand() % 10 +1;
	int Coin3 = rand() % 10 +1;
	/*
	int Coin1 = 1;
	int Coin2 = 4;
	int Coin3 = 6;
	*/
	int K = (rand() % 20) +1;

	int* C =  new int[K+1];	
	int arr1[3]= {Coin1,Coin2,Coin3};	

	

	cout << "Coins Array: "<< endl;

	for (int i = 0; i < 2; i++) {
		cout << arr1[i] << ", ";
	}
	cout << arr1[2] << endl<<endl;
	cout<< "K: " << K <<endl<<endl;

	sortArray(arr1, 3);
	*C= CreateC(arr1,C,3,K);
	cout<< "C Array: " << endl<<endl;
	cout<< "Place: ";
	for (int i = 0; i < K; i++) {
		cout << i << ", ";
	}
	cout << K << endl;

	cout<< "C: ";
		for (int i = 0; i < K; i++) {
		cout << C[i] << ", ";
	}
	cout << C[K] << endl<<endl;

	cout << "You Can get " << K << " with Minimum of "<< C[K] << " Coins" << endl<<endl;

	
	cout << "The Coins Are: " <<endl;
		RestoreC(arr1,C,K);

	cout <<endl<<endl;
	


}



