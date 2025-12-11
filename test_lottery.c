#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char*argv[])
{
  int pid;
  int count = 0;
  
  int start_time = uptime();
  int duration = 1000;

  settickets(99);
  pid = fork();
  
  if(pid < 0){
    printf(1,"fork.failed\n");
    exit();
  }

  if(pid == 0){
    settickets(1);
    while(uptime() < start_time + duration){
      count++;
    }
    printf(0,"Hijo (1 ticket) completo: %d\n",count);
  }else{
    while(uptime() < start_time + duration){
      count++;
    }
    printf(0,"Padre (100 tickets) completo: %d\n",count);
  }

  exit();
}
