/* _load.cpp
 *
 * This file is generated. Do not modify.
 */

#include <corto/parser/parser.h>

int parser_load(void);
int parserMain(int argc, char* argv[]);

#ifdef __cplusplus
extern "C"
#endif
CORTO_PARSER_EXPORT int cortomain(int argc, char* argv[]) {
    if (corto_load("/corto", 0, NULL)) return -1;
    if (parser_load()) return -1;
    if (parserMain(argc, argv)) return -1;
    return 0;
}

