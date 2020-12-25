#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;
using std::cout;

void printMat(vector<vector<int>> mat){

    for(auto row : mat){
        for(auto x : row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void printlist(list<int> v){
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
}

void print_spiral(vector<vector<int>> mat){

    int hirow = mat.size()-1, hicol = mat[0].size()-1, lorow=0, locol=0;

    while( lorow <= hirow && locol <= hicol ){
        
        cout<<" - - " <<lorow<<" "<<hirow<<" "<<locol<<" "<<hicol<<endl;
        if( locol <= hicol ){
            for(int i=locol; i<hicol; i++){
                cout<<mat[lorow][i]<<" ";
            }
            // locol++;
        }

        cout<<endl;

        if( lorow <= hirow ){
            for(int i=lorow; i<hirow; i++){
                cout<<mat[i][hicol]<<" ";
            }
            // lorow++;
        }
        
        cout<<endl;


        if( locol <= hicol && lorow < hirow ){ //if lorow == hirow that row would have been printed in 1st pass (left -> right) 
            for(int i=hicol; i>locol; i--){
                cout<<mat[hirow][i]<<" ";
            }
            // hicol--;
        }

        cout<<endl;


        if( lorow <= hirow && locol<hicol ){
            for(int i=hirow; i>lorow; i--){
                cout<<mat[i][locol]<<" ";
            }
            // hirow--;
        }

        locol++;
        hicol--;
        lorow++;
        hirow--;
        cout<<endl;
        // return;
    }
}


int getIncr(int r, int c, int hirow, int  hicol, int lorow, int locol, int cur, bool clkwise ){

    int rowlen = hirow - lorow;
    int collen = hicol - locol;  

    if(clkwise){


        if(cur<collen) return 1; //c++;

        else if(cur< collen+rowlen) return 2; //r++

        else if(cur< 2*collen+rowlen) return 3;// c--

        else if(cur< 2*collen+2*rowlen) return 4; //r--

        return -1;

    }

    else{

        if(cur<rowlen) return 2;

        else if( cur< rowlen+collen ) return 1;

        else if( cur< 2*rowlen + collen) return 4;

        else if( cur< 2*rowlen + 2*collen ) return 3;


    }

    return -1;

}

void rotate(vector<vector<int>> mat, int k){

    //rotate by k elements

    int hirow = mat.size()-1, hicol = mat[0].size()-1, lorow=0, locol=0;

    list<int> q;

    bool clkwise = false;

    while( lorow < hirow && locol < hicol ){

        int total_ele = 2*(hirow-lorow) + 2*(hicol-locol);
        cout<<" total ele : "<<total_ele<<endl;

        if(k>=total_ele){
            k = k%total_ele;
        }

        int cur = 0, r=lorow, c=locol; 

        while(  cur < total_ele ){

            cout<<" - "<<r<<" "<<c<<" := ";
            printlist(q);

            q.push_back(mat[r][c]);
            
            if(cur>=k){
                mat[r][c] = q.front();
                q.pop_front();
            }


            switch (getIncr(r,c,hirow,hicol,lorow,locol, cur, clkwise))
            {
            case 1:c++;
                break;
            case 2:r++;
                break;
            case 3:c--;
                break;
            case 4:r--;
                break;
            
            default:
                cout<<" - - returned -1"<<endl;
                break;
            }
            cur++;

        }

        // place the remaining elements from the queue
        cur = 0, r=lorow, c=locol; 
        while(!q.empty()){


            cout<<" - "<<r<<" "<<c<<" := ";
            printlist(q);

            mat[r][c] = q.front();
            q.pop_front();

            
            switch (getIncr(r,c,hirow,hicol,lorow,locol, cur, clkwise))
            {
            case 1:c++;
                break;
            case 2:r++;
                break;
            case 3:c--;
                break;
            case 4:r--;
                break;
            
            default:
                cout<<" - - returned -1"<<endl;
                break;
            }
            cur++;

        }

        //change direction
        clkwise = !clkwise; 

        // iterate for inner square
        lorow++;
        hirow--;

        locol++;
        hicol--;

        cout<<endl<<endl<<endl;

        // break;
    }


    printMat(mat);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> mat ={
        { 1, 2, 3, 4, 77 },
        { 5, 6, 7, 8, 77 },
        { 9, 10, 11, 12, 77 },
        { 13, 14, 15, 16, 77 } };
 

    rotate(mat,2);

    return 0;
}