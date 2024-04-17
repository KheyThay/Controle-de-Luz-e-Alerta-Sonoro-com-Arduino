# Controle-de-Luz-e-Alerta-Sonoro-com-Arduino

Este projeto apresenta um sistema inteligente de controle de luminosidade utilizando um Arduino Uno e componentes eletrônicos simples. O dispositivo é capaz de ajustar verificar a intensidade luminosa de acordo com as condições do ambiente, além de emitir um alerta sonoro em situações específicas.


## Introdução:
Este projeto apresenta um sistema versátil e inteligente de controle de luminosidade, utilizando um Arduino Uno e componentes eletrônicos simples. O dispositivo é capaz de ajustar a intensidade luminosa de acordo com as condições do ambiente, além de emitir um alerta sonoro em situações específicas.

## Componentes Utilizados
- Arduino Uno
- Fotoresistor (LDR - Light Dependent Resistor)
- LEDs (verde, amarelo e vermelho)
- Buzzer
- Resistores
- Protoboard
- Jumpers


## Montagem do Circuito
1. Conexão do Fotoresistor (LDR): O terminal mais claro do LDR é conectado ao pino A0 do Arduino, enquanto o terminal mais escuro é conectado ao GND (terra) para formar um divisor de tensão.

2. Conexão dos LEDs: O LED verde é conectado ao pino digital 13.
O LED amarelo é conectado ao pino digital 12.
O LED vermelho é conectado ao pino digital 11.
Cada LED é conectado em série com um resistor para limitar a corrente e proteger o LED.

4. Conexão do Buzzer: O buzzer é conectado ao pino digital 8.
5. Montagem na Protoboard: Os componentes são distribuídos e conectados na protoboard conforme o esquema descrito abaixo.
   
[Modo de montagem no protoboard (Placa de ensaio)]

https://drive.google.com/file/d/1D49o9TUhnsq-6IyCPwDdDtqyQs4JEhLO/view?usp=sharing

https://www.tinkercad.com/things/iSrETKYsxLq-epic-lappi-turing/editel

## Funcionamento do Código

código: 

https://drive.google.com/drive/folders/1Pc0Pah0TaQ7mMdxdK9Qc4c20N-5B6Isu?usp=drive_link

1. Setup():
- Inicialização da comunicação serial com uma taxa de transmissão de 9600 bauds para comunicação com o computador.
- Configuração dos pinos como entrada (para o LDR) e saída (para os LEDs e o buzzer).

2. Loop():
- Leitura do valor analógico do LDR utilizando a função analogRead(), que retorna um valor entre 0 e 1023.
Com base no valor lido do LDR:
- Se a luminosidade for baixa (valorLDR < 100), apenas o LED verde é aceso.
- Se for média (valorLDR entre 100 e 150), apenas o LED amarelo é aceso.
- Se for alta (valorLDR >= 150), apenas o LED vermelho é aceso e o buzzer é ativado por 3 segundos, com pausas de 2 segundos entre cada ativação.
- Os valores lidos do LDR e as ações realizadas são exibidos no monitor serial para acompanhamento.

4. Funções Auxiliares:
- Função apagaLeds(): Desliga todos os LEDs.
- Função ligaBuzzer(): Ativa o buzzer com uma frequência específica.
- Função desligaBuzzer(): Desativa o buzzer.

## Considerações Finais
Este projeto oferece uma solução prática e eficiente para controlar a iluminação de um ambiente de forma automatizada, adaptando-se às condições de luminosidade detectadas pelo fotoresistor. Além disso, a inclusão do buzzer proporciona um meio adicional de alerta, aumentando a utilidade e a aplicabilidade do sistema. Ao seguir este guia, os entusiastas e iniciantes em eletrônica poderão criar facilmente seu próprio sistema de controle de luminosidade e alerta sonoro utilizando um Arduino e componentes acessíveis.

 ## Projeto desenvolvido por 
 
 Gabriel Miranda - RM: 559102    
 Kheyla Thais - RM: 558434

 Users:
 
 @GabrielMiranda05   
 @KheyThay
