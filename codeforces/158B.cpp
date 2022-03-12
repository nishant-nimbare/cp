#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin>> n;

  vector<int> arr(n);

  for(int &x:arr) cin >> x;

  sort(arr.begin(), arr.end(), greater<int>());

  int ans = 0;

  for(int i=0, j=arr.size()-1; i<=j; i++){


    if(i == j){
      //last ele
      ans +=1;
      continue;
    } 

    if(arr[i] == 4){ 
      ans+=1; 
      continue;
    }

    if(arr[i] == 3){ 
      if(arr[j] == 1){
        j--;
      }

      ans+=1;
      continue;
    }


    int rem = 4-arr[i];

    while(i<j && rem>=arr[j]){

      rem -= arr[j];
      j-=1;
    }
    ans+=1;

  } 

  cout<<ans<<endl;


  return 0;
}
