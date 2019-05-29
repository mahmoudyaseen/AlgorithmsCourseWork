#include <iostream>

using namespace std;

const int Element = 4,Weight = 8;
int value[] = { 1 , 5 , 4 , 7};
int weight[] = {  2 , 4 , 3 , 5 };


int mem[Element][Weight];
int out[Element][Weight];
//memoization
int MaxKnapSack(int i,int w)
{
    if(i == 0)
    {
        if(w >= weight[i]){out[i][w] = 1; return value[i];}
        out[i][w] = 0; return 0;
    }

    if(mem[i][w] != -1){ return mem[i][w];}

    int value2 = MaxKnapSack(i-1 , w); out[i][w] = 0;

    int value1 = 0;
    if(w >= weight[i])
        value1 = MaxKnapSack(i-1 , w - weight[i]) + value[i];

    if(value1 > value2)
        out[i][w] = 1;

    return mem[i][w] = max(value1,value2);
}
void printout(int i , int w)
{
    if(i == -1) return;
    if(out[i][w])
        printout(i-1,w-weight[i]);
    else
        printout(i-1,w);
    cout<< i << " " << out[i][w] <<endl;

}
void printout2(int i , int w)
{
    while(i >= 0)
    {
        cout<< i << " " << out[i][w] <<endl;
        if(out[i][w])
            w-=weight[i];
        i--;
    }
}



//button up
int MaxKnapSack2(int k , int w)
{
    for(int i = 0 ; i < Element ; i++)
    {
        for(int j = 0 ; j < Weight ; j++)
        {
            if(i == 0)
            {
                if(j >= weight[i]){out[i][j] = 1; mem[i][j] = value[i];}
                else {out[i][j] = 0; mem[i][j] = 0;}
            }
            else
            {
                int value2 = mem[i-1][j]; out[i][j] = 0;
                int value1 = 0;
                if(j >= weight[i])
                    value1 = mem[i-1][j - weight[i]] + value[i];
                if(value1 > value2)
                    out[i][j] = 1;
                mem[i][j] = max(value1,value2);
            }
        }
    }
    return mem[k][w];
}

//button up space-optimization
int mem2[2][Weight];
int MaxKnapSack3(int i , int w)
{
    int cur = 0;
    for(int i = 0 ; i < Element ; i++)
    {
        for(int j = 0 ; j < Weight ; j++)
        {
            if(i == 0)
            {
                if(j >= weight[i]){mem2[cur][j] = value[i];}
                else { mem2[cur][j] = 0;}
            }
            else
            {
                int value2 = mem2[1-cur][j];
                int value1 = 0;
                if(j >= weight[i])
                    value1 = mem2[1-cur][j - weight[i]] + value[i];
                mem2[cur][j] = max(value1,value2);
            }
        }
        cur = 1 - cur;
    }
    return mem2[1 - cur][w];
}

//button up space-optimization
int mem3[Weight];
int MaxKnapSack4(int i , int w)
{
    for(int i = 0 ; i < Element ; i++)
    {
        for(int j = Weight-1 ; j >=0 ; j--)
        {
            if(i == 0)
            {
                if(j >= weight[i]){mem3[j] = value[i];}
                else { mem3[j] = 0;}
            }
            else
            {
                int value2 = mem3[j];
                int value1 = 0;
                if(j >= weight[i])
                    value1 = mem3[j - weight[i]] + value[i];
                mem3[j] = max(value1,value2);
            }
        }
    }
    return mem3[w];
}

//BranchAndBound
int valuesum[] = { 1 , 6 , 10 , 17};
//gready solu
double fraction_knapsack(int i , int w)
{
    double total = 0 ;
    for( ; i >= 0 ; i--)
    {
        if(w > weight[i])
        {
            total += value[i];
            w -= weight[i];
        }
        else
        {
            total += ((double)value[i] / weight[i]) * w;
            break;
        }
    }
    return total;
}
int knapsackBranchAndBound(int i , int w)
{
    if( i == 0 )
    {
        if(w >= weight[i] ) return value[i];
        else return 0;
    }

    int value2 = 0;
    if(w >= weight[i])
        value2 = knapsackBranchAndBound( i -1 , w - weight[i] ) + value[i];

    //fraction kanpsack
    double optimalbranch = fraction_knapsack(i - 1 , w); //O(N) but more accurate
    //total sum
    //int optimalbranch = valuesum[i -1]; //O(1) but less accurate


    if(value2 > optimalbranch)
        return value2;

    int value1 = knapsackBranchAndBound(i -1 , w);

    return max(value1 , value2);
}


int main()
{
    for(int i = 0 ; i < Element ; i ++)
        for(int j = 0 ; j < Weight ; j++)
            mem[i][j] = -1;
    cout<<MaxKnapSack(3,7)<<"\n";
    printout(3,7);
    cout<<"\n";
    printout2(3,7);
    cout<<"\n";
    cout<<MaxKnapSack2(3,7)<<"\n";
    printout(3,7);
    cout<<"\n";
    printout2(3,7);
    cout<<"\n";
    cout<<MaxKnapSack3(3,7)<<"\n";
    cout<<"\n";
    cout<<MaxKnapSack4(3,7)<<"\n";
    cout<<"\n";
    //sort by value/weight
    //for easy : i will enter values sorted
    //sum the value in valuesum array
    //for easy i will enter this values
    cout<<knapsackBranchAndBound(3 , 7)<<"\n";
    //O((2 ^ N) * N) if we use fraction knapsack
    //O(2 ^ N) if we user valuesum
    cout<<"\n";
    cout<<fraction_knapsack(3,7)<<"\n";

    return 0;
}
