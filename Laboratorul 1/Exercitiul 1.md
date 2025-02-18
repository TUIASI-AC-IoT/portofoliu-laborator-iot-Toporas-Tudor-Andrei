#### gpio_config

- functie de setare a configuratiei pinilor, intotdeauna suprascrie valorile existente

#### moduri configurare GPIO
- pinii GPIO pot fi configurati ca intrare, iesire sau intrare si iesire
- pinii GPIO mai pot fi configurati pentru intreruperi

#### vTaskDelay
- suspenda executia task-ului curent pentru numarul de "tick-uri" specificat
- pentru a avea o valoare in timp real se foloseste macro-ul `portTICK_PERIOD_MS` care reprezinta lungimea unui "tick" in milisecunde

#### app_main
- taskul principal al developer-ului care este adaugat la schedueler-ul sistemului de operare FreeRTOS