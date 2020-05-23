#include "hashtable.cpp"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
        hash1<double> *node;
        //Test 1 - create
        try {
                node = new hash1<double>();
        } catch (...) {
                cout << "Test_1\t->\tFAILED" << endl;
        }
        cout << "Test_1\t->\tPASSED" << endl;


        try {
                node->hashtab_add("Slon",190);
                node->hashtab_add("Volk", 60);
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_NOADD)
                        cout << "Test_2\t->\tFAILED" << endl;
        }
        cout << "Test_2\t->\tPASSED" << endl;


        try {
                node->lookup("Slon");
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_NOELEM)
                        cout << "Test_3\t->\tFAILED" << endl;
        }
        cout << "Test_3\t->\tPASSED" << endl;


        try {
                node-> lookup("Crocodile");
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_NOELEM)
                        cout << "Test_4\t->\tFAILED" << endl;
        }
        cout << "Test_4\t->\tPASSED" << endl;


        try {
                node->hash1_delete("Slon");
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_DELETED)
                        cout << "Test_5\t->\tFAILED" << endl;
        }
        cout << "Test_5\t->\tPASSED" << endl;

        try {
                node->lookup("Slon");
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_NOELEM)
                        cout << "Test_6\t->\tFAILED" << endl;
        }
        cout << "Test_6\t->\tPASSED" << endl;


        try {
                node->hash1_delete("Crocodile");
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_DELETED)
                        cout << "Test_7\t->\tFAILED" << endl;
        }
        cout << "Test_7\t->\tPASSED" << endl;


        try {
                char* l;
                l = node->resize_table("Volk");
                cout<< l<<endl;
                node->lookup(l);
                node->hashtab_add(l, 5);
                node -> lookup(l);
                node->hash1_delete(l);
                node->lookup(l);
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_NOELEM)
                        cout << "Test_8\t->\tFAILED" << endl;
        }
        cout << "Test_8\t->\tPASSED" << endl;


        try {
                delete node;
        } catch (const hash1<double>::hash_error &ex) {
                if (ex != hash1<double>::STERR_DELETEDALL)
                        cout << "Test_9\t->\tFAILED" << endl;
        }
        cout << "Test_9\t->\tPASSED" << endl;

        return 0;
}
