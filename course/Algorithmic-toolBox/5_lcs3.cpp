#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> a){
  for(auto i:a) cout<<i<<' ';
  cout<<"\n";
}

int mmax(int a, int b, int c){
  return max(a, max(b,c));
}

vector<int> lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  size_t l1 = a.size();
  size_t l2 = b.size();

  int table[l1+1][l2+1];
  bool dir[l1+1][l2+1];

  for(int i=0;i<=l1;i++){ table[i][0] = 0; dir[i][0] = false;}
  for(int i=0;i<=l2;i++){ table[0][i] = 0; dir[0][i] = false;}


  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      
      if( a[i-1] == b[j-1] ){ 
        table[i][j] = table[i-1][j-1]+1; //same chars
        dir[i][j] = true;
      }
      else {
          table[i][j] = std::max(
              (table[i-1][j]),
              (table[i][j-1])
          );
        dir[i][j] =false;
        // if( (table[i-1][j]) > (table[i][j-1]) ){
        //   table[i][j] = table[i-1][j];
        //   dir[i][j] = 'u';
        // }else{
        //   table[i][j] = table[i][j-1];
        //   dir[i][j] = 'l';
        // }

      }
    }
  }
  
  // reconstruct the lcs
  vector<int> rev;
  int i = l1, j=l2;

  while( i>0 && j>0 ){
    
    if(dir[i][j]){
      //came from diagonal
      rev.push_back(table[i][j]);
      i-=1;
      j-=1;

    }else{

      if( table[i-1][j] > table[i][j-1] ) i-=1;
      else  j-=1;
    
    }
  }

  reverse(rev.begin(), rev.end());


  return rev;
}


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  cout<<" - a : ";
  printVec(a);
  cout<<" - b : ";
  printVec(b);
  cout<<" - c : ";
  printVec(c);

  
  vector<int> lcs1 = lcs2(a,b); 

  cout<<" lcs b/w a and b \n";
  printVec(lcs1);

  vector<int> ans = lcs2(lcs1,c);

  cout<<" lcs b/w lcs1 and c \n";
  printVec(ans);


  return ans.size();
}


int lcs3D (vector<int> &a, vector<int> &b, vector<int> &c){
  
  size_t l1 = a.size();
  size_t l2 = b.size();
  size_t l3 = c.size();

  int table[l1+1][l2+1][l3+1];


  // for(int i=0;i<=l1;i++)
  //   for(int j=0;j<=l2;j++)
  //     table[i][j][0] = 0;


  // for(int i=0;i<=l2;i++)
  //   for(int j=0;j<=l3;j++)
  //     table[0][i][j] = 0;


  // for(int i=0;i<=l1;i++)
  //   for(int j=0;j<=l3;j++)
  //     table[i][0][j] = 0;


  // for(int i=0;i<=l2;i++) table[0][i][0] = 0;
  // for(int i=0;i<=l3;i++) table[0][0][i] = 0;


  for(int i=0;i<=l1;i++){
    for(int j=0;j<=l2;j++){
      for(int k=0; k<=l2; k++){
      
        if(i==0 || j==0 || k==0 ) table[i][j][k] = 0;

        else if( a[i-1] == b[j-1] && b[j-1] == c[k-1] ) table[i][j][k] = table[i-1][j-1][k-1]+1; //same chars
        else {

            // table[i][j][k] = std::max(
            //   mmax(
            //     ( table[ i-1 ][ j ][ k ] ),
            //     ( table[ i ][ j-1 ][ k ] ),
            //     ( table[ i ][ j ][ k-1 ] )
            //   ),
            //   mmax(
            //     ( table[ i-1 ][ j-1 ][ k ] ),
            //     ( table[ i ][ j-1 ][ k-1 ] ),
            //     ( table[ i-1 ][ j ][ k-1 ] )
            //   )
            // );


            table[i][j][k] = mmax(
                ( table[ i-1 ][ j ][ k ] ),
                ( table[ i ][ j-1 ][ k ] ),
                ( table[ i ][ j ][ k-1 ] )
              ); 

            // table[i][j][k] = mmax(
            //     ( table[ i-1 ][ j-1 ][ k ] ),
            //     ( table[ i ][ j-1 ][ k-1 ] ),
            //     ( table[ i-1 ][ j ][ k-1 ] )
            //   );
        
        }
      
      }
    }
  }
  
  return table[l1][l2][l3];
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3D(a, b, c) << std::endl;
}
