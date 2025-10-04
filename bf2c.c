#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

void write_opening(int fd) {
    ft_printf_fd(fd, "#include <stdio.h>\n");
    ft_printf_fd(fd, "int main() {\n");
    ft_printf_fd(fd, "char array[3000000] = {0};\n");
    ft_printf_fd(fd, "char *ptr = array;\n");
}

void write_closing(int fd) {
    ft_printf_fd(fd, "printf(\"\\n\");\n");
    ft_printf_fd(fd, "return 0;\n");
    ft_printf_fd(fd, "}\n");
}

int main(int argc, char *argv[])
{
    int in_fd;
    int out_fd;

    if (argc != 3) {
        ft_printf("Usage: %s input.bf output.c\n", argv[0]);
        return (1);
    }
    in_fd = open(argv[1], O_RDONLY);
    if (!in_fd || in_fd == -1)
    {
        perror("Error opening input file");
        return (1);
    }
    out_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0)
    {
        perror("Error opening output file");
        close(in_fd);
        return (1);
    }
    write_opening(out_fd);
    char *line;
    while ((line = get_next_line(in_fd)) != NULL)
    {
        int i = 0;
        while (line[i])
        {
            char c = line[i];
            switch (c)
            {
                case '>':
                    ft_printf_fd(out_fd, "++ptr;\n"); break;
                case '<':
                    ft_printf_fd(out_fd, "--ptr;\n"); break;
                case '+':
                    ft_printf_fd(out_fd, "++*ptr;\n"); break;
                case '-':
                    ft_printf_fd(out_fd, "--*ptr;\n"); break;
                case '.':
                    ft_printf_fd(out_fd, "putchar(*ptr);\n"); break;
                case ',':
                    ft_printf_fd(out_fd, "*ptr = getchar();\n"); break;
                case '[':
                    ft_printf_fd(out_fd, "while (*ptr) {\n"); break;
                case ']':
                    ft_printf_fd(out_fd, "}\n"); break;
                default:
                    break;
            }
            i++;
        }
        free(line);
    }
    write_closing(out_fd);
    close(in_fd);
    close(out_fd);
    ft_printf("Translation complete: %s -> %s\n", argv[1], argv[2]);
    return (0);
}
