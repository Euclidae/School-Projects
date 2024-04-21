#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>

// Define string as char* for convenience
#define string char*
string get_string(char *prompt);
char get_char(char *prompt);
double get_double(char *prompt);
float get_float(char *prompt);
int get_int(char *prompt);
long long get_long_long(char *prompt);

char get_char(char *prompt)
{
    printf("%s", prompt);
    while (1)
    {
        string line = get_string("");
        if (line == NULL)
            return CHAR_MAX;
        char c1, c2;
        if (sscanf(line, " %c %c", &c1, &c2) == 1)
        {
            free(line);
            return c1;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

double get_double(char *prompt)
{
    printf("%s", prompt);
    while (1)
    {
        string line = get_string("");
        if (line == NULL)
            return DBL_MAX;
        double d; char c;
        if (sscanf(line, " %lf %c", &d, &c) == 1)
        {
            free(line);
            return d;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

float get_float(char *prompt)
{
    printf("%s", prompt);
    while (1)
    {
        string line = get_string("");
        if (line == NULL)
            return FLT_MAX;
        float f; char c;
        if (sscanf(line, " %f %c", &f, &c) == 1)
        {
            free(line);
            return f;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

int get_int(char *prompt)
{
    printf("%s", prompt);
    while (1)
    {
        string line = get_string("");
        if (line == NULL)
            return INT_MAX;
        int n; char c;
        if (sscanf(line, " %d %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

long long get_long_long(char *prompt)
{
    printf("%s", prompt);
    while (1)
    {
        string line = get_string("");
        if (line == NULL)
            return LLONG_MAX;
        long long n; char c;
        if (sscanf(line, " %lld %c", &n, &c) == 1)
        {
            free(line);
            return n;
        }
        else
        {
            free(line);
            printf("Retry: ");
        }
    }
}

string get_string(char *prompt)
{
    printf("%s", prompt);
    string buffer = NULL;
    unsigned int capacity = 0;
    unsigned int n = 0;
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (n + 1 > capacity)
        {
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }
            string temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
        buffer[n++] = c;
    }
    if (n == 0 && c == EOF)
        return NULL;
    string minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);
    minimal[n] = '\0';
    return minimal;
}

