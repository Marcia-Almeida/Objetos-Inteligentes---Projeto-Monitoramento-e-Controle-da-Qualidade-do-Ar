# Objetos-Inteligentes---Projeto-Monitoramento-e-Controle-da-Qualidade-do-Ar
Este projeto desenvolve um sistema de Internet das Coisas (IoT) para monitorar a qualidade do ar em ambientes internos, alinhado ao ODS 3 da ONU (Boa Saúde e Bem-Estar), utilizando o protocolo MQTT para comunicação.

#  Monitoramento e Controle da Qualidade do Ar em Ambientes Internos com IoT

##  Introdução e Objetivo

Este projeto de Objetos Inteligentes Conectados desenvolve um sistema de Internet das Coisas (IoT) para monitorar e controlar a qualidade do ar, alinhado ao **Objetivo de Desenvolvimento Sustentável (ODS) 3 da ONU** (Boa Saúde e Bem-Estar).

O sistema utiliza:
* **Microcontrolador:** ESP32 (simulado).
* **Sensor:** MQ-135 (leitura de poluentes simulada).
* **Protocolo:** MQTT (para comunicação em tempo real).
* **Interface:** Node-RED Dashboard.

## Nota de Implementação (Simulação)

Devido a desafios logísticos, a demonstração e os testes de comunicação **MQTT** foram realizados por meio da **Simulação WOKWI**, replicando o comportamento do hardware e garantindo a funcionalidade de controle e monitoramento.

##  Tópicos MQTT Utilizados

A comunicação entre o ESP32 (Simulação) e o Node-RED (Dashboard) ocorre via Broker `broker.mqtt-dashboard.com` (Porta 1883) nos seguintes tópicos:

* **Tópico de Dados:** `qualidadear/dados` (Publicação do valor de poluentes pelo ESP32).
* **Tópico de Controle:** `qualidadear/controle` (Comando Ligar/Desligar enviado pelo Node-RED).

##  Arquivos do Projeto 
codigo: sketch.ino + diagram.json
fluxo-nodred: flow.json
artigo do projeto

## Hardware Utilizado (Simulação)

*   **Microcontrolador:** ESP32 DevKit v1
*   **Sensor:** Potenciômetro (simulando o sensor de gás MQ-135)
*   **Atuador:** LED (simulando um módulo relé que aciona um exaustor)

## Software e Plataformas

*   **Simulador de Hardware:** [Wokwi](https://wokwi.com/ )
*   **Broker MQTT e Dashboard:** [Node-RED](https://nodered.org/ )
*   **Firmware IDE:** Arduino IDE

## Como Reproduzir o Projeto

1.  **Firmware (Wokwi):**
    *   Acesse o Wokwi.com
    *   Crie um novo projeto com um ESP32.
    *   Substitua os arquivos `sketch.ino` e `diagram.json` pelos arquivos contidos na pasta `codigo-firmware` deste repositório.
    *   Na aba `wifi.json`, configure o SSID e a senha da sua rede Wi-Fi.

2.  **Fluxo (Node-RED):**
    *   Instale o Node-RED em sua máquina.
    *   Vá para o menu (canto superior direito) -> Importar.
    *   Copie e cole o conteúdo do arquivo `flow.json` (da pasta `fluxo-nodered`) e importe o fluxo.
    *   Clique em "Deploy".

3.  **Execução:**
    *   Inicie a simulação no Wokwi.
    *   Acesse o dashboard do Node-RED em `http://localhost:1880/ui`.
    *   O sistema estará funcionando.

## Documentação

A documentação completa do projeto, incluindo o artigo acadêmico, pode ser encontrada na lista de arquivos.
