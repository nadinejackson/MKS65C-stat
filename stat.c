#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

void rwx(int permissions, char perms[])
{
  permissions = permissions % 512;
  //printf("permissions in octal: %o\n", permissions);
  char letters[9] = "rwxrwxrwx";
  int i = 0;
  while(permissions > 0){
    if(permissions % 2 == 1)
      perms[8 - i] = letters[8 - i];
    else
      perms[8 - i] = '-';
    i++;
    permissions /= 2;
  }
}
int main()
{
  struct stat * buf = malloc(sizeof(struct stat));
  int exam = stat("./johal.puneet.txt", buf);
  //printf("error %d\n", errno);
  //perror("error");
  printf("the size is %ld in bytes\n", buf->st_size);
  char s[9];
  rwx(buf->st_mode, s);
  printf("permissions %s\n", s);
  printf("time of last access: %s\n", ctime(&(buf->st_atime)));
  return 0;
}
