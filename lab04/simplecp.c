#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 2048
#define PERM 0644

void copy_file(const char* name1, const char* name2) {
        int fd1, fd2, n;
        char buf[BUFSIZE];

        if ( (fd1=open(name1, O_RDONLY)) < 0 )  {
        perror("fd1 open err");
        exit(1);
        }

        if ( (fd2=open(name2, O_CREAT|O_WRONLY|O_TRUNC)) < 0 ) {
                perror("fd2 creat err");
                exit(1);
        }

        while ((n = read(fd1, buf, BUFSIZE)) > 0) {
                write(fd2, buf, n);
        }

        close(fd1);
        close(fd2);
}

int main(int argc, char* argv[]) {
        copy_file(argv[1], argv[2]);
        return 0;
}




