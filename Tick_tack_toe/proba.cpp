
#include <iostream>
#include <windows.h>
#include <fstream>
#include <limits>
#include <stdexcept>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    ifstream f("intro.txt");
    string s;

    while(!f.eof())
    {
            getline(f,s);
        cout<<s<<endl;
    }
    f.close();

}
