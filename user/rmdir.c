#include "kern/public.h"
#include <string.h>

int main(int argc, char *argv[]) {
    int i;

    if(argc < 2){
        printf(2, "Usage: rmdir path...\n");
        exit();
    }

    for(i = 1; i < argc; i++){
        if(rmdir(argv[i]) < 0){
            printf(2, "rmdir: %s failed to remove\n", argv[i]);
            break;
        }
    }

    exit();
}
