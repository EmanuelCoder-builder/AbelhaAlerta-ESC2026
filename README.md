# 🐝 AbelhaAlerta — ESC 2026

**Sistema embarcado de monitoramento de atividade de voo para meliponicultura de precisão**

> Competição de Sistemas Embarcados 2026 — SBC / SBESC  
> Universidade Federal Rural de Pernambuco (UFRPE)

---

## 📋 Sobre o Projeto

O **AbelhaAlerta** é um sistema embarcado de baixo custo para monitoramento **não invasivo** de colmeias de abelhas sem ferrão (meliponicultura). O dispositivo é instalado externamente na portinhola da colmeia — sem abrir a caixa em nenhum momento — e coleta dois indicadores principais:

1. **Fluxo de entrada/saída** — Contagem direcional por sensores infravermelhos (TCRT5000)
2. **Detecção de carga** — Identificação de pólen (amarelo) ou resina (escura) nas patas via câmera OV7670 e binarização de Otsu + filtro HSV

Com base nesses dados, o sistema classifica o estado da colmeia em **🟢 Normal**, **🟡 Atenção** ou **🔴 Crítico**, exibindo alertas por LEDs e display OLED — tudo sem internet.

---

## 👥 Equipe

| Nome | Função | Contato |
|------|--------|---------|
| Prof. Lucas Fernando da Silva Cambuim | Professor Orientador | lucas.cambuim@ufrpe.br |
| Emanuel Henrique Silva do Nascimento | Aluno Membro | emanuel.hsilva@ufrpe.br |
| Maria Luiza (Malu) | Aluno Membro | — |
| Carlos Jonathan de Lima Malta (Binho) | Aluno Membro | carlos.malta@ufrpe.br |

**Apoio especializado:**
- Prof. José Fernando Dagnone Figueiredo (UACSA-UFRPE) — Validação biológica e limiares sazonais
- Profa. Darclet Teresinha Malerbo de Souza (DZ-UFRPE) — Colmeia e colônia para testes de campo

---

## 🔧 Hardware

| Componente | Função |
|------------|--------|
| Placa BigDog Lab (RP2040 / Raspberry Pi Pico) | Processamento central |
| 2× Sensores IR TCRT5000 | Contagem direcional de entrada/saída |
| Câmera OV7670 (colorida) | Captura de foto 320×240 para detecção de carga |
| Display OLED SSD1306 (I2C) | Exibição local do estado |
| LEDs Verde, Amarelo, Vermelho | Indicação visual do estado da colmeia |
| Buzzer | Alerta sonoro para estado crítico |
| LED IR auxiliar | Iluminação controlada da portinhola |
| Cartão SD / Memória Flash | Registro de séries temporais |
| Bateria 18650 / Painel Solar | Alimentação autônoma de campo |

Os pinos estão mapeados em [`lib/utils/ports.h`](lib/utils/ports.h).  
As constantes e limiares em [`lib/utils/defines.h`](lib/utils/defines.h).

---

## 📁 Estrutura do Projeto

```
AbelhaAlerta-ESC2026/
├── assets/                  # Imagens, fluxogramas, fotos da colmeia e logos
├── include/                 # Cabeçalhos globais
├── lib/                     # Módulos e drivers desacoplados
│   ├── SensorIR/            # Driver da contagem direcional por interrupção
│   ├── CameraOV7670/        # Driver de captura de foto 320×240
│   ├── OtsuCore/            # Algoritmo C de binarização de Otsu
│   ├── RiskClassifier/      # Motor de regras de risco e sazonalidade
│   ├── DisplayOLED/         # Driver SSD1306 + LEDs + Buzzer
│   └── utils/
│       ├── ports.h          # Mapeamento de pinos da Pico / BigDog Lab
│       └── defines.h        # Constantes, limiares HSV e temporizadores
├── pc_prototype/            # Scripts Python com OpenCV (validação no PC)
├── dataset/                 # Fotos 320×240 organizadas por classe
│   ├── 01_polen/
│   ├── 02_resina/
│   ├── 03_sem_carga/
│   └── 04_fundo_vazio/
├── src/
│   └── main.cpp             # Loop principal e máquina de estados
├── hardware/                # Esquemáticos e modelo 3D do invólucro
├── docs/                    # Relatórios parcial/final e artigos
├── platformio.ini           # Configuração de build PlatformIO
└── README.md
```

---

## 🛠️ Build & Upload

### Requisitos
- [VS Code](https://code.visualstudio.com/) com extensão [PlatformIO](https://platformio.org/)
- Raspberry Pi Pico / BigDog Lab conectada via USB

### Compilar e enviar
1. Abrir o projeto no VS Code com PlatformIO instalado
2. Ajustar pinos em `lib/utils/ports.h` se necessário
3. Compilar: `PlatformIO: Build`
4. Upload: `PlatformIO: Upload`

---

## ⚙️ Funcionamento (Runtime Overview)

1. **Tempo real (Interrupção GPIO):** Sensores IR detectam cruzamento → incrementam `N_in` ou `N_out` → disparam captura da câmera
2. **Por evento IR:** Câmera captura foto 320×240 → binarização de Otsu → filtro HSV → detecta carga (pólen/resina)
3. **A cada 15 min:** Consolida contadores → calcula taxa de atividade forrageira → aplica tabela de pontuação de risco → atualiza LEDs e display
4. **A cada 15 min:** Salva indicadores com timestamp na memória local

### Classificação de Risco
| Pontuação | Estado | Saída |
|-----------|--------|-------|
| 0 | 🟢 Normal | LED Verde |
| 1–2 | 🟡 Atenção | LED Amarelo |
| ≥ 3 | 🔴 Crítico | LED Vermelho + Buzzer |

---

## 🎯 ODS Relacionados

- ODS 2 — Fome zero e agricultura sustentável
- ODS 8 — Trabalho decente e crescimento econômico
- ODS 11 — Cidades e comunidades sustentáveis
- ODS 12 — Consumo e produção responsáveis
- ODS 13 — Ação contra a mudança global do clima

---

## 📜 Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
