#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string>
#include "hashtable.h"
#include <limits.h>
#include <unistd.h>
#include <iostream>
using namespace std;

unsigned int hash1::hashtab_hash(char *key)
{
        int len = strlen(key), hashf = 0;
        if (len <= 1)
                hashf = key[0];
        else
                hashf = key[0] + key[len-1];
        return hashf % HASHTAB_SIZE;
}

hash1::hash1()
{
        int i;
        for (i = 0; i < HASHTAB_SIZE; i++)
        {
                hashtab[i] = NULL;
        }
};
void hash1::hashtab_add(char *key, int value)
{
        hash1 *node;
        int index = hashtab_hash(key);
        node =(hash1*) malloc(sizeof(*node));
        if (node != NULL)
        {
                node->key = key;
                node->value = value;
                node->next = hashtab[index];
                hashtab[index] = node;
                return;
        };
        cerr<<"Can't add the element"<<endl;
        throw STERR_NOADD;
};

hash1* hash1::lookup( char *key)
{
        int index;
        hash1 *node;
        index = hashtab_hash(key);
        for (node = hashtab[index]; node != NULL; node = node->next)
        {
                if (strcmp(node->key, key) == 0)
                {
                        cout<<"Node:"<<node->key<<","<< node->value<<endl;
                        return node;
                }
        }
        cerr<<"No such element"<<endl;
        throw STERR_NOELEM;
        return NULL;
};
void hash1::hash1_delete(char *key)
{
        int index;
        hash1 *p;
        hash1 *prev = NULL;
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

hash1::~hash1()
{
        int index = 0;
        int i = 0;
        hash1 *p;
        hash1 *prev = NULL;
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
char* hash1::resize_table(std::string key)
{
        key.resize(1);
        char* key1 = &key[0];
        cout<<"Using resize: ";
        cout<<key1<<endl;
        return key1;
}
