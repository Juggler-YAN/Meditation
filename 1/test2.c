#include <stdio.h>

int main(void) {
    FILE* fp = fopen("./test.txt" , "w");
	for (int i = 0; i <= 127; i++)
	{
        if (i == 26) continue;
        fprintf(fp, "%c", i);
	}
	fclose(fp);
    return 0;
}