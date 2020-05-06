#include <bits/stdc++.h>

using namespace std;

const int msize = 1000000;
short int arr[msize] = {0};
unsigned int nextZero[msize] = {0};
unsigned int nextTwo[msize] = {0};



int main(int argc, char const *argv[]) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // int arr[n] = {0};
        memset(arr, 0, sizeof(arr));
        memset(nextZero, 0, sizeof(nextZero));
        memset(nextTwo, 0, sizeof(nextTwo));

        int temp;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            temp = temp % 4;
            if(temp<0) temp+=4;
            arr[i] = temp;
        }

        // int nextZero[n+1] = {-1},nextTwo[n+1] = {-1};
        int c0 = n,c2 = n;

        nextZero[n]=n;
        nextTwo[n]=n;

        for (int i = n - 1; i >= 0; i--) {
            
            nextZero[i] = c0;
            nextTwo[i] = c2;

            if (arr[i] == 0) c0 = i;
            if (arr[i] == 2) c2 = i;

        }

        cout << " array \t";
        for (int i=0;i<n;i++) cout << " " << arr[i];
        cout << "\n";

        cout << "next 0 \t";
        for (int i=0;i<n;i++) cout << " " << nextZero[i];
        cout << "\n";

        cout << "next 2 \t";
        for (int i=0;i<n;i++) cout << " " << nextTwo[i];
        cout << "\n\n\n";

        int  f = 0;
        long long int ans = 0;

        while (f < n) {
            int n2 = nextTwo[f];
            int n0 = nextZero[f];
            cout<<" - arr[f] "<<arr[f]<<"\n";

            switch (arr[f]) {
                case 0: {  // add all to right
                    
                    cout<<" - - addng  "<<((n - 1) - f + 1)<<"\n";
                    ans += (n - 1) - f + 1;

                    break;
                }
                case 2: {
                    int m = min(n0, n2);
                    // add all right elements of zero or next 2
                    cout<<" - - addng  "<<((n - 1) - m + 1)<<"\n";
                    ans += (n - 1) - m + 1;

                    break;
                }
                default:  // 1 and 3
                {
                    if (n0 < n2) {
                        // add all right elements
                        cout<<" - - 0 closer adding  "<<((n - 1) - f + 1)<<"\n";
                        ans += (n - 1) - f + 1;
                    }

                    else if (n2 < n0) {

                        cout<<" - - 2 closer adding  "<<((n2 - 1) - f + 1)<<"\n";

                        // add all till 2
                        ans += (n2 - 1) - f + 1;


                        // add all element after the next 2
                        int nn2 = nextTwo[n2];
                        int m = min(n0,nn2);
                        cout<<" - -  adding after next 2/0  "<<((n - 1) - m + 1)<<"\n";
                        ans += (n - 1) - m + 1;
                    }

                    if(n0 == n2){
                        cout<<" - - no 0/2 adding  "<<((n - 1) - f + 1)<<"\n";
                        ans += (n - 1) - f + 1;
                    }

                    break;
                }
            }

            f++;
        }

        cout << " ---------- final ans = " << ans << " -------- \n\n";
        // cout << ans << '\n';
    }

    return 0;
}