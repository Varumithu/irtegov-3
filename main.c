#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    uid_t real = getuid();
    uid_t eff = geteuid();
    printf("RUID = %d EUID = %d\n", real, eff);
    FILE* file = fopen("/export/home/valmit/Documents/programming/irtegov-3/secret.txt", "r+");
    if (file == NULL) {
        perror("Access Denied");
    }
    else fclose(file);
    if (setuid(real) == -1) {
        perror("setuid problem");
    }
    real = getuid();
    eff = geteuid();
    printf("RUID = %d EUID = %d\n", real, eff);
    file = fopen("/export/home/valmit/Documents/programming/irtegov-3/secret.txt", "r+");
    if (file == NULL) {
        perror("Access Denied");
    }
    else fclose(file);
    return 0;
}
