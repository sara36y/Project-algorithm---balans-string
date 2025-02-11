#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int strlen_custom(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int longestBalanced(char* str) {
    int maxLength = 0;
    int length = strlen_custom(str);

    for (int i = 0; i < length; i++) {
        // Reset count1 and count2 for each new starting character
        int count1 = 0, count2 = 0;
        char char1 = str[i], char2 = '\0'; // Initialize char1 with current character

        for (int j = i; j < length; j++) {
            if (str[j] == char1) {
                count1++;
            } else if (char2 == '\0' || str[j] == char2) {
                char2 = str[j]; // Set char2 if encountering a new character
                count2++;
            } else {
                break; // Exit the loop if there are more than 2 different characters
            }

            // Check if there are exactly two different characters and they occur the same number of times
            if ((count1 == count2) && ((count1 + count2) == (j - i + 1))) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}


int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int result = longestBalanced(str);
    if (result > 0) {
        printf("Length of the longest balanced substring: %d\n", result);
    } else {
        printf("Length of the longest balanced substring: 0");
    }

    return 0;
}


