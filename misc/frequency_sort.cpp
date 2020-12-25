#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

struct item{
    int val, idx, count;
    item(int v, int i): val(v), idx(i), count(1) {}
};

bool comp(const item &lhs, const item &rhs ){

    if( lhs.count == rhs.count ){
        return (lhs.idx < rhs.idx);
    }

    return ( lhs.count > rhs.count ); 
}

vector<int> sort_freq(vector<int> arr){

    vector<pair<int,int>> idx;

    for(auto i=0; i< arr.size(); i++ ){
        idx.push_back({arr[i], i});
    }

    sort( idx.begin(), idx.end() );

    vector<item> items;

    items.push_back( item( idx[0].first, idx[0].second ));

    for(int i =1; i<idx.size(); i++){

        pair<int,int> cur = idx[i];

        if( cur.first == items.back().val){
            items.back().count += 1;
        }else{
            items.push_back( item( cur.first, cur.second) );
        } 
    }


    sort( items.begin(), items.end(), &comp);

    vector<int> ans;

    for(auto ele : items){
        for(int t=0; t<ele.count; t++) ans.push_back(ele.val);
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = { 2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12 };
    
    vector<int> ans = sort_freq(arr);

    for(auto x:ans) cout<<x<<" ";

    cout<<endl;
    
    return 0;
}