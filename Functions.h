#pragma once
#include <algorithm>
#include <vector>
#include <string>



void sort_words(std::vector<std::string>& vec, bool (*predicate)(const std::string&));

std::pair<std::pair<int, std::string>, std::pair<int, std::string>> find_min_max(const std::vector<std::string>& vec);