#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/************************************************************************************************************************
1��int socket(int family,int type,int protocol)
family:
	ָ��ʹ�õ�Э���:AF_INET��IPv4�� AF_INET6��IPv6�� AF_LOCAL��UNIXЭ�飩 AF_ROUTE��·���׽��֣� AF_KEY����Կ�׽��֣�
type:
	ָ��ʹ�õ��׽��ֵ�����:SOCK_STREAM���ֽ����׽��֣� SOCK_DGRAM
protocol:
	����׽������Ͳ���ԭʼ�׽��֣���ô���������Ϊ0
2��int bind(int sockfd, struct sockaddr *myaddr, int addrlen)
sockfd:
	socket�������ص��׽���������
myaddr:
	��ָ�򱾵�IP��ַ�Ľṹ��ָ��
myaddrlen:
	�ṹ����
struct sockaddr{
	unsigned short sa_family; //ͨ��Э��������AF_xx
	char sa_data[14];  //14�ֽ�Э���ַ��������socket��IP��ַ�Ͷ˿ں�
};
struct sockaddr_in{
	short int sin_family; //ͨ��Э��������
	unsigned short int sin_port; //�˿ں�
	struct in_addr sin_addr; //IP��ַ
	unsigned char si_zero[8];  //���0�Ա�����sockaddr�ṹ�ĳ�����ͬ
};
3��int connect(int sockfd,const struct sockaddr *serv_addr,socklen_t addrlen)
sockfd:
	socket���������׽���������
serv_addr:
	������IP��ַ�ṹָ��
addrlen:
	�ṹ��ָ��ĳ���
4��int listen(int sockfd, int backlog)
sockfd:
	socket������bind���׽���������
backlog:
	���ÿ����ӿͻ��˵�������Ӹ��������ж���ͻ��������������ʱ���յ���ֵ��Ӱ�졣Ĭ��ֵ20
5��int accept(int sockfd,struct sockaddr *cliaddr,socklen_t *addrlen)
sockfd:
	socket��������listen���׽���������
cliaddr:
	�ͻ����׽��ֽӿڵ�ַ�ṹ
addrlen:
	�ͻ��˵�ַ�ṹ����
6��int send(int sockfd, const void *msg,int len,int flags)
7��int recv(int sockfd, void *buf,int len,unsigned int flags)
sockfd:
	socket�������׽���������
msg:
	�������ݵ�ָ��
buf:
	��Ž������ݵĻ�����
len:
	���ݵĳ��ȣ���flags����Ϊ0
*************************************************************************************************************************/
int main(int argc, char *argv[])
{
	int fd, new_fd, struct_len, numbytes, i;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char buff[BUFSIZ];

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8000);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(server_addr.sin_zero), 8);
	struct_len = sizeof(struct sockaddr_in);

	fd = socket(AF_INET, SOCK_STREAM, 0);
	while (bind(fd, (struct sockaddr *)&server_addr, struct_len) == -1);
	printf("Bind Success!\n");
	while (listen(fd, 10) == -1);
	printf("Listening....\n");
	printf("Ready for Accept,Waitting...\n");
	new_fd = accept(fd, (struct sockaddr *)&client_addr, &struct_len);
	printf("Get the Client.\n");
	numbytes = send(new_fd, "Welcome to my server\n", 21, 0);
	while ((numbytes = recv(new_fd, buff, BUFSIZ, 0)) > 0)
	{
		buff[numbytes] = '\0';
		printf("%s\n", buff);
		if (send(new_fd, buff, numbytes, 0) < 0)
		{
			perror("write");
			return 1;
		}
	}
	close(new_fd);
	close(fd);
	return 0;
}