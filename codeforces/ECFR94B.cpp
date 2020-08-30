#include <bits/stdc++.h>

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
		int p, f, tcs, tcw, s, w, ans=0;
		cin>>p>>f>>tcs>>tcw>>s>>w;


        if(s>w){
            swap(s, w);
            swap(tcs, tcw);
        }

        /**
         *  let pcs, pcw => swords and war axes of p
         *  similary fcs, fcw
         * 
         * 
         *  ans = pcs + pcw + fcs + fcw
         * 
         *  pcs*s + pcw*w <= p
         *  fcs*s + fcw*w <= f
         *  
         *  pcs + fcs <= tcs
         *  pcw + fcw <= tcw
         *  
         *  iterate over pcs and find other values (pcw, fcs, fcw)
         *  store the best ans
         * **/


		for (int pcs = 0; pcs <= min(tcs, p/s); pcs++) {

            int pcw = (p-(pcs*s))/w;
            pcw = min(pcw, tcw);

            /**
             *  now the problem is just to maximise no. of items of f
             * 
             *  we can greedy take all possible items whose weight is smaller of the 2 ( sword in our case as we ensured that above )
             * 
             *  since ans with smaller one will always be better or equal than bigger one
             * 
             * **/

            int fcs = (f/s);
            fcs = min(fcs, tcs-pcs);
            
            int fcw = (f - (fcs*s))/w;
            fcw = min(fcw, tcw-pcw);

            ans = max(ans, pcs+pcw+fcs+fcw);

            // dout<<pcs<<pcw<<fcs<<fcw<<ans<<endl;
        }

        cout<<ans<<endl;
	}

	return 0;
}