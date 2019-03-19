#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sockfd, numbytes;
	char buf[BUFSIZ];
	struct sockaddr_in their_addr;
	printf("break!\n");
	while ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1);
	printf("We get the sockfd~\n");
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(8000);
	their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(&(their_addr.sin_zero), 8);

	while (connect(sockfd, (struct sockaddr*)&their_addr, sizeof(struct sockaddr)) == -1);
	printf("Get the Server~Cheers!\n");
	numbytes = recv(sockfd, buf, BUFSIZ, 0);  //Receive server message  
	buf[numbytes] = '\0';
	printf("%s", buf);
	//while (1)
	int i;
	for( i=1; i<=1000000; i++) 
 	{
		//printf("Enter some thing:");
		//scanf("%s", buf);
		sprintf(buf,"%06d",i);
		numbytes = send(sockfd, buf, strlen(buf), 0);  //send message
		numbytes = recv(sockfd, buf, BUFSIZ, 0);       //receive message
		buf[numbytes] = '\0';
		printf("Received:%s\n", buf);
	}
	close(sockfd);
	return 0;
}
