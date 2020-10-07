#include <bits/stdc++.h>


using namespace std;

int main(int argc, char const *argv[]) {

    float I,P,A;
    cin>>I>>P>>A;

    P = P/(float)100;

    float diff = A-I;

    int curChild =0, pastChild = 1;
    float curI = 0, pastI=I;

    int ans =0;

    while(diff>0){
        curI = pastI*P;

        int req = ceil(diff/curI);

        // cout<<" - "<<curI<<" "<<req<<endl;

        if(req<=2*pastChild){
            ans += req;
            diff = 0;
            pastChild = req;
            break;
        }

        ans += 2;
        diff -= 2*pastChild*(curI);
        pastChild = 2*pastChild;
        pastI = curI;
    }

    cout<<ans;
    return 0;
}