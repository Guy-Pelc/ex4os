#include "VirtualMemory.h"
#include "MemoryConstants.h"
#include <cassert>
#include <cstdio>

#include <iostream>
using namespace std;

void test(){
	printf("RAM_SIZE = %llu\n",RAM_SIZE );
	for (int i=0;i<VIRTUAL_MEMORY_SIZE;++i){
		VMwrite(i,100+i);
//		cout<<"VMwrite "<<i<<endl;
	}
	for (int i=0;i<VIRTUAL_MEMORY_SIZE;++i){
		word_t val;
		VMread(i,&val);
		assert(val==100+i);
	}
	printf("success\n");
}

int main(){
//	cout<<"here"<<endl;
	VMinitialize();
//	cout<<"there"<<endl;
	test();
}