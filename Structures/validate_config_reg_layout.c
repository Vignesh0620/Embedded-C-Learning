#include <stdio.h>

typedef struct {
    unsigned short reg;
} ConfigRegister;

int validate_config(ConfigRegister *cfg) {
    // Write logic using pointer access

    unsigned short value = (*cfg).reg;

    //Check en bit is set
    if((value & 0x0001) == 0)
        return 0;
    
    if(((value>>2) & 0x03)==3)
        return 0;
    
    if((value & 0xFFF0))
        return 0;
    return 1;
}

int main() {
    ConfigRegister cfg;
    scanf("%hx", &cfg.reg);

    int result = validate_config(&cfg);
    printf("%d", result);

    return 0;
}