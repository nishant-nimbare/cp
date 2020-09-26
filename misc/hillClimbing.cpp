#include <bits/stdc++.h>
using namespace std;

/**
 * N blocks 0 ... n-1
 * 
 * raw state of block is the block below it i.e for block i, S[i] is the block below it or -1 (place on ground) 
 * 
 * we take input in above format and then convert it to double LL
 * 
 * **/


// double LinkedList
struct block{
    int id ;
    // int blocksBelow = 0;
    // bool isTopMost = true;
    struct block *above=NULL, *below=NULL;

    block(int i):id(i) {}
};

vector<block *> Goal;
int goalHval;

void printState(vector<block *> &state){

    cout<<" -------- "<<endl;
    for (int i = 0; i<state.size(); i++){
        if(state[i]->above == NULL){
            // cur block is topmost

            block * t = state[i];
            while(t){
                cout<<t->id<<" -> "; 
                t = t->below;
            }
            cout<<endl;
        }
    }

}


int heuristic1(vector<block *> &state){

    // +1 if block is on correct block else -1
    int res =0;

    for(int i=0; i < state.size(); i++){

        block *s = state[i], *g = Goal[i];

        if(s && g && (s->below == g->below)){
            res++;
        }else{
            res--;
        }
    
    }

    return res;
}

int heuristic2(vector<block *> &state){

    // + number of blocks below if  a block is on correct pile else -1 for each block below
    int res =0;

    for(int i=0; i < state.size(); i++){

        block *s = state[i], *g = Goal[i];
        int blocksBelow = -1;
        bool correct = true;

        while(s && g){
            blocksBelow++;

            if(s->below != g->below)
                correct = false;

            s = s->below;
            g = g->below;
        }


        if(correct) res += blocksBelow;
        else res -= blocksBelow;
    }

    return res;
}

int heuristic(vector<block *> &state){
    return heuristic1(state);
}




vector<block *> copyState(vector<block *> state){

    vector<block *> copy(state.size());
    for (int i = 0; i<state.size(); i++){
        copy[i] = new block(i);
    }


    for (int i = 0; i<state.size(); i++){
       
        if(state[i]->below != NULL ) 
        copy[i]->below = copy[ state[i]->below->id ];

        if(state[i]->above != NULL ) 
        copy[i]->above = copy[ state[i]->above->id ];
    }

    return copy;

}

vector<vector<block *>> genChildren(vector<block *> curState){
   
   vector<int> heads;
    
    for (int i = 0; i<curState.size(); i++){
        if(curState[i]->above == NULL){
            //  block is topmost
            heads.push_back(i);
        }
    }

    
    vector<vector<block *>> children;
    
    // put every top element on every other top element or on ground
    for(int i=0; i<heads.size(); i++){
        for(int j=0; j<heads.size(); j++){
            
            vector<block *> curchild = copyState(curState);

            curchild[i]->below->above = NULL;;

            if(i==j){
                curchild[ i ]-> below = NULL; //place on ground               
            }else{
                curchild[ i ]-> below = curchild[ j ];
                curchild[ j ] -> above = curchild[ i ];
            }

            children.push_back(curchild);

        }   
    }

    return children;

}

void hillClimbing(vector<block *> initialState){

    priority_queue <pair< int, vector<block *> > > q;

    q.push({ heuristic(initialState), initialState});


    while(!q.empty()){

        int hVal = q.top().first;
        vector<block *> curState = q.top().second;
        q.pop();

        printState(curState);
        cout<<" cur heuristic : "<<hVal<<endl;

        if(hVal == goalHval){
            cout<<" goal state found "<<endl;
            return;
        }

        vector<vector<block *>> children = genChildren(curState);
        
        for(vector<block *> child : children){
            int chVal = heuristic(child);

            if(chVal > hVal){
                q.push({chVal, child});
            }
        }

    }


    cout<<" goal not found "<<endl;
}


vector<block *> getStateFromRaw (vector<int> rawState){

    vector<block *> allBlocks(rawState.size());

    // vector<block *> state;

    for (int i = 0; i<rawState.size(); i++){
        allBlocks[i] = new block(i);
    }


    for (int i = 0; i<rawState.size(); i++){
        
        // rawState[i] block is below i
        if(rawState[i] == -1 ) continue;

        allBlocks[i]->below = allBlocks[ rawState[i] ] ;

        allBlocks[ rawState[i] ]->above = allBlocks[i] ;
        
        // allBlocks[ rawState[i] ]->isTopMost = false;
        
        // allBlocks[i]->blocksBelow = 1 + allBlocks[ rawState[i] ]->blocksBelow;
    }


    // for (int i = 0; i<allBlocks.size(); i++){
    //     if(allBlocks[i]->above == NULL){
    //         // cur block is topmost
    //         state.push_back(allBlocks[i]);
    //     }
    // }
    
    return allBlocks;
}   




int main(int argc, char const *argv[]){

    cout<<"enter number of blocks"<<endl;
	int n;
	cin>> n;

    vector<int> rawGoalState, rawStartState;
    
    cout<<"enter goal state of blocks"<<endl;

    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        rawGoalState.push_back(a);
    } 

    Goal = getStateFromRaw(rawGoalState);
    goalHval = heuristic(Goal);
    printState(Goal);
    cout<<" goal heuristic : "<<goalHval<<endl;


    cout<<"enter start state of blocks"<<endl;
	
    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        rawStartState.push_back(a);
    } 

    vector<block *> Start = getStateFromRaw(rawStartState);
    printState(Start);
    cout<<" start heuristic : "<<heuristic(Start)<<endl;

    cout<<endl<<" ------- starting hill climbing --------"<<endl;
    hillClimbing(Start);

	return 0;
}