#include <fstream>
#include <iostream>
#include"Tokenaizer.h"
Tokenaizer::Tokenaizer(char *str1){
    this->pos = 0;
    this->str = new char[strlen(str1)];
    this->str2 = new char[strlen(str1)];
    strcpy(this->str,str1);
}
void Tokenaizer::initTokenaizer(vector<char> razd1){
    this->razd = razd1;
    this->tok_list.Clean();
    raz_Token();
}
char* Tokenaizer::get_token(int pos1){
    for(Tokenaizer::iterator i = begin(); i != end(); ++i){//?? ????????? ?????? ?????????, ?? ???? ?? ???????
        if(i.cur->v.pos == pos1){
            return (*i);
        }
    }                                                
    return NULL;
}
void Tokenaizer::raz_Token()
{
    int begin=0;
    int end=0;
    char *str2=this->str;
    while (*str2 != '\0'){
        for (int i=0;i<this->razd.size();++i) {
            if (*str2==razd[i]){
                Token q;
                q.begin=begin;
                q.end=end-1;
                q.pos = pos;
                tok_list.AddAfter(q);
                tok_list.GoToNext();
                end=end+1;
                this->pos++;
                begin=end;
                str2+=1;
                break;
            } 
        }        
    end++;
    str2++;
    }
    if(begin != end){
        Token q;
        q.begin=begin;
        q.end=end-1;
        q.pos = pos;
        tok_list.AddAfter(q);
        tok_list.GoToNext();
    }
}
int Tokenaizer::get_size(){
    return pos+1;
}
Tokenaizer::~Tokenaizer(){
    delete[] str;
    delete[] str2;
}
Tokenaizer::iterator::iterator(){cur==NULL;tt=NULL;}
Tokenaizer::iterator::iterator(LNode *cur, Tokenaizer* tt){this->cur=cur;this->tt=tt;}
void Tokenaizer::iterator::operator++(){if (cur)cur = cur->next;}
int Tokenaizer::iterator::operator!=(const iterator& b) const{return cur!=b.cur;}
int Tokenaizer::iterator::operator==(const iterator& b) const{return cur==b.cur;}
char* Tokenaizer::iterator::operator*(){
    strcpy(tt->str2,tt->str+(cur->v.begin));//?????????? ? ?????? ?????? ?????? ??????? ?????? 
    tt->str2[cur->v.end-cur->v.begin+1]='\0';
    return tt->str2;
}//??????? ???????? ????????, ?? ??????? ????????? ????????, ?????????? ??????!
Tokenaizer::iterator Tokenaizer::begin(){return iterator(tok_list.t.next,this);}//?????? ???????  ? ??????
Tokenaizer::iterator Tokenaizer::end(){return iterator(NULL,this);}
