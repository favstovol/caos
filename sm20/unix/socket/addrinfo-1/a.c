#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    char host[1000];
    char service[1000];
    while (scanf("%s %s", host, service) > 0) {
        struct addrinfo *result;
        struct addrinfo hints = {};
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        int err = getaddrinfo(host, service, &hints, &result);
        if (err) {
            printf("%s\n", gai_strerror(err));
            continue;
        }
        struct sockaddr_in *minimal = (struct sockaddr_in *) result->ai_addr;
        struct addrinfo *cur = result->ai_next;
        while (cur != NULL) {
            struct sockaddr_in *tmp = (struct sockaddr_in *) cur->ai_addr;
            if (ntohl(tmp->sin_addr.s_addr) < ntohl(minimal->sin_addr.s_addr))
                minimal = tmp;
            cur = cur->ai_next;
        }
        printf("%s:%d\n", inet_ntoa(minimal->sin_addr), ntohs(minimal->sin_port));
        freeaddrinfo(result);
    }
}
