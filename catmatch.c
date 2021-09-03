#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
        fprintf(stderr, "%d\n\n\n", getpid());

        FILE *fp;
        char buffer[100];

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
                fprintf(stderr, "Error opening the file");
                return(-1);
        }

        char *pattern = NULL;
        pattern = getenv("CATMATCH_PATTERN");

        while (fgets (buffer, 100, fp) != NULL) {
                if (pattern == NULL) {
                        printf("0 %s", buffer);
                }
                else {
                        char *found;
                        found = strstr(buffer, pattern);

                        if (found != NULL) {
                                printf("1 %s", buffer);
                        }
                        else {
                                printf("0 %s", buffer);
                        }
                }
        }
        fclose(fp);

        /*I COMPLETED THE TMUX EXERCISE!*/

        return 0;
}
