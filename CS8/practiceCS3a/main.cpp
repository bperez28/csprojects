#include <iostream>

using namespace std;

void passbyref(int *x);
void passbyvalue(int x);

int main(int argc, char *argv[])
{
    int x=5;
    passbyref(&x);
    cout<<x<<endl;
}
void passbyvalue(int x){
    x=10;
}
void passbyref(int *x){
    *x=10;
}
