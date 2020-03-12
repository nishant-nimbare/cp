#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <unordered_map>

// #define lli long long int
// 2
// 2 2
// -4 2
// 2 -8
// 8 4
// 1 2 3 6 -1 -2 -3 -6
// 6 -6 1 -1

using namespace std;

const int MAX =1e5;

int sieve[MAX+1];
int freqX[2][MAX+1],freqY[2][MAX+1];


void makeSieve(int max){

    for (int i=2;i<=max;i++)
        if(!sieve[i])
            for(int j=i;j<=max;j+=i)
                sieve[j]=i;    

}

unordered_map<int,int> getFactors(int num){

    unordered_map<int,int> factors;

    while(num!=1){
        int fact = sieve[num];
        
        // cout<<"curr fact"<< fact <<endl;

        if(!factors[fact]) factors[fact] =1;
        else factors[fact]+=1;

        num/=fact;
    }

    return factors;
}

void getDivisors(int fi, int curDivisor, vector<int> &primeFacts ,unordered_map<int,int> factors , vector<int> &divisors){

    // cout<<" - "<<fi<<"  "<<curDivisor<<"\n";

    if(fi>=primeFacts.size()){
        // all factors are exhausted
        
        divisors.push_back(curDivisor);
        return;
    }

    int curFact = primeFacts[fi];


    for(int i=0;i<=factors[curFact];i++){
        
        getDivisors(fi+1, curDivisor, primeFacts, factors, divisors);
        curDivisor*=curFact;

    }


} 

long long int getTriangles( int freqX[2][MAX+1], vector<int> &x, vector<int> &y){

    long long int ans=0;

    for(auto Y:y){

        // cout<<"\nauto Y "<<Y<<"\n\t";

        unordered_map<int,int> factors = getFactors(abs(Y));
        vector<int> primeFacts;

        for(auto itr:factors) {
            // cout<< itr.first << " e "<<itr.second<<"\n\t";
            primeFacts.push_back(itr.first);
        } 

        vector<int> divisors;

        getDivisors(0, 1, primeFacts,factors, divisors);

        // cout<<"all divisors \t";
        // for(auto itr:divisors) cout<<itr<<" ";

        // cout<<"\n\t searching for  ";

        for(auto X:divisors){
            if( (Y*Y)/X <= MAX){
                // cout<<X<<" "<<(Y*Y)/X<<"\t";
                ans+= freqX[0][X] * freqX[1][(Y*Y)/X];

                if(X!=abs(Y)) ans+= freqX[1][X] * freqX[0][(Y*Y)/X];

            }
        }

        // cout<<"\nans till now "<<ans<<"\n\t";            

    }

    // cout<<"\n ---returning ans "<<ans<<"\n";
    return ans;

}

int main(int argc, char const *argv[])
{
	int t;

    makeSieve(MAX);

    // cout<<"sieve done"<<endl;

	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	
	while(t--){
		int n,m;
		cin>>n>>m;

        // cout<<n<<" "<<m<<endl;
        // int x[n],y[m];
        vector<int> x,y;


        memset(freqX,0,sizeof(freqX));
        memset(freqY,0,sizeof(freqY));

        long long int ans=0;
        int temp;
        // cout<<"\n  x";

        for (int i = 0; i < n; i++){
            
            cin>>temp;
            // cout<<" "<<temp;

            freqX[ ( temp<0 ) ][ abs(temp) ]++;

            if(temp==0){
                ans=n*m;
                n--;
            }else{
                x.push_back(temp);
            }
        }
        // cout<<"\n  y";


        for (int i = 0; i < m; i++){
            cin>>temp;
            // cout<<" "<<temp;

            freqY[ ( temp<0 ) ][ abs(temp) ]++;

            if(temp==0){
                ans=n*m;
                m--;
            }else{
                y.push_back(temp);
            }    

        } 
        // cout<<"\n\n";


        // y^2 = x1*x2
        ans+= getTriangles(freqX,x,y);

        //x^2 = y1*y2
        ans+= getTriangles(freqY,y,x);

        // cout<<"total answer "<<ans<<endl;
        cout<<ans<<endl;
        // cout<<"\n _________------------__________\n";
	}

	return 0;
}