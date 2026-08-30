"""
otsu_segmentation.py — Protótipo de binarização de Otsu + detecção de carga (Pólen vs Resina)

Competição de Sistemas Embarcados 2026 | AbelhaAlerta | UFRPE
Responsável: Binho

Uso:
    python otsu_segmentation.py --image <caminho_da_foto_320x240>
"""

import cv2
import numpy as np
import argparse
import os

def otsu_binarize(image_path):
    """Aplica binarização de Otsu para isolar a abelha do fundo."""
    img = cv2.imread(image_path)
    if img is None:
        print(f"Erro: Não foi possível carregar {image_path}")
        return None, None, None
    
    # Redimensionar para 320x240 (resolução da OV7670)
    img = cv2.resize(img, (320, 240))
    
    # Converter para escala de cinza
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    
    # Aplicar filtro gaussiano para reduzir ruído
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    
    # Binarização de Otsu
    threshold, binary = cv2.threshold(blur, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    
    print(f"Limiar de Otsu calculado: {threshold}")
    return img, binary, threshold


def detect_cargo_hsv(img):
    """Detecta carga nas patas da abelha usando filtro de cor HSV."""
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    
    # Máscara para Pólen (tons amarelos/laranjas)
    lower_polen = np.array([15, 100, 100])
    upper_polen = np.array([35, 255, 255])
    mask_polen = cv2.inRange(hsv, lower_polen, upper_polen)
    
    # Máscara para Resina (tons escuros)
    lower_resina = np.array([0, 0, 0])
    upper_resina = np.array([180, 255, 80])
    mask_resina = cv2.inRange(hsv, lower_resina, upper_resina)
    
    # Calcular porcentagem de pixels
    total_pixels = img.shape[0] * img.shape[1]
    pct_polen = (cv2.countNonZero(mask_polen) / total_pixels) * 100
    pct_resina = (cv2.countNonZero(mask_resina) / total_pixels) * 100
    
    # Classificação
    if pct_polen > 2.0:
        return "COM_POLEN", pct_polen
    elif pct_resina > 15.0:
        return "COM_RESINA", pct_resina
    else:
        return "SEM_CARGA", 0.0


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="AbelhaAlerta - Binarização de Otsu + Detecção de Carga")
    parser.add_argument("--image", required=True, help="Caminho da foto 320x240")
    args = parser.parse_args()
    
    img, binary, threshold = otsu_binarize(args.image)
    if img is not None:
        cargo_type, pct = detect_cargo_hsv(img)
        print(f"Resultado: {cargo_type} ({pct:.1f}%)")
        
        # Exibir resultados
        cv2.imshow("Original (320x240)", img)
        cv2.imshow("Binarização de Otsu", binary)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
