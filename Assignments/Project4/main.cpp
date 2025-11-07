#include "p_4_header.hpp"

#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>

constexpr std::size_t WIDTH{ 20 };

void task1_test();
void task2_test();
void task3_test();
void task4_test();
void task5_6_7_test();

/// @brief This main is used for testing. Feel free to modify the contents.
/// @remark This file is replaced with a testing main when you submit your
/// project.
int main()
{
        task1_test();
        task2_test();
        task3_test();
        task4_test();
        task5_6_7_test();

        char **test_words{};          // empty word array
        std::size_t num_test_words{}; // number of words (will be modified when
                                      // a file is read)

        // populate the word array, and update the number of words
        read_words_from_file("test_words.txt", test_words, num_test_words,
                             WIDTH);

        // deallocate
        free_word_array(test_words);

        return 0;
}

void task1_test()
{
        std::cout << "<-- Test Cases for Task1 -->" << std::endl;
        const char *test_word = "character";
        std::cout << "Length of " << test_word << " is " << strlen(test_word)
                  << std::endl;
}

void task2_test()
{
        std::cout << "<-- Test Cases for Task2 -->" << std::endl;

        // Test 1: Equal strings
        std::cout << "Test 1 - Equal strings: compare(\"hello\", \"hello\") = "
                  << compare("hello", "hello") << std::endl;

        // Test 2: str1 < str2
        std::cout << "Test 2 - str1 < str2: compare(\"apple\", \"banana\") = "
                  << compare("apple", "banana") << std::endl;

        // Test 3: str1 > str2
        std::cout << "Test 3 - str1 > str2: compare(\"zebra\", \"apple\") = "
                  << compare("zebra", "apple") << std::endl;

        // Test 4: Prefix comparison
        std::cout << "Test 4 - Prefix: compare(\"cat\", \"catfish\") = "
                  << compare("cat", "catfish") << std::endl;

        // Test 5: Empty string
        std::cout << "Test 5 - Empty string: compare(\"\", \"hello\") = "
                  << compare("", "hello") << std::endl;
}

void task3_test()
{
        std::cout << "<-- Test Cases for Task 3 -->" << std::endl;
        char original_word[WIDTH]{ "original" };

        // Test case1: equal length
        const char *word1{ "birthday" };
        assign(original_word, word1);
        std::cout << "After replacement 1: " << original_word << std::endl;

        // Test case2: longer length
        const char *word2{ "entertainment" };
        assign(original_word, word2);
        std::cout << "After replacement 2: " << original_word << std::endl;

        // Test case3: shorter lenth
        const char *word3{ "cat" };
        assign(original_word, word3);
        std::cout << "After replacement 3: " << original_word << std::endl;
}

void task4_test()
{
        std::cout << "<-- Test Cases for Task4 -->" << std::endl;
        // Hey copilot help me write test cases for distance function
        const char *word1 = "kitten";
        const char *word2 = "sitting";
        std::cout << "Distance between " << word1 << " and " << word2 << " is "
                  << distance(word1, word2) << std::endl;

        // Some more test cases please, copilot
        const char *word3 = "flaw";
        const char *word4 = "lawn";

        std::cout << "Distance between " << word3 << " and " << word4 << " is "
                  << distance(word3, word4) << std::endl;

        const char *word5 = "intention";
        const char *word6 = "execution";

        std::cout << "Distance between " << word5 << " and " << word6 << " is "
                  << distance(word5, word6) << std::endl;

        // Expected output: 3, 2, 5
}

void print_array(char *array[], std::size_t cap)
{
        std::cout << "{";
        for (std::size_t i{ 0 }; i < cap; i++) {
                std::cout << array[i] << " ";
        }
        std::cout << "}" << std::endl;
}

void task5_6_7_test()
{
        std::cout << "<-- Test Cases for Task5, 6 and 7 -->" << std::endl;

        char apple[21] = "apple";
        char banana[21] = "banana";
        char date[21] = "date";
        char cat[21] = "cat";
        char friend_str[21] = "friend";
        char mouse[21] = "mouse";
        char file[21] = "file";
        char zebra[21] = "zebra";
        char word[21] = "word";
        char jungle[21] = "jungle";

        char *words[] = { apple, banana, date,  cat,  friend_str,
                          mouse, file,   zebra, word, jungle };

        // Test 1: Unsorted array
        std::cout << "Test1 - Array with first two items sorted: is_sorted = "
                  << is_sorted(words, 10) << std::endl;

        // Test 2: Sorting array
        insertion_sort(words, 10);
        std::cout << "Sorted Array: ";
        print_array(words, 10);
        std::cout << "Test 2 - Sorted array: is_sorted = "
                  << is_sorted(words, 10) << std::endl;

        // Test 3: Single element
        char *single_array[] = { "hello" };
        std::cout << "Test 3 - Single element: is_sorted([\"hello\"], 1) = "
                  << is_sorted(single_array, 1) << std::endl;

        // Test 4: Two elements sorted
        char *two_sorted[] = { "apple", "banana" };
        std::cout << "Test 4 - Two elements sorted: is_sorted([\"apple\", "
                     "\"banana\"], 2) = "
                  << is_sorted(two_sorted, 2) << std::endl;

        // Test 5: All same strings
        char *same_array[] = { "hello", "hello", "hello" };
        std::cout << "Test 5 - All same strings: is_sorted([\"hello\", "
                     "\"hello\", \"hello\"], 3) = "
                  << is_sorted(same_array, 3) << std::endl;
}
