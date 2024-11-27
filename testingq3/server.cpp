#include<iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<cstring>
using namespace std;
bool checkprime(int k){
    int test=k;
for(int i=k-1;i>1;i--){
if(k%i==0){
return false;

}


}
return true;

}

int find(int t){
t++;
while(!checkprime(t)){

    t++;
}
return t;



}

int main(){
cout<<"here";

int serversock= socket(AF_INET,SOCK_STREAM,0);
if(serversock==-1){

    perror("socket");
    cout<<"sock err";
    exit(100);
}

sockaddr_in socketad;
socketad.sin_family=AF_INET;
socketad.sin_addr.s_addr=INADDR_ANY;
socketad.sin_port=htons(8080);


if(bind(serversock,(const sockaddr*)&socketad,sizeof(socketad))==-1){
perror("socket");
cerr<<endl<<"cant bind socket";
exit(101);
}
if(listen(serversock,5)==-1){

exit(101);

};


while(true){
sockaddr_in clientadd;
socklen_t size;
cout<<"insise";

int clientsocket=accept(serversock,(sockaddr *)&clientadd,&size);

if(clientsocket==-1){
cerr<<endl<<"cant accpet";


}

int cfd=fork();

if(cfd==-1){

    cerr<<endl<<"cant fork";
    exit(100);
    
}
if(cfd==0){


close(serversock);
char greet[]="hi welcome to server";
send(clientsocket,greet,sizeof(greet),0);
char arr1[100];
recv(clientsocket,arr1,sizeof(arr1),0);
cout<<"arr"<<arr1;
int res=atoi(arr1);

int r= find(res);

char resu[100];
sprintf(resu,"%d",r);

cout<<endl<<"next found is "<<endl<<resu;
int i=0;
for(;resu[i]!='\0';i++){


}
send(clientsocket,resu,i,0);
close(clientsocket);
exit(100);
}
close(clientsocket);






}




}