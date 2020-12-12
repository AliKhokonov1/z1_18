#include"Tokenaizer.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int Autotest();
int main (){
    Autotest();
    char *str = new char[512];
    ifstream fin("zhozhozho.txt");
    if (fin.fail()) {
        cout<<"File did not open!";
        return 1;
    }
    fin >> str;
    std::vector<char> razd = {'.',',','/'};
    Tokenaizer tk(str);
    tk.initTokenaizer(razd);
    for(Tokenaizer::iterator i = tk.begin(); i != tk.end(); ++i){
        cout<<*i;
        cout << '\n';
    }
    cout<<'\n';
    cout<<tk.get_token(2);
    cout<<'\n';
    cout<<"Amount of tokens: "<<tk.get_size();
    delete[] str;
    return 0;
}
