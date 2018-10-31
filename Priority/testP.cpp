#include <iostream>

using namespace std;

#include "Priority.h"

int main(){
    Priority myQ(false);

    myQ.push(50);
    myQ.push(100);
    myQ.push(60);
    myQ.push(10);

    cout << myQ.top() << endl;

    myQ.pop();

    cout << myQ.top() << endl;
}