/* ic.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_IC_H
#define CORTO_IC_H

#include <corto/corto.h>
#include <corto/ic/_interface.h>
/* $header() */
#include "corto/vm/vm.h"
/* $end */

#include <corto/ic/_type.h>
#include <corto/ic/_api.h>
#include <corto/ic/_meta.h>

#include <corto/vm/vm.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_IC_EXPORT ic_opKind _ic_opKindFromOperator(
    corto_operatorKind _operator);
#define ic_opKindFromOperator(_operator) _ic_opKindFromOperator(_operator)
#include <corto/ic/accumulator.h>
#include <corto/ic/address.h>
#include <corto/ic/element.h>
#include <corto/ic/function.h>
#include <corto/ic/label.h>
#include <corto/ic/literal.h>
#include <corto/ic/member.h>
#include <corto/ic/node.h>
#include <corto/ic/object.h>
#include <corto/ic/op.h>
#include <corto/ic/program.h>
#include <corto/ic/scope.h>
#include <corto/ic/storage.h>
#include <corto/ic/variable.h>

#ifdef __cplusplus
}
#endif
#endif

