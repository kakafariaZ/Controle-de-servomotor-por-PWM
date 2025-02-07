# Controle de Servomotor por PWM no Raspberry Pi Pico W

## Descrição
Este projeto implementa o controle de um servomotor utilizando o Raspberry Pi Pico W e o módulo PWM. O código é baseado no Pico SDK e simula a movimentação do servomotor no simulador Wokwi.

## Requisitos
- Raspberry Pi Pico W
- Pico SDK 2.1.0
- Compilador `arm-none-eabi-gcc`
- CMake e Ninja
- Simulador Wokwi

## Configuração do Ambiente
1. Clone o repositório do Pico SDK:
   ```sh
   git clone -b 2.1.0 https://github.com/raspberrypi/pico-sdk.git --depth=1
   ```
2. Exporte a variável de ambiente:
   ```sh
   export PICO_SDK_PATH=$(pwd)/pico-sdk
   ```
3. Instale as dependências:
   ```sh
   sudo apt install cmake ninja-build gcc-arm-none-eabi
   ```

## Compilação e Geração do Binário
1. Crie a pasta de build:
   ```sh
   mkdir build && cd build
   ```
2. Execute o CMake:
   ```sh
   cmake .. -G Ninja
   ```
3. Compile o projeto:
   ```sh
   ninja
   ```

## Execução no Simulador Wokwi
1. No arquivo `wokwi.toml`, defina os binários:
   ```toml
   [wokwi]
   version = 1
   firmware = 'build/tarefa.hex'
   elf = 'build/tarefa.uf2'
   ```
2. Acesse o [Wokwi](https://wokwi.com/) e carregue o binário compilado.

## Estrutura do Projeto
```
/tarefa_servo
│── CMakeLists.txt
│── tarefa.c
│── README.md
│── wokwi.toml
└── /build
```

## Contato
Caso tenha dúvidas ou sugestões, entre em contato!
