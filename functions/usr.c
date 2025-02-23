#include "usr.h"

void show_user_list(FILE* out, FILE* err)
{
    struct passwd *pw;
    while ( (pw = getpwent()) != NULL)
    {
        fprintf(out, "%s:  %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}
