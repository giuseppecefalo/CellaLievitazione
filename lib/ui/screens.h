#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *program;
    lv_obj_t *wi_fi_select;
    lv_obj_t *temperatura;
    lv_obj_t *umidita;
    lv_obj_t *intestazione;
    lv_obj_t *id_clock_label;
    lv_obj_t *wi_fi_off;
    lv_obj_t *auto_btn;
    lv_obj_t *setup_button;
    lv_obj_t *programmazione;
    lv_obj_t *wi_fi_x;
    lv_obj_t *wi_fi_name;
    lv_obj_t *temp_label;
    lv_obj_t *umidita_label;
    lv_obj_t *t_cella_label;
    lv_obj_t *temperatura_interna;
    lv_obj_t *umidita_interna;
    lv_obj_t *t_su;
    lv_obj_t *t_giu;
    lv_obj_t *h_su;
    lv_obj_t *h_giu;
    lv_obj_t *giorno;
    lv_obj_t *btn_00_00;
    lv_obj_t *btn_00_30;
    lv_obj_t *btn_01_00;
    lv_obj_t *btn_01_30;
    lv_obj_t *btn_02_00;
    lv_obj_t *btn_02_30;
    lv_obj_t *btn_03_00;
    lv_obj_t *btn_03_30;
    lv_obj_t *btn_04_00;
    lv_obj_t *btn_08_00;
    lv_obj_t *btn_12_00;
    lv_obj_t *btn_16_00;
    lv_obj_t *btn_20_00;
    lv_obj_t *btn_04_30;
    lv_obj_t *btn_05_00;
    lv_obj_t *btn_05_30;
    lv_obj_t *btn_06_00;
    lv_obj_t *btn_06_30;
    lv_obj_t *btn_07_00;
    lv_obj_t *btn_07_30;
    lv_obj_t *btn_08_30;
    lv_obj_t *btn_09_30;
    lv_obj_t *btn_10_00;
    lv_obj_t *btn_10_30;
    lv_obj_t *btn_11_00;
    lv_obj_t *btn_11_30;
    lv_obj_t *btn_09_00;
    lv_obj_t *btn_12_30;
    lv_obj_t *btn_13_30;
    lv_obj_t *btn_14_00;
    lv_obj_t *btn_14_30;
    lv_obj_t *btn_15_00;
    lv_obj_t *btn_15_30;
    lv_obj_t *btn_13_00;
    lv_obj_t *btn_16_30;
    lv_obj_t *btn_17_30;
    lv_obj_t *btn_18_00;
    lv_obj_t *btn_18_30;
    lv_obj_t *btn_19_30;
    lv_obj_t *btn_17_00;
    lv_obj_t *btn_19_00;
    lv_obj_t *btn_20_30;
    lv_obj_t *btn_21_30;
    lv_obj_t *btn_22_00;
    lv_obj_t *btn_22_30;
    lv_obj_t *btn_23_30;
    lv_obj_t *btn_21_00;
    lv_obj_t *btn_23_00;
    lv_obj_t *avanti;
    lv_obj_t *home;
    lv_obj_t *id_clock_label_2;
    lv_obj_t *reti_disponibili;
    lv_obj_t *roller_wi_fi;
    lv_obj_t *wi_fi_pass;
    lv_obj_t *btn_pass_view;
    lv_obj_t *btn_wi_fi_send;
    lv_obj_t *wi_fi_btn_save;
    lv_obj_t *obj0;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_PROGRAM = 2,
    SCREEN_ID_WI_FI_SELECT = 3,
};

void create_screen_main();
void tick_screen_main();

void create_screen_program();
void tick_screen_program();

void create_screen_wi_fi_select();
void tick_screen_wi_fi_select();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/