/**
 * @file hud_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "hud_ui_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * roboto_regular_24;
extern lv_font_t roboto_regular_24_data;
lv_font_t * roboto_bold_40;
extern lv_font_t roboto_bold_40_data;
lv_font_t * roboto_bold_150;
extern lv_font_t roboto_bold_150_data;

/*----------------
 * Images
 *----------------*/

const void * subaru_logo;
extern const void * subaru_logo_data;
const void * rotation;
extern const void * rotation_data;
const void * brightness;
extern const void * brightness_data;
const void * hud;
extern const void * hud_data;
const void * warning;
extern const void * warning_data;
const void * disconnect;
extern const void * disconnect_data;
const void * back;
extern const void * back_data;
const void * restart;
extern const void * restart_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_dark;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t engine_rpm;
lv_subject_t coolant_temp;
lv_subject_t speed;
lv_subject_t fuel_capacity;
lv_subject_t can_error;
lv_subject_t con_error;
lv_subject_t settings_brightness;
lv_subject_t settings_rotation;
lv_subject_t settings_hud;
lv_subject_t settings_restart;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void hud_ui_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'roboto_regular_24' from a C array */
    roboto_regular_24 = &roboto_regular_24_data;
    /* get font 'roboto_bold_40' from a C array */
    roboto_bold_40 = &roboto_bold_40_data;
    /* get font 'roboto_bold_150' from a C array */
    roboto_bold_150 = &roboto_bold_150_data;


    /*----------------
     * Images
     *----------------*/
    subaru_logo = &subaru_logo_data;
    rotation = &rotation_data;
    brightness = &brightness_data;
    hud = &hud_data;
    warning = &warning_data;
    disconnect = &disconnect_data;
    back = &back_data;
    restart = &restart_data;

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_dark);
        lv_style_set_bg_color(&style_dark, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_dark, 255);
        lv_style_set_text_color(&style_dark, lv_color_hex(0xffffff));
        lv_style_set_text_font(&style_dark, roboto_regular_24);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&engine_rpm, 0);
    lv_subject_init_int(&coolant_temp, 0);
    lv_subject_init_int(&speed, 0);
    lv_subject_init_int(&fuel_capacity, 0);
    lv_subject_init_int(&can_error, 0);
    lv_subject_set_min_value_int(&can_error, 0);
    lv_subject_set_max_value_int(&can_error, 1);
    lv_subject_init_int(&con_error, 1);
    lv_subject_set_min_value_int(&con_error, 0);
    lv_subject_set_max_value_int(&con_error, 1);
    lv_subject_init_int(&settings_brightness, 127);
    lv_subject_set_min_value_int(&settings_brightness, 10);
    lv_subject_set_max_value_int(&settings_brightness, 255);
    lv_subject_init_int(&settings_rotation, 0);
    lv_subject_set_min_value_int(&settings_rotation, 0);
    lv_subject_set_max_value_int(&settings_rotation, 3);
    lv_subject_init_int(&settings_hud, 0);
    lv_subject_set_min_value_int(&settings_hud, 0);
    lv_subject_set_max_value_int(&settings_hud, 3);
    lv_subject_init_int(&settings_restart, 0);
    lv_subject_set_min_value_int(&settings_restart, 0);
    lv_subject_set_max_value_int(&settings_restart, 1);

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "roboto_regular_24", roboto_regular_24);
    lv_xml_register_font(NULL, "roboto_bold_40", roboto_bold_40);
    lv_xml_register_font(NULL, "roboto_bold_150", roboto_bold_150);

    /* Register subjects */
    lv_xml_register_subject(NULL, "engine_rpm", &engine_rpm);
    lv_xml_register_subject(NULL, "coolant_temp", &coolant_temp);
    lv_xml_register_subject(NULL, "speed", &speed);
    lv_xml_register_subject(NULL, "fuel_capacity", &fuel_capacity);
    lv_xml_register_subject(NULL, "can_error", &can_error);
    lv_xml_register_subject(NULL, "con_error", &con_error);
    lv_xml_register_subject(NULL, "settings_brightness", &settings_brightness);
    lv_xml_register_subject(NULL, "settings_rotation", &settings_rotation);
    lv_xml_register_subject(NULL, "settings_hud", &settings_hud);
    lv_xml_register_subject(NULL, "settings_restart", &settings_restart);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "subaru_logo", subaru_logo);
    lv_xml_register_image(NULL, "rotation", rotation);
    lv_xml_register_image(NULL, "brightness", brightness);
    lv_xml_register_image(NULL, "hud", hud);
    lv_xml_register_image(NULL, "warning", warning);
    lv_xml_register_image(NULL, "disconnect", disconnect);
    lv_xml_register_image(NULL, "back", back);
    lv_xml_register_image(NULL, "restart", restart);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/