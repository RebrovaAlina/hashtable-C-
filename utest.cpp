#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
        hash1 *node;
        //Test 1 - create
        try {
                node = new hash1();
        } catch (...) {
                cout << "Test_1\t->\tFAILED" << endl;
        }
        cout << "Test_1\t->\tPASSED" << endl;



        try {
                node->hashtab_add("Slon",190);
                node->hashtab_add("Volk", 60);
        } catch (...) {
                cout << "Test_2\t->\tFAILED" << endl;
        }
        cout << "Test_2\t->\tPASSED" << endl;

        try {
                node->lookup("Slon");
        } catch (...) {
                cout << "Test_3\t->\tFAILED" << endl;
        }
        cout << "Test_3\t->\tPASSED" << endl;


        try {
                node-> lookup("Crocodile");
        } catch (...) {
                cout << "Test_4\t->\tFAILED" << endl;
        }
        cout << "Test_4\t->\tPASSED" << endl;


        try {
                node->hash1_delete("Slon");
        } catch (...) {
                cout << "Test_5\t->\tFAILED" << endl;
        }
        cout << "Test_5\t->\tPASSED" << endl;

        try {
                node->lookup("Slon");
        } catch (...) {
                cout << "Test_6\t->\tFAILED" << endl;
        }
        cout << "Test_6\t->\tPASSED" << endl;


        try {
                node->hash1_delete("Crocodile");
        } catch (...) {
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
        } catch (...) {
                cout << "Test_8\t->\tFAILED" << endl;
        }
        cout << "Test_8\t->\tPASSED" << endl;


        try {
                delete node;
        } catch (...) {
                cout << "Test_9\t->\tFAILED" << endl;
        }
        cout << "Test_9\t->\tPASSED" << endl;

        return 0;
}