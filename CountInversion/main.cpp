#include <iostream>

using namespace std;
int MergeInversion(int *arr , int mid ,  int n)
{
    int i = 0 , j = mid , inversions = 0, k = 0;
    int *sorted = new int[n];
    while(i < mid || j < n)
    {
        if( j == n || ( i < mid && arr[i] <= arr[j] ) )
        {
            sorted[k++] = arr[i++];
        }
        else
        {
            inversions += mid - i;
            sorted[k++] = arr[j++];
        }
    }
	for (int i = 0; i < n; i++)
		arr[i] = sorted[i];
    return inversions;

}
int count_inversion(int *arr , int n)
{
    if(n == 1)
        return 0;
    int mid = n / 2;
    int x = count_inversion(arr , mid);
    int y = count_inversion(arr + mid , n - mid );
    int z = MergeInversion(arr , mid , n);
    return x + y + z;

}

int main()
{
    int arr1[] = {9,8,7,6,5,4,3,2};
    cout<<count_inversion(arr1 , 8)<<endl;
    return 0;
}
