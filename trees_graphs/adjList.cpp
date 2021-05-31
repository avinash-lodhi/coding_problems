#include <iostream>
#include <list>

using namespace std;

class Graph{
private:    
    int V;
    bool *visited;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        visited = new bool [V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
    }
    void addEdge(int x, int y){
        l[y].push_back(x);
    }
    void visit(int x){
        visited[x]=true;
        cout << x << " ";
    }
    bool isVistedAdjLst(int x){
        for(int i: l[x]){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    bool isVisited(int x){
        return visited[x];
    }
    bool isVisitedALL(){
        for (int i =0; i<V;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    void get_depencdency(){
        while(!isVisitedALL()){
            bool val = true;
            for(int i=0;i<this->V;i++){
                if(!isVisited(i)){
                    if(l[i].empty()||isVistedAdjLst(i)){
                        visit(i);
                        val = false;
                    }
                }
            }
            if(val){cout<<"No valid build order";return;}
        }
    }
};

int main(){
    Graph *g = new Graph(6);
    g->addEdge(0,3);
    g->addEdge(5,1);
    g->addEdge(1,3);
    g->addEdge(5,0);
    g->addEdge(3,2);
    g->get_depencdency();
}