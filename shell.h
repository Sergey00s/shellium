#ifndef SHELL_H

#define SHELL_H
#include <llist.h>

typedef unsigned char _8bit;

typedef struct {

    _8bit last_return_code;
    list_t *command_list;

} shell_info;


typedef enum {
    BUILD_IN = 0,
    EXTERNAL = 1,
    BUILD_IN_PIPE = 2,
    EXTERNAL_PIPE = 3,
    BUILD_IN_REDIRECT = 4,
    EXTERNAL_REDIRECT = 5,
    BUILD_IN_DELIMITER = 6,
    EXTERNAL_DELIMITER = 7
} command_type;


typedef struct
{
    command_type type;
    char *command;
    char **args;
    int output;
    int input;
} command_info;


extern shell_info shell;

#endif