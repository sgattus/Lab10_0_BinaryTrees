//
// Created by Toby Dragon on 8/26/17.
//

#ifndef COMP220LAB_TESTLIB_H
#define COMP220LAB_TESTLIB_H

#include <string>

/**
 * reports whether ints are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(int expected, int actual);

/**
 * reports whether floats are close enough to equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @param errorMargin - the amount of error you're willing to accept
 * @post prints only "pass" if the values are within the error margin from each other,
 *       else it prints "FAIL" and their respective values
 */
void printAssertCloseToEqual(float expected, float actual, float errorMargin);

/**
 * reports whether arrays are equal or not
 * @param expected - the array you expect the actual value to be
 * @param actual - the actual array to test
 * @param size - the number of elements in the arrays to check
 * @post prints only "pass" if the arrays are equal,
 *      Else it prints "FAIL" and the number of values that are different
 */
void printAssertArrayEqual(int* expected, int* actual, int size);

/**
 * reports whether strings are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertStringEqual(std::string expected, std::string actual);

/**
 * checks whether an array is in sorted order or not
 * @param a - a pointer to the array to check
 * @param size - the number of elements in the array to check
 * @return true if the array is sorted, false otherwise
 */
bool checkSorted(int* a, int size);

/**
 * checks whether two arrays contain the same elements or not
 * @param a1 - a pointer to the first array to check
 * @param a2 - a pointer to the second array to check
 * @param size - the number of elements in the array to check
 * @return true if the arrays contain the same elements, false otherwise
 */
bool checkForSameElements(const int* a1, const int* a2, int size);

#endif //COMP220LAB_TESTLIB_H
