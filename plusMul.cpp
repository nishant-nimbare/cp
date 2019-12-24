#include <iostream>
#include <cstring>
using namespace std;

int convert(string x){
    int n=0;
    char arr[x.length()+1];
    int len = x.length();
    strcpy(arr , x.c_str());

    cout<<"converting ...";
	cout <<"x "<< x << "	 len"<<len<< endl;

    for (int i = len; i > 0; i--) {
        
        if(arr[len-i] == '1') n=n+(1<<(i-1));
    }
    return n;
    
}

int main() {
	// your code goes here
	string a,b,N;
	int T,a1,b1,count,u=0,v=0;
	
	cin >> T;
	getline(cin,N);
	while(T>0){
	    count = 0;
        
        getline(cin,a);
        getline(cin,b);
        
	    a1 = convert(a);
	    b1 = convert(b);
	    
		cout <<"a1 "<< a1 << "	 b1	"<<b1<< endl;


	    while(b1 >0){
	    	u = a1^b1;
	        b1=(a1&b1) << 1;
	        a1 = u;
	        count ++;
			cout <<"	u "<< u << "	 b1	"<<b1<< endl;
	    } 

	    cout << count<< endl;
	    T--;
	}
	return 0;
}

