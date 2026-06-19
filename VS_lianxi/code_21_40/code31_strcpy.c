// strcpy
// - `char * strcpy(char *restrict dst, const char *restrict src);`
// - 把`src`的字符串拷贝到`dst`
//   - `restrict`表明`src`和`dst`不重叠（C99）
// - 返回`dst`
//   - 为了能链起代码来

// 复制一个字符串
// char *dst = (char*)malloc(strlen(src)+1);
// strcpy(dst, src);

#include <stdio.h>
#include <string.h>

char* mycpy(char* dst, const char* src)
{
    // int idx = 0;
    // while (src[idx] ) {
    //   dst[idx] = src[idx];
    //   idx++;
    // }
    // dst[idx] = '\0';
    char* ret = dst;
    while ( *dst++ = *src++ )
        ;
    *dst = '\0';

    return ret;
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    strcpy(s1,s2);

    return 0;
}