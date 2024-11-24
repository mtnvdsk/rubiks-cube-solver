#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube {
private:

    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for(int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2-i][0];        // top row values assign from 1st column
        for(int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];          // right column values assign from 0th row
        for(int i = 0; i < 3; i++) cube[ind][2][2-i] = temp_arr[i][2];        // bottom row values assign from last right column
        for(int i = 0; i < 3; i++) cube[ind][2-i][0] = temp_arr[2][2-i];      // left column values assign from bottom row
    }

public:
    char cube[6][3][3]{};

    RubiksCube3dArray() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }

    RubiksCube &u() override {
        this->rotateFace(0);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];          // back face top row
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];   // back face top row is replaced by left face top row
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];   // left face top row is replaced by front face top row
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];   // front face top row is replaced by right face top row
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];         // right face top row is replaced by back face top row

        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};                                             //left column of top face
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];     // top face's left column replaced by back face's right column
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];     // back face's right column replaced by bottom face's left column
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];         // bottom face left column replaced by front face's left column
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];           // front face left column replaced by original top face left column

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];              // bottom row of top face
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];        // bottom row of top face replcaed by reversed right column of left face
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];    // right column of left face is replaced by reversedd top row of bottom face
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];        // top row of bottom face is replaced by left column of right face
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];              // left column of right face is replaced with original bottom row of top face

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];           // right column of top face
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];     // right column of top face is replaced by right column of front face
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];     // right column of front face is replaced by right column of bottom face
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];         // right column of bottom face is replaced by left column of back face
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];               // left column of back face is replaced by original right column of top face

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];         //back edge of the top face
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];   // back edge if top face is replaced by back edge of right face
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];       // back edge of right faceis replaced by back edge of bottom face
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];           // back edge of bottom face is replaced by back edge of left face
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];             // back edge of left face is replaced by original back edge of top face

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];     //bottom row of front face
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];   // bottom row of front face is replaced by bottom row of left face
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];   // bottom row of left face is replaced by bottom row of back face
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];   // bottom row of back face is replaced by bottom row of right face
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];     // bottom row of right face is replaced by original bottom row of front face

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube3dArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3dArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};