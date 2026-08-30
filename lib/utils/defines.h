/**
 * @file defines.h
 * @brief Constantes globais, limiares de risco, parâmetros de câmera e temporização.
 *
 * Ajuste os limiares sazonais aqui sem precisar alterar o código dos módulos.
 */

#ifndef DEFINES_H
#define DEFINES_H

// =============================================
// TEMPORIZAÇÃO
// =============================================
#define ANALYSIS_INTERVAL_MS   900000   // Intervalo de análise: 15 minutos (em ms)
#define IR_DEBOUNCE_MS              50  // Debounce dos sensores IR (em ms)
#define IR_TIMEOUT_MS              500  // Timeout entre IR1 e IR2 para contagem direcional

// =============================================
// CÂMERA OV7670
// =============================================
#define CAM_WIDTH               320     // Resolução horizontal da captura
#define CAM_HEIGHT              240     // Resolução vertical da captura
#define CAM_FPS_TARGET            2     // FPS alvo (~2 FPS no RP2040)

// =============================================
// LIMIARES DE COR HSV (DETECÇÃO DE CARGA)
// =============================================
// Pólen (tons amarelos/laranjas)
#define HSV_POLEN_H_MIN          15
#define HSV_POLEN_H_MAX          35
#define HSV_POLEN_S_MIN         100
#define HSV_POLEN_S_MAX         255
#define HSV_POLEN_V_MIN         100
#define HSV_POLEN_V_MAX         255

// Resina/Própolis (tons escuros)
#define HSV_RESINA_V_MAX         80     // Valor de brilho máximo para considerar escuro

// =============================================
// LIMIARES DE RISCO (TABELA DE PONTUAÇÃO)
// =============================================
#define RISK_FLOW_DROP_HIGH      40     // Queda de saída > 40% = +2 pts
#define RISK_FLOW_DROP_MED       20     // Queda de saída 20-40% = +1 pt
#define RISK_CARGO_DROP_HIGH     20     // Retorno com carga < 20% = +2 pts
#define RISK_CARGO_DROP_MED      40     // Retorno com carga < 40% = +1 pt
#define RISK_NO_FLIGHT_PEAK       3     // Ausência total em horário de pico = +3 pts
#define RISK_NIGHT_ACTIVITY       1     // Atividade noturna anormal = +1 pt

// Classificação final
#define RISK_THRESHOLD_NORMAL     0     // 0 pts = Normal (Verde)
#define RISK_THRESHOLD_ATTENTION  1     // 1-2 pts = Atenção (Amarelo)
#define RISK_THRESHOLD_CRITICAL   3     // >= 3 pts = Crítico (Vermelho)

// =============================================
// PARÂMETROS SAZONAIS (Ajustar por época do ano)
// =============================================
#define SEASON_WINTER_FACTOR    0.6f    // No inverno, reduzir limiares em 40%
#define SEASON_SUMMER_FACTOR    1.0f    // No verão, limiares normais

#endif // DEFINES_H
