#include "Graph.h"

void Graph::AddNode(int x, int y, int z){
   lists[x].push_back(y);
   hold = z;
}

void Graph::BFS(){
    for(int i = 0; i < hold; i++) seen[i] = false;//set everything to false

    seen[1] = true;
    vert.push_back(1);
    track.push_back(1);
    //start search at 1

    while(!vert.empty()){
        curv = vert.front();

        vert.erase(vert.begin());

        for(int i = 0; i < lists[curv].size(); i++){
            onum = lists[curv].at(i);
            if(!seen[onum]){
                seen[onum] = true;
                vert.push_back(onum);
                track.push_back(onum);
            }//to see if something is seen
        }//loops through verts connections

    }//till graph is empty
}

bool Graph::connected(){
    if(track.size() == hold) return true;
    return false;
}

int Graph::components(){
   while(track.size() != hold){

        int i = 1;
        while(seen[i]) i++;
        vert.push_back(i);
        track.push_back(i);
        seen[i] = true;

        while(!vert.empty()){
            curv = vert.front();

            vert.erase(vert.begin());

            for(int i = 0; i < lists[curv].size(); i++){
                onum = lists[curv].at(i);
                if(!seen[onum]){
                    seen[onum] = true;
                    vert.push_back(onum);
                    track.push_back(onum);
                }//to see if something is seen
            }//loops through verts connections

        }//till graph is empty

        connect++;
    }
    return connect;
}
