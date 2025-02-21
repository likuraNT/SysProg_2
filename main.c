#define _GNU_SOURCE

#include "./functions/usr.c"
#include <getopt.h>


int main(int argc, char* argv[])
{
    const char* short_options = "uphl:e:";

    const struct option long_options[] =
    {
        { "users", no_argument, NULL, 'u'},
        { "processes", no_argument, NULL, 'p'},
        { "help", no_argument, NULL, 'h'},
        { "log", required_argument, NULL, 'l'},
        { "errors", required_argument, NULL, 'e'},
        { NULL, 0, NULL, 0}
    };

    int result;
    int option_ind;

    while ( (result = getopt_long(argc, argv, short_options, long_options, &option_ind)) != -1 )
    {
        switch(result)
        {
            case 'u':
            {
                show_user_list();
                break;
            }
            case 'p':

        }
    }
}
