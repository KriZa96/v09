#include "app.h"

namespace vsite::oop::v9
{
	void fill_vector(std::vector<int>& iter, const int num_of_elements) {
		for (int i = 0; i < num_of_elements; i++) {
			iter.push_back(i * i);
		}
	}

	void remove_element(std::vector<int>& iter, const int position) {
		iter.erase(iter.begin() + position);
	}

	void input_element(std::vector<std::string>& iter, const int position, const std::string& value) {
		iter.insert(iter.begin() + position, value);
	}

	int list_nth_element(const std::list<int>& iter, const int position) {
		auto starting_position = iter.begin();
		std::advance(starting_position, position);

		return *starting_position;
	}

	void list_sort_desc(std::list<int>& iter) {
		iter.sort(std::greater<int>());
	}

	unsigned unique_numbers(std::istream& input) {
		std::unordered_set<int> unique;
		int tmp;

		while (input >> tmp) {
			unique.insert(tmp);
		}

		return unique.size();
	}

	void word_frequency::populate_words(std::istream& input) {
		std::string word;

		while (input >> word) {
			word[0] = tolower(word[0]);
			words[word]++;
		}
	}

	word_frequency::word_frequency(std::istream& input) {
		populate_words(input);
	}

	unsigned word_frequency::count() {
		return words.size();
	}

	unsigned word_frequency::frequency(std::string key) {
		return words.contains(key) ? words[key] : 0;
	}
}