#include <iostream>
using namespace std;

int main() {

    // sample input (assuming its user input n)
    const int input[5][2] = {{1,2},{3,4},{0,6},{5,7},{8,9}};
    
    // output variables
    int overlapIndices[5] = {};
    int overlapLastIndex = 0;


    // time complexity is O(n^2)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            
            int s = input[i][0];
            int e = input[i][1];
            int os = input[j][0];
            int oe = input[j][1];

            // some adjustments to the conditions
            bool isSameTuple = s == os && e == oe;
            bool isOverlap   = os < e && oe > s;
            bool isSubset    = (s > os && oe > e) || (os > s && e > oe);


            // if true, worse case time complexity is O(n^3)
            if ( !isSameTuple && isOverlap && !isSubset) {

                // i and j are overlapping
                // check if i or j is already in the overlapIndices
                // if not, add them to the overlapIndices

                bool isIndexInStack = false;
                bool isOtherIndexInStack = false;
                
                for (int k = 0; k < overlapLastIndex; k++) {

                    if (overlapIndices[k] == i) {
                        isIndexInStack = true;
                    }
                    if (overlapIndices[k] == j) {
                        isOtherIndexInStack = true;
                    }
                }

                if (!isIndexInStack) {
                    overlapIndices[overlapLastIndex] = i;
                    overlapLastIndex++;
                }
                if (!isOtherIndexInStack) {
                    overlapIndices[overlapLastIndex] = j;
                    overlapLastIndex++;
                }

                
            } // close condition
        } // close inner loop
    } // close outer loop


    // print the inputs without overlapIndices
    if (overlapLastIndex == 0) {
        cout << "No overlapping tuples found." << endl;
    }
    else {
        // since index start from 0
        cout << (overlapLastIndex + 1) << ": " << "{ ";
    }
    
    // O(n^2)
    for (int i = 0; i < 5; i++) {
        bool isOverlap = false;
        for (int j = 0; j < overlapLastIndex; j++) {
            if (i == overlapIndices[j]) {
                isOverlap = true;
            }
        }
        if (!isOverlap) {
            cout << "(" << input[i][0] << ", " << input[i][1] << ")" << ", ";
        }
    }
    cout << " }" << endl;

    return 0;
}