//
//  KMPStrMatch.h
//  D_week6
//
//  Created by runny on 2020/7/7.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef KMPStrMatch_h
#define KMPStrMatch_h

#include <stdio.h>
void ViolenceMatch(char* SourceStr,int SL,char* Pattern,int PL);
int* getNextArray(char* Pattern,int PL);
void KMP(char* SourceStr,int SL,char* Pattern,int PL);
#endif /* KMPStrMatch_h */
