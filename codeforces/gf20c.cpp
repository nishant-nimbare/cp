#include <bits/stdc++.h>

// #define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

float attempt1(int n, int l, vector<int> &flags){

    size_t f1=0, f2=n-1, as=1, bs=1;
    float a=0, b=l, ans = 0, totalTime=0; 

    while(a<b){
        float atime = (float)(flags[f1]-a)/(float)as  , btime=(float)(b-flags[f2])/(float)bs;

        dout<<" - "<<atime<<" "<<btime<<" "<<a<<" "<<b<<" "<<totalTime<<endl;


        if( atime < btime ){
            a = flags[f1++];
            as+=1;
            b = b-(atime*bs);
            totalTime += atime;
        }else if( atime > btime ){
            b = flags[f2--];
            bs+=1;
            a = a+(btime*as);
            totalTime += btime;

        }else{
            // reach respective flag at the same time
            a = flags[f1++];
            b = flags[f2--];

            as+=1; bs+=1;
            totalTime += atime;
            
        }



        if(a == b){
            break;
        }

        if(f1>f2){
            totalTime += (float)(b-a)/(float)(as+bs);
            // ans = a+as*ans;
            break;
        }
    }

    return totalTime;

}


float binarySearch(int n, int l, vector<int> &flags){

    float left = 0, right = l/(float)2;
    int itr =0;
    while(left < right){

        float curTime = (left+right)/2;
        dout<<" - "<<curTime<<" ";
        // float adist = 0.0;
        float alast = 0;
        float aspeed = 1;
        for(int i=0; i<n; i++){
            float timeTillNext = (flags[i]-alast)/aspeed;

            if(curTime < timeTillNext) break;

            curTime -= timeTillNext;
            alast = flags[i];
            aspeed+=1;

        }

        alast +=curTime*aspeed;
        dout<<alast<<" ";

        curTime = (left+right)/2;

        // float bdist = l;
        float blast = l;
        float bspeed = 1;
        for(int i=n-1; i>=0; i--){
            float timeTillNext = (blast-flags[i])/bspeed;

            if(curTime < timeTillNext) break;

            curTime -= timeTillNext;
            blast = flags[i];
            bspeed+=1;

        }

        blast -=curTime*bspeed;

        curTime = (left+right)/2;

        if(alast == blast || itr==100){
            return curTime;

        }else if( alast < blast ){
            left = curTime;

        }else{
            right = curTime;
        }

        itr++;
    }

    return (left+right)/2;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	// std::fstream myfile("./input.txt", std::ios_base::in);

	cin>> t;
	// cout.precision(6);
	while(t--){
		int n,l;
		cin >> n>>l;

        vector<int> flags(n);
		for (int i = 0; i < n; i++) {
            cin>>flags[i];
		} 

        float totalTime = binarySearch(n,l,flags);



        cout << std::setprecision (25)<<totalTime<<endl;
	}

	return 0;
}