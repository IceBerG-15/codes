#include <stdio.h>
#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int i = 0, j = 0;
    int stack[pushedSize];
    int top = -1;

    while (i < pushedSize) {
        if (top != -1 && stack[top] == popped[j]) {
            top--;
            j++;
        } else {
            stack[++top] = pushed[i];
            i++;
        }
    }

    while (top != -1 && stack[top] == popped[j]) {
        top--;
        j++;
    }

    return (i == pushedSize) && (j == poppedSize);
}

int main() {
    int pushed[] = {5, 10, 15, 20, 25};
    int popped1[] = {20, 25, 15, 10, 5};
    int popped2[] = {20, 15, 25, 5, 10};

    int pushedSize = sizeof(pushed) / sizeof(pushed[0]);
    int poppedSize = sizeof(popped1) / sizeof(popped1[0]);

    bool result1 = validateStackSequences(pushed, pushedSize, popped1, poppedSize);
    bool result2 = validateStackSequences(pushed, pushedSize, popped2, poppedSize);

    printf("Output for Example 1: %d\n", result1);
    printf("Output for Example 2: %d\n", result2);

    return 0;
}
