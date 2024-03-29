/* 
    Array Lab CSCI 111
    Updated By: Mia Weber
    Date: 01/Nov/2021
    
    This lab demonstrates the use of array and some operations on array.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

using big_int = long long int;

//function that reads numbers
void readData(int *, int);
//function that finds max & min numbers from given array of numbers
void findMaxAndMin(int *, int, int&, int&);
//function that finds the sum of the numbers in a given array
big_int findSum(int *, int);
//function that sorts the numbers into ascending order
void bubbleSort(int *, int);
//function that prints each element in the array
void printArray(int *, int);
//crux of the program is done in this function
void program();

int main(int argc, char* argv[]) {
    char ans = 'y';
    do {
        program();
        cin.ignore(1000, '\n');
        cout << "\nWould you like to run the program again?[y/n]: ";
        cin >> ans;
    } while (ans == 'y');

    cin.ignore(1000, '\n');
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

//crux of program
void program() {
    size_t size;
    cout << "This program finds statistical values of some integers entered by the user.\n";
    cout << "How many numbers would you like to enter? ";
    cin >> size;
    int *nums = new int[size]; //declare a dynamic int array of size
    int max, min;
    readData(nums, size); //read the data into nums array
    printf("Done reading %zu data numbers.\n", size);
    printArray(nums, size); //print the array to check if the values are there
    findMaxAndMin(nums, size, max, min);
    printf("Max = %u\n", max);
    //fixme2: print Min value ##FIXED##
    printf("Min = %u\n", min);
    printf("Sum = %lld\n", findSum(nums, size));
    cout << "Sorted list in ascending order:\n";
    bubbleSort(nums, size);
    //fixme3: print sorted array ##FIXED##
    printArray(nums, size);
    delete [] nums;
}

//read data from a file and store it into given nums array.
void readData(int nums[], int size) {
    cout << "You've asked to enter " << size << " integers.\n";
    for (int i=0; i < size; i++) {
        cout << "Enter an integer: ";
        cin >> nums[i];
    }
}

void printArray(int nums[], int len) {
    cout << "[ ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    } 
    cout << "]" << endl;
}

void findMaxAndMin(int nums[], int len, int &max, int &min) {
    max = nums[0]; //say max is the first element
    min = nums[0]; //say min, is the first element
    for (int i = 0; i < len; i++) {
        if (max < nums[i]) {//compare max with every element and update max if needed
            max = nums[i];
        }
        //fixme4: compare min with each element and update min ##FIXED##
        if (min > nums[i]) {
            min = nums[i];
        }
    }
}

//Implements bubble sort
void bubbleSort(int nums[], int len) {
    int i, j, temp;
    bool sorted = false;
    for (i = 0; i < len; i++) {
        sorted = true;
        for (j = 0; j < len-i-1; j++) {
            //if two adjacent numbers are not in order, switch them
            if (nums[j] > nums[j+1]) {
                //fixme5: swap the values of nums[j] and nums[j+1] ##FIXED##
                //can use built-in swap or implement your own swap
                swap(nums[j], nums[j+1]); 
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

big_int findSum(int nums[], int len) {
    big_int sum = 0;
    //fixme6: iterate through nums array and add each element to sum ##FIXED##
    for (int k = 0; k < len; k++) {
        sum += nums[k];
    }
    return sum;
}