#pragma once
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <iostream>


namespace vsite::oop::v9
{

	void fill_vector(std::vector<int>& iter, const int num_of_elements);

	void remove_element(std::vector<int>& iter, const int position);

	void input_element(std::vector<std::string>& iter, const int position, const std::string& value);

	int list_nth_element(const std::list<int>& iter, const int position);

	void list_sort_desc(std::list<int>& iter);

	unsigned unique_numbers(std::istream& input);

	class word_frequency {
	public:
		word_frequency(std::istream& input);
		unsigned frequency(std::string key);
		unsigned count();
	private:
		std::unordered_map<std::string, unsigned> words;
		void populate_words(std::istream& input);
	};
}
