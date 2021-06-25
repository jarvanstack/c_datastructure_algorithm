#include <stdio.h>

#define bool int
#define true 1
#define  false 0
//reference:https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd
bool verify_post_BST(int seq[], int len) {
    if (seq == NULL || len <= 0) {
        return false;
    }
    int root = seq[len - 1];
    //get left tree
    int l = 0;
    for (; l < len - 1; l++) {
        if (root < seq[l]) {
            break;
        }
    }
    //get right tree.
    int r = l;
    for (; r < len - 1; r++) {
        if (root > seq[r]) {
            return false;
        }
    }
    bool left = true;
    if (l > 0) {
        left = verify_post_BST(seq, l);
    }
    bool right = true;
    if (r < len - 1) {
        right = verify_post_BST(seq + l, len - l - 1);
    }
    return left && right;
}
int main() {
    int seq1[] = {5, 7, 6, 9, 11, 10, 8};
    bool r1 = verify_post_BST(seq1, 7);
    int seq2[] = {7,4,5,6};
    bool r2 = verify_post_BST(seq2, 4);
    printf("r1=%d\n", r1);
    printf("r2=%d\n", r2);
    return 0;
}
