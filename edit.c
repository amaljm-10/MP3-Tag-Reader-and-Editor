#include "main.h"

void edit_mp3(int argc, char *argv[])
{
    char *option = argv[2];
    char *new_text = argv[3];
    char *filename = argv[4];

    FILE *fp = fopen(filename, "r+");
    if (!fp)
    {
        printf(RED "ERROR: Unable to open file\n\n" RESET);
        return;
    }

    char tag[3];
    fread(tag, 1, 3, fp);

    if (strncmp(tag, "ID3", 3) != 0)
    {
        printf(RED "ERROR: Not a valid ID3 file\n\n" RESET);
        fclose(fp);
        return;
    }

    fseek(fp, 10, SEEK_SET);

    char target_frame[5] = {0};

    if (strcmp(option, "-t") == 0)
        strcpy(target_frame, "TIT2");
    else if (strcmp(option, "-a") == 0)
        strcpy(target_frame, "TPE1");
    else if (strcmp(option, "-A") == 0)
        strcpy(target_frame, "TALB");
    else if (strcmp(option, "-y") == 0)
        strcpy(target_frame, "TYER");
    else if (strcmp(option, "-m") == 0)
        strcpy(target_frame, "TCON");
    else if (strcmp(option, "-c") == 0)
        strcpy(target_frame, "COMM");
    else
    {
        printf(RED "ERROR: Invalid edit option\n\n" RESET);
        fclose(fp);
        return;
    }

    while (1)
    {
        char frame_id[5] = {0};
        if (fread(frame_id, 1, 4, fp) != 4)
            break;

        unsigned char size_bytes[4];
        fread(size_bytes, 1, 4, fp);

        int frame_size =
            (size_bytes[0] << 24) |
            (size_bytes[1] << 16) |
            (size_bytes[2] << 8) |
            size_bytes[3];

        fseek(fp, 2, SEEK_CUR);

        if (strcmp(frame_id, target_frame) == 0)
        {
            long pos = ftell(fp);

            if (strcmp(target_frame, "COMM") == 0)
                fseek(fp, pos + 4, SEEK_SET);
            else
                fseek(fp, pos + 1, SEEK_SET);

            int new_len = strlen(new_text);
            if (new_len > frame_size - 1)
                new_len = frame_size - 1;

            fwrite(new_text, 1, new_len, fp);

            int rem = frame_size - 1 - new_len;
            for (int i = 0; i < rem; i++)
                fputc('\0', fp);

            printf(GREEN "Tag edited successfully!! \n\n" RESET);

            fclose(fp);
            view_mp3(filename);
            return;
        }
        else
        {
            fseek(fp, frame_size, SEEK_CUR);
        }
    }

    printf(RED "ERROR: Frame not found\n\n" RESET);
    fclose(fp);
}