#include <stdio.h>
void HelperSort(int j,int arr[]){
	if(j>=1 && arr[j-1]>arr[j])
	{
		int temp=arr[j-1];
		arr[j-1]=arr[j];
		arr[j]=temp;
		HelperSort(--j,arr);
	}

}
void InsertionSort(int i, int array[], int size){
	if(i < size)
	{
		int j;
		HelperSort(i,array);
		InsertionSort(++i,array,size);
	}
}
int main(){
	int arr[]={24,4,1,15,1,1,6,26,34,67,456,34,62,2,561,4,21,141,123,44,65};
	InsertionSort(0,arr,21);
	int i;
	for (i = 0; i < 21; ++i)
	{
		printf("%d\n",arr[i] );
	}

	return 0; 

}
