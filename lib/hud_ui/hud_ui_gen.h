/**
 * @file hud_ui_gen.h
 */

#ifndef HUD_UI_GEN_H
#define HUD_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_dark;

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * roboto_regular_24;

extern lv_font_t * roboto_bold_40;

extern lv_font_t * roboto_bold_150;

/*----------------
 * Images
 *----------------*/

extern const void * subaru_logo;
extern const void * rotation;
extern const void * brightness;
extern const void * hud;
extern const void * warning;
extern const void * disconnect;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t engine_rpm;
extern lv_subject_t coolant_temp;
extern lv_subject_t speed;
extern lv_subject_t fuel_capacity;
extern lv_subject_t can_error;
extern lv_subject_t con_error;
extern lv_subject_t settings_brightness;
extern lv_subject_t settings_rotation;
extern lv_subject_t settings_hud;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void hud_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/settings_item/settings_item_gen.h"
#include "screens/boot_gen.h"
#include "screens/dashboard_gen.h"
#include "screens/settings_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*HUD_UI_GEN_H*/