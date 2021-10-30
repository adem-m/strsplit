#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void skipDelimiters(char *str, char delimiter, int *i)
{
    while (str[*i] == delimiter)
    {
        *i = *i + 1;
    }
}

int isFullOfDelimiter(char *str, char delimiter)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != delimiter)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int getElementsNumber(char *str, char delimiter)
{
    int result = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        skipDelimiters(str, delimiter, &i);
        if (str[i] != '\0')
        {
            result++;
            while (str[i] != delimiter && str[i] != '\0')
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    return result;
}

char **split(char *str, char delimiter)
{
    int numberOfElements = getElementsNumber(str, delimiter);
    char **result = malloc((numberOfElements + 1) * sizeof(char *));
    result[numberOfElements] = NULL;
    int i = 0;
    int word = 0;
    while (str[i] != '\0')
    {
        skipDelimiters(str, delimiter, &i);
        if (str[i] != '\0')
        {
            int start = i;
            while (str[i] != delimiter && str[i] != '\0')
            {
                i++;
            }
            result[word] = malloc(sizeof(char) * 100);
            strncpy(result[word], str + start, i - start);
            result[word][i - start + 1] = '\0';
            word++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    char *strToSplit = "a b c";
    char delimiter = ' ';

    if (isFullOfDelimiter(strToSplit, delimiter) == 1)
    {
        printf("Your string if full of delimiters");
        return 1;
    }

    char **result = split(strToSplit, delimiter);

    printf("%s", result[0]);

    return 0;
}