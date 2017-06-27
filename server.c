#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>

#define point_addr_client const struct sockaddr
#define MAXLINE 10

int main(int argc, char const *argv[]) {

  struct sockaddr_in client_addr;
  int descript_socket,descript_socket_1;

  memset(&client_addr,0, sizeof(client_addr));

  client_addr.sin_family = AF_INET;
  client_addr.sin_port = htons(13);
  client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if((descript_socket = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
  {
    printf("Errorr socket():%s\n",strerror(errno));
  }

  if((descript_socket_1 = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
  {
    printf("Errorr socket():%s\n",strerror(errno));
  }

  if(bind(descript_socket, (point_addr_client *) &client_addr, sizeof(client_addr)) == -1)
  {
    printf("Error bind(): %s\n", strerror(errno));
  }

  int recv_buffer[4];
  int send_buffer[4] = {1,0,1,0};

  while(1)
  {
   if(recvfrom(descript_socket, recv_buffer, sizeof(recv_buffer), 0, (point_addr_client *) &client_addr,sizeof(client_addr)) == -1)
   {
     printf("Error recvfrom(): %s\n", strerror(errno));
   }
   printf("World_1: %d\n",recv_buffer[0]);
   printf("World_2: %d\n",recv_buffer[1]);
   printf("World_3: %d\n",recv_buffer[2]);
   printf("World_4: %d\n",recv_buffer[3]);

   if(recv_buffer[0] == 1) printf("okkkkiiiii \n");

  }


return 0;
}
