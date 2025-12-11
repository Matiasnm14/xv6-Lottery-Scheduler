#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char*argv[])
{
  int pid;
  
  settickets(100);
  pid = fork();
  
  if(pid < 0){
    printf(1,"fork.failed\n");
    exit();
  }

  if(pid == 0){
    settickets(1);
    for(;;){}
  }else{
    for(;;){
      printf(0,"Algo");
    }
  }
  exit();
}
