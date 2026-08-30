/**
 * @file display.h
 * @brief Driver do display OLED SSD1306 (I2C) + LEDs de status + Buzzer.
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "../RiskClassifier/classifier.h"

/**
 * @brief Inicializa o display OLED, LEDs e buzzer.
 */
void display_init(void);

/**
 * @brief Atualiza o display e LEDs com o estado atual da colmeia.
 * @param level Nível de risco atual.
 * @param entries Contagem de entradas no ciclo.
 * @param exits Contagem de saídas no ciclo.
 * @param cargo_pct Percentual de retorno com carga (0-100).
 */
void display_update(RiskLevel level, uint32_t entries, uint32_t exits, uint8_t cargo_pct);

/**
 * @brief Aciona o buzzer por um período (alerta crítico).
 * @param duration_ms Duração do bip em milissegundos.
 */
void display_buzzer_alert(uint16_t duration_ms);

#endif // DISPLAY_H
