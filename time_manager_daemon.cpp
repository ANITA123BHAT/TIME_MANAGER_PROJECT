/* The time manager daemon (continuous running process) shall be created in this file.
   It should be the socket server which caters to the request coming from the shared library 
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define BACKLOG 10 // it is a no of client can at a time
#define PORT 9090
int main(){
 
 int n_client=0;
 int sockfd=socket(AF_INET,SOCK_STREAM,0);
 struct sockaddr_in serverAddress;
 serverAddress.sin_family =AF_INET;
 serverAddress.sin_addr.s_addr=INADDR_ANY;
 serverAddress.sin_port=htons(PORT);

 //binding...
 bind(sockfd,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
 printf("[+]Bind\n");
 listen(sockfd,BACKLOG);
 printf("[+]Listening for the client\n");
 //service started.....
int i=1;
 while(i){
         int client_socket=accept(sockfd,NULL,NULL);
         n_client++;
         if(client_socket<0){
                              perror("");
                           }
         printf("Connected succesfully with %d client\n",n_client);
         int64_t current_time=static_cast<int64_t>(time(NULL));
         std::string c_time=std::to_string(current_time);
         send(client_socket,c_time.c_str(),c_time.size(),0);
         close(client_socket);
         }
   close(sockfd);
 }
 */


#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include<thread>
#define BACKLOG 10 // it is a no of client can at a time
#define PORT 9090
using namespace std; 

void multiThread(){
   int n_client=0;
 int sockfd=socket(AF_INET,SOCK_STREAM,0);
 struct sockaddr_in serverAddress;
 serverAddress.sin_family =AF_INET;
 serverAddress.sin_addr.s_addr=INADDR_ANY;
 serverAddress.sin_port=htons(PORT);

 //binding...
 bind(sockfd,(struct sockaddr*)&serverAddress,sizeof(serverAddress));
 printf("[+]Bind\n");
 listen(sockfd,BACKLOG);
 printf("[+]Listening for the client\n");
 //service started.....
int i=1;
 while(i){
         int client_socket=accept(sockfd,NULL,NULL);
         n_client++;
         if(client_socket<0){
                              perror("");
                           }
         printf("Connected succesfully with %d client\n",n_client);
         int64_t current_time=static_cast<int64_t>(time(NULL));
         std::string c_time=std::to_string(current_time);
         send(client_socket,c_time.c_str(),c_time.size(),0);
         close(client_socket);
         }
   close(sockfd);
}
int main(){
   thread t1(multiThread);  
   t1.join();
   return 0;
}
