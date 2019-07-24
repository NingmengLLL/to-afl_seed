#include "klee_to_afl.h"

void generate_afl_seed_dir(const std::string& path, std::unordered_set<std::string>& cache){
	auto dir_path = fs::path(path.c_str());  
	fs::create_directory(path);
	std::ostringstream filename;
	for(auto& test:cache){
		std::ofstream file;
		filename << path << "/" << rand() << ".txt";
		file.open(filename.str());
		file << test << std::endl; 
		filename.str(std::string());
	}
}

void allocations_parse(std::string messages_file){

}

void warnings_parse(std::string messages_file){

}

void ktest_parse(fs::path &path_obj,std::unordered_set<std::string> &cache) {
	auto ktest_file = path_obj.string();
	std::ostringstream debug;
	KTest* result = kTest_fromFile(ktest_file.c_str());
	auto objects = result -> objects;
	uint64_t object_amount = result -> numObjects;
	for (size_t i = 0; i < object_amount; ++i){
		auto object = objects[i];
		auto size = object.numBytes;
		auto data = object.bytes;
		for(size_t i=0; i < size; ++i){
		//debug << "\\x0" << (int)data[i];
		debug << (char)data[i];
		//debug << data[i];
		}
		//std::cout << ktest_file << "=" << "\"" << debug.str() << "\"" << std::endl;
		if (cache.find(debug.str()) == cache.end()){
		cache.insert(debug.str());
		}
		debug.str(std::string());
	}
}

void klee_to_afl(){
	std::unordered_set<std::string> cache;
	for (const auto &f : fs::directory_iterator(myinput)){
		auto path = f.path();
		auto ext = path.extension();
		auto filename = path.string();
		if (ext == ".ktest"){
			ktest_parse(path, cache);
		} else if (ext == ".txt"){
			if (path.stem() == "messages"){
				allocations_parse(filename);
			} else if (path.stem() == "warnings"){
				warnings_parse(filename);
			}
		} else if (ext == ".ll"){

		} else if (ext == ".stats"){
		
		} else if (ext == ".istats"){

		} else if (ext == ""){

		} else if (ext == ".kquery"){

		} else if (ext == ".err"){

		}
	}
	generate_afl_seed_dir(myoutput,cache);
}
