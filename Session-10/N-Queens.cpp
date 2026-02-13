
#include <bits/stdc++.h>
using namespace std;



vector<vector<string>> result;
vector<string> board;
int n;

bool isSafe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q') return false;
    }

    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 'Q') return false;
    }

    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(int row)
{
    if(row == n) 
    {
        result.push_back(board);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(isSafe(row, i))
        {
            board[row][i] = 'Q';
            solve(row + 1);
            board[row][i] = '.';
        }
    }
}

void solve(int row)
{
    if(row == n)
    {
        result.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(isSafe(row, i))
        {
            board[row][i] = 'Q';
            solve(row + 1);
            board[row][i] = '.';
        }
    }
}

bool isSafe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 'Q') return false;
    }

    for(int i = row + 1, j = col; i < n && j >= 0; i++, j--)
    {
        if(board[i][j] == 'Q') return false;
    }

    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 'Q') return false;
    }
    return true;
}


vector<vector<string>> result;
vector<string> board;

board = vector<string>(n, string(n, '.'));
solve(0);

for(auto b : result)
{
    for(auto r : b)
    {
        cout<<r<<endl;
    }
}



int main()
{
    cin>>n;
    board = vector<string>(n, string(n, '.'));
    solve(0);

    for(auto &b : result)
    {
        for(auto &row : b)
            cout << row << endl;
        cout << endl;
    }
    return 0;

}
