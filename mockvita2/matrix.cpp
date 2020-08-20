#include <bits/stdc++.h>
using namespace std;

vector< vector<int>> matrix;


// struct point{
//     int row,col;
//     point(int r, int c) : row(r), col(c) {}
// };


// point next(point p, bool dir, int minr, int minc, int maxr, int maxc){

//     if(dir){
//         // counter clockwise

//     }else{

//         if( p.row == minr){
            
//             if( p.col < maxc ) p.col += 1;
//             else{
//                 p.row += 1;
//             }
//         }


//         else if( )

//     }

// }


void printMat(int m, int n){

    for(int i=0; i<m; i++){
    	for( int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

}

void rotate(int lvl, int k, int m, int n){

  	int minr=lvl, maxr = m-1-lvl, minc=lvl, maxc=n-1-lvl;
  
  	list<int> firstk;


    int r=minr, c = minc;

    int t=0;
	int totalele = 2*(maxr-minr) + 2*(maxc - minc);
  
  	k %= 2*(maxr-minr) + 2*(maxc - minc);
  

    if(lvl%2==0){
        // counter clock wise

        t=k;
        while(t--){

            firstk.push_back(matrix[r][c]);

                if(r==minr && minc<c && c<=maxc) c--;
            else if(c==maxc && minr<r && r<=maxr) r--;
            else if(r==maxr && minc<=c && c<maxc) c++;
            else if(c==minc && minr<=r && r<maxr) r++; 
        
        }


        t= totalele;
        
        while(t--){
        
            int cur = firstk.front();
            firstk.pop_front();

            firstk.push_back(matrix[r][c]);
            
            matrix[r][c] = cur;
            
            // printMat(m,n);

        
                if(r==minr && minc<c && c<=maxc) c--;
            else if(c==maxc && minr<r && r<=maxr) r--;
            else if(r==maxr && minc<=c && c<maxc) c++;
            else if(c==minc && minr<=r && r<maxr) r++; 
        
        }

    }else{
        // clockwise
        t=k;
        while(t--){

            firstk.push_back(matrix[r][c]);

             if(r==minr && minc<=c && c<maxc) c++;
            else if(c==maxc && minr<=r && r<maxr) r++;
            else if(r==maxr && minc<c && c<=maxc) c--;
            else if(c==minc && minr<r && r<=maxr) r--; 
        
        }


        t= totalele;
        
        while(t--){
        
            int cur = firstk.front();
            firstk.pop_front();

            firstk.push_back(matrix[r][c]);
            
            matrix[r][c] = cur;
            
            // 1printMat(m,n);
            
            if(r==minr && minc<=c && c<maxc) c++;
            else if(c==maxc && minr<=r && r<maxr) r++;
            else if(r==maxr && minc<c && c<=maxc) c--;
            else if(c==minc && minr<r && r<=maxr) r--; 
        
        }

    }
  
}

int main(int argc, char const *argv[]){
	int m,n;
  	cin>>m>>n;
  
  	for(int i=0; i<m; i++){
    	vector<int> row;
    	for( int j=0; j<n; j++){
			int a; cin>>a;
          	row.push_back(a);
        }
      	matrix.push_back(row);
    }

  	int max_lvl = std::min( m/2, n/2 );

    // printMat(m,n);
  
  	for(int l=0; l<max_lvl; l++){
    	
      int k;
      cin>>k;
    //   cout<<" rotating by "<<k<<" \n";
      if(k>0)
      rotate(l,k,m,n);
      	
    }


    printMat(m,n);


}