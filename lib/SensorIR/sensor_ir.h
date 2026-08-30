/**
 * @file sensor_ir.h
 * @brief Driver de contagem direcional por 2 sensores IR (TCRT5000).
 *
 * Utiliza interrupções GPIO para detectar a sequência de acionamento:
 * - IR1 -> IR2 = ENTRADA (incrementa N_in e dispara câmera)
 * - IR2 -> IR1 = SAÍDA (incrementa N_out)
 */

#ifndef SENSOR_IR_H
#define SENSOR_IR_H

#include <stdint.h>

/**
 * @brief Inicializa os pinos dos sensores IR e configura interrupções GPIO.
 */
void sensor_ir_init(void);

/**
 * @brief Retorna o número de entradas detectadas desde o último reset.
 */
uint32_t sensor_ir_get_entries(void);

/**
 * @brief Retorna o número de saídas detectadas desde o último reset.
 */
uint32_t sensor_ir_get_exits(void);

/**
 * @brief Reseta os contadores de entrada e saída.
 */
void sensor_ir_reset_counters(void);

#endif // SENSOR_IR_H
