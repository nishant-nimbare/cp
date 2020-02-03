#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string.h>

#define F(i,a,b) for( i=(int)a ; i<=(int)b ; i++)
#define RF(i,a,b) for( i=(int)a ; i>=(int)b ; i--)


using namespace std;


int  threemin(int a,int b,int c){
    return min(a , min(b,c));
}

void showHash(int *arr,int n1,int n2){
int i=0;
F(i,0,n1){
    int j=0;
    F(j,0,n2){
        cout<<*((arr+i*n2)+j)<<"\t";
    }
    cout<<endl;
}

}


int main(int argc, char const *argv[])
{
	string source,target;
	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>>source>>target;
	
    cout<<"source "<<source<<endl;
    cout<<"target "<<target<<endl;

    char sa [source.length()], ta [target.length()];

    int hash[source.length()][target.length()];

    strcpy(sa,source.c_str());
    strcpy(ta,target.c_str());

    int i=0;
    F(i,0,source.length())
    {
        hash[0][i]=i;
        cout<<"0 "<<i<<endl;
    }

    int k=0;
    F(k,0,target.length())
    {
        hash[k][0]=k;
        cout<<k<<" 0"<<endl;

    }

    showHash((int *)hash,source.length(),target.length());


    //starting dp
    i=1;
    F(i,1,source.length())
    {
        int j=1;
        F(j,1,target.length())
        {
            if(sa[i-1] == ta[j-1]){
                //same 

                hash[i][j]=hash[i-1][j-1];

            }else{
                //different
                hash[i][j] = threemin( hash[i-1][j], hash[i][j-1], hash[i-1][j-1]) +1;
            }
        }
    }

    showHash((int *)hash,source.length(),target.length());

    cout << hash[source.length()+1][target.length()+1]<<endl;
	return 0;
}