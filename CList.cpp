#include <fstream>
#include <iostream>
#include"CList.h"
using namespace std;
CList::CList(){cur = &t;t.next = NULL;}//???????????
CList::~CList(){Clean();}
int CList::IsEmpty(){return t.next==NULL;}//????????? ?? ????????? ???????? ???? ??, ?? ????
void CList::Clean(){GoToBegin();while(!IsEmpty()){DelNext();}}
void CList:: GoToBegin(){cur=&t;}
int CList::GetCur(Token &x){if(cur==&t)return -2; x=cur->v; return 0;}
int CList::GoToNext(){if(cur->next==NULL) return -1; cur=cur->next;return 0;}
void CList::AddAfter(const Token &x) 
{   
    LNode *p = new LNode;
    p->v=x;
    p->next=this->cur->next;//????????? ????? ?? ???????
    cur->next=p;
}
int CList::DelNext()
{ 
    if(cur -> next==NULL){return -1;};
    LNode *save = cur->next;
    cur->next=cur->next->next;
    delete save;
    return 0;
}

