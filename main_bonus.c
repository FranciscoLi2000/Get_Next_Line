#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int *fds;
    int num_files;
    char *line;
    int all_done;
    int i;

    if (argc < 2)
    {
        printf("Introduce texto (Ctrl+D para terminar):\n");// Leer de stdin si no hay argumentos
        while ((line = get_next_line(STDIN_FILENO)))
        {
            printf("[stdin] > %s", line);
            free(line);
        }
        return 0;
    }

    /* Abrir todos los archivos */
    num_files = argc - 1;
    fds = malloc(num_files * sizeof(int));
    if (!fds)
        return 1;

    for (i = 0; i < num_files; i++)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        if (fds[i] == -1)
        {
            perror("Error abriendo archivo");
            // Cerrar los ya abiertos
            for (int j = 0; j < i; j++)
                close(fds[j]);
            free(fds);
            return 1;
        }
    }

    // Leer alternadamente de todos los archivos
    printf("Leyendo alternadamente de %d archivos:\n", num_files);
    do {
        all_done = 1;
        
        for (i = 0; i < num_files; i++) {
            if (fds[i] == -1) continue;
            
            line = get_next_line(fds[i]);
            if (line) {
                printf("[%s] > %s", argv[i + 1], line);
                free(line);
                all_done = 0;
            } else {
                close(fds[i]);
                fds[i] = -1;
            }
        }
    } while (!all_done);

    free(fds);
    return 0;
}