#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat buf;
    stat("./test.c", &buf);
    printf("/etc/hosts file type & mode  = %d\n", buf.st_mode);
}
