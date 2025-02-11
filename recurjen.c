#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isBalanced (char* S, int startindex , int endindex ) {
    int count[26] = {0};

    for (int i = startindex; i <= endindex; i++) {
        count[S[i] - 'a']++;
    }

    int distinctChars = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            distinctChars++;
        }
    }

    if (distinctChars == 2) {
        int CharCount1 = 0;
        int CharCount2 = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                if (CharCount1 == 0) {
                    CharCount1 = count[i];
                } else {
                    CharCount2 = count[i];
                }
            }
        }

        return CharCount1 == CharCount2;
    }

    return false;
}

void LongestBalance (char* S, int startindex, int endindex, int* maxLength) {
    if (startindex > endindex) {
        return;
    }

    if (isBalanced (S, startindex, endindex)) {
        int currentLength = endindex - startindex + 1;
        if (currentLength > *maxLength) {
            *maxLength = currentLength;
        }
    }

    LongestBalance (S, startindex, endindex - 1, maxLength);
    LongestBalance (S, startindex + 1, endindex, maxLength);
}

void getLongestBalanced (char* S) {
    int maxLength = 0;
    int startIndex = 0;
    int endIndex = 0;
    int size = 0;
    while ( S[size]!='\0'){
        size++;
    }
    int length = size;

    LongestBalance (S, 0, length - 1, &maxLength);

    printf("Longest balanced string length: %d\n", maxLength);
}

int main() {

    char S[100];
    printf("Enter a string: ");
    scanf("%s", S);

    getLongestBalanced (S);

    return 0;
}



