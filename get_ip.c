#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc, char **argv)
{
		if (argc < 2 || argc > 2)
  {
    fprintf(stderr, "Uso: %s link\nEjemplo: %s www.yahoo.com/lalal.html\n", argv[0], argv[0]);
    return(0);
  }
  struct in_addr inp;
  char ip[16];
  struct hostent *host;
  char url[strlen(argv[1])];
  strcpy(url,argv[1]);
		char *host_name = strtok(url,"/");
  host = gethostbyname(host_name);
  if (host != NULL)
  {
    memcpy(&inp, host->h_addr_list[0], host->h_length);
    sprintf(ip, "%s", inet_ntoa(inp));
				printf("IP ---> %s\n",ip);
  }
  else
  {
    printf("ERROR - Host ip was not found.\n\n");
    exit(1);
  }
  return 0;
}

