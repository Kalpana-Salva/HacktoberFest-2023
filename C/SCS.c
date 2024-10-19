#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the length of the Shortest Common Supersequence (SCS)
int shortestCommonSupersequenceLength(char X[], char Y[], int dp[][100]) {
    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;  // If X is empty, add all characters from Y
            else if (j == 0)
                dp[i][j] = i;  // If Y is empty, add all characters from X
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];  // If last characters match
            else
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);  // Else take the minimum
        }
    }

    return dp[m][n];  // The value at dp[m][n] gives the SCS length
}

// Function to print the Shortest Common Supersequence (SCS)
void printSCS(char X[], char Y[], int dp[][100]) {
    int m = strlen(X);
    int n = strlen(Y);
    int SCSLength = dp[m][n];  // We already calculated the SCS length in dp array
    char SCS[SCSLength + 1];   // Array to store the SCS
    SCS[SCSLength] = '\0';     // Null-terminate the string

    int i = m, j = n, k = SCSLength;

    // Backtrack to find the SCS
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {  // If characters match
            SCS[k - 1] = X[i - 1];
            i--;
            j--;
            k--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {  // Move in the direction of greater value
            SCS[k - 1] = X[i - 1];
            i--;
            k--;
        } else {
            SCS[k - 1] = Y[j - 1];
            j--;
            k--;
        }
    }

    // Add remaining characters of X
    while (i > 0) {
        SCS[k - 1] = X[i - 1];
        i--;
        k--;
    }

    // Add remaining characters of Y
    while (j > 0) {
        SCS[k - 1] = Y[j - 1];
        j--;
        k--;
    }

    printf("Shortest Common Supersequence: %s\n", SCS);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    // Create a DP array to store intermediate results
    int dp[100][100];  // Assuming max length of strings is less than 100

    // Get the length of the SCS
    int SCSLength = shortestCommonSupersequenceLength(X, Y, dp);
    printf("Length of Shortest Common Supersequence: %d\n", SCSLength);

    // Print the SCS
    printSCS(X, Y, dp);

    return 0;
}
