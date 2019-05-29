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
    bool Union(int i1, int i2)
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
};

class Kruskal
{
private:
    pair<int, pair<int, int > >p;
    priority_queue <pair<int, pair<int, int > > > edges;   // weight from to // we can use minimum heap it is easer
    vector < pair<int, pair<int, int > > > MSP;   // the output
public:
    void add (int weight, int from, int to)
    {
        edges.push( make_pair(-1 * weight, make_pair(from, to)));
    }
    int getMSP()
    {
        DisjoinSet sett(edges.size()); //to avoid cicles
        int total_cost = 0;
        while(!edges.empty())
        {
            p = edges.top();
            p.first *= -1;
            if(sett.Union(p.second.first, p.second.second))
            {
                MSP.push_back(p);
                total_cost += p.first;
                cout<<p.second.first << " -> " << p.second.second << " weight = " << p.first << "\n";
            }
            edges.pop();
        }
        return total_cost;
    }
};
int main()
{
    Kruskal k ;
    k.add(1 , 7 , 6);
    k.add(2 , 8 , 2);
    k.add(2 , 6 , 5);
    k.add(4 , 0 , 1);
    k.add(4 , 2 , 5);
    k.add(6 , 8 , 6);
    k.add(7 , 2 , 3);
    k.add(7 , 7 , 8);
    k.add(8 , 0 , 7);
    k.add(8 , 1 , 2);
    k.add(9 , 3 , 4);
    k.add(10 , 5 , 4);
    k.add(11 , 1 , 7);
    k.add(14 , 3 , 5);
    cout<<k.getMSP()<<"\n";
    return 0;
}
