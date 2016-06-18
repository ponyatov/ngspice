#ifndef _KLU_BINDING_H
#define _KLU_BINDING_H

#define XFOO(ptr, binding, a, b)                                        \
    if ((here->a != 0) && (here->b != 0)) {                             \
        i = here->ptr ;                                                 \
        matched = (BindElement *) bsearch (&i, BindStruct, nz, sizeof(BindElement), BindCompare) ; \
        here->binding = matched ;                                       \
        here->ptr = matched->CSC ;                                      \
    }

#define BFOO(ptr, binding, a, b)                        \
    if ((here->a != 0) && (here->b != 0))               \
        here->ptr = here->binding->CSC_Complex ;

#define CFOO(ptr, binding, a, b)                \
    if ((here->a != 0) && (here->b != 0))       \
        here->ptr = here->binding->CSC ;

#endif
