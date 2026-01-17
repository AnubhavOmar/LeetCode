// Solution of LeetCode Problem 
// 278. First Bad Version
// Solution in C 

// Approach - 1 ( Using Binary Search )

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int i = 1, j = n;

    while (i <= j) {
        int mid = i + (j - i) / 2;

        if (isBadVersion(mid)) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return i;
}
