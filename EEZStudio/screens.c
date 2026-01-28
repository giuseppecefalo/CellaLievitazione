#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Intestazione
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.intestazione = obj;
            lv_obj_set_pos(obj, 100, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Cella lievitazione");
        }
        {
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 62, 41);
            lv_obj_set_size(obj, 197, 199);
            lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
            lv_scale_set_range(obj, 0, 24);
            lv_scale_set_total_tick_count(obj, 25);
            lv_scale_set_major_tick_every(obj, 1);
            lv_scale_set_label_show(obj, true);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff5ad75f), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff5ad75f), LV_PART_ITEMS | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Cavaliere
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.cavaliere = obj;
                    lv_obj_set_pos(obj, 0, 77);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "-");
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xfff50901), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // TempLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.temp_label = obj;
                    lv_obj_set_pos(obj, 64, 69);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "22.6");
                    lv_obj_add_event_cb(obj, action_temp_label_update_event_handler, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff212121), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 72, 107);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Temp°C");
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 21, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Min");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 276, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Max");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // T_Max
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.t_max = obj;
            lv_obj_set_pos(obj, 264, 47);
            lv_obj_set_size(obj, 47, 30);
            lv_roller_set_options(obj, "19.5\n20.0\n20.5\n21.0\n21.5\n22.0\n22.5\n23.0\n23.5\n24.0\n24.5\n25.0\n", LV_ROLLER_MODE_NORMAL);
            lv_obj_add_event_cb(obj, action_temp_max_setting, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xfff60303), LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // T_Min
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.t_min = obj;
            lv_obj_set_pos(obj, 10, 47);
            lv_obj_set_size(obj, 47, 30);
            lv_roller_set_options(obj, "15.0\n15.5\n16.0\n16.5\n17.0\n17.5\n18.0\n18.5\n19.0\n19.5", LV_ROLLER_MODE_NORMAL);
            lv_obj_add_event_cb(obj, action_temp_min_setting, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff0f42d4), LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3), LV_PART_SELECTED | LV_STATE_DEFAULT);
        }
        {
            // ID_CLOCK_LABEL
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.id_clock_label = obj;
            lv_obj_set_pos(obj, 194, 2);
            lv_obj_set_size(obj, 121, 12);
            lv_label_set_text(obj, "Lun. 01/01/2000 - 12:00");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffcf2727), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Fiamma
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.fiamma = obj;
            lv_obj_set_pos(obj, 139, 171);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_fiamma);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // WiFiOFF
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wi_fi_off = obj;
            lv_obj_set_pos(obj, 3, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
        }
        {
            // AutoBtn
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            objects.auto_btn = obj;
            lv_obj_set_pos(obj, 269, 110);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 37);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_auto, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &img_manual, NULL);
            lv_obj_add_event_cb(obj, action_img_btn_auto_togle_esclusivo, LV_EVENT_PRESSED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            // SetupButton
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            objects.setup_button = obj;
            lv_obj_set_pos(obj, 271, 197);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 35);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_setup_icon, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &img_setup_icon, NULL);
            lv_obj_add_event_cb(obj, action_go_to_program_page, LV_EVENT_PRESSED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            // programmazione
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.programmazione = obj;
            lv_obj_set_pos(obj, 3, 219);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Programmazione Test");
        }
        {
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            lv_obj_set_pos(obj, 3, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 11);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_wi_fi_on, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &img_wi_fi_red, NULL);
            lv_obj_add_event_cb(obj, action_wi_fi_page_selet, LV_EVENT_PRESSED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            // WiFi_x
            lv_obj_t *obj = lv_img_create(parent_obj);
            objects.wi_fi_x = obj;
            lv_obj_set_pos(obj, 3, 3);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_x);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_program() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.program = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            // giorno
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.giorno = obj;
            lv_obj_set_pos(obj, 131, 17);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Lun");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Btn_00:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_00_00 = obj;
            lv_obj_set_pos(obj, 6, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_00:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_00_30 = obj;
            lv_obj_set_pos(obj, 45, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)1);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "00:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_01:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_01_00 = obj;
            lv_obj_set_pos(obj, 84, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)2);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "01:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_01:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_01_30 = obj;
            lv_obj_set_pos(obj, 123, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)3);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "01:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_02:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_02_00 = obj;
            lv_obj_set_pos(obj, 162, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)4);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "02:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_02:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_02_30 = obj;
            lv_obj_set_pos(obj, 201, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)5);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "02:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_03:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_03_00 = obj;
            lv_obj_set_pos(obj, 240, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)6);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "03:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_03:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_03_30 = obj;
            lv_obj_set_pos(obj, 279, 62);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)7);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, -1, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "03:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_04:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_04_00 = obj;
            lv_obj_set_pos(obj, 6, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)8);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "04:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_08:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_08_00 = obj;
            lv_obj_set_pos(obj, 6, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)16);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "08:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_12:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_12_00 = obj;
            lv_obj_set_pos(obj, 6, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)24);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_16:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_16_00 = obj;
            lv_obj_set_pos(obj, 6, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)32);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_20:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_20_00 = obj;
            lv_obj_set_pos(obj, 6, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)40);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "20:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_04:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_04_30 = obj;
            lv_obj_set_pos(obj, 44, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)9);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "04:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_05:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_05_00 = obj;
            lv_obj_set_pos(obj, 84, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)10);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "05:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_05:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_05_30 = obj;
            lv_obj_set_pos(obj, 123, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)11);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "05:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_06:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_06_00 = obj;
            lv_obj_set_pos(obj, 162, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)12);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "06:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_06:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_06_30 = obj;
            lv_obj_set_pos(obj, 201, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)13);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "06:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_07:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_07_00 = obj;
            lv_obj_set_pos(obj, 240, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)14);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "07:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_07:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_07_30 = obj;
            lv_obj_set_pos(obj, 279, 90);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)15);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "07:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_08_30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_08_30 = obj;
            lv_obj_set_pos(obj, 44, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)17);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "08:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_09:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_09_30 = obj;
            lv_obj_set_pos(obj, 123, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)19);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "09:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_10:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_10_00 = obj;
            lv_obj_set_pos(obj, 162, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)20);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "10:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_10:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_10_30 = obj;
            lv_obj_set_pos(obj, 201, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)21);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "10:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_11:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_11_00 = obj;
            lv_obj_set_pos(obj, 240, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)22);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "11:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_11:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_11_30 = obj;
            lv_obj_set_pos(obj, 279, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)23);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "11:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_09:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_09_00 = obj;
            lv_obj_set_pos(obj, 84, 118);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)18);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "09:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_12:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_12_30 = obj;
            lv_obj_set_pos(obj, 44, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)25);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "12:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_13:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_13_30 = obj;
            lv_obj_set_pos(obj, 123, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)27);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "13:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_14:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_14_00 = obj;
            lv_obj_set_pos(obj, 162, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)28);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "14:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_14:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_14_30 = obj;
            lv_obj_set_pos(obj, 201, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)29);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "14:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_15:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_15_00 = obj;
            lv_obj_set_pos(obj, 240, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)30);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "15:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_15:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_15_30 = obj;
            lv_obj_set_pos(obj, 279, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)31);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "15:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_13:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_13_00 = obj;
            lv_obj_set_pos(obj, 84, 146);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)26);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "13:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_16:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_16_30 = obj;
            lv_obj_set_pos(obj, 44, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)33);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "16:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_17:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_17_30 = obj;
            lv_obj_set_pos(obj, 123, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)35);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "17:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_18:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_18_00 = obj;
            lv_obj_set_pos(obj, 162, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)36);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "18:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_18:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_18_30 = obj;
            lv_obj_set_pos(obj, 201, 176);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)37);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "18:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_19:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_19_30 = obj;
            lv_obj_set_pos(obj, 279, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)39);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "19:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_17:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_17_00 = obj;
            lv_obj_set_pos(obj, 84, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)34);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "17:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_19:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_19_00 = obj;
            lv_obj_set_pos(obj, 240, 175);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)38);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "19:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_20:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_20_30 = obj;
            lv_obj_set_pos(obj, 44, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)41);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "20:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_21:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_21_30 = obj;
            lv_obj_set_pos(obj, 123, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)43);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "21:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_22:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_22_00 = obj;
            lv_obj_set_pos(obj, 162, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)44);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "22:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_22:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_22_30 = obj;
            lv_obj_set_pos(obj, 201, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)45);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "22:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_23:30
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_23_30 = obj;
            lv_obj_set_pos(obj, 279, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)47);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "23:30");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_21:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_21_00 = obj;
            lv_obj_set_pos(obj, 84, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)42);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "21:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Btn_23:00
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_23_00 = obj;
            lv_obj_set_pos(obj, 240, 202);
            lv_obj_set_size(obj, 36, 22);
            lv_obj_add_event_cb(obj, action_time_select, LV_EVENT_LONG_PRESSED, (void *)46);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "23:00");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // Avanti
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            objects.avanti = obj;
            lv_obj_set_pos(obj, 209, 16);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 32);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_avanti, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &img_avanti, NULL);
            lv_obj_add_event_cb(obj, action_giorno_avanti, LV_EVENT_PRESSED, (void *)0);
        }
        {
            // Home
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            objects.home = obj;
            lv_obj_set_pos(obj, 0, 3);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 32);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_home, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, NULL, &img_home_red, NULL);
            lv_obj_add_event_cb(obj, action_go_home, LV_EVENT_LONG_PRESSED, (void *)0);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        }
        {
            // ID_CLOCK_LABEL_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.id_clock_label_2 = obj;
            lv_obj_set_pos(obj, 194, 2);
            lv_obj_set_size(obj, 121, 12);
            lv_label_set_text(obj, "Lun. 01/01/2000 - 12:00");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe6065c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_program();
}

void tick_screen_program() {
}

void create_screen_wi_fi_select() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.wi_fi_select = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // RetiDisponibili
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.reti_disponibili = obj;
            lv_obj_set_pos(obj, 60, 8);
            lv_obj_set_size(obj, 200, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Reti disponibili");
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // RollerWiFi
            lv_obj_t *obj = lv_roller_create(parent_obj);
            objects.roller_wi_fi = obj;
            lv_obj_set_pos(obj, 10, 37);
            lv_obj_set_size(obj, 302, 50);
            lv_roller_set_options(obj, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);
            lv_obj_add_event_cb(obj, action_wi_fi_selectef_from_list, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // WiFiPass
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.wi_fi_pass = obj;
            lv_obj_set_pos(obj, 47, 91);
            lv_obj_set_size(obj, 188, 35);
            lv_textarea_set_max_length(obj, 80);
            lv_textarea_set_placeholder_text(obj, "Password");
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, true);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 10, 132);
            lv_obj_set_size(obj, 300, 108);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // BtnPassView
            lv_obj_t *obj = lv_imagebutton_create(parent_obj);
            objects.btn_pass_view = obj;
            lv_obj_set_pos(obj, 11, 93);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 30);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &img_occhio, NULL);
            lv_imagebutton_set_src(obj, LV_IMAGEBUTTON_STATE_PRESSED, NULL, &img_occhio, NULL);
            lv_obj_add_event_cb(obj, action_password_view, LV_EVENT_PRESSED, (void *)0);
        }
        {
            // BtnWiFiSend
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.btn_wi_fi_send = obj;
            lv_obj_set_pos(obj, 243, 93);
            lv_obj_set_size(obj, 69, 30);
            lv_obj_add_event_cb(obj, action_wi_fi_register, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // WiFiBtnSave
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.wi_fi_btn_save = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Save");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.obj1, objects.wi_fi_pass);
    
    tick_screen_wi_fi_select();
}

void tick_screen_wi_fi_select() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_program,
    tick_screen_wi_fi_select,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_program();
    create_screen_wi_fi_select();
}
