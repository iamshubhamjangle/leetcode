/*
Sudoku_Solver.cpp

https://leetcode.com/problems/sudoku-solver/
1. Backtracking. Check each digit at each location. TC: O(9(n ^ 2)) SC: O(1)
	isValid() { for 0 to 8:
		if(board[i][col] == ch) return false;
		if(board[row][i] == ch) return false;
		if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
	}
*/
#include<bits/stdc++.h>
using namespace std;



bool isValid(vector<vector<char>> &board, int row, int col, char ch) {
	for(int i=0; i<9; i++) {
		if(board[i][col] == ch) return false;
		if(board[row][i] == ch) return false;
		if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
	}
	return true;
}

bool solve(vector<vector<char>> &board) {
	for(int row=0; row<board.size(); row++) {
		for(int col=0; col<board[0].size(); col++) {
			if(board[row][col] == '.') {
				for(char ch='1'; ch<='9'; ch++) {
					if(isValid(board, row, col, ch)) {
						board[row][col] = ch;

						if(solve(board)) {
							return true;
						} else {
							board[row][col] = '.';
						}
					}
				}

				return false;
			}
		}
	}

	return true;
}

void solveSudoku(vector<vector<char>>& board) {
	solve(board);
}


void print(vector<vector<char>> &board) {
	for(auto row: board) {
		for(auto item: row) {
			cout << item << " ";
		}
		cout << endl;
	}
}

int main(){
	vector<vector<char>> board = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};
	solveSudoku(board);
	print(board);
	return 0;	
}