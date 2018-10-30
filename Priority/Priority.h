#include <vector>

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
    vecotr<int> list;

};

Priority::Priority(){
    pr = true;
}

Priority::Priority(bool p){
    pr = p;
}

int Priority::top(){
    return list[0];
}

int Priority::size(){
    return list.size();
}

bool Priority::empty(){
    return list.size()==0;
}

void Priority::push(int data){
    list.push_back(data);

    int curr = list[list.size()-1];
    int aux;

    if(pr){
        while(curr > 1 && list[curr/2]<list[curr]){
            aux = list[curr/2];
            list[curr/2] = list[curr];
            list[curr] = aux;
        }
    } else{
        while(curr > 1 && list[curr/2]>list[curr]){
            aux = list[curr/2];
            list[curr/2] = list[curr];
            list[curr] = aux;
        }
    }
}

void Priority::pop(){
    h
}