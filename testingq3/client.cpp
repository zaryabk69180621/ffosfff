#include<iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<cstring>
#define PORT 8080
#define IP "127.0.0.1"
using namespace std;
bool checkprime(int k){
    int test=k;
for(int i=k-1;i>1;i--){
if(k%i==0){
return false;

}
int main(){

int clientsocket= socket(AF_INET,SOCK_STREAM,0);
if(clientsocket==-1){

    cerr<<endl<<"cant create socket";
    exit(101);
}
sockaddr_in servad;
servad.sin_addr.s_addr=inet_addr(IP);
servad.sin_family=AF_INET;
servad.sin_port=htons(PORT);
int servsock=connect(clientsocket,(sockaddr*)&servad,sizeof(servad));
if(servsock==-1){

   perror("connect");
    exit(100);
}
int n;
char greet[100];
int t=recv(clientsocket,greet,sizeof(greet),0);
cout<<endl<<"t:"<<t;
greet[t]='\0';
cout<<endl<<"greet"<<greet;
cout<<endl<<"enter the number";
cin>>n;
char arr1[100]={'\0'};
sprintf(arr1,"%d",n);
int i;
for(;arr1[i]!='\0';i++);
cout<<endl<<"while sending"<<arr1<<"and i:"<<i;
send(clientsocket,arr1,i,0);
char arrx[100]={'\0'};
int b=recv(clientsocket,arrx,sizeof(arrx),0);
arrx[b]='\0';
cout<<endl<<"final:"<<arrx;





}

