#include "../headers/prcs.h"
#include <stdio.h>
#include <unistd.h>

void show_processes_list(void)
{
    DIR* directory;
    struct dirent* entry;

    directory = opendir("/proc");
    if (directory != NULL)
    {
        while ( (entry = readdir(directory)) != NULL)
        {
            if (entry -> d_type == DT_DIR)
            {
                printf("PID: %s\t NAME: ", entry->d_name);

            }
        }
    }
    closedir(directory);
}
