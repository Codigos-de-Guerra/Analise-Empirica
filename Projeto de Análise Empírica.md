# Projeto de Análise Empírica



## Descrição do projeto

​	Relatório técnico feito com o propósito de descrever análises obtidas, através de diversos casos teste, sobre os tempos de busca e passos necessários na execução de 7 diferentes algoritmos de busca. Espera-se que através deste relatório seja possível perceber as melhores situações de uso para algoritmo, além dos requisitos necessários para suas implementações, podendo, assim, perceber o melhor curso de ação baseado no problema em que o cliente se encontrar.

​	Neste relatório, encontram-se também diversas observações complementares ao entedimento, e gráficos gerados para visualização das quantias usadas e curvas de crescimento(tempo e iterações) para cada algoritmo utilizado.



## Método de Utilização



### Pré-requisitos

A máquina a ser utilizada na execução completa ,e sem alteração do projeto, deve vir a possuir:

- ##### Compilador G++;

  Necessário para compilação dos programas *source* e gerador de arquivos para plotagem no ***GNUPLOT***.

  ```bash
  # Como instalar no Ubuntu 16.04 LTS:
  sudo apt-get install g++
  ```

- ##### Gnuplot¹;

  Necessário pra plotagem de gráficos a serem analisados.

  ```bash
  # Como instalar no Ubuntu 16.04 LTS:
  sudo apt-get update
  sudo apt-get install gnuplot
  ```

  [^¹]: Programa de geração de gráficos tanto em 2D quanto 3D, utilizando séries de pontos ou funções.

- ##### Git.

  Necessário para utilização dos comandos ***git*** no terminal.

  ```bash
  # Como instalar no Ubuntu 16.04 LTS:
  sudo apt-get update
  sudo apt-get install git
  ```




### Materiais Utilizados

#### Caracterização técnico da máquina utilizada

- Processador

  ```bash
  Intel core i7-alguma coisa
  ```

- Memória

  ```bash
  16GB, LPDDR3, alguma coisa
  ```

#### Linguagem de programação utilizada

```bash
C++ 11
```

#### Versão do sistema operacional utilizado

```bash
Ubuntu 16.04 LTS
```

#### Tipo e versão do compilador utilizado

```bash
g++ (Não faço ideia)
```



### Compilação

Primeiro recuperamos, para qualquer diretório desejado, o repositório do projeto usando o comando ***git***:

```bash
git clone https://github.com/Codigos-de-Guerra/Analise-Empirica.git
```

Agora, para compilação do programa usaremos o arquivo ***makefile***, com os seguintes comandos a serem utilizados:

```bash
# Compilando e gerando executável
make

# Para exclusão de dados residuais:
## Excluindo o executável
make cleanbin

## Excluindo a pasta de arquivos objeto
make cleanobj

## Execluindo a pasta de arquivos de saída
make cleanout

## Excluindo todos acima
make clean
```

### Execução

Realizada a compilação, dentro do diretório raiz do projeto iremos executar o programa com os parâmetros desejados:

```bash
./analise [MiTA] [MaTA] [CT] [AU]
```

Para realizarmos uma busca e análise de algoritmos sucinta, precisamos definir o tamanho do vetor e alcance da busca. Como extras da execução, iremos também definir a quantidade de casos testes e quais algoritmos a serem utilizados. Como recurso de dinamização do código, os incrementos no tamanho entre vetores, é sempre o mesmo.

- [MiTA] - ***Mínimo Tamanho Alocado***

  Neste parâmetro definimos o menor tamanho de vetor a ser buscado.

  ​

- [MaTA] - ***Máximo Tamanho Alocado***

  Neste, definimos o maior tamanho possível de vetor para realização da nossa busca.

  **Obs:** Atenção na determinação do tamanho máximo, pois dependendo da máquina utilizada pode ocorrer falha na alocação devido a um excesso na memória.

  ​

- [CT] - ***Casos Teste***

  Neste, definimos a quantidade de testes, ou seja, a quantidade de diferentes tamanhos de vetor a serem analisados.

  ​

- [AU] - ***Algoritmos Utilizados***

  Por último, escolhemos quais algoritmos de busca desejamos utilizar e checar. Este parâmetro deve possuir somente os algarismos $1$ e $0$, e um tamanho de 7.

  ######Exemplos:

  `1000000` Irá rodar apenas o 1° algoritmo.

  `0111100` Irá rodar apenas o 2°, 3°, 4° e 5° algoritmos.

  `1001` Não irá rodar, e emitirá uma mensagem de erro, pois deve possuir tamanho estritamente igual à 7.

Então, se quisermos buscar um vetor entre $10000$ e $500000$ elementos, checando $100$ casos teste diferentes e utilizando todos as buscas, teremos a seguinte execução do programa:

```bash
./analise 10000 500000 100 1111111
```

O programa então irá executar $100$ vezes cada busca selecionada, criar uma média de tempo necessário para busca e realizar contagem das iterações necessárias para cada busca, para então, armazenar tais dados em arquivos separados.


#### Criação de gráficos

Para plotar os gráficos desejados, utilizaremos o software livre ***GNUPLOT*** e um script em  `C++` para gerar um arquivo contendo as especificações do gráfico a ser gerado. 



Ainda precisamos compilar o executável para gerar tais arquivos, logo, dentro da raiz do repositório:

```bash
# Compilando e gerando executável
make plot
```

Agora, ainda na raiz, para executá-lo usamos:

```bash
./plot [TG] [AS]
```



- [TG]	 - ***Tipo de Gráfico***

  Trata-se do parâmetro para definir qual deve ser a comparação realizada no gráfico.  Uma comparação entre *Iterações realizadas* e *Tamanho do vetor*, ou entre *Média do tempo* e *Tamanho do vetor*. Este parâmetro deve ser única e exclusivamente o número $1$ ou $0$.

  - `0` gerará um gráfico *Iterações x Tamanho;*

  - `1` gerará um gráfico *Tempo de busca x Tamanho*;

  - `2` gerará uma mensagem de erro.

    ​

- [AS] - ***Algoritmos Selecionados***

  Parâmetro que irá escolher quais algoritmos serão comparados no gráfico.

##### Exemplos:

```bash
./plot 0 0001110
```

Rodar o executável acima irá plotar um gráfico de comparação entre as iterações realizadas e o tamanho do vetor entre apenas o 4°, 5° e 6° algoritmo de busca.



#### Ordem dos Algoritmos

Para ambos os executáveis previamente mostrados, a ordem dos algoritmos de busca é da seguinte forma:

- 1º: **Busca Sequencial Iterativa**;
- *2º:* **Busca Binária Iterativa**;
- *3º:* **Busca Binária Recurssiva;**
- 4º: **Busca Ternária Iterativa;**
- 5º: **Busca Ternária Recurssiva;**
- 6º: **Busca Fibonacci**;
- 7º: ***Jump Search***.



####Organização das Amostras

No quesito de geração de amostras, o programa recebe via linha de comando o maior tamanho alocado **[MaTA]**, o menor tamanho alocado **[MiTA]** e a quantidade de casos teste **[CT]**.

Então, calcula-se o valor de incremento com $(([MaTA] - [MiTA])/[CT])$, então, a partir do menor tamanho alocado **[MiTA]**, incrementa-se o tamanho do vetor usando o valor de incremento até chegar no maior tamanho alocado **[MaTA]**, dessa forma, são criados **[CT] + 1** diferentes tamanhos de vetor. Todos preenchidos sequencialmente, visto que a maioria dos algoritmos de busca a serem testados necessitam de um **vetor ordenado** e **sem elementos repetidos**.



#### Uso das Buscas

Todos os algoritmos serão testados na busca por um elemento inexistente, ou seja, iremos analisar somente o **pior caso**.



## Algoritmos Implementados

### Busca Sequencial Iterativa

#### Descrição

Também chamada de busca linear, é uma das formas de busca mais rudimentares que existem, e dentre os algoritmos aqui testados, a mais básica. Consiste de percorrer sequencialmente (linearmente), o vetor inteira, e a cada parada checar se é o valor procurado ou não.

Sua aplicação não exije um vetor ordenado, visto que de qualquer maneira, ele checará todos os elementos. Em casos que a ordenação existe, é altamente recomendado que opte por outro algoritmo de busca mais eficiente, uma vez que o crescimento do tempo em função do tamanho da amostra é demasiadamente grande. A depender do cenário problema, mesmo que o vetor não esteja ordenado, é preferível que seja implementada uma função de ordenação e utilizada outra técnica de busca, pois ainda é possível esta ser a versão mais rápida.

 ##### Pseudocódigo

```bash
buscaSequencial_Iterativa(vetor, valor)
	para indice: 0 -> tamanho_vetor
		se (vetor[indice] = valor) entao
		devolva indice
		fimse
	fimpara
	devolva valor nao achado
fim
```















Nesterelatórioencontram-se também todas as informações obtidas sobre cadaalgoritmo, para diferentes tamanhos de vetor. As curvas decrescimento das buscas, as eficácias e recomendações básicas parasituações específicas. Esperamos que através deste relatório,seja possível que nosso cliente entenda sua situação e siga nossarecomendação de qual curso de ação seguir.