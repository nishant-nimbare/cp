#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]){

    int n,m,d;
    cin>>n>>m>>d;

    int matrix[n][m];

    int minEle = INT_MAX;
    long long int moves=0;

    bool brk=false;

    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<m; j++){
            cin>>matrix[i][j];

            cout<<" - "<<matrix[i][j]<<"  min "<<minEle<<'\n';

            if(minEle == INT_MAX) {
                minEle = matrix[i][j]; 
                continue;
            }

            if(matrix[i][j] < minEle){

                if((minEle - matrix[i][j])%d !=0){
                    brk=true;
                    break;                
                }

                int exmov = (minEle - matrix[i][j])/d;
                
                moves+= exmov*(i*m+j);               
                minEle = matrix[i][j];
                continue;
            }

            if((matrix[i][j] - minEle)%d != 0){
                brk=true;
                break;                
            }

            moves += (matrix[i][j] - minEle)/d;
            cout<<" - - "<<matrix[i][j]<<' '<<minEle<<"  "<<moves<<"\n";     

        }

        if(brk){
            cout<<" Breaking at "<<i<<' '<<moves<<"\n";     
            break;
        }
    }


    if(brk) cout<<-1<<'\n';
    else cout<<moves<<'\n';
}