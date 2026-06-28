#ifndef MP3_H
#define MP3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;38;5;46m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

// File prototyps
void view_mp3(char *filename);
void edit_mp3(int argc, char *argv[]);
void print_help(void);

#endif