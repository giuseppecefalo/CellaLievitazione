#include "vars.h"
#include <stdio.h>

// Funzione per la gestione della temperatura di setpoint 
float set_temperature = 20.0f;   // NOTA: non static

extern "C" float get_var_set_temperature(void) {
    return set_temperature;
}

extern "C" void set_var_set_temperature(float value) {
    set_temperature = value;
}

extern "C" const char *get_var_set_temperature_text(void) {
    static char buf[16];
    snprintf(buf, sizeof(buf), "%.1f °C", (double)set_temperature);
    return buf;
}

// funzione per la gestione della umidità di setpoint
int32_t set_umidita = 40;   // ORA coerente

extern "C" int32_t get_var_set_umidita(void) {
    return set_umidita;
}

extern "C" void set_var_set_umidita(int32_t value) {
    set_umidita = value;
}

extern "C" const char *get_var_set_umidita_text(void) {
    static char buf[16];
    snprintf(buf, sizeof(buf), "%d %%", set_umidita);
    return buf;
}
