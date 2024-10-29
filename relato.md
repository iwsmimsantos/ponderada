No projeto, foi utilizada uma placa **ESP32** como controlador principal, onde foram conectados os seguintes componentes:

- **Botão de Controle**: Conectado a porta 14 do ESP32, o botão permite ativar e desativar o sistema de semáforo manualmente. Quando pressionado, ele interrompe a sequência dos LEDs, e, ao ser pressionado novamente, volta o sistema a partir da próxima cor da sequência, simulando uma pausa no funcionamento do semáforo.
  
- **LEDs Vermelho, Amarelo e Verde**: Os LEDs representam as luzes de um semáforo e estão conectados a diferentes pinos do ESP32 (2, 4 e 17). Cada LED possui um **resistor de 330 Ohms** para limitar a corrente. A sequência de iluminação dos LEDs simula o que foi pedido na ponderada, e com tempos definidos para cada cor:

1. 6 segundos no vermelho
2. 2 segundos no amarelo
3.  2 segundos no verde
4.  +2 segundos no verde (simulando um tempo adicional para pedestres terminarem a travessia)
5.  2 segundos no amarelo


- **Conexões**: Foram usados cabos **jumper macho-fêmea** para interligar o ESP32 com os LEDs, além de cabos **macho-macho** para a botão e GND, facilitando o circuito e organização dos componentes.

Com esses elementos, o ESP32 controla a sequência de funcionamento dos LEDs e responde ao botão, permitindo ao usuário pausar e retomar o funcionamento do semáforo.


| Componente               | Especificação                       | Quantidade |
|--------------------------|-------------------------------------|------------|
| LED                      | Vermelho, Verde, Amarelo            | 3          |
| Jumper Macho-Macho       | Cabos de conexão                   | 3          |
| Jumper Fêmea-Macho       | Cabos de conexão                   | 6          |
| Placa                    | ESP32                              | 1          |
| Protoboard               | Placa de prototipagem              | 1          |
| Resistor                 | 330 Ohms                           | 3          |
| Base                     | Madeira MDF                        | 2          |
| Cabo de conexão          | USB (para ESP32 e computador)     | 1          |
