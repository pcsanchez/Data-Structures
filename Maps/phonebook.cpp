#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string,string> phoneBook;

void add(string number,string name){
    if(phoneBook.find(number)==phoneBook.end()){
        phoneBook.insert(pair<string,string>(number,name));
    } else{
        phoneBook.find(number)->second = name;
    }
}

void del(string number){
    phoneBook.erase(number);
}

void find(string number){
    if(phoneBook.find(number)!=phoneBook.end()){
        cout << phoneBook.find(number)->second;
    } else{
        cout << "not found";
    }
    cout << endl;
}

int main(){
    int n;
    string query,sub,number,name;

    cin >> n;
    cin.ignore();

    for(int i = 0;i < n;i++){
        getline(cin,query);
        stringstream ss;
        ss << query;
        ss >> sub;
        if(sub=="add"){
            ss >> number;
            ss >> name;
            add(number,name);
        } else if(sub == "del"){
            ss >> number;
            del(number);
        } else if(sub == "find"){
            ss >> number;
            find(number);
        }
    }
}