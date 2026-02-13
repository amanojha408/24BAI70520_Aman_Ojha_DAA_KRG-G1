#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long opCount = 0;
int depthReached = 0;

void solveRec(int n, int depth)
{
    if (depth > depthReached)
        depthReached = depth;

    if (n <= 2)
        return;

    int x = n;
    while (x > 0)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = i ^ x;
            opCount++;
        }
        x = x >> 1;
    }

    vector<int> sq(n);
    for (int i = 0; i < n; i++)
    {
        sq[i] = i * i;
        opCount++;
    }

    reverse(sq.begin(), sq.end());

    // recursive calls
    solveRec(n / 2, depth + 1);
    solveRec(n / 2, depth + 1);
    solveRec(n / 2, depth + 1);
}

int main()
{
    int test[] = {8, 16, 32};

    for (int i = 0; i < 3; i++)
    {
        int n = test[i];
        opCount = 0;
        depthReached = 0;

        auto t1 = high_resolution_clock::now();
        solveRec(n, 1);
        auto t2 = high_resolution_clock::now();

        auto timeTaken = duration_cast<milliseconds>(t2 - t1);

        cout << "n = " << n << endl;
        cout << "Operations = " << opCount << endl;
        cout << "Recursion Depth = " << depthReached << endl;
        cout << "Time Taken = " << timeTaken.count() << " ms\n\n";
    }

    return 0;
}
/*
    Recurrence Relation
    T(n) = 3 T(n / 2) + O(n log n)
*/ 


/*
    Master Theorem 
    f(n) = O(n log n)
    a = 3, b = 2

    Case 1 used
    T(n) = Theta(n ^ (log_2 3))
*/
