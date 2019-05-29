#include <iostream>

using namespace std;
const int  To = 5 ;
int dim[]={30,10,20,50,20};
int mcmarr[To][To];
int mcmout[To][To];

//memoization
int MCMmemo(int i , int j)
{
    if(i == j-1) return 0;
    if(mcmarr[i][j] != -1) return mcmarr[i][j];
    int minvalue = 2147483647;
    for(int k = i+1 ; k < j ; k++)
    {
        int res = MCMmemo(i , k) + MCMmemo(k , j) + dim[i] * dim[k] * dim[j];
        if(res < minvalue){minvalue = res; mcmout[i][j] = k;}
    }
    return mcmarr[i][j] = minvalue;
}

void MCMout(int i , int j)
{
    if(i == j-1) {cout<<"(A"<<i<<")"; return;}
    cout<<" ( ";
    MCMout(i , mcmout[i][j]);
    cout<<" X ";
    MCMout(mcmout[i][j] , j);
    cout<<" ) ";
}

//button up
int MCMmemo2(int i , int j)
{
    for(int I = To-2 ; I >= 0 ; I--)
    {
        for(int J = I+1 ; J < To ; J++)
        {
            if(I == J-1) mcmarr[I][J] = 0;
            else
            {
                int minvalue = 2147483647;
                for(int k = I+1 ; k < J ; k++)
                {
                    int res = mcmarr[I][k] + mcmarr[k][J] + dim[I] * dim[k] * dim[J];
                    if(res < minvalue){minvalue = res; mcmout[I][J] = k;}
                }
                mcmarr[I][J] = minvalue;
            }
        }
    }
    return mcmarr[i][j];
}

//button up
int MCMmemo3(int i , int j)
{
    for(int S = 1 ; S < To  ; S++)
    {
        for(int I = 0 ; I + S < To ; I++)
        {
            int J = I + S;
            if(I == J-1) mcmarr[I][J] = 0;
            else
            {
                int minvalue = 2147483647;
                for(int k = I+1 ; k < J ; k++)
                {
                    int res = mcmarr[I][k] + mcmarr[k][J] + dim[I] * dim[k] * dim[J];
                    if(res < minvalue){minvalue = res; mcmout[I][J] = k;}
                }
                mcmarr[I][J] = minvalue;
            }
        }
    }
    return mcmarr[i][j];
}

int main()
{
   for(int i = 0 ; i < To ; i++)
        for(int j = 0 ; j < To ; j++)
        {
            mcmarr[i][j] = mcmout[i][j] = -1;
        }
    cout<<MCMmemo(0,4)<<"\n";
    MCMout(0,4);
    cout<<"\n";

    cout<<MCMmemo2(0,4)<<"\n";
    MCMout(0,4);
    cout<<"\n";


    cout<<MCMmemo3(0,4)<<"\n";
    MCMout(0,4);
    cout<<"\n";

    return 0;
}
