#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;


int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>> t;
	
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;

    /**
     *  
     * 
     * **/
        int bestb=-1, bestLastEle=-1, besta=-1;

        for (int n1 = 0; n1 < n-1; n1++) {
            
            for( int n2 = n1+1; n2<n; n2++){

                if((y-x)%(n2-n1)==0){

                    int b = (y-x)/(n2-n1);

                    if(bestb==-1){
                        
                        bestLastEle = y - (n2*b) + (n-1)*b; 
                        bestb = b;
                        besta = y - (n2*b);
                    }else{
                        int curLast = y - (n2*b) + (n-1)*b;
                        
                        if((curLast < bestLastEle) && (y>(n2*b)) ){
                            bestLastEle = curLast;
                            bestb = b;
                            besta = y - (n2*b);
                        }
                    }
                }
            }
		} 


        for(int i=0; i<n; i++){
            cout<<(besta+(i*bestb))<<" ";
        }
        cout<<endl;
	}

	return 0;
}