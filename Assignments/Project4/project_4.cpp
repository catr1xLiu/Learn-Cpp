#include "p_4_header.hpp"

std::size_t length(const char *a)
{
        for (std::size_t i = 0; i <= 21; i++) {
                if (a[i] == '\0')
                        return i;
        }

        return 0;
}

int compare(const char *str1, const char *str2)
{
        return 0; // TODO: implement this function
}

void assign(char *str1, const char *str2)
{
        // TODO: implement
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
