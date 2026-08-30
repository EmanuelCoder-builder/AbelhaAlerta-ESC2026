/**
 * @file ports.h
 * @brief Mapeamento centralizado de pinos GPIO da Raspberry Pi Pico / BigDog Lab.
 *
 * IMPORTANTE: Quando a placa BigDog Lab chegar, altere APENAS este arquivo
 * para ajustar os pinos. Nenhum outro módulo precisa ser modificado.
 */

#ifndef PORTS_H
#define PORTS_H

// =============================================
// SENSORES IR (Contagem Direcional)
// =============================================
#define PIN_IR_SENSOR_1     2   // GPIO para sensor IR #1 (TCRT5000) - Interrupção
#define PIN_IR_SENSOR_2     3   // GPIO para sensor IR #2 (TCRT5000) - Interrupção

// =============================================
// CÂMERA OV7670 (Interface Paralela)
// =============================================
#define PIN_CAM_XCLK        4   // Clock de saída para a câmera
#define PIN_CAM_PCLK        5   // Pixel clock (entrada)
#define PIN_CAM_VSYNC       6   // Vertical sync
#define PIN_CAM_HREF        7   // Horizontal reference
#define PIN_CAM_SDA         8   // I2C SDA (configuração SCCB)
#define PIN_CAM_SCL         9   // I2C SCL (configuração SCCB)
#define PIN_CAM_D0         10   // Dados paralelos D0
#define PIN_CAM_D1         11   // Dados paralelos D1
#define PIN_CAM_D2         12   // Dados paralelos D2
#define PIN_CAM_D3         13   // Dados paralelos D3
#define PIN_CAM_D4         14   // Dados paralelos D4
#define PIN_CAM_D5         15   // Dados paralelos D5
#define PIN_CAM_D6         16   // Dados paralelos D6
#define PIN_CAM_D7         17   // Dados paralelos D7

// =============================================
// DISPLAY OLED SSD1306 (I2C)
// =============================================
#define PIN_OLED_SDA       18   // I2C SDA
#define PIN_OLED_SCL       19   // I2C SCL
#define OLED_I2C_ADDR    0x3C   // Endereço I2C do SSD1306

// =============================================
// LEDs DE STATUS + BUZZER
// =============================================
#define PIN_LED_GREEN      20   // LED Verde  (Normal)
#define PIN_LED_YELLOW     21   // LED Amarelo (Atenção)
#define PIN_LED_RED        22   // LED Vermelho (Crítico)
#define PIN_BUZZER         26   // Buzzer (PWM)

// =============================================
// LED IR AUXILIAR (Iluminação da Portinhola)
// =============================================
#define PIN_IR_LED_AUX     27   // LED IR para iluminação controlada

// =============================================
// CARTÃO SD (SPI)
// =============================================
#define PIN_SD_MOSI        -1   // Definir quando integrar SD
#define PIN_SD_MISO        -1
#define PIN_SD_SCK         -1
#define PIN_SD_CS          -1

#endif // PORTS_H
