#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s = "I bought an apple. Then I eat an apple. Apple is my favorite.";
    string myWord = "";
    map<string, int> myMap;
    for(auto i : s){
        if(i == ' ' || i == ',' || i == '.'){
            myMap[myWord]++;
            myWord="";
        }else{
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
