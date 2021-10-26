#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char **my_str_to_word_array(const char *str);

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }

    return i;
}

char *my_strdup(const char *to_dup)
{
    char *dup = malloc(sizeof(char) * my_strlen(to_dup));

    for (int i = 0; to_dup[i]; i++)
        dup[i] = to_dup[i];
    
    return dup;
}

int is_alpha(char c)
{
    return ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'));
}

int get_n_word(const char *str)
{
    int count = 0;
    int i = 0;
    int switcher = 0;
    while (str[i]) {
        if (switcher && is_alpha(str[i])) {
            switcher = 0;
            count += 1;
        } else if (!switcher && !is_alpha(str[i]))
            switcher = 1;
        i++;
    }

    return count;
}

char **my_str_to_word_array(const char *str)
{
    int n = get_n_word(str);
    char **array = malloc(sizeof(char *) * (n + 1));
    int switcher = 1;
    char *dup = my_strdup(str);
    int act = 0;
    for (int i = 0; str[i] != '\0' && act < n; i++) {
        if (switcher && is_alpha(str[i])) {
            switcher = 0;
            array[act] = &dup[i];
            act += 1;
        } else if (!switcher && !is_alpha(str[i])) {
            switcher = 1;
        }
        if (!is_alpha(str[i]))
            dup[i] = '\0';
    }
    array[act] = NULL;
    return array;
}

int main(int argc, char **argv)
{
    char **str_str = my_str_to_word_array(argv[1]);

    while (*str_str != NULL) {
        printf("%s\n", *str_str);
        str_str++;
    }
}

