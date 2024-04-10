#include "Number.h"


void Number::SwitchBase(int newBase) {
    int n = to10(), cnt = 0;
    xto10(n,newBase);
    delete[] s;
    s = xto10(n,newBase);
    this->base = newBase;
}

Number::Number(const char *value, int base) {
    int cnt = 0;
    for(int i = 0; value[i]; i++)
        cnt++;
    this->s = new char[cnt+1];
    for(int i = 0; i < cnt; i++)
        this->s[i] = value[i];
    this->s[cnt] = '\0';
    this->base = base;
}


int Number::GetBase() {
    return this->base;
}

int Number::GetDigitsCount() {
    char * c = this->s;
    int cnt = 0;
    for(int i = 0; c[i]; i++)
        cnt++;
    return cnt;
}

void Number::Print() {
    printf("Numarul are valoarea: %s si baza: %d si valoarea in baza 10 este: %d\n", Gets(),GetBase(),to10());
}

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return -1;
}
int Number::to10() {
    char * c = this->s;
    int baza = this->base;
    int length = GetDigitsCount();
    int decimal = 0;
    int p = 0;
    for(int i = length-1; i >= 0; i--){
        int cif = charToInt(c[i]);

        if(cif == -1  || cif >= baza)
            return -1;
        decimal += cif * pow(baza, p);
        p++;
    }
    return decimal;
}

char *Number::xto10(int n, int base) {
    int digits = 1;
    int temp = n;
    while (temp /= base) {
        digits++;
    }

    char *buffer = new char[digits + 1];
    buffer[digits] = '\0';

    for (int i = digits - 1; i >= 0; i--) {
        int digit = n % base;
        n /= base;
        buffer[i] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
    }
    return buffer;
}

char Number::operator[](int index) {
    char * c = this->s;
    return c[index];
}

Number operator+(Number nr1, Number nr2) {
    int base1, base2, valoarea1, valoarea2;
    base1 = nr1.GetBase();
    base2 = nr2.GetBase();
    valoarea1 = nr1.to10();
    valoarea2 = nr2.to10();
    int valoare = valoarea1 + valoarea2;
    if(base1 == base2){
        Number cartof(nr1.xto10(valoare,base1),base1);
        return cartof;
    }else{
        if(base1 > base2)
        {
            Number cartof(nr1.xto10(valoare, base1), base1);
            nr2.SwitchBase(base1);
            //cout << cartof.GetBase() <<" **(*(*(*" << cartof.Gets() << cartof.to10();
            return cartof;
        }else{
            Number cartof(nr1.xto10(valoare, base2), base2);
            nr1.SwitchBase(base2);
            return cartof;
        }

    }
}
 Number operator-(Number nr1,Number nr2) {
    int base1, base2, valoarea1, valoarea2;
    base1 = nr1.GetBase();
    base2 = nr2.GetBase();
    valoarea1 = nr1.to10();
    valoarea2 = nr2.to10();
    int valoare = valoarea1 - valoarea2;
    if(base1 == base2){
        Number cartof(nr1.xto10(valoare,base1),base1);
        return cartof;
    }else{
        if(base1 > base2)
        {
            Number cartof(nr1.xto10(valoare, base1), base1);
            nr2.SwitchBase(base1);
            return cartof;
        }else{
            Number cartof(nr1.xto10(valoare, base2), base2);
            nr1.SwitchBase(base2);
            return cartof;
        }

    }
}

char *Number::Gets() {
    return this->s;
}

Number::Number(){
    base = 0;
    s = nullptr;
}
//copy constructor
Number::Number(const Number &d) {
    base = d.base;
    s = d.s;
}
//move constructor
Number::Number(const Number &&d) {
    base = d.base;
    s = d.s;
    delete[] d.s;
}

Number &Number::operator=(Number nr) {
    base = nr.GetBase();
    s = nr.Gets();
    return *this;
}

bool Number::operator>(Number nr) {
    int val1 = to10();
    int val2 = nr.to10();
    return val1 > val2;
}

bool Number::operator<(Number nr) {
    int val1 = to10();
    int val2 = nr.to10();
    return val1 < val2;
}

Number &Number::operator=(int nr) {
    if(base == 0){
        base = 10;
        int cnt = 0;
        int aux = nr;
        int aux2 = nr;
        while(aux2) {
            cnt++;
            aux2 /= 10;
        }
        this->s = new char[cnt+1];
        s[cnt] = '\0';
        for(int i = cnt-1; i >= 0; i--){
            s[i] = '0'+ (aux%10);
            aux /= 10;
        }
    }else{
        char * c = xto10(nr, base);
        delete[] s;
        s = c;
    }

    return *this;
}

Number &Number::operator+=(Number nr) {
    int val1 = to10();
    int val2 = nr.to10();
    int val = val1 + val2;
    delete[] s;
    s = xto10(val,base);
    return *this;
}

Number &Number::operator=(char *  c) {
    int baza = base;
    int cnt = 0;
    for(int i = 0; c[i]; i++)
        cnt++;
    int decimal = 0;
    int p = 0;
    for(int i = cnt-1; i >= 0; i--){
        int cif = charToInt(c[i]);
        decimal += cif* pow(baza, p);
        p++;
    }
    int val1 = decimal;
    delete[] s;
    s = xto10(val1 ,base);
    return *this;
}

void Number::operator--() {
    int nr = GetDigitsCount();
    for(int i = 0; i < nr; i++)
        s[i] = s[i+1];
    s[nr-1] = '\0';
}

void Number::operator--(int numar) {
    int nr = GetDigitsCount();
    s[nr-1] = '\0';
}


Number::~Number() = default;










