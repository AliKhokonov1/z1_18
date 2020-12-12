#include"Tokenaizer.h"
#include <fstream>
#include <iostream>
using namespace std;
int Autotest (void) {
    char *str = new char[512];
    char *str1 = new char[512];
    ifstream fin("zhozhotest.txt");
    if (fin.fail()) {
        cout<<"File did not open!"<<endl;
        return 2;
    }
    ifstream vin("zhozhozhorestest.txt");
    if (vin.fail()) {
        cout<<"File did not open!"<<endl;
        return 3;
    }
    fin >> str;
    std::vector<char> razd = {'.',','};
    Tokenaizer tk(str);
    tk.initTokenaizer(razd);
    for(Tokenaizer::iterator i = tk.begin(); i != tk.end(); ++i){
        vin >> str1;
        if(strcmp(*i,str1)!=0){
            cout << "Autottets failed \n";
            delete[] str;
            delete[] str1;
            return 1;
        }
    }   
    
    if (tk.get_size() != 4) {
            cout << "Autottets failed \n";
            delete[] str;
            delete[] str1;
            return 1;
    }
    if (strcmp(tk.get_token(1),"zhozho")!=0) {
            cout << "Autottets failed \n";
            delete[] str;
            delete[] str1;
            return 1;
    }
    cout<< "Autotest passed! \n";
    cout<<'\n';
    delete[] str;
    delete[] str1;
    return 0;
}        
