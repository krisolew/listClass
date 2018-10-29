#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

Lista::Lista(node *f)
{
    first=f;
}

Lista::~Lista()
{
    node *tmp;

    while (first!=NULL)
    {
        tmp=first;
        first=first->next;
        delete tmp;
    }
}

int Lista::size()
{
    int licznik=0;
    node *kopia=first;
    while (kopia!=NULL)
    {
        licznik++;
        kopia=kopia->next;
    }

    return licznik;
}

bool Lista::empty()
{
    if (first==NULL) return true;
    else return false;
}

void Lista::print()
{
    if (first==NULL) return;

    node *kopia=first;
    while (kopia!=NULL)
    {
        cout<<kopia->val<<" ";
        kopia=kopia->next;
    }
    cout<<endl;
}

void Lista::push(int w)
{
    node *n=new node;
    n->val=w;

    if(first==NULL)
    {
        first=n;
        n->next=NULL;
        return;
    }

    node *kopia=first;
    while( kopia->next!=NULL )
        kopia=kopia->next;

    n->next=kopia->next;
    kopia->next=n;

}

void Lista::insert(int p, int w)
{
    node *n=new node;
    n->val=w;

    if (first==NULL || p==1)
    {
        n->next=first;
        first=n;
        return;
    }

    node *kopia=first;
    int i;
    for(i=2;i<p && kopia->next!=NULL;i++) kopia=kopia->next;

    n->next=kopia->next;
    kopia->next=n;
}

void Lista::pop()
{
    if ( first==NULL ) return;
    if ( first->next==NULL)
    {
        first=NULL;
        return;
    }

    node *kopia=first;
    while( kopia->next->next!=NULL )
        kopia=kopia->next;

    node *tmp=kopia->next;
    kopia->next=NULL;
    delete tmp;
}

int Lista::last()
{
    if ( first==NULL ) exit(0);

    node *kopia=first;
    while( kopia->next!=NULL )
        kopia=kopia->next;

    return kopia->val;
}

void Lista::wstaw ( node *&p, node *tmp)
{
    node *p1=p;
    node *p2=NULL;
    while (p1!=NULL && p1->val<tmp->val )
    {
        p2=p1;
        p1=p1->next;
    }
    if (p2==NULL)
    {
        tmp->next=p;
        p=tmp;
    }
    else
    {
        tmp->next=p1;
        p2->next=tmp;
    }

}

void Lista::sort()
{
    if ( first==NULL ) return;

    node *p=first;
    node *tmp;
    first=first->next;
    p->next=NULL;

    while (first!=NULL)
    {
        tmp=first;
        first=first->next;
        tmp->next=NULL;

        wstaw(p,tmp);
    }
    first=p;
}

void Lista::rewers()
{
    if (first==NULL) return;

    node *p=NULL;
    node *n=first->next;

    while (n!=NULL)
    {
        first->next=p;
        p=first;
        first=n;
        n=n->next;
    }
    first->next=p;
}
