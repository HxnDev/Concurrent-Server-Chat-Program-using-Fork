#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<sys/wait.h> 
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include<string.h>

int main(){
    char buf1[256];
    char message[256] = "HELLO CLIENT";
	
    // create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 3);
    int client_socket;
    int status;
    int stoploop = 0;

    while(1)
    {
        client_socket = accept(server_socket, NULL, NULL);
     
        int pid = fork();
        
        if(pid == 0 )           //Child Process
        {
            while(1)
            {
                recv(client_socket, &buf1, sizeof(buf1), 0);
                printf("CLIENT: ");
	            puts(buf1);
               
            }
            exit(status);
        }
        
        else if(pid > 0){
            //wait(&status);
            printf("IN PARENT PROCESS\n");
            close(client_socket);
        }

        //if(stoploop) break;
    }
    close(server_socket);
 
    
}