# include <iostream>
# include <cassert>

/**
 * Generate a geometric function as a double array.
 * @param a the value of the first term
 * @param ratio the ratio between every previous term and the next term
 * @return a newly allocated double array with capacity cap1, caller takes owenership
 */
double* geometric(double a, double ratio, size_t cap);

/**
 * Finds the cross correlation between the two arrays.
 *
 */
double* cross_correlation(double array0[], size_t cap0, double array1[], size_t cap1);

/**
 * Moves duplicate entries to the end of the array.
 * The unique entries will be moved to the front of the array in the same order that they first appear, while the duplicate entries will be moved the end of the array.
 * @param array the array
 * @param cap the capacity of the array
 * @return the number of unique entries
 */
size_t shift_duplicates(int array[], size_t cap);

/**
 * Sets all entries of a memory space to zero, then deallocates them.
 * @param ref_to_ptr A writtable reference to the pointer pointing to a memory space of double values
 * @param is_arr if the pointer is an array
 * @param cap the size of the array, if the given pointer is pointing to an array
 *
 */
void deallocated(double*& ref_to_ptr, bool is_arr, size_t cap = 0);


double* geometric(double a, double ratio, size_t cap)
{
        double* arr = new double[cap] { a };
        for (size_t i = 1; i < cap; i++) {
                arr[i] = ratio * arr[i - 1];
        }

        return arr;
}

double* cross_correlation(double array0[], size_t cap0, double array1[], size_t cap1)
{
        assert(cap0 + cap1 >= 1);
        double* results = new double[cap0 + cap1 - 1] { 0.0 };

        for (size_t i = 0; i < cap0; i++) {
                for (size_t j = 0; j < cap1; j++) {
                        results[i + j] += array0[i] * array1[j];
                }
        }

        return results;
}

size_t shift_duplicates(int array[], size_t cap)
{
        int* unique_entries = new int[cap] { 0 };
        size_t unique_index{ 0 };

        int* duplicated_entries = new int[cap] { 0 };
        size_t duplicated_index{ 0 };

        for (size_t i = 0; i < cap; i++) {
                bool duplicated = false;
                for (size_t j = 0; j < unique_index; j++) {
                        if (duplicated = unique_entries[j] == array[i]) break;
                }
                if (duplicated) {
                        duplicated_entries[duplicated_index++] = array[i];
                }
                else {
                        unique_entries[unique_index++] = array[i];
                }
        }

        for (size_t i = 0; i < cap; i++) {
                array[i] = i < unique_index
                        ? unique_entries[i]
                        : duplicated_entries[i - unique_index];
        }

        delete[] unique_entries;
        delete[] duplicated_entries;

        return unique_index;
}

void deallocated(double*& ref_to_ptr, bool is_arr, size_t cap = 0)
{
        if (!is_arr || cap == 0) {
                *ref_to_ptr = 0.0;
                delete ref_to_ptr;
                ref_to_ptr = nullptr;
                return;
        }

        for (size_t i = 0; i < cap; i++) {
                ref_to_ptr[i] = 0.0;
        }
        delete[] ref_to_ptr;
        ref_to_ptr = nullptr;
}

int main()
{

}