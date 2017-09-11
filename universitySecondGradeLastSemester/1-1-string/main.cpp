#include<cstdio>
#include<iostream>
#include<cstring>

String& String::Insert(int id,const String& s){
    char *p, *p1, *buf;
    int len = size;
    int len1 = s.size;
    int left = len - id;
    int i;
    if(id < 0 || id > len){
        Error("id illegal!");
    }
    buf = str;
    str = new char[len + len1 + 1];
    if(str == NULL){
        Error("overflow");
    }
    strcpy(str, buf);
    delete[]buf;
    p = str + len;
    p1 = p + len1;
    for( i = 1; 1 <= left + 1; i ++){
        *p1-- = *p--;
    }
    p = str + id;
    p1 = s.str;
    while(*p1 != '\0'){
        *p++ = *p1++;
    }
    size = len + len1;
    return(*this);
}