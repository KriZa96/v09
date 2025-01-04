#include "CppUnitTest.h"
#include "../app/app.h"

#include <sstream>
#include <algorithm> // is_sorted


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std::string_literals;
using namespace vsite::oop::v9;

namespace all_tests
{
	TEST_CLASS(test_v09)
	{
	public:
		
		TEST_METHOD(vector_fill)
		{
			std::vector<int> v;
			fill_vector(v, 10);
			Assert::AreEqual(10ull, v.size());
			Assert::AreEqual(0, v[0]);
			Assert::AreEqual(1, v[1]);
			Assert::AreEqual(9, v[3]);
			Assert::AreEqual(25, v[5]);
			Assert::AreEqual(81, v[9]);
			fill_vector(v, 5);
			Assert::AreEqual(15ull, v.size());
			Assert::AreEqual(0, v[10]);
			Assert::AreEqual(4, v[12]);
			Assert::AreEqual(16, v[14]);
		}
		
		TEST_METHOD(vector_remove_element)
		{
			std::vector<int> v{ 1, 2, 3, 4, 5 };
			remove_element(v, 2);
			Assert::AreEqual(4ull, v.size());
			Assert::AreEqual(2, v[1]);
			Assert::AreEqual(4, v[2]);
		}

		TEST_METHOD(vector_input_element)
		{
			std::vector<std::string> v{ "a", "b", "d" };
			input_element(v, 2, "c");
			Assert::AreEqual(4ull, v.size());
			Assert::AreEqual("c"s, v[2]);
			Assert::AreEqual("d"s, v[3]);
		}

		TEST_METHOD(list_nth_element_test)
		{
			std::list<int> c{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
			Assert::AreEqual(4, list_nth_element(c, 4));
			Assert::AreEqual(8, list_nth_element(c, 8));
		}

		TEST_METHOD(list_sort_descending)
		{
			std::list<int> c{ 7, 1, 5, 3, 4, 2 };
			list_sort_desc(c);
			Assert::AreEqual(6ull, c.size());
			Assert::IsTrue(std::is_sorted(c.rbegin(), c.rend()));
		}

		TEST_METHOD(unique_values_test)
		{
			std::stringstream ss1("-9 -7 -5 -3 -1");
			Assert::AreEqual(5u, unique_numbers(ss1));
			std::stringstream ss2("1 2 3 2 3 2 1 2 3");
			Assert::AreEqual(3u, unique_numbers(ss2));
			std::stringstream ss3("0 1 1 0 0 1 0");
			Assert::AreEqual(2u, unique_numbers(ss3));
		}

		TEST_METHOD(word_frequency_test)
		{
			std::stringstream ss("Lorem ipsum dolor sit amet lorem ipsum dolor");
			word_frequency h(ss);
			Assert::AreEqual(5u, h.count());
			Assert::AreEqual(2u, h.frequency("lorem"));
			Assert::AreEqual(1u, h.frequency("amet"));
			Assert::AreEqual(0u, h.frequency("nope"));
			Assert::AreEqual(5u, h.count());
		}
	};
}
