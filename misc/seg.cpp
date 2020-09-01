#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

//segment tree implementation

// imput.txt
// 4 7
// 1 0 3
// 0 1 2
// 1 0 1
// 1 0 0
// 0 0 3
// 1 0 3
// 1 3 3

vector<int> segTree;
vector<int> lazyTree;
vector<int> arr;

void printTree(vector<int> tree){

	cout<<"**********************************-------------------------------------------****************************************"<<endl;

	for (std::vector<int>::iterator i = tree.begin(); i != tree.end(); i++)
	{
		cout<< *i <<" "; 
	}

	cout<<endl;
	cout<<"**********************************-------------------------------------------****************************************"<<endl;

}

void createSegmentTree(int low,int high,int pos){

	if(low>high) return;

	if(low == high){
		segTree.at(pos) = arr.at(low); 
		return;
	}

	int mid = (low + high) / 2;
	// cout<<"mid "<<mid<<endl;

	createSegmentTree(low,mid,2*pos+1);		//left
	createSegmentTree(mid+1,high,2*pos+2);	//right

	segTree.at(pos) = segTree.at(2*pos+1) + segTree.at(2*pos+2);
}

void updateSegmentTree(int ql , int qh, int low, int high, int pos, int delta ){

	// cout<<"update "<< ql << qh << low << high << pos <<endl;

	if( low > high ) return; 


	if( lazyTree.at(pos) != 0 ) {
		
		// propogation remaining

		// segTree.at(pos) += ( high - low + 1) * lazyTree.at(pos);

		segTree.at(pos) = ( high - low + 1) - segTree.at(pos);


		if( low != high){
			lazyTree.at(2*pos+1) += lazyTree.at(pos);
			lazyTree.at(2*pos+2) += lazyTree.at(pos);
			lazyTree.at(2*pos+1) %= 2;
			lazyTree.at(2*pos+2) %= 2;
		}

		lazyTree.at(pos) = 0; 
	}

	//no overlap
	if(ql>high || qh<low) return;

	//total overlap
	if( ql<=low && high<=qh ) {
		
		// segTree.at(pos) += ( high - low + 1) * delta;
		segTree.at(pos) = ( high - low + 1) - segTree.at(pos);

		if( low != high){
			lazyTree.at(2*pos+1) += delta;
			lazyTree.at(2*pos+2) += delta;
			lazyTree.at(2*pos+1) %= 2;
			lazyTree.at(2*pos+2) %= 2;
		}

		return; 
	}

	//partial overlap
	int mid = (low + high) / 2;
	// cout<<"mid "<<mid<<endl;

	updateSegmentTree(ql, qh, low, mid, 2*pos+1, delta );		//left
	updateSegmentTree(ql, qh, mid+1, high, 2*pos+2, delta);		//right

	segTree.at(pos) = segTree.at(2*pos+1) + segTree.at(2*pos+2);

}


int findSegTree(int ql , int qh, int low, int high, int pos ){

	// cout<<"find "<< ql << qh << low << high << pos <<endl;

	//no overlap
	if(ql>high || qh<low) return 0;


	if( lazyTree.at(pos) != 0 ) {
		
		// propogation remaining

		// segTree.at(pos) += ( high - low + 1) * lazyTree.at(pos);

		segTree.at(pos) = ( high - low + 1) - segTree.at(pos);
		

		if( low != high){
			lazyTree.at(2*pos+1) += lazyTree.at(pos);
			lazyTree.at(2*pos+2) += lazyTree.at(pos);
			lazyTree.at(2*pos+1) %= 2;
			lazyTree.at(2*pos+2) %= 2;
		}

		lazyTree.at(pos) = 0; 
	}

	//total overlap
	if( ql<=low && high<=qh ) return segTree.at(pos);

	if( low == high ) return segTree.at(pos);

	//partial overlap
	int mid = (low + high) / 2;
	// cout<<"mid "<<mid<<endl;

	int l = findSegTree(ql, qh, low, mid, 2*pos+1);		//left
	int r = findSegTree(ql, qh, mid+1, high, 2*pos+2);	//right

	return l+r;
}


int main(int argc, char const *argv[])
{
	int size,csize,x,tsize;

	std::fstream myfile("./input.txt", std::ios_base::in);

	myfile>> size >> csize;

	// int arr[size];

	for(int i=0;i<size;i++){
		// myfile>>x;
		// cout<<x<<" ";
		arr.push_back(0);
	}

	tsize = 1 << (int)(ceil(log2(size))); 

	tsize = tsize*2 -1;

	cout<<"tsize "<<tsize<<endl;

	segTree.resize(tsize);
	lazyTree.resize(tsize);

	createSegmentTree(0,(size-1),0);

	cout<<"segTree"<<endl;

	printTree(segTree);

	int com,ql,qh;

	while(csize--){
	
		myfile >> com >> ql >> qh;

		if(com == 0){
			// update
			cout<<"updateing  "<<ql<<qh;
			updateSegmentTree(ql, qh, 0, size-1, 0, 1);

			// cout<<"segTree"<<endl;
			
			// printTree(segTree);
			// cout<<"\n lazyTree"<<endl;
			
			// printTree(lazyTree);

		}else{		
			cout<<findSegTree(ql, qh, 0, size-1, 0)<<endl;
		}

	}
	

	return 0;
}