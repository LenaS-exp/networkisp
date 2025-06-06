# Distributed Integral Calculator  

**Master-Worker** система для распределённого вычисления определённых интегралов.  

## 🚀 Быстрый старт  

### 1. Клонирование и сборка  
```bash  
git clone https://github.com/LenaS-exp/networkisp.git  
cd networkisp 
make all  # Собирает master_integral и worker_integral  
```  

### 2. Запуск  
#### На одном компьютере (тестовый режим):  
- **В терминале 1** (Управляющий узел - Мастер):  
  ```bash  
  ./bin/master_integral 8080 2 20 0 1  # Порт, количество рабочих, таймаут(сек), a, b (отрезок интегрирования) 
  ```  
- **В терминале 2 и 3** (Рабочие узлы - Воркеры):  
  ```bash  
  ./bin/worker_integral 127.0.0.1 8080 2  # IP мастера, порт, количество ядер
  ```
  - **Запуск тестов**:  
  ```bash  
  make test
  ```
   - **Запуск aнализа**:  
  ```bash  
  make analyze
  ``` 
 

## 📊 Результат  
Мастер выведет:  
```  
∫x²dx от 0.00 до 1.00 = 0.333333  
Время: ? сек (2 workers, 4 ядра)  
```  

## ⚙️ Параметры  
- `master_integral`: `<порт> <кол-во_воркеров> <таймаут> <a> <b>`  
- `worker_integral`: `<IP_мастера> <порт> <кол-во_ядер>`  


Тестовый пример: ∫x²dx (можно заменить в `worker_integral.c`).  
