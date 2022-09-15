#include<bits/stdc++.h>
using namespace std;
vector<int > makearr(string p, int n)
{
    vector<int > r(n,0);
    r[0] = 0;
    int ptr=0;
    int i=1;
    while(i<n)
    {
        if(p[ptr]==p[i])
        {
            ptr++;
            r[i]=ptr;
            i++;
        }
        else
        {
            r[i]=0;
            i++;
            ptr=0;
        }
    }
    return r;
}

int main()
{

    string A = "abadababada";
    string p = "abada";
    bool check = false;
    vector<int> to_index = makearr(p, p.length());
    int j=-1;
    int count=0;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]==p[j+1])
        {
            j++;
        }
        else if(j!=-1 && A[i]!=p[j+1]){
            j=to_index[j]-1;
            i--;
        }
        if(j==p.length()-1)
        {
            check = true;
            count++;
            j=to_index[j]-1;
        }
    }
    cout<<count<<endl; 
    // if(check==true)
    // {
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }
}