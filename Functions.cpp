#include "Functions.h"

void sort_words(std::vector<std::string>& vec, bool(*predicate)(const std::string&))
{
	std::sort(vec.begin(), vec.end(), [&](const std::string& a, const std::string& b) {return predicate(a) > predicate(b); });
}

std::pair<std::pair<int, std::string>, std::pair<int, std::string>> find_min_max(const std::vector<std::string>& vec)
{

	auto min_it = std::min_element(vec.begin(), vec.end());
	auto max_it = std::max_element(vec.begin(), vec.end());

	int min_index = std::distance(vec.begin(), min_it);
	int max_index = std::distance(vec.begin(), max_it);

	return std::pair<std::pair<int, std::string>, std::pair<int, std::string>>(
		std::pair<int, std::string>(min_index, *min_it), std::pair<int, std::string>(max_index, *max_it));

}
