#include <stdio.h>
#include "version.h"

#include <locale.h>
#include <libintl.h>
#define _(String) gettext (String)
#define gettext_noop(String) String
#define N_(String) gettext_noop (String)

int usage(int code)
{
    printf(_("Hello world example %s\n"
           "Copyright Jiang Xin <jiangxin AT ossxp DOT com>, 2009.\n"
           "\n"
           "Usage:\n"
           "    hello\n"
           "            say hello to the world.\n\n"
           "    hello -v, --version\n"
           "            show version.\n\n"
           "    hello -h, -help\n"
           "            this help screen.\n\n"), _VERSION);
    return code;
}

void show_version(void)
{
    printf(_("hello version %s\n"), _VERSION );
}

int
main(int argc, char **argv)
{
    setlocale( LC_ALL, "" );
    bindtextdomain("helloworld","locale");
    textdomain("helloworld");

    if (argc == 1) {
        printf (_("Hello world.\n"));
    } else if ( strcmp(argv[1],"-h") == 0 ||
                strcmp(argv[1],"--help") == 0 ) {
                return usage(0);
    } else if ( strcmp(argv[1],"-v") == 0 ||
                strcmp(argv[1],"--version") == 0 ) {
                show_version();
                return 0;
    } else {
        return usage(1);
    }
    return 0;
}
