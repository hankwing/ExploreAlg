//
//  main.c
//  ExploreAlg
//
//  Created by hankwing on 3/10/15.
//  Copyright (c) 2015 Hank Wing. All rights reserved.
//

#include <stdio.h>
#include "string.h"

int reversePairs(int argc, const char * argv[]) {
    void mergeSort(int *sum, int A[], int p, int r);
    
    int A[10] = {0};
    int i,sum = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }
    
    mergeSort(&sum, A, 0, 9);
    printf("%d\n", sum);
    
    return 0;
    
}

void mergeSort( int *sum, int A[], int p, int r) {
    void merge(int *sum, int A[] , int p, int q, int r);
    int q;
    if (p < r) {
        q = (p+r)/2;
        mergeSort(sum, A, p, q);
        mergeSort(sum, A, q+1, r);
        merge(sum, A, p, q,r);
    }
}

void merge( int *sum, int A[], int p, int q, int r) {
    
    int length1 = q-p+1;
    int length2 = r-q;
    
    int a1[length1], a2[length2];
    int i,j,k;
    for( i = 0; i< length1; i++ ) {
        a1[i] = A[p+i];
    }
    
    for (j = 0; j< length2; j++) {
        a2[j] = A[q+1+j];
    }
    
    i = 0; j= 0;
    for( k = p; k <= r && i < length1 && j < length2 ; k++ ) {
        
        if( a1[i] > a2[j]) {
            A[k] = a1[i];
            i++;
            *sum += (length2 - j);
        }
        else {
            A[k] = a2[j];
            j++;
        }
    }
    
    while( i < length1) {
        A[k] = a1[i];
        k++;
        i++;
    }
    while (j < length2) {
        A[k] = a2[j];
        k++;
        j++;
    }
    
}
