#include "klee_to_afl.h"

int main(int argc, char* argv[]) {
	get_path(argv[1],argv[2]);
	klee_to_afl(); 
}
