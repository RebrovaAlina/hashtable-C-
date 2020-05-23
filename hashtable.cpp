#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string>
#include "hashtable.h"
#include <limits.h>
#include <unistd.h>
#include <iostream>
using namespace std;


template<class V>
unsigned int hash1<V>::hashtab_hash(char *key)
{
        int len = strlen(key), hashf = 0;
        if (len <= 1)
                hashf = key[0];
        else
                hashf = key[0] + key[len-1];
        return hashf % 101;
}
template<class V>
hash1<V>::hash1()
{
        int i;
        for (i = 0; i < HASHTAB_SIZE; i++)
        {
                hashtab[i] = NULL;
        }
};
template<class V>
void hash1<V>::hashtab_add(char *key, V value)
{
        hash1<V> *node;
        int index = hashtab_hash(key);
        node =(hash1*) malloc(sizeof(*node));
        if (node != NULL)
        {
                node->key = key;
                node->value = value;
                node->next = hashtab[index];
                cout<<node<<endl;
                hashtab[index] = node;
                return;
        };
        cerr<<"Can't add the element"<<endl;
        throw STERR_NOADD;
};


template<class V>
hash1<V>* hash1<V>:: lookup( char *key)
{
        int index;
        hash1<V> *node;
        index = hashtab_hash(key);
        for (node = hashtab[index]; node != NULL; node = node->next)
        {
                if (strcmp(node->key, key) == 0)
                {
                        cout<<node<<endl;
                        return node;
                }
        }
        cerr<<"No such element"<<endl;
        throw STERR_NOELEM;
        return NULL;
};

template<class V>
void hash1<V>::hash1_delete(char *key)
{
        int index;
        hash1<V> *p;
        hash1<V> *prev = NULL;
        index = hashtab_hash(key);
        for (p = hashtab[index]; p != NULL; p = p->next)
        {
                if (strcmp(p->key, key) == 0)
                {
                        if (prev == NULL)
                                hashtab[index] = p->next;
                        else prev->next = p->next;
                        free(p);
                        return;
                }
                prev = p;
        }
        cerr<<"Can't delete the element"<<endl;
        throw STERR_DELETED;
}



template<class V>
hash1<V>::~hash1()
{
        int index = 0;
        int i = 0;
        hash1<V> *p;
        hash1<V> *prev = NULL;
        for (index = 0; index < HASHTAB_SIZE; index++)
        {
                p = hashtab[index];
                if(p!=NULL)
                {
                        if (prev == NULL)
                                hashtab[index] = p->next;
                        else prev->next = p->next;
                        free(p);
                        i++;
                };
                prev = p;
        };
        if(i==0)
        {
                cerr<<"No table"<<endl;
                throw STERR_DELETEDALL;
        }
}
template<class V>
char* hash1<V>::resize_table(std::string key)
{
        key.resize(1);
        char* key1 = &key[0];
        cout<<"Using resize: ";
        cout<<key1<<endl;
        return key1;
}
