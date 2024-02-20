#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 10
#define MAX_LINE_SIZE 24
#define CHUNK 16

typedef struct
{
    char key[MAX_STRING_SIZE];
    char value[MAX_STRING_SIZE];

} pair;


FILE *open_file(const char *filepath, const char *mode)
{
    FILE *file = NULL;
    file = fopen(filepath, mode);

    if(file == NULL)
    {
        perror(filepath);
        exit(1);
    }

    return file;
}


void close_file (FILE *file)
{
    if(fclose(file) == EOF)
    {
        perror("Cannot close file");
        exit(2);
    }
}


pair read_data_line(FILE *file)
{
    pair data;

    char line[MAX_LINE_SIZE];

    if(fgets(line, MAX_LINE_SIZE, file) == NULL)
    {
        data.key[0] = '\0';
        data.value[0] = '\0';
        return data;
    }
    
    char *token = strtok(line, " =");

    strcpy(data.key, token);

    token = strtok(NULL, " =\n");
    
    strcpy(data.value, token);

    return data;
}


pair *input_array(FILE *file, int *size)
{
    pair *data_array = NULL;
    pair aux_input;

    int allocated_size = 0;
    int used_size = 0;

    while(1)
    {
        aux_input = read_data_line(file);

        if(aux_input.key[0] == '\0' && aux_input.value[0] == '\0')
        {
            break;
        }

        if(used_size == allocated_size)
        {
            allocated_size += CHUNK;

            data_array = realloc(data_array, (unsigned long)allocated_size * sizeof(pair));

            if(data_array == NULL)
            {
                perror("Memory alloc error");
                exit(-1);
            }
        }

        data_array[used_size++] = aux_input;
    }

    *size = used_size;

    return data_array;
}


void sort_array(pair *array, int size)
{
    pair aux;
    int ok = 0;

    do
    {
        ok = 0;
        for(int i = 0; i < size - 1; i++)
            if(strcmp(array[i].key, array[i + 1].key) > 0)
            {
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                ok = 1;
            }
    } while (ok);
    
}


void print_array(pair *array, int size)
{
    for(int i = 0; i < size; i++)
        printf("%s = %s\n", array[i].key, array[i].value);
}


void print_last_values(pair *array, int size)
{
    for(int i = 0; i < size - 1; i++)
        if(strcmp(array[i].key, array[i + 1].key) != 0)
            printf("%s = %s\n", array[i].key, array[i].value);

    if(strcmp(array[size - 2].key, array[size - 1].key) != 0)
        printf("%s = %s\n", array[size - 1].key, array[size - 1].value);
}


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        perror("Invalid number of arguments");
        return 1;
    }

    FILE *input_file = open_file(argv[1], "r");

    int size = 0;
    pair *data_array = NULL;

    data_array = input_array(input_file, &size);

    if(data_array == NULL)
    {
        perror("File is empty");
        return 0;
    }

    sort_array(data_array, size);

    print_last_values(data_array, size);

    free(data_array);

    close_file(input_file);
    
    return 0;
}
