#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

        // string line;
        // getline(cin, line);
        // cin>>line;

        // stringstream ss(line);

        // cout<<t<<" -> "<<n<<" \n";//<<line<<"\n";

        int five=0, ten=0;
        bool flag=false;

		for (int i = 0; i < n; i++) {

			int a;
            cin>>a;
            // cout<<" - -  "<<a<<"\n";            
            
            if(a == 5){
                
                five+=1;

            }else if(a == 10){
                if(five>0){
                    ten+=1;
                    five-=1;
                }else{
                    flag=true;

                    // Ignore to the end of line
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    break;
                }        
            }else{
                if( ten>0 ){
                    ten-=1;
                }else if(five>1){
                    five-=2;
                }else{
                    flag=true;
                    
                    // Ignore to the end of line
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    break; 
                }
            }

            // cout<<" - found "<<a<<" "<<five<<" "<<ten<<"\n";

		}

        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
	}

	return 0;
}