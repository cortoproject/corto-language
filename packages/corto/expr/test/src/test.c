/* $CORTO_GENERATED
 *
 * test.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int cortomain(int argc, char *argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("corto/expr", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_ll_count(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
/* $end */
}
