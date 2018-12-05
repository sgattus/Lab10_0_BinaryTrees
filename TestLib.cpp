//
// Created by Toby Dragon on 8/26/17.
//
#include <iostream>
#include "TestLib.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertCloseToEqual(float expected, float actual, float errorMargin ){
    float diff = expected - actual;
    if ( diff <= errorMargin && diff >= -errorMargin){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\t not close to actual: " << actual << std::endl;
    }
}

void printAssertArrayEqual(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}

void printAssertStringEqual(std::string expected, std::string actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "actual: " << actual << std::endl;
    }
}

bool checkSorted(int* a, int size){
    int failCount = 0;
    for (int i=0; i<size-1; i++){
        if (a[i] > a[i+1]) {
            failCount++;
        }
    }
    return failCount == 0;
}

int countOccurrences(const int* a1, int size, int itemToCount){
    //return the number of times itemToCount occurs in a1
    int total = 0;
    for (int i=0; i< size; i++) {
        if (a1[i] == itemToCount) {
            total++;
        }
    }
    return total;
}

bool checkForSameElements(const int* a1, const int *a2, int size){
    //check that the same number of each element exists using countOccurrences on every element from one array on the other
    //check everything in a1 exists in a2
    for (int i=0; i<size; i++) {
        if ((countOccurrences(a1, size, a1[i])) != countOccurrences(a2, size, a1[i])) {
            std::cout << "Error: element: " << a1[i] << " not found in both lists\n";
            return false;
        }
    }
    //edge case: a2 may contain things that are not in a1
    //so check everything in a2
    for (int i=0; i<size; i++) {
        if ((countOccurrences(a1, size, a2[i])) != countOccurrences(a2, size, a2[i])) {
            std::cout << "Error: element: " << a1[i] << " not found in both lists\n";
            return false;
        }
    }
    return true;
}