#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <inttypes.h>

struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

void print_node(int fd, int ps) {
    lseek(fd, sizeof(struct Node) * ps, SEEK_SET);
    struct Node node;
    int size = 0;
    while (size != sizeof(struct Node)) {
        int numb = read(fd, (&node) + size, sizeof(struct Node) - size);
        if (numb < 0)
            return;
        size += numb;
    }
    if (node.right_idx != 0)
        print_node(fd, node.right_idx);
    printf("%" PRId32 "\n", node.key);
    if (node.left_idx != 0)
        print_node(fd, node.left_idx);
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    print_node(fd, 0);
    close(fd);
}
