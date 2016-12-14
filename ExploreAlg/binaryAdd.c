//
//  main.c
//  ExploreAlg
//
//  Created by hankwing on 3/10/15.
//  Copyright (c) 2015 Hank Wing. All rights reserved.
//

#include <stdio.h>
#include "string.h"
#define bool int
#define false 0
#define true 1

typedef struct{
    
    char a[10];
    int length;
}charInt;

int binarySort() {
    
    int a[10] = {0}, i, j, min;
    
    for( i = 0; i < 10; i++ ) {
        scanf("%d", &a[i]);
    }
    
    for( i = 0; i< 9; i++) {
        
        for ( min = j = i; j< 10 ; j++ ) {
            if( a[min] > a[j]) {
                min = j;
            }
        }
        
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        
    }
    
    for( i = 0; i < 10; i++ ) {
        printf("%d ", a[i]);
    }
    
    return 0;
    
}
