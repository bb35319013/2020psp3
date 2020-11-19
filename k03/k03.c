#include <stdio.h>
#include <string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start=0,pos=0,text_len=strlen(text),key_len=strlen(key);
    while(start<=text_len-key_len){
        while(pos<key_len){
            if(text[start+pos]==key[pos]){
              if(pos==key_len-1){
                  return text+start;
              }
              pos++;
            }
            else{
                break;
            }
        }
        start++;
        pos=0;
    }
        return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    char table[256];
    int n=0,index=strlen(key)-1,pos=3,key_len=strlen(key);
    while(n<=256){
        table[n]=4;
        n++;
    }
    int table_len=strlen(table);
    n=0;
    while(n<key_len){
        table[(int)key[n]]=key_len-1-n;
        n++;
    }
    while(index<=table_len){
        while(pos>=0){
            if(text[index]==key[pos]){
                if(pos==0){
                    return text+index;
                }
                index--;
                pos--;
            }
            else{
                break;
            }
        }
        index=index+table[(int)text[index]];
    }
        return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}