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

## ⚠️ Nota de Implementação (Simulação)

Devido a desafios logísticos, a demonstração e os testes de comunicação **MQTT** foram realizados por meio da **Simulação Tinkercad Circuits**, replicando o comportamento do hardware e garantindo a funcionalidade de controle e monitoramento.

## 🔌 Tópicos MQTT Utilizados

A comunicação entre o ESP32 (Simulação) e o Node-RED (Dashboard) ocorre via Broker `broker.mqtt-dashboard.com` (Porta 1883) nos seguintes tópicos:

* **Tópico de Dados:** `qualidadear/dados` (Publicação do valor de poluentes pelo ESP32).
* **Tópico de Controle:** `qualidadear/controle` (Comando Ligar/Desligar enviado pelo Node-RED).

##  Arquivos do Projeto (A Serem Inseridos)

Esta seção será preenchida após a conclusão das etapas técnicas.

1.  **Código Fonte ESP32:** [Link para a pasta Codigo_ESP32/ com o arquivo .ino]
2.  **Fluxo do Node-RED:** [Link para o arquivo .json do fluxo]
3.  **Link da Simulação:** [Link público para o projeto no Tinkercad]
