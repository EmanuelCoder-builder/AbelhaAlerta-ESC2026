/**
 * @file main.cpp
 * @brief Loop principal do AbelhaAlerta — Máquina de estados e orquestração dos módulos.
 *
 * Competição de Sistemas Embarcados 2026 (SBC/SBESC)
 * Equipe: Emanuel, Malu, Binho | Orientador: Prof. Lucas Cambuim | UFRPE
 */

#include <Arduino.h>
#include "utils/ports.h"
#include "utils/defines.h"

// TODO: Incluir headers dos módulos quando implementados
// #include "SensorIR/sensor_ir.h"
// #include "CameraOV7670/camera.h"
// #include "OtsuCore/otsu.h"
// #include "RiskClassifier/classifier.h"
// #include "DisplayOLED/display.h"

// =============================================
// VARIÁVEIS GLOBAIS
// =============================================
volatile uint32_t N_in = 0;         // Contador de entradas
volatile uint32_t N_out = 0;        // Contador de saídas
volatile uint32_t N_carga = 0;      // Contador de retornos com carga
unsigned long lastAnalysisTime = 0; // Timestamp da última análise

void setup() {
    Serial.begin(115200);
    Serial.println("============================");
    Serial.println("  AbelhaAlerta - ESC 2026");
    Serial.println("  UFRPE - Meliponicultura");
    Serial.println("============================");

    // TODO: Inicializar módulos
    // sensor_ir_init();
    // camera_init();
    // display_init();

    Serial.println("[OK] Sistema inicializado.");
}

void loop() {
    unsigned long now = millis();

    // ---- Ciclo de Análise (a cada 15 min) ----
    if (now - lastAnalysisTime >= ANALYSIS_INTERVAL_MS) {
        lastAnalysisTime = now;

        Serial.println("--- Ciclo de Análise ---");
        Serial.print("  Entradas: "); Serial.println(N_in);
        Serial.print("  Saídas:   "); Serial.println(N_out);
        Serial.print("  Com carga:"); Serial.println(N_carga);

        // TODO: Calcular índice de risco
        // int risk = classifier_calculate(N_in, N_out, N_carga);

        // TODO: Atualizar LEDs e display
        // display_set_status(risk);

        // TODO: Salvar dados no cartão SD
        // datalog_save(N_in, N_out, N_carga, risk);

        // Resetar contadores para o próximo ciclo
        N_in = 0;
        N_out = 0;
        N_carga = 0;
    }
}
