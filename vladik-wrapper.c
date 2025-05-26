#include "vladik.h"
#include <stdlib.h>
#include <pthread.h>

// Объявляем оригинальные функции из ваших файлов
extern int master_main(int argc, char** argv);
extern int worker_main(int argc, char** argv);

static pthread_t node_thread;
static int node_running = 0;

static void* master_thread(void* arg) {
    dc_config_t* config = (dc_config_t*)arg;
    char* argv[] = {
        "master",
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->port),
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->max_workers),
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->max_timeout),
        (char[16]){0}, sprintf((char[16]){0}, "%.2f", config->a),
        (char[16]){0}, sprintf((char[16]){0}, "%.2f", config->b),
        NULL
    };
    master_main(6, argv);
    return NULL;
}

static void* worker_thread(void* arg) {
    dc_config_t* config = (dc_config_t*)arg;
    char* argv[] = {
        "worker",
        (char*)config->master_ip,
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->port),
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->max_cores),
        (char[16]){0}, sprintf((char[16]){0}, "%d", config->max_timeout),
        NULL
    };
    worker_main(5, argv);
    return NULL;
}

int dc_run(const dc_config_t* config) {
    if (node_running) return -1;
    
    node_running = 1;
    int res = pthread_create(&node_thread, NULL, 
        config->mode == DC_MODE_MASTER ? master_thread : worker_thread, 
        (void*)config);
    
    return res == 0 ? 0 : -1;
}

void dc_stop() {
    if (node_running) {
        // Здесь можно добавить мягкое завершение
        pthread_cancel(node_thread);
        node_running = 0;
    }
}