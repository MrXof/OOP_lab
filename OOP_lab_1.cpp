#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include "Functions.h"



std::vector<std::string> read_file_input(const std::string& filename);

bool is_upper_case(const std::string& str);





// var 0221

int main(int argc, char* argv[])
{

	std::vector<std::string> user_input;

	if (argc < 2)
	{

		std::cout << "No parameters were passed, please enter filename to read from: ";
		std::string filename;
		std::cin >> filename;

		try
		{
			user_input = read_file_input(filename);
		}
		catch (const std::exception& ex)
		{
			std::cout << "Error: " << ex.what() << '\n';
			return 1;
		}

	}
	else
	{
		for (size_t i = 1; i < argc; i++)
		{
			user_input.push_back(argv[i]);
		}
	}

	std::string result_filename = user_input[0];
	user_input.erase(user_input.begin());

	auto min_max_result = find_min_max(user_input);

	std::ofstream out(result_filename);
	if (!out)
	{
		std::cout << "Error: Couldn't open the file: " << result_filename << '\n';
		return 1;
	}

	sort_words(user_input, is_upper_case);

	out << "Sorted sequence: ";
	for (auto& i : user_input)
	{
		out << i << ' ';
	}
	out << '\n';

	out << "Min value index: " << min_max_result.first.first << '\n';
	out << "Min value: " << min_max_result.first.second << '\n';
	out << "Max value index: " << min_max_result.second.first << '\n';
	out << "Max value: " << min_max_result.second.second << '\n';

	out.close();

	std::cout << "Program run successful.\n";

	return 0;

}



std::vector<std::string> read_file_input(const std::string& filename)
{

	std::ifstream in(filename);
	if (!in.is_open())
	{
		throw std::exception(("Couldn't open the file: " + filename).c_str());
	}

	std::vector<std::string> result;
	std::string input;

	while (!in.eof())
	{
		in >> input;
		if (input != "\n" && input != "")
		{
			result.push_back(input);
		}
	}

	return result;

}



bool is_upper_case(const std::string& str)
{

	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isupper(str[i]))
		{
			return false;
		}
	}

	return true;

}
