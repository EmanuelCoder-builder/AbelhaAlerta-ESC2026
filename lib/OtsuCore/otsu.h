/**
 * @file otsu.h
 * @brief Algoritmo de binarização de Otsu otimizado para C embarcado (sem OpenCV).
 */

#ifndef OTSU_H
#define OTSU_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Calcula o limiar ótimo de Otsu para uma imagem em escala de cinza.
 * @param grayscale Ponteiro para os pixels em escala de cinza.
 * @param width Largura da imagem.
 * @param height Altura da imagem.
 * @return Valor do limiar (0-255).
 */
uint8_t otsu_threshold(const uint8_t* grayscale, uint16_t width, uint16_t height);

/**
 * @brief Detecta se há carga visível (protuberância) nas patas da abelha.
 * @param rgb_buffer Buffer RGB565 da imagem 320x240.
 * @return true se carga (pólen ou resina) foi detectada.
 */
bool otsu_detect_cargo(const uint8_t* rgb_buffer);

#endif // OTSU_H
