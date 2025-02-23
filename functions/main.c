#define _GNU_SOURCE

#include "usr.c"
#include "prcs.c"
#include "help.c"

#include <getopt.h>

int main(int argc, char* argv[])
{
    const char* short_options = "uphl:e:";

    const struct option long_options[] =
    {
        { "users",          no_argument, NULL, 'u'},
        { "processes",      no_argument, NULL, 'p'},
        { "help",           no_argument, NULL, 'h'},
        { "log",            optional_argument, NULL, 'l'},
        { "errors",         optional_argument, NULL, 'e'},
        { NULL,             0,                 NULL,   0}
    };

    FILE* out = stdout, *err = stderr;
    int result = 0;
    int option_ind = 0;

    if (argc == 1)
    {
        show_help(out, err);
        exit(-1);

    }
    while ( (result = getopt_long(argc, argv, short_options, long_options, &option_ind)) != -1 )
    {
        switch(result)
        {
            case 'u':
            {
                show_user_list(out, err);
                break;
            }
            case 'p':
            {
                show_processes_list(out, err);
                break;
            }
            case 'h':
            {
                show_help(out, err);
                break;
            }
            case 'l':
            {
                if (( out = fopen(optarg, "w")) == NULL)
                {
                    perror("Error opening log file");
                    exit(-1);
                }
                break;
            }
        }
    }
    fclose(out);
    fclose(err);
}
