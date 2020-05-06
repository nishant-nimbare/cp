#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

// done

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    int cd=0, cs=-1, total=0;

    while( (cd+tank) < dist){
        int bestStop = cs +1;

        while(bestStop< stops.size() && stops[bestStop]<=(cd+tank)){
            bestStop++;
        }


        if( ( bestStop>=stops.size() ) ||  ( stops[bestStop] > (cd+ tank) ) ){
            bestStop--;
            if(bestStop == cs){
                // not possible
                return -1;
            }
        }
        
        cs = bestStop;
        cd = stops[bestStop];
        total++;
        

        // cout<<" - "<<bestStop<<"  "<< cd << "\n";
    }

    return total;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
