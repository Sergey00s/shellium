#include <libft.h>
#include <llist.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "build_in.h"
#include "shell.h"



char *get_line(char *prompt)
{
    char *line = readline(prompt);
    add_history(line);
    return line;
}

int jump_quotes(char *line, int *i, char quote)
{
    int j;

    j = *i + 1;
    while (line[j])
    {
        if (line[j] == quote)
        {
            *i = j;
            return 1;
        }
        j++;
    }
    return 0;
}


char *cut_spaces(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] == 39)
        {
            if (!jump_quotes(line, &i, 39))
            {
                return NULL;
            }
        }
        if (line[i] == '"')
        {
            if (!jump_quotes(line, &i, '"'))
            {
                return NULL;
            }
        }
        if (line[i] == ' ' || line[i] == '\t')
        {
            if (line[i + 1] == ' ' || line[i + 1] == '\t')
            {
                ft_memmove(line + i, line + i + 1, ft_strlen(line + i + 1) + 1);
                continue;
            }
        }
        i++;
    }
    return line;
}

char *lexer(char *line)
{
    char *lexed = NULL;

    lexed = ft_strtrim(line, " \t");
    lexed = cut_spaces(lexed);
    return lexed;
}

char *pre_parse(char *line)
{

    //soon
    return line;
}


list_t *parse(char *str)
{
    list_t *lst;
    command_info cmd;
    int i;
    int j;

    lst = NULL;
    i = 0;
    j = 0;
    while (str[i])
    {

        
        list_add_back(&lst, &cmd);
        i++;

    }
    
}

int main(void)
{
    char *line;
    char *lexed;

    line = NULL;
    lexed = NULL;
    while ((line = get_line("prompt >>")))
    {
        lexed = lexer(line);
        lexed = pre_parse(lexed);
        shell.command_list = parse(lexed);
        free(line);
    }
    return 0;
}
