#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // fork
#include <sys/types.h> //pid
#include <sys/wait.h> 
#include <sys/stat.h> //chmod
#include <fcntl.h>

int main() {
    // Process-related system calls
    pid_t child_pid;
    int status;

    printf("Parent process (PID: %d)\n", getpid());

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process waiting for child process to finish...\n");
        wait(&status);
        printf("Child process has finished\n");
    }

    //Read file contents from test file and write to target file
	char buf[50];
	int n,fd,fd1;
	fd = open("test.txt",O_RDONLY);
	n= read(fd,buf,50);
	fd1 = open("target",O_CREAT|O_WRONLY,0642);
	write(fd1,buf,n);
	
	//Write on the screen
	write(1,"Hello\n",6);
	
	//Read from keyboard and print on the screen
	int x;
	char b[30];
	x = read(0,b,30);
	write(1,b,x);
	printf("\n");
	
	//Use lseek function to read specific characters
	
	int z,f,f1;
	char buff[10];
	f= open("seeking.txt",O_RDWR);
	read(f,buff,10);
	write(1,buff,10);
	lseek(f,10,SEEK_CUR);
	read(f,buff,10);
	write(1,buff,10);
	
	
    // Protection-related system call
    if (chmod("example.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) {
        perror("chmod");
        exit(EXIT_FAILURE);
    }

    printf("File permissions changed successfully\n");

    return 0;
}

