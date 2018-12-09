//  main.cpp
//  TreeProject

#include <iostream>
#include "BST.h"
#include "TestLib.h"

void addValuesToTree(int* a, int size, BST& tree){
    for (int i=0; i<size; i++){
        tree.add(a[i]);
    }
}

int checkIfValsInTree(int* a, int size, BST& tree){
    int problemCount = 0;
    for (int i=0; i<size; i++){
        if (tree.find(a[i]) == false){
            std::cout << "Missing value:" << a[i] << std::endl;
            problemCount++;
        }
    }
    return problemCount;
}

int checkIfValsNotInTree(int* a, int size, BST& tree){
    int problemCount = 0;
    for (int i=0; i<size; i++){
        if (tree.find(a[i])){
            std::cout << "Value found that shouldn't be:" << a[i] << std::endl;
            problemCount++;
        }
    }
    return problemCount;
}

void testCopyConstructor(int* a, int size){
    BST orig = BST();
    addValuesToTree(a, size, orig);
    BST copy = BST(orig);

    checkIfValsInTree(a, size, copy);
    //will throw create malloc error when returning if shallow copy
}

void testAssnOp(int* a, int size){
    BST orig = BST();
    addValuesToTree(a, size, orig);
    BST copy = BST();
    copy.add(5);
    copy.add(7);

    copy = orig;
    checkIfValsInTree(a, size, copy);
    int v[] = {5, 7};
    checkIfValsNotInTree(v, 2, copy);

    //make sure nothing happens when assinging to oneself
    copy = copy;
    checkIfValsInTree(a, size, copy);
    checkIfValsNotInTree(v, 2, copy);

    //will throw create malloc error when returning if shallow copy
}

int main(){

    BST t1 = BST();
    int v1Size = 9;
    int v1[] = {20, 40, 30, 6, 3, 100, 12, 14, 35};
    addValuesToTree(v1, v1Size, t1);

    BST t2 = BST();
    int v2Size = 7;
    int v2[] = {-3, -2, -22, -17, -19, -4, -1};
    addValuesToTree(v2, v2Size, t2);

    BST t3 = BST();
    int v3Size = 6;
    int v3[] = {5, 17, 9, 14, 16, 13};
    addValuesToTree(v3, v3Size, t3);


    BST t4 = BST();
    int v4Size = 4;
    int v4[] = {1, 2, 3, 4};
    addValuesToTree(v4, v4Size, t4);

    BST t5 = BST();
    t5.add(0);

    BST t6 = BST();

    std::cout << "\nTesting find" << std::endl;
    int notInValsSize = 4;
    int notInVals[] = {-8, 8, 18, -18};
    printAssertEquals(0, checkIfValsInTree(v1, v1Size, t1));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t1));
    printAssertEquals(0, checkIfValsInTree(v2, v2Size, t2));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t2));
    printAssertEquals(0, checkIfValsInTree(v3, v3Size, t3));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t3));
    printAssertEquals(0, checkIfValsInTree(v4, v4Size, t4));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t4));

    printAssertEquals(true, t5.find(0));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t5));
    printAssertEquals(0, checkIfValsNotInTree(notInVals, notInValsSize, t6));

    std::cout << "\nTesting PrintInOrder:" << std::endl;
    t1.printInOrder();
    t2.printInOrder();
    t3.printInOrder();
    t4.printInOrder();
    t5.printInOrder();
    t6.printInOrder();

    std::cout << "\nTesting Item Count:" << std::endl;
    printAssertEquals(9, t1.itemCount());
    printAssertEquals(7, t2.itemCount());
    printAssertEquals(6, t3.itemCount());
    printAssertEquals(4, t4.itemCount());
    printAssertEquals(1, t5.itemCount());
    printAssertEquals(0, t6.itemCount());

    std::cout << "\nTesting Height:" << std::endl;
    printAssertEquals(-100, t1.height());
    printAssertEquals(-100, t2.height());
    printAssertEquals(-100, t3.height());
    printAssertEquals(-100, t4.height());
    printAssertEquals(0, t5.height());
    printAssertEquals(-1, t6.height());

    std::cout << "\nTesting Max:" << std::endl;
    printAssertEquals(100, t1.max());
    printAssertEquals(-1, t2.max());
    printAssertEquals(17, t3.max());
    printAssertEquals(4, t4.max());
    printAssertEquals(0, t5.max());
    try {
        t6.max();
        std::cout << "FAIL: max should throw error when tree is empty" << std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << ("pass") << std::endl;
    }

    std::cout<<"done\n";

    testCopyConstructor(v1, v1Size);
    int one[] = {1};
    testCopyConstructor(one, 1);
    testCopyConstructor(nullptr, 0);
    std::cout<<"Done \n";

//    testAssnOp(v1, v1Size);
//    testAssnOp(one, 1);
//    testAssnOp(nullptr, 0);

    return 0;
}
