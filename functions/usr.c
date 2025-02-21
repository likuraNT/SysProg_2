#include "../headers/usr.h"
#include <stdio.h>
#include <unistd.h>

void show_user_list(void)
{
    struct passwd *pw;
    while ( (pw = getpwent()) != NULL)
    {
        fprintf(stdout, "%s:  %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}
