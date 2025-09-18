#include "libft.h"

static int word_count(const char *str, char c);
static char *fill_word(const char *str, int start, int end);
static void *ft_free(char **strs, int count);
static void ft_initiate_vars(size_t *i, int *j, int *s_word);

char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;
    
    ft_initiate_vars(&i, &j, &s_word); //why do we write it like this?//

    res = ft_calloc((word_count(s, c) + 1), sizeof(char *)); //allocate memory for N+1 pointers, all set to NULL.//
    if (!res)
        return (NULL);

    while (i <= ft_strlen(s))
    {
        if (s[i] != c && s_word < 0)
            s_word = i; //If the current character is not the delimiter (!= c) AND we’re not already in a word (s_word < 0) →
//this means: we’ve just found the start of a new word.
//Save this index in s_word.//

        else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
        {
            res[j] = fill_word(s, s_word, i); 
            // copies the substring starting at s_word and ending at i into a new string.

            if (!(res[j]))
                return (ft_free(res, j));
            // If copying failed, free everything and stop.
            s_word = -1; //Reset s_word because we’re no longer in a word.//
            j++; //Move to the next slot in res.//
        }
        i++; //Move to next character in the input string.//
    }
    return (res); //Finally return the array of strings.//
}

static void ft_initiate_vars(size_t *i, int *j, int *s_word)
{
    *i = 0;
    *j = 0;
    *s_word = -1;
}

static void *ft_free(char **strs, int count)
{
    int i;
    
    i = 0;
    while (i< count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

static char *fill_word(const char *str, int start, int end)
{
    char *word;
    int i;
    
    i = 0;
    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);

    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = 0;
    return (word);
}

static int word_count(const char *str, char c)
{
    int count;
    int x;
    
    count = 0;
    x = 0;

    while (*str)
    {
        if (*str != c && x == 0)
        {
            x = 1;
            count++;
        }
        else if (*str == c)
            x = 0;
        str++;
    }
    return (count);
}

