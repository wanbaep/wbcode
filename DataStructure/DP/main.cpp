#include <iostream>

using namespace std;
string lcsRet = "";

int lcs(int** lcsTable, const string& x, const string& y, int i, int j);
void lcsTraceBack(int** lcsTable, const string& x, const string& y, int m, int n);
void lcsPrintTable(int** lcsTable, const string& x, const string& y, int lenX, int lenY);

int main() {
    string x = "GOOD MORNING.";
    string y = "GUTEN MORGEN.";
    char* result;

    int lenX = x.size();
    int lenY = y.size();

    int** LCSTable = NULL;

    LCSTable = (int**) malloc(sizeof(int*) * (lenX + 1));

    for(int i = 0; i < lenX + 1; ++i) {
        LCSTable[i] = (int*)malloc(sizeof(int) * (lenY + 1));
        memset(LCSTable[i], 0, sizeof(int) * (lenY + 1));
    }
    printf("%s (%d)\n", x.c_str(), lenX);
    printf("%s (%d)\n", y.c_str(), lenY);

    int ret = lcs(LCSTable, x, y, lenX, lenY);
    printf("LCS Length: %d\n", ret);
    lcsPrintTable(LCSTable, x, y, lenX, lenY);
    lcsTraceBack(LCSTable,x, y, lenX, lenY);
    printf("lcsRet: %s\n", lcsRet.c_str());

    return 0;
}

int lcs(int** lcsTable, const string& x, const string& y, int i, int j) {
    for(int m = 0; m <= i; ++m) {
        lcsTable[m][0] = 0;
    }
    for(int n = 0; n <= j; ++n) {
        lcsTable[0][n] = 0;
    }

    for(int m = 1; m <= i; ++m) {
        for(int n = 1; n <= j; ++n) {
            if(x[m - 1] == y[n - 1]) {
                lcsTable[m][n] = lcsTable[m - 1][n - 1] + 1;
            } else {
                if(lcsTable[m-1][n] > lcsTable[m][n - 1]) {
                    lcsTable[m][n] = lcsTable[m - 1][n];
                } else {
                    lcsTable[m][n] = lcsTable[m][n - 1];
                }
            }
        }
    }
    return lcsTable[i][j];
}

void lcsTraceBack(int** lcsTable, const string& x, const string& y, int m, int n) {
    if(m == 0 || n == 0) return;

    if(lcsTable[m][n] > lcsTable[m][n - 1]
    && lcsTable[m][n] > lcsTable[m - 1][n]
    && lcsTable[m][n] > lcsTable[m - 1][n - 1]) {
        lcsRet = x[m - 1] + lcsRet;
        lcsTraceBack(lcsTable, x, y, m - 1, n - 1);
    }
    else if(lcsTable[m][n] > lcsTable[m - 1][n] && lcsTable[m][n] == lcsTable[m][n - 1]) {
        lcsTraceBack(lcsTable, x, y, m, n - 1);
    } else {
        lcsTraceBack(lcsTable, x, y, m - 1, n);
    }
}

void lcsPrintTable(int** lcsTable, const string& x, const string& y, int lenX, int lenY) {
    int i = 0;
    int j = 0;

    printf("%4s", "");
    for(i = 0; i < lenY + 1; ++i) {
        printf("%c ", y[i]);
    }
    printf("\n");
    
    for(i = 0; i < lenX + 1; ++i) {
        if(i==0) printf("%2s", "");
        else printf("%-2c", x[i - 1]);

        for(j = 0; j < lenY + 1; ++j) {
            printf("%d ", lcsTable[i][j]);
        }
        printf("\n");
    }
}
