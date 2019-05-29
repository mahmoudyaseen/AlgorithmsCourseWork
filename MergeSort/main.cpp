#include <iostream>

using namespace std;
void Merge(int *arr , int mid , int n)
{
    int i = 0 , j = mid , k = 0;
    int *sorted = new int[n];
    while(i < mid || j < n)
    {
        if( j == n || ( i < mid && arr[i] <= arr[j] ) )
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }
	for (int i = 0; i < n; i++)
		arr[i] = sorted[i];
}
void MergeSort(int *arr , int n)
{
    if(n == 1)
        return;
    int mid = n / 2;
    MergeSort(arr , mid);
    MergeSort(arr + mid , n - mid );
    Merge(arr , mid , n);
}

int main()
{
    int arr[] = {7,5,3,4,6,8,2,1,0};
    MergeSort(arr , 9);
    for(int i = 0 ; i <  9 ; i ++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
