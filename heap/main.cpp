#include <bits/stdc++.h>

using namespace std;
class MinHeap
{
private:
    vector<int> arr;
    int parent(int i){return (i-1)/2;}
    int left(int i){return i * 2 + 1;}
    int right(int i){return i * 2 + 2;}
    void heapifyUp(int i)
    {
        if(i == 0) return;
        if(arr[parent(i)] > arr[i])
            swap(arr[parent(i)] , arr[i]);
        heapifyUp(parent(i));
    }
    void heapifyDown(int i = 0)
    {
        int Left , Right , Min;
        Left = left(i);
        Right = right(i);
        Min = i;
        if(Left < arr.size() && arr[Left] < arr[i])
        {
            Min = Left;
        }
        if(Right < arr.size() && arr[Min] > arr[Right])
        {
            Min = Right;
        }
        if(Min != i)
        {
            swap(arr[i] , arr[Min]);
            heapifyDown(Min);
        }
    }
    void DivideAndConcreHeap(int i = 0)
    {
        if( i  >=  arr.size())
            return;
        DivideAndConcreHeap(left(i));
        DivideAndConcreHeap(right(i));
        heapifyDown(i);
    }
public:
    void push(int x)
    {
        arr.push_back(x);
        heapifyUp(arr.size()-1);
    }
    int pop()
    {
        if(arr.size() == 0)
            throw "ERROR";
        int minimum = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        heapifyDown();
        return minimum;
    }
    void show()
    {
        for(int i = 0 ; i < arr.size() ; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    void vectorToHeap(vector<int> a)
    {
        arr.clear();
        for(int i = 0 ; i < a.size() ; i++)
        {
            arr.push_back(a[i]);
        }
        DivideAndConcreHeap(0);
    }
};
int main()
{
    MinHeap m ;
//    m.push(5);
//    m.push(4);
//    m.push(7);
//    m.push(2);
//    m.push(6);
//    m.push(3);
//    m.push(4);
//    m.push(0);
//    m.push(10);
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
//    cout<<m.pop()<<endl;
//    m.show();
    vector<int> a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(7);
    a.push_back(1);
    a.push_back(4);
    a.push_back(3);
    a.push_back(8);
    m.vectorToHeap(a);
    m.show();
    return 0;
}
