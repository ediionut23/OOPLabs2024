#include <iostream>
#include <string>
#include <map>

using namespace std;

bool Mare(char c){
    return c >= 'A' && c <= 'Z';
}

int main() {
    string s = "I bought an apple. Then I eat an apple. Apple is my favorite.";
    string myWord = "";
    map<string, int> myMap;
    for(auto i : s){
        if(i == ' ' || i == ',' || i == '.'){
            if(myWord != "" || myWord != "\0")
                myMap[myWord]++;
            myWord="";
        }else{
            if(Mare(i))
                i += 32;
            myWord = myWord + i;
        }
    }
    myMap[myWord]++;

    cout << "Cuvinte si frecventa lor:\n";
    for (auto pair : myMap) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}