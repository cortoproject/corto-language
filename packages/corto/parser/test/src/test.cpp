/* $CORTO_GENERATED
 *
 * test.cpp
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

int testMain(int argc, char* argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("corto/parser", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_llSize(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
/* $end */
}
