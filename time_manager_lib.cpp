#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include<time.h>
#define PORT 9090

int64_t getTime()
{
   struct sockaddr_in serverAddress;
   int sockfd;
   char response[30];
   //struct sockaddr_in serverAddress;

      sockfd=socket(AF_INET,SOCK_STREAM,0);
      if(sockfd<0){
                     perror("");
                  }
   serverAddress.sin_family =AF_INET;
   serverAddress.sin_addr.s_addr=INADDR_ANY;
   serverAddress.sin_port=htons(PORT);
      if((connect(sockfd,(struct sockaddr*)&serverAddress,sizeof(serverAddress)))<0){
                  perror("");
      }

   printf("\nConnected to the server \n");
   recv(sockfd,response,29,0);
   int64_t epoch_time=atoi(response);
   return epoch_time;
   close(sockfd);
}
