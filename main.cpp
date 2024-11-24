#include <bits/stdc++.h>
#include "Models/RubiksCube3dArray.cpp"
#include "Models/RubiksCube1dArray.cpp"
#include "Models/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"

using namespace std;

int main() {
        // RubiksCube3dArray object3DArray;
        // object3DArray.print();
        // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
        // else cout << "NOT SOLVED\n\n";
        // object3DArray.u();
        // object3DArray.print();

        // Create two Cubes ------------------------------------------------------------------------------------------

        //    RubiksCube3dArray cube1;
        //    RubiksCube3dArray cube2;

        //    RubiksCube1dArray cube1;
        //    RubiksCube1dArray cube2;

        //    RubiksCubeBitboard cube1;
        //    RubiksCubeBitboard cube2;

        //  Equality and assignment of cubes --------------------------------------------------------------------------

        //    if(cube1 == cube2) cout << "Is equal\n";
        //    else cout << "Not Equal\n";
        //
        //    cube1.randomShuffleCube(1);
        //
        //    if(cube1 == cube2) cout << "Is equal\n";
        //    else cout << "Not Equal\n";
        //
        //    cube2 = cube1;
        //
        //    if(cube1 == cube2) cout << "Is equal\n";
        //    else cout << "Not Equal\n";

        //  Unordered_map of Cubes  ------------------------------------------------------------------------------------


        //    unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

        //    unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

        //    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
        //
        //    mp1[cube1] = true;
        //    cube2.randomShuffleCube(8);
        //    if (mp1[cube1]) cout << "Cube1 is present\n";
        //    else cout << "Cube1 is not present\n";
        //
        //    if (mp1[cube2]) cout << "Cube2 is present\n";
        //    else cout << "Cube2 is not present\n";

        // DFS Solver Testing __________________________________________________________________________________________
        //    RubiksCube3dArray cube;
        //    cube.print();
        //
        //    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
        //    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    cube.print();
        //
        //    DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
        //    vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
        //
        //    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    dfsSolver.rubiksCube.print();

        //BFS Solver -----------------------------------------------------------------------------------------------------
        //    RubiksCubeBitboard cube;
        //    cube.print();
        //
        //    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
        //    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    cube.print();
        //
        //    BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
        //    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
        //
        //    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    bfsSolver.rubiksCube.print();

        // IDDFS Solver ----------------------------------------------------------------------------------------------------
        RubiksCubeBitboard cube;
        cube.print();

        vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
        for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
        cube.print();

        IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
        vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();

        for (auto move: solve_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
        iddfsSolver.rubiksCube.print();

        // IDA* SOLVER ---------------------------------------------------------------------------------------------------
        //    RubiksCubeBitboard cube;
        //    cube.print();
        //
        //    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
        //    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    cube.print();
        //
        //    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
        //    vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
        //    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
        //    cout << "\n";
        //    idAstarSolver.rubiksCube.print();

        // CornerPatternDatabase Testing ---------------------------------------------------------------------------------

        //    CornerPatternDatabase cornerDB;
        //    RubiksCubeBitboard cube;
        //    cube.print();
        //
        //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
        //
        //    cornerDB.setNumMoves(cube, 5);
        //
        //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
        //
        //    cube.randomShuffleCube(1);
        //    cube.print();
        //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
        //
        //    cornerDB.setNumMoves(cube, 6);
        //
        //    cout << (int)cornerDB.getNumMoves(cube) << "\n";


}