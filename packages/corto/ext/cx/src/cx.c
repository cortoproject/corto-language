/* $CORTO_GENERATED
 *
 * cx.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <driver/ext/cx/cx.h>

/* $header() */
int cx_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    return ast_loadFile(file, argc, argv);
}
/* $end */

int cxMain(int argc, char *argv[]) {
/* $begin(main) */

    corto_load_register("cx", cx_loadFile, NULL);

    return 0;
/* $end */
}
