///Users/hankwing/Desktop/ExploreAlg/ExploreAlg/main.c
//  chooseSort.c
//  ExploreAlg
//
//  Created by hankwing on 3/11/15.
//  Copyright (c) 2015 Hank Wing. All rights reserved.
//

#include <stdio.h>

int quickSort() {
    
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
