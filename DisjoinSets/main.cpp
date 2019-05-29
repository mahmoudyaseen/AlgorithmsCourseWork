#include <bits/stdc++.h>

using namespace std;
class DisjoinSet
{
private:
    int *parent;
    int *counter;
    int Size;
public:
    DisjoinSet(int size)
    {
        Size = size;
        parent = new int [size];
        counter = new int [size];
        for(int i = 0 ; i < size ; i++)
        {
            parent[i] = i ;
            counter[i] = 1;
        }
    }
    int Find(int i)
    {
        if(parent[i] == i)
            return i;
        return Find(parent[i]);
    }
    bool Union(int i1 , int i2)
    {
        if(Find(i1) == Find(i2))
            return false;
        if(counter[Find(i1)] > counter[Find(i2)])
        {
            counter[Find(i1)] += counter[Find(i2)];
            parent[Find(i2)] = Find(i1);
        }
        else
        {
            counter[Find(i2)] += counter[Find(i1)];
            parent[Find(i1)] = Find(i2);
        }
        return true;
    }
    void show()
    {
        for(int i = 0 ; i < Size ; i++)
        {
            cout<< i << " -> " << Find(i) << " = " << counter[i] << "\n";
        }
        cout<<"\n";
    }
    void showp()
    {
        for(int i = 0 ; i < Size ; i++)
        {
            cout<< i << " -> " << parent[i] << " = " << counter[i] << "\n";
        }
        cout<<"\n";
    }
};
int main()
{
    DisjoinSet d(6);
    d.Union(0,1);
    d.show();
    d.Union(2,3);
    d.show();
    d.Union(4,2);
    d.show();
    d.Union(5,0);
    d.show();
    d.Union(5,4);
    d.show();
    d.showp();
    cout<<d.Union(1,0);
    return 0;
}
