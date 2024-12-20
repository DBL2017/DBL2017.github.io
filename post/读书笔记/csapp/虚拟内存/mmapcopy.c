#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    struct stat stat;
    int fd=open("test",O_RDONLY);
    if (fd!=0 )
    {
        fstat(fd,&stat);
        void* bufP=mmap(NULL,stat.st_size,PROT_READ,MAP_PRIVATE,fd,0);
        write(1,bufP,stat.st_size);
    }
    return 0;
}