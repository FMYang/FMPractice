//
//  main.c
//  Learn_C
//
//  Created by yfm on 2022/8/16.
//

#include <stdio.h>
#include "pointer.h"
#include "array.h"
#include "struct.h"
#include "bit.h"
#include "list.h"
#include "queue.h"
#include "tree.h"
#include "stack.h"

void up_and_down(int);

int* twoSum(int* nums, int numsSize, int target, int *returnSize){
    for(int i = 0; i<numsSize; i++) {
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                returnSize[0] = i;
                returnSize[1] = j;
            }
        }
    }
    return returnSize;
}

int main(int argc, const char * argv[]) {
//    up_and_down(1);
    
    pointer_example();
    array_example();
    struct_example();
    bit_example();
    list_example();
    queue_example();
    tree_example();
    stack_example();
    
    int nums[4] = {2, 7, 11, 16};
    int returnSize[2];
    int *rs = twoSum(nums, 4, 27, returnSize);
    printf("[%d, %d]\n", rs[0], rs[1]);
    
    return 0;
}

// 递归
void up_and_down(int n) {
    printf("before %d: n location %p\n", n, &n);
    if(n < 4) {
        up_and_down(n+1); // 1.2.3
    }
    printf("after %d: n location %p\n", n, &n);
}
