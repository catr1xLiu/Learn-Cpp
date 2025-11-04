#include "p_4_header.hpp"

/**
 * @brief Calculates the length of a string
 * @param a the constant char array, terminated by '\0'
 * @return the length
 * */
std::size_t length(const char *a)
{
        // Use a recursive algorithm for simplicity
        return *a == '\0' ? 0 : length(a + 1) + 1;
}

/**
 * @brief Compares which two strings occurs in the dictionary first
 * @param str1 the first string
 * @param str2 the second string
 * @return -1 if str1 occurs before str2, 1 if str2 occurs before str1, 0 if the
 * two strings are equal
 * */
int compare(const char *str1, const char *str2)
{
        // If both strings are ended
        // They are equal (we've already compared previous digit)
        if (*str1 == '\0' && *str2 == '\0')
                return 0;

        // The first digit that is different tells us which word comes first
        if (*str1 < *str2)
                return -1;
        if (*str2 > *str1)
                return 1;

        // If the current digit is equal, move to next using recurssion
        return compare(str1 + 1, str2 + 1);
}

/**
 * @brief Copies the value of a string to another
 * @param str1 the target string, with sufficient memory allocated
 * @param str2 the source string terminated by '\0'
 * */
void assign(char *str1, const char *str2)
{
        // Copy the current digit
        *str1 = *str2;

        // Terminates when str2 terminates
        if (*str2 != '\0') {
                // Move the next digit using recurssion
                assign(str1 + 1, str2 + 1);
        }
}

unsigned int distance(const char *str1, const char *str2)
{
        return 0; // TODO: implement
}

std::size_t is_sorted(char **array, std::size_t capacity)
{
        return 0; // TODO: implement
}

void insert(char *array[], std::size_t capacity)
{
        // TODO: implement
}

void insertion_sort(char *array[], std::size_t capacity)
{
        // TODO: implement
}

std::size_t remove_duplicates(char *array[], std::size_t capacity)
{
        return 0; // TODO: implement
}

std::size_t find(char *array[], std::size_t capacity, const char *str)
{
        return 0; // TODO: implement
}

void read_words_from_file(const char *filename, char *(&work_array)[],
                          std::size_t &numwords, std::size_t max_length)
{
        // TODO: implement
}

void free_word_array(char *word_array[])
{
        // TODO: implement
}
