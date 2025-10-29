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
void deallocate(double*& ref_to_ptr, bool is_arr, size_t cap = 0);

// Testing functions:
bool compare_double(double x1, double x2);

bool check_geometric(double array[], size_t capacity, double a, double ratio);

template<class T>
void print_array(T array[], size_t cap);

int main()
{
        // Test cases for geometric array generator
        {
                // Case 1: integer array
                double* geometric_arr1 = geometric(5, 3, 10);
                std::cout << check_geometric(geometric_arr1, 10, 5, 3) << " ";
                print_array(geometric_arr1, 10);

                // Case 2: larger array with decimal ratio
                double* geometric_arr2 = geometric(10, 1.1, 100);
                std::cout << check_geometric(geometric_arr2, 100, 10, 1.1) << "\n";

                // Case 3: very large array to approximate e at limit
                int n = 1e5;
                double* geometric_arr3 = geometric(1, (1.0 + 1.0 / n), n);
                // lim (x->inf) (1+1/n)^n = e
                std::cout << geometric_arr3[n - 1] << "\n\n"; // Should be close to 2.718

                // Use deallocate function to free memory
                deallocate(geometric_arr1, true, 10);
                deallocate(geometric_arr2, true, 100);
                deallocate(geometric_arr3, true, n);
        }


        // Test cases for cross correlation
        {
                // Case1: simple case with array of length 1
                // We use a geometric array to examine
                double* geometric_arr = geometric(1.0, 1.1, 100);
                double len1_arr[]{ 5.0 };
                double* cross_corr4 = cross_correlation(geometric_arr, 100, len1_arr, 1);
                // The cross correlation itself should also be a geometric array with a multiplied
                std::cout << check_geometric(cross_corr4, 100 - 1, 5.0, 1.1) << "\n";

                // Case2: simple case with two arrays of length > 1
                double arr0[]{ 1, 2, 3 };
                double arr1[]{ 0, 1, 0.5 };
                double* cross_corr1 = cross_correlation(arr0, 3, arr1, 3);
                print_array(cross_corr1, 3 + 3 - 1);

                // Case4: edge case with one empty array
                double empty_arr[]{};
                double* cross_corr3 = cross_correlation(geometric_arr, 100, empty_arr, 0);
                // Check if all terms are zero
                for (size_t i = 0; i < 100 - 1; i++) {
                        assert(cross_corr3[i] == 0);
                }
                std::cout << "All entries are checked to be zero.\n\n";

                // Use deallocate function to free memory
                deallocate(geometric_arr, true, 100);
        }

        // Test cases for shift duplicates
        {
                // Case1: simple test data
                int data[10]{ 5, 4, 2, 2, 2, 4, 5, 1, 4, 3 };
                shift_duplicates(data, 10);
                print_array(data, 10);

                // Case2: complex data with generation function
                // First, generate the complex data
                int numbers[6]{ 2, 3, 5, 8, 13, 21 };
                int repeats[6]{ 30, 40, 50, 30, 20, 20 };
                int data_cap{ 0 };
                for (size_t i = 0; i < 6; i++) {
                        data_cap += repeats[i];
                }
                int* complex_data = new int[data_cap];
                size_t index{ 0 };
                for (size_t i = 0; i < 6; i++) {
                        for (size_t j = 0; j < repeats[i]; j++) {
                                complex_data[index++] = numbers[i];
                        }
                }

                // Next, perform shift duplicates
                shift_duplicates(complex_data, data_cap);

                // Now we check the data
                // First, check if the unique entries are at the front
                std::cout << "First 6 entries of the array: ";
                print_array(complex_data, 6);
                for (size_t i = 0; i < 6; i++) {
                        assert(complex_data[i] == numbers[i]);
                }
                std::cout << "Unique entries are confirmed to be at the front (Success)\n";

                // Then, check if all entries are still included in the back
                int numbers_actual_count[6]{ 0 };
                for (size_t i = 0; i < data_cap; i++) for (size_t j = 0; j < 6; j++) {
                        if (numbers[j] == complex_data[i]) numbers_actual_count[j]++;
                }
                std::cout << "Actual Number Counts: ";
                print_array(numbers_actual_count, 6);
                // Check if the number counts are preserved
                for (size_t i = 0; i < 6; i++) {
                        assert(repeats[i] == numbers_actual_count[i]);
                }
                std::cout << "The number counts are preserved (Success)\n";


                delete[] complex_data; // Free up memory
        }

        // Test cases for the memory deallocation function
        {
                // Case1: deallocation of a single variable
                double* double_ptr = new double(10.0);
                double* another_ptr = double_ptr;
                deallocate(double_ptr, false);
                std::cout << "pointer after deallocation: " << double_ptr << " \n";
                // std::cout << "value after deallocation: " << *double_ptr << " \n"; // This should give us segmentation fault
                std::cout << "value in memory after deallocation: " << *another_ptr << "\n"; // Undefined behavior

                // Case2: deallocation of memory
                // We will periodically declare new arrays of 8MB in the heap for 10 * 1024 times.
                // Without the deallocation function, this will ofcourse cause memory overflow (80GB memory used).
                // But with the deallocation function, the code should be able to run correctly.

                std::cout << "Testing memory deallocation, this might take a while...\n";
                for (int i = 0; i < 1024 * 10; i++) {
                        // New array with size 1024 * 1024 * sizeof(double) = 8MB
                        double* new_arr = new double[1024 * 1024] {};
                        deallocate(new_arr, true, 1024 * 1024);
                        // Print progress every 100 times
                        if (i % 100 == 0) {
                                std::cout << i << "/" << 1024 * 10 << " arrays declared.\n";
                        }
                }

                std::cout << "Code completed without memory overflow (Success)." << "\n";

                // I tried to run the code without the deallocate function, and got:
                // terminate called after throwing an instance of 'std::bad_alloc'
                // (Wow, I thought my computer will explode LOL).
        }

        return 0;
}


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
        double* results = new double[cap0 + cap1 - 1] {};

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

void deallocate(double*& ref_to_ptr, bool is_arr, size_t cap)
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

bool check_geometric(double array[], size_t capacity, double a, double ratio)
{
        if (capacity == 0) return false;
        if (array[0] != a) return false;
        for (size_t i = 1; i < capacity; i++) {
                double actual_ratio = array[i] / array[i - 1];
                if (!compare_double(actual_ratio, ratio)) return false;
        }

        return true;
}

bool compare_double(double x1, double x2)
{
        double diff = x1 > x2 ? x1 - x2 : x2 - x1;
        constexpr double TOLERANCE = 1e-7;
        return diff < TOLERANCE;
}

template<class T>
void print_array(T array[], size_t cap)
{
        for (size_t i = 0; i < cap; i++) {
                std::cout << array[i] << ", ";
        }
        std::cout << "\n";
}