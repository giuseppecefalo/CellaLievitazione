#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_setup_icon;
extern const lv_img_dsc_t img_fiamma;
extern const lv_img_dsc_t img_wi_fi_on;
extern const lv_img_dsc_t img_wi_fi_off;
extern const lv_img_dsc_t img_auto;
extern const lv_img_dsc_t img_manual;
extern const lv_img_dsc_t img_ritorno_black;
extern const lv_img_dsc_t img_ritorno_red;
extern const lv_img_dsc_t img_avanti;
extern const lv_img_dsc_t img_indietro;
extern const lv_img_dsc_t img_home;
extern const lv_img_dsc_t img_home_red;
extern const lv_img_dsc_t img_wi_fi_red;
extern const lv_img_dsc_t img_occhio;
extern const lv_img_dsc_t img_x;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[15];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/