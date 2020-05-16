#include <stdint.h>
#include <string>
#include <stdlib.h>
#include<iostream>
#define HASHTAB_SIZE 128 

using namespace std;

class hash1
{
        public:
                enum hash_error{
                        STERR_SUCCESS,
                        STERR_FULL,
                        STERR_DELETED,
                        STERR_NOELEM,
                        STERR_DELETEDALL ,
                        STERR_NOADD
                };
                char *key;
                int value;
                hash1 *next;
                hash1 *hashtab[HASHTAB_SIZE];

                hash1();
                void hashtab_add(char *key, int value);
                void hash1_delete (char *key);
                hash1 *lookup(char *key);
                unsigned int hashtab_hash(char *key);
                ~hash1();
                char* resize_table(std::string key);

};
