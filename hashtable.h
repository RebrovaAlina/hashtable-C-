#include <stdint.h>
#include <string>
#include <stdlib.h>
#include<iostream>
#define HASHTAB_SIZE 128 

using namespace std;

template<class V>
class hash1
{
        private:
                char *key;
                V value;
                hash1<V> *next;

        public:

                hash1<V> *hashtab[HASHTAB_SIZE];
                enum hash_error
                {
                        STERR_SUCCESS,
                        STERR_FULL,
                        STERR_DELETED,
                        STERR_NOELEM,
                        STERR_DELETEDALL ,
                        STERR_NOADD
                };

                hash1();
                void hashtab_add(char *key, V value);
                void hash1_delete (char *key);
                hash1<V> *lookup(char *key);
                unsigned int hashtab_hash(char *key);
                ~hash1();
                char* resize_table(std::string key);


                friend ostream &operator<<(ostream &output, const hash1<V>* node) {
                        output<<"Node:"<<node->key<<","<< node->value<<endl;
                        return output;
                };
};
