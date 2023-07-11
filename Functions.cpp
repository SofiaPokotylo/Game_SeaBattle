//
// Created by Софiя Покотило on 05.12.21.
//


#include <cmath>
#include "Functions.h"


int len(string a){
    int i = 0;
    for(; a[i]!=0; ++i);
    return i;
}

int str_to_int(string &s){
    int integ = 0;
    int slen = 0;
    int *svec;
    slen = len(s);
    /*if(slen==0)
        throw NegativeArrayIndexException();*/

    /*if(!(s[0]==45 || (s[0]>=48 && s[0]<=57)))
        throw CinException("\n\nWhen entering a number, extraneous characters were used!\n\n");
*/
    for(int i=0; i<slen; ++i){
        if(s[i]<48 || s[i]>57);
        //throw CinException("\n\nWhen entering a number, extraneous characters were used\n\n");
    }

    svec = new int[slen];
    for (int i = 0; i < slen; ++i)
        if (s[i] >= 48 && s[i] <= 57)
            svec[i] = s[i] - '0';
    for (int i = slen - 1; i >= 0; --i)
        integ += svec[i] * pow(10, slen - i - 1);
    return integ;
}
