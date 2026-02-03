#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void action_temp_label_update_event_handler(lv_event_t * e);
extern void action_temp_min_setting(lv_event_t * e);
extern void action_temp_max_setting(lv_event_t * e);
extern void action_img_btn_auto_togle_esclusivo(lv_event_t * e);
extern void action_time_select(lv_event_t * e);
extern void action_go_home(lv_event_t * e);
extern void action_giorno_avanti(lv_event_t * e);
extern void action_go_to_program_page(lv_event_t * e);
extern void action_wi_fi_page_selet(lv_event_t * e);
extern void action_wi_fi_selectef_from_list(lv_event_t * e);
extern void action_password_view(lv_event_t * e);
extern void action_wi_fi_register(lv_event_t * e);
extern void action_go_programmazione(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/