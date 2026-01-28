#include "actions.h"
#include "screens.h"
#include "ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Dichiarazione delle funzioni definita in C++ (main)
#ifdef __cplusplus
extern "C" {
#endif

void connect_to_wifi(const char* ssid, const char* password);

#ifdef __cplusplus
}
#endif

// Dichiarazioni funzioni
void init_slot_buttons(void);
void aggiorna_button_program_page(void);
void salva_programmazione(void);
void scanWiFi(void);

// Callback per impostazione della temperatura minima
extern float tMin;
// Callback per impostazione della temperatura massima
extern float tMax;

void action_temp_min_setting(lv_event_t * e) {
    char selected_str[8];
//    lv_roller_get_selected_str(objects.t_min, selected_str, sizeof(selected_str));

    // Usa atof per gestire i decimali
    float value = atof(selected_str);
    tMin = value;

    // Controlla la coerenza con tMax
    if (tMin > tMax) {
        tMin = tMax - 0.5f;
        if (tMin < 15.0f) tMin = 15.0f;
    }

     // (Facoltativo) salva subito in flash:
    // salva_programmazione();
}

void action_temp_max_setting(lv_event_t * e) {
    char selected_str[8];
//    lv_roller_get_selected_str(objects.t_max, selected_str, sizeof(selected_str));

    // Usa atof per gestire i decimali
    float value = atof(selected_str);
    tMax = value;

    // Controlla la coerenza con tMax
    if (tMax < tMin){
        tMax = tMin + 1;
        value = tMax;
    }

     // (Facoltativo) salva subito in flash:
    // salva_programmazione();
}

// Callback per aggiornamento della temperatura ed accensione caldaia
extern float tempC;
extern bool accensioneCaldaia;

void action_temp_label_update_event_handler(lv_event_t * e) {
    char tempStr[32];
//    snprintf(tempStr, sizeof(tempStr), "%.1f °C", tempC);
    snprintf(tempStr, sizeof(tempStr), "%.1f", tempC);
//    lv_label_set_text(objects.temp_label, tempStr); 
    /*
    // Imposta l'accensione e lo spegnimento della caldaia
    if (tempC < (tMax + 0.2)) {
    //    accensioneCaldaia = 1;
    //    lv_obj_clear_flag(objects.fiamma, LV_OBJ_FLAG_HIDDEN);  // Rendi visibile l'oggetto Fiamma
        // Attiva lo switch di accensione
    //    lv_obj_add_state(objects.button_accensione, LV_STATE_CHECKED);
    } else {
    //    accensioneCaldaia = 0;
    //    lv_obj_add_flag(objects.fiamma, LV_OBJ_FLAG_HIDDEN);    // Rendi invisibile l'oggetto Fiamma
        // Disattiva lo switch di accensione
    //    lv_obj_clear_state(objects.button_accensione, LV_STATE_CHECKED);
    }  
    */
}

// Callback per aggiornamento di imgbutton manuale
extern bool programAccensione;
extern void gestisciAccensioneCaldaia();

void action_img_btn_auto_togle_esclusivo(lv_event_t * e){
    lv_obj_t * obj = lv_event_get_target(e);

    if (lv_obj_has_state(obj, LV_STATE_CHECKED)) {
        programAccensione = true;  // Se il pulsante è CHECKED → programAccensione = false
    } else {
        programAccensione = false; // Se il pulsante è RELEASED → programAccensione = true
    }
    gestisciAccensioneCaldaia();
}

//extern previous_page;
extern lv_obj_t *previous_page;

void action_go_to_program_page(lv_event_t * e) {
    // memorizza la pagina attuale
    previous_page = lv_scr_act();  // Salva schermata attuale
    // aggiorna l'array dei buttons
    init_slot_buttons();
    // aggiorna lo stato dei button della pagina
     aggiorna_button_program_page();
    // Passa alla pagina Program
    lv_scr_load(objects.program);
}

void action_back_page(lv_event_t * e){
    if (previous_page != NULL) {
        lv_scr_load(previous_page);
        previous_page = NULL; // opzionale: resetta
    }
}

void action_programming_day_call(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btnm = lv_event_get_target(e);

    if(code == LV_EVENT_PRESSED) {
        uint16_t btn_id = lv_btnmatrix_get_selected_btn(btnm);
                lv_scr_load(objects.program);
    }
}

extern bool time_selected[7][48];
//extern int current_day;
extern uint8_t giorno_corrente;


void action_time_select(lv_event_t * e) {
    if (lv_event_get_code(e) != LV_EVENT_LONG_PRESSED) return;

    lv_obj_t * btn = lv_event_get_target(e);
    uint8_t index = (uint8_t)(intptr_t)lv_event_get_user_data(e);

    // Alterna stato nella matrice
//    time_selected[current_day][index] = !time_selected[current_day][index];
    time_selected[giorno_corrente][index] = !time_selected[giorno_corrente][index];

    // Imposta il colore in base allo stato
//    bool state = time_selected[current_day][index];
    bool state = time_selected[giorno_corrente][index];

    lv_color_t color = state
        ? lv_palette_main(LV_PALETTE_RED)
        : lv_palette_main(LV_PALETTE_BLUE);

    lv_obj_set_style_bg_color(btn, color, 0);

    // 🔍 Debug: stampa stato, colore e puntatore del pulsante
    printf("[DEBUG] Giorno %d, Slot %02d → Stato: %s, Colore: %s, Btn: %p\n",
           giorno_corrente, // current_day,
           index,
           state ? "ON" : "OFF",
           state ? "RED" : "BLUE",
           (void *)btn);

           // colora di giallo un singolo button con user data = 10
        //   lv_obj_set_style_bg_color(lv_obj_get_child(lv_scr_act(), 10), lv_palette_main(LV_PALETTE_YELLOW), 0);
           for (uint32_t i = 0; i < lv_obj_get_child_cnt(lv_scr_act()); i++) if ((uint8_t)(intptr_t)lv_obj_get_user_data(lv_obj_get_child(lv_scr_act(), i)) == 10) { lv_obj_set_style_bg_color(lv_obj_get_child(lv_scr_act(), i), lv_palette_main(LV_PALETTE_YELLOW), 0); break; }


    // Facoltativo: leggero delay per stabilizzare visivamente
    lv_timer_handler();
    vTaskDelay(pdMS_TO_TICKS(10)); 
}

// funzione per tornare all'Home del cronotermostato
void action_go_home(lv_event_t * e) {
    salva_programmazione(); // chiama la funzione di registrazione della porgrammazione prima di tornare alla home
    lv_scr_load(objects.main);
}

// extern giorno_corrente; // già richiamato prima
extern char* giorni_settimana[];

void action_giorno_avanti(lv_event_t * e){
   giorno_corrente = (giorno_corrente + 1) % 7;
   if (objects.giorno != NULL) {
    lv_label_set_text(objects.giorno, giorni_settimana[giorno_corrente]);
    init_slot_buttons(); // Inizializza l'array dei buttons
    aggiorna_button_program_page(); // Chiama la funzione di aggiornamento dei buttons
   }
   
// qui puoi aggiungere anche aggiornamento visivo dei 48 slot, se serve
}
// funzione di aggiornamento della pagina 

void aggiorna_program_page() {
    lv_obj_t * screen = lv_scr_act();
    uint32_t child_count = lv_obj_get_child_cnt(screen);

    for (uint32_t i = 0; i < child_count; i++) {
        lv_obj_t * obj = lv_obj_get_child(screen, i);

    //    if (lv_obj_get_class(obj) != lv_btn_get_class()) continue;

        uint8_t index = (uint8_t)(intptr_t)lv_obj_get_user_data(obj);
        if (index >= 48) continue;

        bool state = time_selected[giorno_corrente][index];

        lv_color_t color = state
            ? lv_palette_main(LV_PALETTE_RED)
            : lv_palette_main(LV_PALETTE_BLUE);

        lv_obj_set_style_bg_color(obj, color, 0);
    }
}

static lv_obj_t *slot_buttons[48];  // solo dichiarazione


void init_slot_buttons() {
    slot_buttons[0]  = objects.btn_00_00;
    slot_buttons[1]  = objects.btn_00_30;
    slot_buttons[2]  = objects.btn_01_00;
    slot_buttons[3]  = objects.btn_01_30;
    slot_buttons[4]  = objects.btn_02_00;
    slot_buttons[5]  = objects.btn_02_30;
    slot_buttons[6]  = objects.btn_03_00;
    slot_buttons[7]  = objects.btn_03_30;
    slot_buttons[8]  = objects.btn_04_00;
    slot_buttons[9]  = objects.btn_04_30;
    slot_buttons[10] = objects.btn_05_00;
    slot_buttons[11] = objects.btn_05_30;
    slot_buttons[12] = objects.btn_06_00;
    slot_buttons[13] = objects.btn_06_30;
    slot_buttons[14] = objects.btn_07_00;
    slot_buttons[15] = objects.btn_07_30;
    slot_buttons[16] = objects.btn_08_00;
    slot_buttons[17] = objects.btn_08_30;
    slot_buttons[18] = objects.btn_09_00;
    slot_buttons[19] = objects.btn_09_30;
    slot_buttons[20] = objects.btn_10_00;
    slot_buttons[21] = objects.btn_10_30;
    slot_buttons[22] = objects.btn_11_00;
    slot_buttons[23] = objects.btn_11_30;
    slot_buttons[24] = objects.btn_12_00;
    slot_buttons[25] = objects.btn_12_30;
    slot_buttons[26] = objects.btn_13_00;
    slot_buttons[27] = objects.btn_13_30;
    slot_buttons[28] = objects.btn_14_00;
    slot_buttons[29] = objects.btn_14_30;
    slot_buttons[30] = objects.btn_15_00;
    slot_buttons[31] = objects.btn_15_30;
    slot_buttons[32] = objects.btn_16_00;
    slot_buttons[33] = objects.btn_16_30;
    slot_buttons[34] = objects.btn_17_00;
    slot_buttons[35] = objects.btn_17_30;
    slot_buttons[36] = objects.btn_18_00;
    slot_buttons[37] = objects.btn_18_30;
    slot_buttons[38] = objects.btn_19_00;
    slot_buttons[39] = objects.btn_19_30;
    slot_buttons[40] = objects.btn_20_00;
    slot_buttons[41] = objects.btn_20_30;
    slot_buttons[42] = objects.btn_21_00;
    slot_buttons[43] = objects.btn_21_30;
    slot_buttons[44] = objects.btn_22_00;
    slot_buttons[45] = objects.btn_22_30;
    slot_buttons[46] = objects.btn_23_00;
    slot_buttons[47] = objects.btn_23_30;
}

void aggiorna_button_program_page() {
    for (int i = 0; i < 48; i++) {
        bool selected = time_selected[giorno_corrente][i];

        lv_color_t color = selected
            ? lv_palette_main(LV_PALETTE_RED)
            : lv_palette_main(LV_PALETTE_BLUE);

        lv_obj_set_style_bg_color(slot_buttons[i], color, 0);
    }
}

// Funzione di registrazione della programmazione eseguita nella flash
static void delayed_screen_load_WiFiSelect(lv_timer_t * timer)
{
    lv_scr_load(objects.wi_fi_select);
}


void action_wi_fi_page_selet(lv_event_t * e) {
    // scannerizzo le connessioni WiFi
    scanWiFi();
    // azzera gli elementi della pagina
    lv_label_set_text(objects.reti_disponibili, "Reti disponibili");  // Resetta la label al testo iniziale
    lv_textarea_set_text(objects.wi_fi_pass, ""); // Cancella la password
    lv_roller_set_selected(objects.roller_wi_fi, 0, LV_ANIM_OFF); // posiziona la scelta sul primo elemento della lista
    // Passa alla pagina Program    
    //lv_scr_load(objects.wi_fi_select);
    
    lv_label_set_text(objects.programmazione, "Ricerca reti");
    lv_timer_t* t = lv_timer_create(delayed_screen_load_WiFiSelect, 6000, NULL);
    lv_timer_set_repeat_count(t, 1);  // Esegui solo una volta
}

// Dichiara i puntatori agli oggetti solo se sono definiti altrove
extern lv_obj_t* WiFiList;                    // Definito nel main.c

// Callback per la selezione dalla lista WiFi
void action_wi_fi_selectef_from_list(lv_event_t * e) {
    
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) return;
    
    lv_obj_t * roller = lv_event_get_target(e);
    char ssid[64];
    lv_roller_get_selected_str(roller, ssid, sizeof(ssid));
    printf("[INFO] SSID selezionato: %s\n", ssid);
}

// Funzione per rendere visibile la password
void action_password_view(lv_event_t * e){
    // Legge lo stato attuale della modalità password
    bool current_mode = lv_textarea_get_password_mode(objects.wi_fi_pass);
    // Lo inverte
    bool new_mode = !current_mode;
    // Applica il nuovo stato
    lv_textarea_set_password_mode(objects.wi_fi_pass, new_mode);}

// Funzione per la registrazione delle rete WiFi

static void delayed_screen_load_main(lv_timer_t * timer)
{
    lv_scr_load(objects.main);
}

void action_wi_fi_register(lv_event_t * e)
{
    char ssid[64];
    char password[64];

    // Ottieni SSID dal roller
    lv_roller_get_selected_str(objects.roller_wi_fi, ssid, sizeof(ssid));
    
    // Ottieni la password dalla textarea
    const char* pwd = lv_textarea_get_text(objects.wi_fi_pass);
    strncpy(password, pwd, sizeof(password));
    password[sizeof(password) - 1] = '\0';

    // Aggiorno la label di fondo pagina
    lv_label_set_text(objects.reti_disponibili,"Tentativo connessione");
    lv_timer_handler(); // Forza l'elaborazione e aggiornamento del display

    // aggiornamento della label e torna alla pagina principale
    lv_timer_t* t = lv_timer_create(delayed_screen_load_main, 5000, NULL);
    lv_timer_set_repeat_count(t, 1);  // Esegui solo una volta

    // Chiama la funzione definita in C++ per la connessione
    connect_to_wifi(ssid, password);

}




