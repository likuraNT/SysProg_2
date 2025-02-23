#include "prcs.h"

void show_processes_list(FILE* out, FILE* err)
{
    const char *proc_path = "/proc";
    DIR* directory = NULL;
    struct dirent* entry;
    char status_path[PATH_MAX];


    directory = opendir(proc_path);
    if (directory != NULL)
    {
        while ( (entry = readdir(directory)) != NULL)
        {
            if (entry -> d_type == DT_DIR)
            {
                fprintf(out, "PID: %s\n", entry->d_name);

            }
            else
            {
                fprintf(err, "Error: Unable to open&read directory");
            }
        }
    }
    else
    {
        fprintf(err, "Error: Unable to open %s", proc_path);
    }
    closedir(directory);
}
