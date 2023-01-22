#include <stdio.h>

#define LEN 10

char * s_gets(char *, int);
char * reverse(char *);

int main(void) {
    char s[LEN];
    while (s_gets(s, LEN)) {
        puts(reverse(s));
    }
    return 0;
}

char * s_gets(char * st, int n) {
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        }
        else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

char * reverse(char * s) {
    char * start = s,
         * end = s;
    while (*end) {
        end++;
    }
    end--;
    while (start < end) {
        char temp;
        temp = *start;
        *start = *end;
        *end = temp;
        start++, end--;
    }
    return s;
}