/* _interface.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_CORTO_PARSER && defined _MSC_VER
#define PARSER_DLL_EXPORTED __declspec(dllexport)
#elif BUILDING_CORTO_PARSER
#define CORTO_PARSER_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define CORTO_PARSER_EXPORT __declspec(dllimport)
#else
#define CORTO_PARSER_EXPORT
#endif

