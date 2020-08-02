#include <bits/stdc++.h>

using namespace std;

int ini[3];
int tar[3];
// int diff[3];
int quo[3], rem[3];

int findExact(int q[3], int r[3], bitset<3> &done){

    int res=0;

    for(int i=0;i<2;i++)
        for(int j=i+1; j<3; j++)
            if( done[i]==0 && done[j]==0 && q[i]==q[j] && r[i]==r[j] ) res+=1;


    return res;
}

int findExactQ(int q[3], bitset<3> &done){

    int res=0;

    for(int i=0;i<2;i++)
        for(int j=i+1; j<3; j++)
            if( done[i]==0 && done[j]==0 && q[i]==q[j] ) res+=1;


    return res;
}

int findNext(int arr[3], bitset<3> &done){
    int m=-1,i=1;

    while(i<3){
        if((m==-1) && (done[i] == 0)) m=i;

        if( (done[i] == 0) && (arr[i] < arr[m]) ) m=i;

        i+=1;
    }

    return m;
}

int main(int argc, char const *argv[]){

    // fflush(stdin);

    cout<<" starting ... \n";
	int t;
	cin>>t;
	
	while(t--){
        cout<<"t :"<<t<<"\n";
		// int p, q, r, a, b, c;

        int step=0;

        int i=0;
        while(i<3) {
            cin>>ini[i];
            i+=1;
        }

        i=0;
        while(i<3) {
            cin>>tar[i];
            i+=1;
        }        


        cout<<" input taken \n";
        bitset<3> done(0);

        i=0;
        while(i<3){
            // diff[i] = tar[i] - ini[i];
            if(ini[i] == 0 ){
                quo[i] = -1;
                rem[i] = tar[i];
            }else{
                quo[i]  = tar[i] / ini[i];
                quo[i] -= 1; 
                rem[i]  = tar[i] % ini[i];
            }

            if(ini[i] == tar[i]) done[i] =1;            

            cout<<ini[i]<<" ";
            i+=1;
        };
        cout<<"\n";

        if(done.count() == 3){
            cout<<0<<"\n";
            continue;
        }

        int exact = findExact(quo, rem, done);
        
        if(exact >= 3-done.count()){
            cout<<1<<"\n";
            continue;
        }

        int exactQ = findExactQ(quo, done);

        if(exactQ == ( 3 - done.count() ) && exact == ( 2-done.count() ) ){
            for(int r:rem) 
                if(r==0){ 
                    cout<<2<<"\n";
                    continue;
                }
        }


        cout<<3-done.count()<<"\n";

        // while(done.count()<3){

        //     cout<<" done "<<done<<"\n";
        //     int iq = findNext(quo, done);
        //     int ir = findNext(rem, done);

        //     cout<<" - iq "<<iq<<"\n";
        //     // if( iq == -1 ) break;

        //     if(quo[iq]>0){
        //         i=0;
        //         int mul = quo[iq];
        //         cout<<" - mul "<<mul<<"\n - - new arr ";
        //         while(i<3) {

        //             // if(done[i] == 1) continue;

        //             ini[i]  += ( ini[i]*mul ) ;
                    
        //             if(ini[i] == 0 ){
        //                 quo[i] = -1;
        //                 rem[i] = tar[i];
        //             }else{
        //                 quo[i]  = tar[i] / ini[i];
        //                 quo[i] -= 1; 
        //                 rem[i]  = tar[i] % ini[i];
        //             }
                    
        //             if(ini[i] == tar[i]) done[i] =1;    

        //             cout<<ini[i]<<"  ";
        //             i+=1;
                
        //         }
        //         cout<<"\n";
        //         step+=1;
        //         continue;
        //     }

        //     cout<<" - ir "<<ir<<"\n";
        //     if( ir == -1 ) break;

        //     i=0;
        //     int add = rem[ir];
        //     cout<<" - add "<<add<<"\n  - - new arr ";

        //     while(i<3) {

        //         // if(done[i] == 1) continue;

        //         ini[i] += add;
                
        //         if(ini[i] == 0 ){
        //             quo[i] = -1;
        //             rem[i] = tar[i];
        //         }else{
        //             quo[i]  = tar[i] / ini[i];
        //             quo[i] -= 1; 
        //             rem[i]  = tar[i] % ini[i];
        //         }
                
        //         if(ini[i] == tar[i]) done[i] =1;         
            
        //         cout<<ini[i]<<" ";
        //         i+=1;
        //     }
        //     cout<<"\n";
        //     step+=1;
            
        // }
	
        // cout<<step<<"\n";
    }

	return 0;
}