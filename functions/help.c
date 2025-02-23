#include "help.h"

void show_help(FILE* out, FILE* err)
{
    fputs("Menu:\n", out);
    fprintf(out, "--help            -h           Shows help menu\n");
    fprintf(out, "--processes       -p           Shows running processes and PID\n");
    fprintf(out, "--users           -u           Shows users and their home directories\n");
    fprintf(out, "--log <FILE>      -l <FILE>    Redirects stdout to <FILE>\n");
    fprintf(out, "--errors <FILE>   -e <FILE>    Redirects stderr to <FILE>\n");
}
