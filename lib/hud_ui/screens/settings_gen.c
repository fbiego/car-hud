/**
 * @file settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "settings_gen.h"
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

lv_obj_t * settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_cont;
    static lv_style_t style_dropdown;
    static lv_style_t style_slider;
    static lv_style_t style_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 360);
        lv_style_set_height(&style_cont, 300);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_pad_row(&style_cont, 0);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_cont, LV_FLEX_FLOW_COLUMN);

        lv_style_init(&style_dropdown);
        lv_style_set_border_width(&style_dropdown, 0);
        lv_style_set_radius(&style_dropdown, 5);

        lv_style_init(&style_slider);
        lv_style_set_width(&style_slider, 200);

        lv_style_init(&style_pressed);
        lv_style_set_bg_color(&style_pressed, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_pressed, 100);
        lv_style_set_radius(&style_pressed, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "settings_#");

    lv_obj_add_style(lv_obj_0, &style_dark, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_scrollbar_mode(lv_obj_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * settings_back = settings_item_create(lv_obj_1, back);
    lv_obj_set_name(settings_back, "settings_back");
    lv_obj_add_style(settings_back, &style_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_0 = lv_label_create(settings_back);
    lv_obj_set_flex_grow(lv_label_0, 1);
    lv_label_set_text(lv_label_0, "Back to Main Screen");
    
    lv_obj_t * settings_item_0 = settings_item_create(lv_obj_1, brightness);
    lv_obj_set_style_pad_column(settings_item_0, 50, 0);
    lv_obj_t * lv_slider_0 = lv_slider_create(settings_item_0);
    lv_slider_set_min_value(lv_slider_0, 10);
    lv_slider_set_max_value(lv_slider_0, 255);
    lv_slider_bind_value(lv_slider_0, &settings_brightness);
    lv_obj_set_ext_click_area(lv_slider_0, 50);
    lv_obj_add_style(lv_slider_0, &style_slider, 0);
    
    lv_obj_t * settings_item_1 = settings_item_create(lv_obj_1, hud);
    lv_obj_t * lv_label_1 = lv_label_create(settings_item_1);
    lv_obj_set_flex_grow(lv_label_1, 1);
    lv_label_set_text(lv_label_1, "HUD Mode");
    
    lv_obj_t * lv_dropdown_0 = lv_dropdown_create(settings_item_1);
    lv_dropdown_set_options(lv_dropdown_0, "OFF\nX Flip\nY Flip\nXY Flip");
    lv_dropdown_bind_value(lv_dropdown_0, &settings_hud);
    lv_dropdown_set_symbol(lv_dropdown_0, NULL);
    lv_obj_add_style(lv_dropdown_0, &style_dropdown, 0);
    lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(lv_dropdown_0);
    lv_obj_set_style_pad_all(lv_dropdown_0, 10, 0);
    lv_obj_add_style(lv_dropdown_list_0, &style_dropdown, 0);
    
    lv_obj_t * settings_item_2 = settings_item_create(lv_obj_1, restart);
    lv_obj_t * lv_label_2 = lv_label_create(settings_item_2);
    lv_obj_set_flex_grow(lv_label_2, 1);
    lv_label_set_text(lv_label_2, "Restart on Disconnect");
    
    lv_obj_t * lv_switch_0 = lv_switch_create(settings_item_2);
    lv_obj_bind_checked(lv_switch_0, &settings_restart);
    
    lv_obj_t * settings_restart = settings_item_create(lv_obj_1, restart);
    lv_obj_set_name(settings_restart, "settings_restart");
    lv_obj_add_style(settings_restart, &style_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_3 = lv_label_create(settings_restart);
    lv_obj_set_flex_grow(lv_label_3, 1);
    lv_label_set_text(lv_label_3, "Restart Now");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

