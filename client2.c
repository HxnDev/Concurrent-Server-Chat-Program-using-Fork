#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include<arpa/inet.h>
int main() {
	
	char request[256]; 
	char buf[256];

	// create the socket
	int sock;
	

	

    while(1)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
	
	    //setup an address
	    struct sockaddr_in server_address;
	    server_address.sin_family = AF_INET;
	    server_address.sin_addr.s_addr = INADDR_ANY;;
	    server_address.sin_port = htons(3001);

        if(connect(sock, (struct sockaddr *) &server_address, sizeof(server_address))<0)        //Connection check
        {
            printf("\nERROR\n");
            exit(1);
        }

        printf("ENTER REQUEST: ");
        gets(request);	
        if(strcmp(request,"exit") == 0) break;          //Exits program if "exit" is typed
    	send(sock, request, sizeof(request), 0);

    
        
    }
}