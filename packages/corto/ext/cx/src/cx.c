/* $CORTO_GENERATED
 *
 * cx.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/ext/cx/cx.h>

/* $header() */
int cx_loadFile(corto_string file, int argc, char* argv[], void* udata) {
    return ast_loadFile(file, argc, argv);
}
/* $end */

int cxMain(int argc, char *argv[]) {
/* $begin(main) */

    corto_loaderRegister("cx", cx_loadFile, NULL);

    return 0;
/* $end */
}
