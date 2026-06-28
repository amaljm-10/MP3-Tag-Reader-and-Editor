#include "main.h"

void view_mp3(char *file_name)
{
    FILE *fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf(RED "ERROR: Cannot open the file : %s\n\n" RESET, file_name);
        return;
    }

    /* Check whether the file contains ID3 tag */
    char id3_tag[3];
    fread(id3_tag, 1, 3, fptr);

    if (strncmp(id3_tag, "ID3", 3) != 0)
    {
        printf(RED "ERROR: File does not contain valid ID3 tag\n\n" RESET);
        fclose(fptr);
        return;
    }

    /* Read ID3 version */
    unsigned char ver[2];
    fread(ver, 1, 2, fptr);

    if (ver[0] != 3)
    {
        printf(RED "ERROR: This ID3 version is not supported\n\n" RESET);
        fclose(fptr);
        return;
    }

    printf(YELLOW "------ MP3 TAG INFORMATION ------\n" RESET);

    /* Move file pointer after ID3 header */
    fseek(fptr, 10, SEEK_SET);

    while (1)
    {
        char frame[5] = {0};

        /* Read frame identifier */
        if (fread(frame, 1, 4, fptr) != 4)
            break;

        unsigned char frame_size_bytes[4];
        fread(frame_size_bytes, 1, 4, fptr);

        int size =
            (frame_size_bytes[0] << 24) |
            (frame_size_bytes[1] << 16) |
            (frame_size_bytes[2] << 8)  |
             frame_size_bytes[3];

        /* Skip flag bytes */
        fseek(fptr, 2, SEEK_CUR);

        if (size <= 0)
            break;

        char *data = malloc(size + 1);
        fread(data, 1, size, fptr);
        data[size] = '\0';

        /* Print required tag values */
        if (!strcmp(frame, "TIT2"))
            printf(WHITE "Title  : %s\n" RESET, data + 1);

        else if (!strcmp(frame, "TPE1"))
            printf(WHITE "Artist : %s\n" RESET, data + 1);

        else if (!strcmp(frame, "TALB"))
            printf(WHITE "Album  : %s\n" RESET, data + 1);

        else if (!strcmp(frame, "TYER"))
            printf(WHITE "Year   : %s\n" RESET, data + 1);

        else if (!strcmp(frame, "TCON"))
            printf(WHITE "Genre  : %s\n" RESET, data + 1);

        else if (!strcmp(frame, "COMM"))
        {
            if (*(data + 4) == '\0')
                printf(WHITE "Comment : <Empty>\n\n" RESET);
            else
                printf(WHITE "Comment : %s\n\n" RESET, data + 4);

        }

        free(data);
    }

    fclose(fptr);
}