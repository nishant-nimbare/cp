#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<int>> segTree;
vector<int> lazyTree;

void printTree(vector<int> tree){

	// cout<<"**********************************-------------------------------------------****************************************"<<endl;

	// for (std::vector<int>::iterator i = tree.begin(); i != tree.end(); i++)
	// {
	// 	cout<< *i <<" "; 
	// }

	// cout<<endl;

    int treeDepth=log2(tree.size());

    for(int depth=0;depth<log2(tree.size());depth++){
        
        std::cout << std::string( (treeDepth-depth), '\t' );

        int from=(int)(1<<depth)-1;
        int to=(int)(1<<(depth+1))-1;

        // cout<<depth<<from<<to<<"\n";

        for(int i= from; i<to; i++ ){
            cout<<tree[i]<<"\t";
        }
        cout<<"\n";
    }
	// cout<<"**********************************-------------------------------------------****************************************"<<endl;

}


void createSegmentTree(int low,int high, int pos){

    if(low>high) return;

    if(low==high){
        // leaf node
        segTree[0][pos]=1;
        segTree[1][pos]=0;
        segTree[2][pos]=0;

        //all leaves are initially zero i.e divisible by 3
        return;
    }

    int mid = (low+high)/2;

    createSegmentTree(low,mid,2*pos+1);
    createSegmentTree(mid+1,high,2*pos+2);

    segTree[0][pos] = segTree[0][2*pos+1] + segTree[0][2*pos+2];

}

int findSegTree(int ql, int qh, int low, int high,int pos){

    // cout<<"find -- "<<ql<<qh<<low<<high<<pos<<"\n";

    if(low>high) return 0;
    
    if(qh<low || high<ql){
        //no overlap
        return 0;
    }

    if(lazyTree[pos]!=0){
        //values remaining

        while (lazyTree[pos]--){
            
            int temp =segTree[0][pos];
            segTree[0][pos]=segTree[2][pos];
            segTree[2][pos]=segTree[1][pos];
            segTree[1][pos] = temp;

        }

        if(low!=high){
            lazyTree[2*pos+1]+=1;
            lazyTree[2*pos+2]+=1;
            lazyTree[2*pos+1]%=3;
            lazyTree[2*pos+2]%=3;
        }

        lazyTree[pos]=0;
    }


    if(low==high) return segTree[0][pos]; //leaf node

    if(ql<=low && high<=qh){
        //total overlap
        return segTree[0][pos];
    }

    int mid = (low+high)/2;

    return findSegTree(ql,qh,low,mid,2*pos+1) + findSegTree(ql,qh,mid+1,high,2*pos+2);

}

void updateSegmentTree(int ql,int qh,int low,int high,int pos){

     if(low>high) return;
    
    if(qh<low || high<ql){
        //no overlap
        return;
    }


    if(lazyTree[pos]!=0){
        //propogation remaining

        while (lazyTree[pos]--){
            
            // cout<<" ROTATING at "<<pos<<"\n";
            int temp =segTree[0][pos];
            segTree[0][pos]=segTree[2][pos];
            segTree[2][pos]=segTree[1][pos];
            segTree[1][pos] = temp;

        }

        if(low!=high){
            lazyTree[2*pos+1]+=1;
            lazyTree[2*pos+2]+=1;
            lazyTree[2*pos+1]%=3;
            lazyTree[2*pos+2]%=3;
        }

        lazyTree[pos]=0;
        
    }



    //leaf node and total overlap
    if((low==high)||(ql<=low && high<=qh)){
        
        // cout<<" rotating at "<<pos<<"\n";

        int temp =segTree[0][pos];
        segTree[0][pos]=segTree[2][pos];
        segTree[2][pos]=segTree[1][pos];
        segTree[1][pos] = temp;

        if(low!=high){
            lazyTree[2*pos+1]+=1;
            lazyTree[2*pos+2]+=1;
            lazyTree[2*pos+1]%=3;
            lazyTree[2*pos+2]%=3;
        }
        return;
    
    }   

    int mid = (low+high)/2;

    updateSegmentTree(ql,qh,low,mid,2*pos+1);
    updateSegmentTree(ql,qh,mid+1,high,2*pos+2);

    segTree[0][pos] = segTree[0][2*pos+1] + segTree[0][2*pos+2];
    segTree[1][pos] = segTree[1][2*pos+1] + segTree[1][2*pos+2];
    segTree[2][pos] = segTree[2][2*pos+1] + segTree[2][2*pos+2];

    return;

}


int main(int argc, char const *argv[])
{
	int size,csize,x,tsize;

// 	std::fstream myfile("./input.txt", std::ios_base::in);

    vector<int> segTree0,segTree1,segTree2;
    segTree.push_back(segTree0);
    segTree.push_back(segTree1);
    segTree.push_back(segTree2);


	cin>> size >> csize;

	// int arr[size];

	// for(int i=0;i<size;i++){
	// 	// myfile>>x;
	// 	// cout<<x<<" ";
	// 	arr.push_back(0);
	// }

	tsize = 1 << (int)(ceil(log2(size))); 

	tsize = tsize*2 -1;

// 	cout<<"tsize "<<tsize<<endl;

	segTree[0].resize(tsize,0);
	segTree[1].resize(tsize,0);
	segTree[2].resize(tsize,0);
	lazyTree.resize(tsize,0);

	createSegmentTree(0,(size-1),0);

// 	cout<<"segTree"<<endl;

	// printTree(segTree[0]);
	// printTree(segTree[1]);
	// printTree(segTree[2]);

    // cout<<"findin test"<<"\n";

    // cout<<findSegTree(0, 3, 0, size-1, 0)<<endl;
    // cout<<findSegTree(0, 2, 0, size-1, 0)<<endl;
    // cout<<findSegTree(2, 4, 0, size-1, 0)<<endl;
    // cout<<findSegTree(1, 2, 0, size-1, 0)<<endl;

	int com,ql,qh;

	while(csize--){
	
		cin >> com >> ql >> qh;

		if(com == 0){
			// update
			updateSegmentTree(ql, qh, 0, size-1, 0);

			// cout<<"segTrees"<<endl;
            // printTree(segTree[0]);
            // printTree(segTree[1]);
            // printTree(segTree[2]);

			// cout<<"\n lazyTree"<<endl;			
			// printTree(lazyTree);

		}else{		
			cout<<findSegTree(ql, qh, 0, size-1, 0)<<endl;
		}

        // cout<<"\n\n\n";

	}
	

	return 0;
}