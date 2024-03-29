#ifndef KLEE_TO_AFL_H
#define KLEE_TO_AFL_H

#include <iostream>
#include <unordered_set>
#include <experimental/filesystem>
#include <sstream>
#include <fstream>
#include "KTest.h"

extern std::string myinput;
extern std::string myoutput;

namespace fs = std::experimental::filesystem;
void allocations_parse(std::string messages_file);
void warnings_parse(std::string messages_file);
void ktest_parse(fs::path &path_obj, std::unordered_set<std::string> &cache);
void generate_afl_seed_dir(const std::string& path, std::unordered_set<std::string>& cache);
void klee_to_afl();
void get_path(const std::string& path1, const std::string& path2);
#endif 
