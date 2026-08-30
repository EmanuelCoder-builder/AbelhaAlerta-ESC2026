/**
 * @file camera.h
 * @brief Driver de captura de foto 320x240 com câmera OV7670 via GPIO paralelo.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Inicializa a câmera OV7670 (configuração SCCB/I2C + clock XCLK).
 */
void camera_init(void);

/**
 * @brief Captura um frame de 320x240 pixels e armazena no buffer.
 * @param buffer Ponteiro para o buffer de saída (deve ter 320*240*2 bytes para RGB565).
 * @return true se a captura foi bem-sucedida.
 */
bool camera_capture_frame(uint8_t* buffer);

#endif // CAMERA_H
