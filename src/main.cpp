#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>


bool buggy_compare(char *a, char *b){
    if (a == NULL || b == NULL) {
        return false;
    }
    for (int i=0; a[i] != '\0' && b[i] != '\0'; i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void nope() {
    puts("wrong password, try again!");
    exit(1);
}

void login(char *rootPass, char *password) {
    bool is_admin = buggy_compare(rootPass, password);
    const char* user_type = is_admin ? "admin" : "user";
    printf("\n\nyou are logged in as %s\n\n", user_type);
    exit(0);
}

void fill_secure_root_password(char* buffer) {

    strcpy(buffer, "0@000");
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    unsigned int salt = (unsigned int)ts.tv_nsec/1000;

    buffer[0] = buffer[0] + int(salt%37);
    buffer[2] = buffer[2] + fmin(int(salt%79), 78);
    buffer[3] = buffer[3] + fmin(int(salt%67), 78);
    buffer[4] = buffer[4] + fmin(int(salt%73), 78);
    buffer[5] = 0x0;

    // printf("1 - %s %d\n", buffer, (int)buffer[4] + (int)buffer[2] + (int)buffer[3]);
    int rr = 0;
    while (((int)buffer[4] + (int)buffer[2] + (int)buffer[3]) != 300) {
        buffer[2+rr] = fmin(126, buffer[2+rr]+1);
        rr = (rr+1)%3;
    }

    // printf("2 - %s %d\n", buffer, (int)buffer[4] + (int)buffer[2] + (int)buffer[3]);
}

int main() {

    char* password  = (char *)malloc(16);
    char* rootPass  = (char *)malloc(16);

    fill_secure_root_password(rootPass);
    printf("enter password: ");
    fgets(password, 32, stdin);

    size_t len = strlen(password);
    if (len < 5) {
        nope();
    }
    if (password[1] != '@') {
        nope();
    }
    for(int i = 0; i < 3; i++) {
        if((int)password[i+2] < 48 || (int)password[i+2] >= 127) {
            nope();
        }
    }
    if ((int)password[4] + (int)password[2] + (int)password[3] != 300) {
        nope();
    }

    login(rootPass, password);
    return 0;
}
