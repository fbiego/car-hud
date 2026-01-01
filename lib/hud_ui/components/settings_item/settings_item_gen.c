/**
 * @file settings_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_item_gen.h"
#include "hud_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * settings_item_create(lv_obj_t * parent, const void * icon)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_item;
    static lv_style_t style_slider;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_item);
        lv_style_set_width(&style_item, 360);
        lv_style_set_height(&style_item, 100);
        lv_style_set_pad_all(&style_item, 0);
        lv_style_set_pad_left(&style_item, 10);
        lv_style_set_pad_right(&style_item, 10);
        lv_style_set_border_width(&style_item, 1);
        lv_style_set_text_color(&style_item, lv_color_hex3(0xfff));
        lv_style_set_border_side(&style_item, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_radius(&style_item, 0);
        lv_style_set_bg_opa(&style_item, 0);
        lv_style_set_layout(&style_item, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_item, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_item, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_slider);
        lv_style_set_width(&style_slider, 200);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "settings_item_#");

    lv_obj_add_style(lv_obj_0, &style_item, 0);
    lv_obj_t * lv_image_0 = lv_image_create(lv_obj_0);
    lv_image_set_src(lv_image_0, icon);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

