#include <stdio.h>
#include "version.h"

int usage(int code)
{
    printf("Hello world example %s\n"
           "Copyright Jiang Xin <jiangxin AT ossxp DOT com>, 2009.\n"
           "\n"
           "Usage:\n"
           "    hello\n"
           "            say hello to the world.\n\n"
           "    hello -v, --version\n"
           "            show version.\n\n"
           "    hello -h, -help\n"
           "            this help screen.\n\n", _VERSION);
    return code;
}

void show_version(void)
{
    printf( "hello version %s\n", _VERSION );
}

int
main(int argc, char **argv)
{
    if (argc == 1) {
        printf ("Hello world.\n");
    } else if ( strcmp(argv[1],"-h") == 0 ||
                strcmp(argv[1],"--help") == 0 ) {
                return usage(0);
    } else if ( strcmp(argv[1],"-v") == 0 ||
                strcmp(argv[1],"--version") == 0 ) {
                show_version();
                return 0;
    } else {
        printf("Hi, %s.\n", argv[1]);
    }
    return 0;
}
