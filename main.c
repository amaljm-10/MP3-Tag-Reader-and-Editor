#include "main.h"

int main(int argc, char *argv[])
{
    printf(PURPLE "\n\t 💿  MP3 Tag Editor/Reader 💿\n\n" RESET);
    /* Case 1: No arguments */
    if (argc < 2)
    {
        printf(RED "\nERROR: Invalid Arguments !!!" RESET WHITE " Refer usage menu\n" RESET);
        print_help();
        return 0;
    }

    /* Case 2: Help option */
    if (strcmp(argv[1], "-help") == 0)
    {
        print_help();
    }
    /* Case 3: View MP3 tags */
    else if (strcmp(argv[1], "-v") == 0)
    {
        if (argc != 3)
        {
            printf(RED "\nERROR: Invalid Arguments !!!" RESET WHITE " Refer usage menu\n" RESET);
            print_help();
        }
        else
        {
            view_mp3(argv[2]);
        }
    }
    /* Case 4: Edit MP3 tags */
    else if (strcmp(argv[1], "-e") == 0)
    {
        if (argc != 5)
        {
            printf(RED "\nERROR: Invalid Arguments !!!" RESET WHITE " Refer usage menu\n" RESET);
            print_help();
        }
        else
        {
            edit_mp3(argc, argv);
        }
    }
    /* Case 5: Invalid option */
    else
    {
        printf(RED "\nERROR: Invalid Arguments !!!" RESET WHITE " Refer usage menu\n" RESET);
        print_help();
    }

    return 0;
}
