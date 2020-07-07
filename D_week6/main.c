//
//  main.c
//  D_week6
//
//  Created by runny on 2020/7/5.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
#include "KMPStrMatch.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    char* Source = "ababcbaa";
    char* Pattern = "abab";
//    ViolenceMatch(Source,8,Pattern,4);
//    getNextArray(Pattern, 4);
    KMP(Source, 8, Pattern, 4);
    return 0;
}
