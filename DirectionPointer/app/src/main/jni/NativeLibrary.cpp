//
// Created by shifuddin on 5/7/2016.
//
#include <masud_shifuddin_directionpointer_NativeLibrary.h>
#include <log.h>
#include <Headers.h>
#include "Ident.h"
using namespace std;
/*
 * Class:     masud_shifuddin_directionpointer_NativeLibrary
 * Method:    fetch_ident
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_masud_shifuddin_directionpointer_NativeLibrary_fetch_1ident
  (JNIEnv *, jobject){

    vector <string> v;

    v = fetch_current_ident();
    write_ident_file(v);

    LOG_I("FETCH DONE");
  }

/*
 * Class:     masud_shifuddin_directionpointer_NativeLibrary
 * Method:    match_ident
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_masud_shifuddin_directionpointer_NativeLibrary_match_1ident
  (JNIEnv *, jobject){

            vector<string> v1;
            vector <string> v2;

            v1 = fetch_previous_ident();
            v2 = fetch_current_ident();

            if(is_ident_match(v1, v2))
            {
                LOG_I("MATCH");
                return 0;
            }
            else
            {
                LOG_I("DON'T MATCH");
                return -1;
            }

            LOG_I("MATCHING DONE");
  }

/*
 * Class:     masud_shifuddin_directionpointer_NativeLibrary
 * Method:    false_ident
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_masud_shifuddin_directionpointer_NativeLibrary_false_1ident
  (JNIEnv *, jobject){
            //LOG_I("CHECK FALSE");
            write_false_ident();
  }
