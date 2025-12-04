// mycopy는 인자를 두 개 받는다. (source-file, dest-file)
// 없는 파일을 만들어야하니까 create도 되게해야하고, read에서 write를 0가 될 때까지 계속 해야하기 때문에 loof가 필요하다.
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: mycp source_file target_file\n");
        return 0;
    }

    int fd_src = open(argv[1], O_RDONLY);
    int fd_tgt = open(argv[2], O_WRONLY | O_CREAT, 0644);

    int 

    while(1) {

    }

    return 0;

}