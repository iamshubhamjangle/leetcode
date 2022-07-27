/*
N-Queens.cpp

https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14

https://leetcode.com/problems/n-queens/
1. Backtracking. loop left, lefttop, leftbottom to find isValid.
	- TC: (N! * N) SC: O(N^2)

2. Backtracking. Maintain 3 vector for left, leftTop, leftBottom.
	- TC: O(N! * N) SC: O(N)
*/

/*
// 1
bool isValid(int row, int col, vector<string> board, int n) {
	int duprow = row;
	int dupcol = col;

	while(row >= 0 and col >= 0) {
		if(board[row][col] == 'Q') return false;
		row--;
		col--;
	}

	col = dupcol;
	row = duprow;
	while(col >= 0) {
		if(board[row][col] == 'Q') return false;
		col--;
	}

	row = duprow;
	col = dupcol;
	while(row < n and col >= 0) {
		if(board[row][col] == 'Q') return false;
		row++;
		col--;
	}

	return true;
}


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
	// base condition
	if(col == n) {	// if we reach the last column
		ans.push_back(board);
		return;
	}

	// isValid - mark, recurse, unmark
	for(int row=0; row<n; row++) {
		if(isValid(row, col, board, n)) {
			board[row][col] = 'Q';
			solve(col+1, board, ans, n);
			board[row][col] = '.';
		}
	}

}


vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n);
	// populate the board with <"....">
	string s(n, '.');
	for(int i=0; i<n; i++)
		board[i] = s;

	solve(0, board, ans, n);
	return ans;
}
*/


// 2
void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
	if(col == n) {
		ans.push_back(board);
		return;
	}

	for(int row=0; row<n; row++) {
		if(leftRow[row] == 0 and lowerDiagonal[row+col] == 0 and upperDiagonal[n-1 + col - row] == 0) {
			// mark, recurse, unmark
			board[row][col] = 'Q';
			leftRow[row] = 1;
			lowerDiagonal[row + col] = 1;
			upperDiagonal[n-1 + col - row] = 1;
			solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
			board[row][col] = '.';
			leftRow[row] = 0;
			lowerDiagonal[row + col] = 0;
			upperDiagonal[n-1 + col - row] = 0;
		}
	}
}


vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ans;
	vector<string> board(n);
	// populate the board with <"....">
	string s(n, '.');
	for(int i=0; i<n; i++)
		board[i] = s;

	vector<int> leftRow(n,0), upperDiagonal(2*n - 1), lowerDiagonal(2*n - 1);
	solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
	return ans;
}