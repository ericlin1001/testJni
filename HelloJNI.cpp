#include <stdio.h>
#include <iostream>
using namespace std;
#include "HelloJNI.h"

#define Trace(m) cout<<#m"="<<(m)<<endl;
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj){
	printf("hello world\n");
	return ;
}



JNIEXPORT jint JNICALL Java_HelloJNI_add
  (JNIEnv *env, jobject, jint a,  jint b){
	Trace(sizeof(a));
	Trace(jint(a));
	int k = a +b;
	a = -1;
	printf("add(%d,%d)=%d from cpp\n", a, b, a+b);
	  //return a+b;
	  return -2;

}
