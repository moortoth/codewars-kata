#include <stdbool.h>

bool validSolution(unsigned int board[9][9])
{
    bool rows[9][10];
    bool cols[9][10];
    bool blocks[9][9][10];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            rows[i][j + 1] = false;
            cols[i][j + 1] = false;

            for (int k = 0; k < 9; ++k) {
                blocks[i / 3][j / 3][k + 1] = false;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            unsigned int curr_num = board[i][j];
            
            if (curr_num == 0)
                return false;
            
            if (rows[i][curr_num]) {
                return false;
            }

            rows[i][curr_num] = true;

            if (cols[j][curr_num]) {
                return false;
            }

            cols[j][curr_num] = true;

            if (blocks[i / 3][j / 3][curr_num]) {
                return false;
            }

            blocks[i / 3][j / 3][curr_num] = true;
        }
    }

    return true;
}

int main (int argc, char* argv[]) {
    unsigned int example1[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2}, 
        {6, 7, 2, 1, 9, 0, 3, 4, 8},
        {1, 0, 0, 3, 4, 2, 5, 6, 0},
        {8, 5, 9, 7, 6, 1, 0, 2, 0},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 0, 1, 5, 3, 7, 2, 1, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 0, 0, 4, 8, 1, 1, 7, 9}
    };

    bool res0 = validSolution(example1);
}