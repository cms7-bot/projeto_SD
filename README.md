# 🎮 Jogo do Passa ou Repassa (Arduino)

## 📌 Descrição

O **Jogo do Passa ou Repassa** é um projeto interativo desenvolvido com
**Arduino Uno** para testar o reflexo de dois jogadores.

O sistema funciona da seguinte forma:

-   Ao iniciar a rodada, o jogador pressiona o botão de **reset**.
-   Após um tempo aleatório, o LED vermelho acende.
-   O primeiro jogador que apertar seu botão após o LED acender vence a
    rodada e ganha um ponto.
-   Se algum jogador apertar antes do LED acender, ele é "queimado" e o
    adversário ganha o ponto.
-   O placar é exibido no **Monitor Serial**.

------------------------------------------------------------------------

## 🎯 Objetivos

-   Criar um jogo interativo para testar reflexos.
-   Implementar um sistema de penalidade por antecipação.
-   Exibir o placar em tempo real.
-   Permitir reinício da rodada com botão reset.

------------------------------------------------------------------------

## 🛠 Componentes Utilizados

-   1x Arduino Uno
-   2x Botões (Jogadores)
-   1x Botão de Reset
-   3x LEDs (Vermelho, Verde e Azul)
-   3x Resistores de 220Ω
-   1x Protoboard
-   Jumpers (fios)
-   1x Cabo USB
-   1x Display LCD
------------------------------------------------------------------------

## ⚙️ Funcionamento

1.  Pressione o botão de reset.
2.  O sistema aguarda entre 2 e 6 segundos.
3.  O LED vermelho acende.
4.  Os jogadores apertam seus botões.
5.  O primeiro a apertar vence.
6.  Se alguém apertar antes, perde a rodada.
7.  O placar é atualizado no Monitor Serial.

------------------------------------------------------------------------

## 💻 Lógica de Programação

O código utiliza:

-   `random()` para tempo aleatório
-   `digitalRead()` para ler botões
-   `digitalWrite()` para LEDs
-   `Serial.print()` para mostrar placar
-   Estruturas condicionais (`if/else`)

------------------------------------------------------------------------

## 📚 Competências Desenvolvidas

-   Eletrônica básica
-   Uso de protoboard
-   Leitura de entradas digitais
-   Controle de saídas digitais
-   Programação em Arduino
-   Temporização
-   Comunicação serial

------------------------------------------------------------------------

## 👨‍💻 Equipe

-   Arthur Henrique
-   Caio Moraes
-   Igor Almeida
-   José André

------------------------------------------------------------------------

## 📄 Licença

Projeto acadêmico para fins educacionais.
