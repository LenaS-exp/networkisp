#ifndef DISTRIBUTED_COMPUTING_H
#define DISTRIBUTED_COMPUTING_H

// Режимы работы
typedef enum {
    DC_MODE_MASTER,
    DC_MODE_WORKER
} dc_mode_t;

// Конфигурация
typedef struct {
    dc_mode_t mode;
    
    // Общие параметры
    const char* master_ip;  // Для worker
    unsigned short port;    // Для master
    
    // Параметры master
    int max_workers;
    int max_timeout;
    double a, b;           // Границы интегрирования
    
    // Параметры worker
    int max_cores;
} dc_config_t;

// Запуск узла
int dc_run(const dc_config_t* config);

// Остановка узла
void dc_stop();

#endif