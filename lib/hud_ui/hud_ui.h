/**
 * @file hud_ui.h
 */

#ifndef HUD_UI_H
#define HUD_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "hud_ui_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void hud_ui_init(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HUD_UI_H*/