#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <string.h>


#define NEW(type, size) ({ \
    type *bosta = malloc(sizeof(type)*size); \
    bzero(bosta, sizeof(type)*size); \
    bosta;\
})

#endif // UTILS_H
