#include "main.h"

void print_help(void)
{
    printf(PURPLE "\nHELP MENU:\n" RESET);

    printf(WHITE "TO VIEW MP3 TAGS:\n" RESET);
    printf(WHITE "  ./a.out -v <mp3_file>\n\n" RESET);

    printf(WHITE "TO EDIT MP3 TAGS:\n" RESET);
    printf(WHITE "  ./a.out -e -t <new_title>  <mp3_file>\n" RESET);
    printf(WHITE "  ./a.out -e -a <new_artist> <mp3_file>\n" RESET);
    printf(WHITE "  ./a.out -e -A <new_album>  <mp3_file>\n" RESET);
    printf(WHITE "  ./a.out -e -y <new_year>   <mp3_file>\n" RESET);
    printf(WHITE "  ./a.out -e -m <new_genre>  <mp3_file>\n" RESET);
    printf(WHITE "  ./a.out -e -c <comment>    <mp3_file>\n\n" RESET);

    printf(WHITE "FOR HELP:\n" RESET);
    printf(WHITE "  ./a.out -help\n\n" RESET);
}