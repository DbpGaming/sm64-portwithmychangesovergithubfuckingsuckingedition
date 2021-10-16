#ifndef __EXTENDED_BOUNDS_H__
#define __EXTENDED_BOUNDS_H__



//for the static assert macro
#include "macros.h"

#include "config.h"

//don't touch the stuff unless you know what you're doing!

//default value to check if the user set a proper extended bounds mode
#define LEVEL_BOUNDARY_MAX 0x0000

#if EXTENDED_BOUNDS_MODE == 0
    #undef LEVEL_BOUNDARY_MAX // Undefine the old value to avoid compiler warnings
    #define LEVEL_BOUNDARY_MAX 0x2000L
    #define CELL_SIZE          0x400
#elif EXTENDED_BOUNDS_MODE == 1
    #undef LEVEL_BOUNDARY_MAX
    #define LEVEL_BOUNDARY_MAX 0x2000L
    #define CELL_SIZE          0x200
#elif EXTENDED_BOUNDS_MODE == 2
    #undef LEVEL_BOUNDARY_MAX
    #define LEVEL_BOUNDARY_MAX 0x2000L
    #define CELL_SIZE          0x100
#elif EXTENDED_BOUNDS_MODE == 3
    #undef LEVEL_BOUNDARY_MAX
    #define LEVEL_BOUNDARY_MAX 0x4000L
    #define CELL_SIZE          0x400
#elif EXTENDED_BOUNDS_MODE == 4
    #undef LEVEL_BOUNDARY_MAX
    #define LEVEL_BOUNDARY_MAX 0x4000L
    #define CELL_SIZE          0x200
#elif EXTENDED_BOUNDS_MODE == 5
    #undef LEVEL_BOUNDARY_MAX
    #define LEVEL_BOUNDARY_MAX 0x8000L
    #define CELL_SIZE          0x400
#endif

STATIC_ASSERT(LEVEL_BOUNDARY_MAX != 0, "You must set a valid extended bounds mode!");

#define NUM_CELLS (2 * LEVEL_BOUNDARY_MAX / CELL_SIZE)

#define NOT_ENOUGH_ROOM_FOR_SURFACES (1 << 0)
#define NOT_ENOUGH_ROOM_FOR_NODES    (1 << 1)


#endif // __EXTENDED_BOUNDS_H__
