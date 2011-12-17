#include <stdio.h>
#include <getopt.h>

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
    int ch;

    /* options descriptor */
    static struct option longopts[] = {
            { "help",     no_argument,  NULL, 'h' },
            { "version",  no_argument,  NULL, 'v' },
            { NULL,       0,            NULL, 0 }
    };

    while ((ch = getopt_long(argc, argv, "hv", longopts, NULL)) != -1)
            switch (ch) {
            case 'v':
                    show_version();
                    return 0;
            case 'h':
                    return usage(0);
            default:
                    return usage(1);
    }
    argc -= optind;
    argv += optind;

    /* unknown arguments */
    if (argc > 0) {
        return usage(1);
    }

    printf ("Hello world.\n");
    return 0;
}


/*
 * vim: et ts=4 sw=4
 */
