1.Write a C program that copies a file using open, read, write, close. Support a configurable buffer size via command-line. 

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(int  argc,char *args[]){
if(argc<4){
printf("give all arguments");
return 1;
}
int fd= open(args[1],O_RDONLY);
if(fd<0){
perror("open source");
return 1;
}
int fd1 = open(args[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
if(fd1<0){
close(fd);
return 1;
}
int buf_size = atoi(args[3]);
char *buffer = malloc(buf_size);
ssize_t bytes;
while((bytes = read(fd,buffer,buf_size))>0){
write(fd1,buffer,bytes);
}
free(buffer);
close(fd);
close(fd1);
return 0;
}


2.Implement a hexdump utility: read a file and print bytes in hex with ASCII on the side (16 bytes per line). 

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char buffer[16];
    ssize_t bytes;
    int offset = 0;

    while ((bytes = read(fd, buffer, 16)) > 0) {
        printf("%08x  ", offset);

        for (int i = 0; i < 16; i++) {
            if (i < bytes)
                printf("%02x ", buffer[i]);
            else
                printf("   ");
        }

        printf(" ");

        for (int i = 0; i < bytes; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126)
                printf("%c", buffer[i]);
            else
                printf(".");
        }

        printf("\n");
        offset += bytes;
    }

    close(fd);
    return 0;
}

3.Create a program that appends text to a file using O_APPEND and verifies correctness. 

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *text = "Appended line\n";

    int fd = open("test.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    write(fd, text, strlen(text));
    close(fd);

    fd = open("test.txt", O_RDONLY);
    char buffer[1024];
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    buffer[bytes] = '\0';
    printf("File Content:\n%s", buffer);

    close(fd);
    return 0;
}

4.Write a program that reads from stdin and writes to stdout using only read/write. 

#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytes;

    while ((bytes = read(0, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes);
    }

    return 0;
}

5.Measure throughput for different buffer sizes. 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file> <buffer_size>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    int buf_size = atoi(argv[2]);

    char *buffer = malloc(buf_size);
    ssize_t bytes;
    size_t total = 0;

    clock_t start = clock();

    while ((bytes = read(fd, buffer, buf_size)) > 0) {
        total += bytes;
    }

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Read %zu bytes in %.3f seconds\n", total, time_taken);
    printf("Throughput: %.2f MB/s\n", (total / (1024.0 * 1024.0)) / time_taken);

    free(buffer);
    close(fd);
    return 0;
}
6.Demonstrate O_CREAT | O_EXCL to safely create a file and handle the “file exists” case. 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    int fd = open("newfile.txt", O_CREAT | O_EXCL | O_WRONLY, 0644);

    if (fd < 0) {
        if (errno == EEXIST) {
            printf("File already exists!\n");
        } else {
            perror("open");
        }
        return 1;
    }

    write(fd, "Created safely\n", 15);
    close(fd);

    printf("File created successfully\n");
    return 0;
}
