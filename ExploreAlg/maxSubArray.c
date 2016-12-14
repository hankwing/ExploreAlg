//
//  main.c
//  ExploreAlg
//
//  Created by hankwing on 3/10/15.
//  Copyright (c) 2015 Hank Wing. All rights reserved.
//

#include <stdio.h>
#include "string.h"

int maxSubArray(int argc, const char * argv[]) {
    void findMax( int A[], int i, int j, int *resultI, int *resultJ, int *sum);
    void bruteForce(int A[], int *i, int *j, int *sum);
    int A[10] = {0};
    int i, j,sum;
    for (i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }
    findMax( A, 0, 9, &i, &j, &sum);
    //bruteForce(A, &i, &j, &sum);
    printf("%d %d %d\n", i, j, sum);
    
    return 0;
    
}

void bruteForce1( int A[], int *i, int *j, int *sum) {
    
    *sum = -100;
    int tempSum ,tempI, tempJ,m ;
    for (tempI = 0; tempI< 10; tempI++) {
        for (tempJ = tempI; tempJ < 10; tempJ++ ) {
            
            tempSum = 0;
            for (m = tempI; m <= tempJ; m++) {
                tempSum += A[m];
                if (tempSum > *sum) {
                    *sum = tempSum;
                    *i = tempI;
                    *j = tempJ;
                }
            }
            
        }
    }
    
}

void findMax1( int A[], int i, int j, int *resultI, int *resultJ, int *sum) {
    void findMidMax( int *, int , int, int *, int *, int , int*);
    int mid, leftI, leftJ,leftSum, rightI, rightJ, rightSum, midI, midJ, midSum;
    if (i == j) {
        *resultI = i;
        *resultJ = j;
        *sum = A[i];
    }
    else {
        mid = (i+j)/2;
        findMax( A, i, mid, &leftI, &leftJ, &leftSum);
        findMax( A, mid+1, j,&rightI, &rightJ, &rightSum);
        findMidMax(A, i, j, &midI, &midJ, mid, &midSum);
        
        if (leftSum > rightSum && leftSum > midSum) {
            *resultI = leftI;
            *resultJ = leftJ;
            *sum = leftSum;
        }
        else if ( rightSum > leftSum && rightSum > midSum) {
            *resultI = rightI;
            *resultJ = rightJ;
            *sum = rightSum;
        }
        else {
            *resultI = midI;
            *resultJ = midJ;
            *sum = midSum;
        }
    }
    
    
}

void findMidMax1( int A[], int i, int j, int *resultI, int *resultJ, int mid, int *sum) {
    
    int leftSum = -100, tempI, tempJ,rightSum = -100;;
    int leftTempSum = 0,rightTempSum = 0;
    for (tempI = mid; tempI >= i; tempI --) {
        leftTempSum += A[tempI];
        if (leftTempSum > leftSum) {
            leftSum = leftTempSum;
            *resultI = tempI;
            
        }
    }
    
    for (tempJ = mid+1; tempJ <= j; tempJ ++) {
        rightTempSum += A[tempJ];
        if (rightTempSum > rightSum) {
            rightSum = rightTempSum;
            *resultJ = tempJ;
            
        }
    }
    
    *sum = leftSum + rightSum;
}

// non-recursive
void findMaxSubArray1( int A[], int *i, int *j, int *sum) {
    
    int m,n, tempSum, testI = 0, testJ = 0, oldI, oldJ;
    int testSum, oldSum = 0;
    oldI = 0;
    oldJ = 0;
    oldSum = A[0];
    for (m = 1; m < 10; m++) {
        tempSum = 0;
        testSum = -100;
        testJ = m;
        for (n = m; n >= 0; n--) {
            tempSum += A[n];
            if (tempSum > testSum) {
                testSum = tempSum;
                testI = n;
            }
        }
        
        if (testSum > oldSum) {
            *i = oldI = testI;
            *j = oldJ = testJ;
            *sum = oldSum = testSum;
        }
        else {
            *i = oldI;
            *j = oldJ;
            *sum = oldSum;
        }
    }
}

