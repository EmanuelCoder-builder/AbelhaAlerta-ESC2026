/**
 * @file classifier.h
 * @brief Motor de regras de classificação de risco da colmeia (Normal/Atenção/Crítico).
 */

#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <stdint.h>

typedef enum {
    RISK_NORMAL = 0,    // LED Verde
    RISK_ATTENTION = 1, // LED Amarelo
    RISK_CRITICAL = 2   // LED Vermelho + Buzzer
} RiskLevel;

/**
 * @brief Calcula o nível de risco com base nos contadores do ciclo atual.
 * @param entries Número de entradas no ciclo.
 * @param exits Número de saídas no ciclo.
 * @param cargo Número de retornos com carga detectada.
 * @param hist_avg_exits Média histórica de saídas (para comparação).
 * @param hist_avg_cargo Média histórica de retornos com carga.
 * @return Nível de risco (NORMAL, ATTENTION ou CRITICAL).
 */
RiskLevel classifier_calculate(uint32_t entries, uint32_t exits, uint32_t cargo,
                                uint32_t hist_avg_exits, uint32_t hist_avg_cargo);

#endif // CLASSIFIER_H
