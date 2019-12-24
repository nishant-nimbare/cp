
// https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {

 int len = w.length();
 char arr [n];

 strcpy(arr,w.c_str());

//  cout<<char_arr<<endl;

//traverse from right
int i=n-1;
while(i>0){
    
    if(arr[i]>arr[i-1]){
        break;
    }
    if    
i--;
}

//perfecctly decending order
if(i == 0 ) return "no answer";

int smallest=arr[i];
int small_i = i;
int k=i+1;
while(k<n){
    if(arr[k]<smallest && arr[k]>arr[i]){
        smallest = arr[k];
        small_i = k;
    }
    k++;
}

//swap
int t = arr[i];
arr[i] = arr[small_i];
arr[small_i] = t;





}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

