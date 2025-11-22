// Arquivo: wokwi_firmware.ino
// Projeto: Monitoramento e Controle da Qualidade do Ar com ESP32 e MQTT
// Autor: Manus (Assistente)
// Plataforma de Simulação: WOKWI

#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

// Configurações de Rede - CORRIGIDO
const char* ssid = "Wokwi-GUEST";   // Rede correta do WOKWI
const char* password = "";          // Sem senha no WOKWI

// Configurações do MQTT Broker (HiveMQ Public Broker)
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_client_id = "ESP32Client-AirQuality"; // ID único

// Tópicos MQTT
const char* topic_publish_air_quality = "mackenzie/air_quality/ppm";
const char* topic_subscribe_control = "mackenzie/air_quality/control";

// Pinos do Hardware (WOKWI)
const int PIN_MQ135 = 34; // Leitura analógica do potenciômetro simulando MQ-135
const int PIN_RELE = 23;  // GPIO 23 controla o exaustor (LED ou relé)

// Variáveis de Controle
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
int threshold_ppm = 150; // Limiar de acionamento

// Protótipos
void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
int read_mq135_simulated();
void publish_air_quality(int ppm);
void control_actuator(int ppm);

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, LOW); // Exaustor começa desligado

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) { // Publica a cada 5 segundos
    lastMsg = now;

    int ppm_value = read_mq135_simulated();  // Lê sensor simulado
    publish_air_quality(ppm_value);          // Envia ao MQTT
    control_actuator(ppm_value);             // Liga/desliga exaustor
  }
}

// =============================================================
// FUNÇÕES DE CONEXÃO
// =============================================================

void setup_wifi() {
  Serial.println();
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int tentativas = 0;
  while (WiFi.status() != WL_CONNECTED && tentativas < 30) {
    delay(300);
    Serial.print(".");
    tentativas++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi conectado!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha ao conectar ao WiFi!");
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida no tópico: ");
  Serial.println(topic);

  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Payload: ");
  Serial.println(message);

  if (String(topic) == topic_subscribe_control) {
    if (message == "ON") {
      digitalWrite(PIN_RELE, HIGH);
      Serial.println("-> Exaustor LIGADO (MQTT)");
    } else if (message == "OFF") {
      digitalWrite(PIN_RELE, LOW);
      Serial.println("-> Exaustor DESLIGADO (MQTT)");
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect(mqtt_client_id)) {
      Serial.println("conectado!");
      client.subscribe(topic_subscribe_control);
    } else {
      Serial.print("Falhou (rc=");
      Serial.print(client.state());
      Serial.println("). Tentando em 5s...");
      delay(5000);
    }
  }
}

// =============================================================
// FUNÇÕES DO SENSOR E ATUADOR
// =============================================================

int read_mq135_simulated() {
  int raw_value = analogRead(PIN_MQ135); // 0 a 4095
  int ppm = map(raw_value, 0, 4095, 0, 500);

  Serial.print("Leitura Analógica: ");
  Serial.print(raw_value);
  Serial.print(" -> PPM: ");
  Serial.println(ppm);

  return ppm;
}

void publish_air_quality(int ppm) {
  char msg[10];
  sprintf(msg, "%d", ppm);

  client.publish(topic_publish_air_quality, msg);
  Serial.print("Publicado MQTT (PPM): ");
  Serial.println(msg);
}

void control_actuator(int ppm) {
  if (ppm > threshold_ppm) {
    digitalWrite(PIN_RELE, HIGH);
    Serial.println("⚠️ ALERTA: Qualidade do ar RUIM. Exaustor LIGADO.");
  } else {
    digitalWrite(PIN_RELE, LOW);
    Serial.println("Qualidade do ar OK. Exaustor DESLIGADO.");
  }
}
