/* vm/_project.h
 *
 * This file contains generated code. Do not modify!
 */

#if BUILDING_VM && defined _MSC_VER
#define VM_DLL_EXPORTED __declspec(dllexport)
#elif BUILDING_VM
#define VM_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define VM_EXPORT __declspec(dllimport)
#else
#define VM_EXPORT
#endif

