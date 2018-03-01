#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileContent read_file(int fd) {
    struct FileContent answer;
    answer.size = 0;
    answer.data = NULL;
    int buf_size = 4096;
    int is_end = 0;
    char local_buf[buf_size];
    while (!is_end) {
        int size = 0;
        while (size < buf_size) {
            int numb = read(fd, (local_buf + size), buf_size - size);
            if (numb == -1) {
                answer.size = -1;
                free(answer.data);
                answer.data = NULL;
                return answer;
            }
            if (numb == 0) {
                is_end = 1;
                break;
            }
            size += numb;
        }
        char *new_data = realloc(answer.data, answer.size + size + 1);
        if (new_data == NULL) {
            answer.size = -1;
            free(answer.data);
            answer.data = NULL;
            return answer;
        }
        answer.data = new_data;
        memcpy(answer.data + answer.size, local_buf, size);
        answer.data[answer.size + size] = 0;
        answer.size += size;
    }
    return answer;
}
