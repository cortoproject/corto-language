/* $CORTO_GENERATED
 *
 * cx.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <driver/ext/cx/cx.h>
int cx_loadFile(corto_string file, int argc, char* argv[], void* ctx) {
    return ast_loadFile(file, argc, argv);
}

int cortomain(int argc, char *argv[]) {

    corto_load_register("cx", cx_loadFile, NULL);

    return 0;
}
