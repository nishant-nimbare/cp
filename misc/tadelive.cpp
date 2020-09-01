#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// std::vector<int> a ;
// std::vector<int> b ;


int main() {
    
    int n,x,y;
	// std::fstream myfile("./input.txt", std::ios_base::in);
    
	
	cin>>n>>x>>y;
    
    int a[n+1]={0};
    int b[n+1] = {0};
    int mhash[n+1][n+1];

	std::fill(&mhash[0][0], &mhash[0][0]+sizeof(mhash), 0);

	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 	{
	// 		cout<<mhash[i][j]<<"\t";
	// 	}

	// 	cout<<endl;
		
	// }
	// cout<<" ------------ "<<endl;
        
    int t;
    for (int i = 1; i <= n; i++) {
        cin >>t;
        // a.push_back(t);
        a[i]=t;
		// cout<<a[i];
    }
	cout<<endl;
    
    for (int i = 1; i <= n; i++) {
        cin >>t;
        // b.push_back(t);
        b[i] = t;
		// cout<<b[i];
    }
	cout<<endl;

	mhash[1][0]=b[1];
	mhash[1][1]=a[1];

    for (int i = 1; i <= n; i++) {
        
        for (int j = 0; (j<=x && j<=i) ; j++) {
            
            int l=0,r=0;
            
            if(j<=x && j!=0)
            l = a[i] + mhash[i-1][j-1];
        
            if((i-j)<=y && j!=i)
            r = b[i] + mhash[i-1][j];

			cout<<"i j l r"<<i<<j<<l<<r<<endl;
            
            mhash[i][j] = max(l,r);
        }
    }

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout<<mhash[i][j]<<"\t";
		}

		cout<<endl;
		
	}
	

    int ans=0;
    for (int i = 1; i < n; i++) {
        ans = max(ans,mhash[n][i]);
    }

    cout<<ans<<endl;
	return 0;
}
