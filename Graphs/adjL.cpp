#include <vector>
#include <stack>

using namespace std;

void leeListAdj(vector<vector<int>> &listAdj,int e){
    int a, b;
    for(int i = 0;i < e;i++){
        cin >> a >> b;
        listAdj[a-1].push_back(b-1);
        listAdj[b-1].push_back(a-1);
    }
}

void printListAdj(vector<vecotr<int>> &listAdj){
    for(int i =0;i < listAdj.size();i++){
        cout << 1+1 << " ";
        for(int j = 0;j < listAdj[i].size();j++){
            cout << " - " << listAdj[i][j] + 1;
        }
        cout << endl;
    }
}

void DFS(vector<vector<int>> &listAdj,int v){
    stack <int> pila;
    pila.push(0);
    int data;
    vector<bool> status(v,false);
    while(!pila.empty()){
        data = pila.top();
        pila.pop();
        if(!status[data]){
            cout << data + 1 << " ";
            status[data] = true;
            for(int i = listAdj[data].size()-1;i >= 0;i--){
                if(!status[listAdj[data][i]]){
                    pila.push(listAdj[data][i]);
                }
            }
        }
    }
}

imt main(){

    int v, e;

    cin >> v >> e;

    vector<vector<int>> listAdj[v];
    leeListAdj(listAdj,e);
    printListAdj(listAdj);
    DFS(listAdj,v);

    return 0;
}