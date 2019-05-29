#include <iostream>

using namespace std;

string s1 = "san",s2 ="yaseen";

int EDarr[100][100];
int EDout[100][100];
//memoization
int ED(int i , int j)
{
    if(i == 0)
        return j;
    if(j == 0)
        return i;

    if(EDarr[i][j] != -1) return EDarr[i][j];

    if(s1[i-1] == s2[j-1])
        return ED(i-1,j-1);

    int sub = ED(i-1,j-1);
    EDout[i][j] = 0;

    int add = ED(i,j-1);
    if(add<sub) EDout[i][j] = 1;

    int del = ED(i-1,j);
    if(del<min(add,sub)) EDout[i][j] = 2;

    return EDarr[i][j] = min(sub , min(del,add))+1;
}

//button up
int EDButtomUp(int k , int h)
{
    for(int i = 0 ;  i <= s1.length(); i++)
    {
        for(int j = 0 ; j <= s2.length() ; j++)
        {
            if(i == 0)
                EDarr[i][j] =  j ;
            else if(j == 0)
                EDarr[i][j] =  i ;
            else
            {
                if(s1[i-1] == s2[j-1])
                    EDarr[i][j] = EDarr[i-1][j-1];
                else
                {
                    int sub = EDarr[i-1][j-1];
                    EDout[i][j] = 0;

                    int add = EDarr[i][j-1];
                    if(add<sub) EDout[i][j] = 1;

                    int del = EDarr[i-1][j];
                    if(del<min(add,sub)) EDout[i][j] = 2;

                    EDarr[i][j] =  min(sub , min(del,add))+1;
                }
            }
        }
    }
    return EDarr[k][h];
}

//button up space-optimization
int EDarr2[2][100];
int EDButtomUpV2(int k , int h)
{
    int cur = 0;
    for(int i = 0 ;  i <= s1.length(); i++)
    {
        for(int j = 0 ; j <= s2.length() ; j++)
        {
            if(i == 0)
                EDarr2[cur][j] =  j ;
            else if(j == 0)
                EDarr2[cur][j] =  i ;
            else
            {
                if(s1[i-1] == s2[j-1])
                    EDarr2[cur][j] = EDarr2[1-cur][j-1];
                else
                {
                    int sub = EDarr2[1-cur][j-1];
                    int add = EDarr2[cur][j-1];
                    int del = EDarr2[1-cur][j];
                    EDarr2[cur][j] =  min(sub , min(del,add))+1;
                }
            }
        }
        cur = 1-cur;
    }
    return EDarr2[1-cur][h];
}

//button up space-optimization
int EDarr3[100];
int prev ; //[n-1][m-1]
int EDButtomUpV3(int k , int h)
{
    for(int i = 0 ;  i <= s1.length(); i++)
    {
        for(int j = 0 ; j <= s2.length() ; j++)
        {
            int temp = EDarr3[j]; //prev = [n-1][m-1]
            if(i == 0)
                EDarr3[j] =  j ;
            else if(j == 0)
                EDarr3[j] =  i ;
            else
            {
                if(s1[i-1] == s2[j-1])
                    EDarr3[j] = prev;
                else
                {
                    int sub = prev;
                    int add = EDarr3[j-1];
                    int del = EDarr3[j];
                    EDarr3[j] =  min(sub , min(del,add))+1;
                }
            }
            prev = temp;
        }
    }
    return EDarr3[h];

}

void EDoutfun(int i , int j)
{
    if(i == 0)
    {
        for(int s= j-1; s>= 0 ; s--)
            cout<<"add " << s2[s]<<"\n";
        return;
    }
    if(j == -1)
    {
        for(int s= i-1; s>= 0 ; s--)
            cout<<"delete " << s1[s]<<"\n";
        return;
    }
    if(s1[i-1] == s2[j-1])
        return EDoutfun(i-1,j-1);
    if(EDout[i][j] == 0)
    {
        cout<<"substitute "<<s1[i-1] << " with " << s2[j-1] <<"\n";
        return EDoutfun(i-1,j-1);
    }
    if(EDout[i][j] == 1)
    {
        cout<<"add "<< s2[j-1] <<"\n";
        return EDoutfun(i,j-1);
    }
    if(EDout[i][j] == 2)
    {
        cout<<"delete "<< s1[i-1] <<"\n";
        return EDoutfun(i-1,j);
    }
}

int main()
{
    for(int j = 0 ; j < 100 ; j++)
        for(int i = 0 ; i <100;i++)
            EDarr[i][j] = EDout[i][j] = -1;
    cout<<ED(s1.length(),s2.length())<<"\n";
    EDoutfun(s1.length(),s2.length());
    cout<<"\n";
    cout<<EDButtomUp(s1.length(),s2.length())<<"\n";
    EDoutfun(s1.length(),s2.length());
    cout<<"\n";
    cout<<EDButtomUpV2(s1.length(),s2.length())<<"\n";
    cout<<EDButtomUpV3(s1.length(),s2.length())<<"\n";
   return 0;
}
