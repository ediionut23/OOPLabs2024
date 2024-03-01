#include <iostream>
using namespace std;

int conv(char * s){
    int r = 0;
    int i = 0;
    while(s[i] >= '0' && s[i] <= '9'){
        r = r * 10 + (s[i++] -'0');
    }
    return r;
}

int main(){
    FILE * file;
    char line[100];
    file = fopen("in.txt", "r");
    if(file == NULL)
        printf("fisierul nu s-a deschis cum trebuie\n");
    int sum = 0;
    while(fgets(line, sizeof(line), file) != NULL){
        int num = conv(line);
        sum += num;
    }
    printf("%d", sum);
}