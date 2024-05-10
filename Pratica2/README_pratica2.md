## Sensor DHT11
**Descrição:** Utilizar um sensor de temperatura conectado ao esp32 e enviar essas informações para um servidor online hospedado no thinkspeak.

**Passo 1)** Para configurar o sensor DHT11 na IDE do Arduino, vá em Ferramentas → Gerenciador de bibliotecas → "'DHT sensor library' by Adafruit" (essa biblioteca inclui o Adafruit Unified Sensor)

❗ **OBS1: lembre-se de selecionar a placa correta, vá em Ferramentas → Placa → esp32 → ESP32 Dev Module**

**Passo 2)** Comente o código "#include <ESP8266WiFi.h>" e adicione a biblioteca "#include <WiFi.h>" (um código inicial foi fornceido)

**Passo 3)** Crie uma conta no [site](www.thingspeak.com) e, em seguida, crie um novo canal, preenchendo as informações necessárias

**Passo 4)** Ajuste o código, modificando:
- Escreva seu Write API key do site ThingSpeak;
- Substitua com o ssid e senha da rede WiFi;
- Ao final do trecho "Serial.println("%. Send to Thingspeak.");" adcione um delay ("delay(1000);");
- Verifique a montagem do circuito;

**Passo 5)** Verificar o código cliando *Verify*, para compilar o script, e depois para baixar o código compilado na placa esp32 clique em "*Upload*"

❗ **OBS2: em algumas placas esp32 tem o problema de gravação do código, apresentado o erro "*exit status 2*" no arduino, para solucionar isso, enquanto o programa estiver sendo baixado no esp32 segure o botão de **BOOT/FLASH** do micro até que o upload termine por completo**

## Botão
**Descrição:** Utilizar um botão conectado ao esp32 e enviar os estados(0/1) desse botão para um servidor online hospedado no thinkspeak.

**Passo 1)** Construa o código responsável por verificar o estado do botão e enviar para o thingspeak

**Passo 2)** Verifique a montagem do circuito

❗ **OBS3: no exemplo mostrado neste repositório, o estado do botão é 1 quando ele não está pressionado e 0 quando ele está pressionado, logo os valores mostrados no thingspeak fazem referências a esses estados**

**Passo 3)** Verificar o código cliando *Verify*, para compilar o script, e depois para baixar o código compilado na placa esp32 clique em "*Upload*" (**OBS2** continua válida)
