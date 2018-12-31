#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    uid_t real = getuid();
    uid_t eff = geteuid();
    printf("RUID = %d EUID = %d\n", real, eff);
    FILE* file = fopen("/home/valmit/Documents/QtProjects/irtegov-3/secret.txt", "r+");
    if (file == NULL) {
        perror("Access Denied");
    }
    else fclose(file);
    if (setuid(real) == -1) {
        perror("setuid problem");
    }
    printf("RUID = %d EUID = %d\n", real, eff);
    file = fopen("/home/valmit/Documents/QtProjects/irtegov-3/secret.txt", "r+");
    if (file == NULL) {
        perror("Access Denied");
    }
    else fclose(file);
    return 0;
}
