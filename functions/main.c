#define _GNU_SOURCE

#include "usr.h"
#include "prcs.h"
#include "help.h"

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main(int argc, char* argv[])
{
    const char* short_options = "uphl:e:";

    const struct option long_options[] =
    {
        { "users",          no_argument, NULL, 'u'},
        { "processes",      no_argument, NULL, 'p'},
        { "help",           no_argument, NULL, 'h'},
        { "log",            required_argument, NULL, 'l'},
        { "errors",         required_argument, NULL, 'e'},
        { NULL,             0,                 NULL,   0}
    };

    FILE* out = stdout, *err = stderr;
    int result = 0;
    int option_ind = 0;
    int output_result[5];

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
                output_result[4] = 1;
                show_user_list(out, err);
                break;
            }
            case 'p':
            {
                output_result[3] = 1;
                show_processes_list(out, err);
                break;
            }
            case 'h':
            {
                output_result[2] = 1;
                show_help(out, err);
                break;
            }
            case 'l':
            {
                output_result[1] = 1;
                break;
            }
            case 'e':
            {
                output_result[0] = 1;
                break;
            }
            default:
            {
                perror("Error parsing arguments");
                exit(-1);
                break;
            }
            return 0;
        }
        if (output_result[1] == 1)
        {
            if ((out = fopen(optarg, "w+")) == NULL)
                {
                    perror("Error opening log file");
                    exit(-1);
                }

            else if (output_result[4] == 1) {show_user_list(out, err);}
            else if (output_result[3] == 1) {show_processes_list(out, out);}
            else if (output_result[2] == 1) {show_help(out, err);}
        }

        if (output_result[0] == 1)
        {
            if ((err = fopen(optarg, "w+")) == NULL)
            {
                perror("Error opening err file");
                exit(-1);
            }

            else if (output_result[4] == 1) {show_user_list(err, err);}
            else if (output_result[3] == 1) {show_processes_list(err, err);}
            else if (output_result[2] == 1) {show_help(err, err);}

        }
    }
    fclose(out);
    fclose(err);
    return 0;
}
