#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_SET_TEMPERATURE = 0,
    FLOW_GLOBAL_VARIABLE_SET_TEMPERATURE_TEXT = 1,
    FLOW_GLOBAL_VARIABLE_SET_UMIDITA = 2,
    FLOW_GLOBAL_VARIABLE_SET_UMIDITA_TEXT = 3
};

// Native global variables

extern float get_var_set_temperature();
extern void set_var_set_temperature(float value);
extern const char *get_var_set_temperature_text();
extern void set_var_set_temperature_text(const char *value);
extern int32_t get_var_set_umidita();
extern void set_var_set_umidita(int32_t value);
extern const char *get_var_set_umidita_text();
extern void set_var_set_umidita_text(const char *value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/