#include <vector>

using namespace std;

class Priority{

    public:
    Priority();
    Priority(bool p);
    int top();
    int size();

    void push(int data);
    void pop();

    bool empty();


    private:
    bool pr;
    vector<int> list;
    bool biggestSon(int curr);
    bool smallestSon(int curr);

};

Priority::Priority(){
    list.push_back(100);
    pr = true;
}

Priority::Priority(bool p){
    list.push_back(100);
    pr = p;
}

int Priority::top(){
    return list[1];
}

int Priority::size(){
    return list.size()-1;
}

bool Priority::empty(){
    return list.size()==1;
}

void Priority::push(int data){
    list.push_back(data);

    int curr = list.size()-1;
    int aux;

    if(pr){
        while(curr > 1 && list[curr/2]<list[curr]){
            aux = list[curr/2];
            list[curr/2] = list[curr];
            list[curr] = aux;
            curr = curr/2;
        }
    } else{
        while(curr > 1 && list[curr/2]>list[curr]){
            aux = list[curr/2];
            list[curr/2] = list[curr];
            list[curr] = aux;
            curr = curr/2;
        }
    }
}

bool Priority::biggestSon(int curr){
    if(curr*2+1 > list.size()-1){
        return true;
    }
    else{
        return(list[curr*2] > list[curr*2+1]) ? true : false;
    }
}

bool Priority::smallestSon(int curr){
    if(curr*2+1 > list.size()-1){
        return true;
    }
    else{
        return(list[curr*2] < list[curr*2+1]) ? true : false;
    }
}

void Priority::pop(){

    if(list.size()>1){
        list[1] = list.back();
        list.pop_back();

        int curr = 1;
        int son = curr*2;
        int aux;
        int bigger;
        bool exist = true;

        if(pr){
            while(son <= list.size()-1&&exist){
                bigger = biggestSon(curr) ? curr*2 : curr*2+1;
                if(list[curr] < list[bigger]){
                    aux = list[curr];
                    list[curr] = list[bigger];
                    list[bigger] = aux;
                    curr = bigger;
                    son = curr*2;
                } else{
                    exist = false;
                }
            }
        } else{
            while(son <= list.size()-1&&exist){
                bigger = smallestSon(curr) ? curr*2 : curr*2+1;
                if(list[curr] > list[bigger]){
                    aux = list[curr];
                    list[curr] = list[bigger];
                    list[bigger] = aux;
                    curr = bigger;
                    son = curr*2;
                } else{
                    exist = false;
                }
            }
        }
    }

}