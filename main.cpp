#include <bits/stdc++.h>
#include "Models/RubiksCube3dArray.cpp"
using namespace std;

int main() {
        RubiksCube3dArray object3DArray;
        object3DArray.print();
        if (object3DArray.isSolved()) cout << "SOLVED\n\n";
        else cout << "NOT SOLVED\n\n";
        object3DArray.u();
        object3DArray.print();
}