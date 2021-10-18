#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 * A catch-all file for configuring various settings
 */

// Support Rumble Pak
#define ENABLE_RUMBLE (0 || VERSION_SH)

// Screen Size Defines
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

//blj fix
#define BLJ_FIX (0 || VERSION_SH)

// Border Height Define for NTSC Versions
#ifdef TARGET_N64
#define BORDER_HEIGHT 30
#else
// What's the point of having a border?
#define BORDER_HEIGHT 0
#endif

// Enable debug level select
//#define DEBUG_LEVEL_SELECT

// skip peach cutscene
#define SKIP_PEACH

//hud locations
#define HUD_TOP_Y 210-BORDER_HEIGHT
#define HUD_BOTTOM_Y 16+BORDER_HEIGHT

//coin star
#define COIN_STAR 100

// animated red coin hud
// #define ANIMATED_RED_COIN_HUD

/*
    Better Extended Bounds by anonymous_moose
        Thanks to someone2639 for the shiftable segments patch
        Thanks to Wiseguy for the Surface Pool Full error code and 4x bounds fix

    0: Regular bounds
        Same as vanilla sm64, boundaries are (-8192 to 8191)
        16x16 collision cells.
    1: Regular bounds (performance)
        Same boundaries as vanilla (-8192 to 8191), but with quadruple the amount of collision cells
        Trades more RAM usage for faster collision calculations.
        32x32 collision cells.
    2: Regular bounds (double performance)
        Same boundaries as vanilla (-8192 to 8191), but with 16x the amount of collision cells
        Trades more RAM usage for faster collision calculations.
        64x64 collision cells.
    3: 4x extended bounds (refered to 2x in most tools and the blender template)
        level boundaries are twice as big (-16384 to 16383)
        Collision calculations remain as fast as vanilla, at the cost of using more RAM.
        32x32 collision cells.
    4: 4x extended bounds (performance) (refered to 2x in most tools and the blender template)
        Same boundaries as 2x extended bounds (-16384 to 16383), but with twice the amount of collision cells
        Trades more RAM usage for faster collision calculations.
        64x64 collision cells.
    5: 16x extended bounds (refered to 4x in most tools and the blender template)
        level boundaries are 4 times as big (-32768 to 32767)
        Collision calculations remain as fast as vanilla, at the cost of using far more RAM (16 times vanilla).
        64x64 collision cells.

    If you see "SURFACE POOL FULL" or "SURFACE NODE POOL FULL" in game, you should increase
    SURFACE_POOL_SIZE or SURFACE_NODE_POOL_SIZE, respectively, or reduce the amount of
    collision surfaces in your level.
*/

//set this to the extended bounds mode you want, then do "make clean".
#define EXTENDED_BOUNDS_MODE 2

//the maximum amount of collision surfaces (static and dynamic combined)
//8200 should work fine for a 2x extended stage, the vanilla value is 2300
#define SURFACE_POOL_SIZE 16000

//make this approximately (amount of collision cells) + (SURFACE_POOL_SIZE * 3)
//22000 should work fine for a 2x extended stage, the vanilla value is 7000
#define SURFACE_NODE_POOL_SIZE SURFACE_POOL_SIZE * 3

#endif // CONFIG_H
