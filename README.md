# Projeto de Análise Empírica

Disciplina: Estrutura de Dados Básicas I, Universidade Federal do Rio Grande do Norte.

##### Autores

- [Daniel Guerra](https://github.com/Codigos-de-Guerra)
- [Samir Pessoa](https://github.com/JamKingSPR)

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
  Intel core i7 3,1 GHz
  ```

- Memória

  ```bash
  10GB 2133MHz LPDDR3
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
g++ Ubuntu 5.4.0-6ubuntu1~16.04.9
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
buscaSequencial_Iterativa(inicio, fim, valor)
	para indice: 0 -> tamanho_vetor
		se (inicio+indice = valor) entao
			devolva inicio+indice
		fimse
	fimpara
	devolva valor nao achado
fim
```

Como pode-se obeservar, a partir do primeiro elemento do arranjo checa-se o valor e caso não seja o procurado, continua-se a busca para o próximo elemento, até achar o valor procurado ou chegar ao fim do arranjo.

##### Cenários

Como possíveis cenários em nossa busca, teremos o ***melhor caso***, ***caso médio*** e ***pior caso***. 

- **Melhor Caso:** Este é o caso em que o valor procurado encontra-se na primeira posição, logo, sendo necessária apenas uma iteração. O algoritmo possuiu complexidade $O(1)$ neste caso. Numa generalização, para um vetor de tamanho **N**(índices de **0** até **N-1**), para ser considerado **melhor caso**, o valor procurado **x**, deve se encontrar no vetor com índice de $1$.
- **Caso Médio:** Este é o caso considerado geral. Considerando-se as probabilidades de se encontrar o valor procurado, é visível que as chances do valor procurado estar no índice $0$, é a mesma de estar no índice $1$, $2$, ou qualquer outro. Logo, teremos uma complexidade $O(n)$.
- **Pior Caso:** Caso onde o elemento buscado não se encontra na amostra procurada, logo, obrigatoriamente iremos checar a amostra por completa para podermos afirmar que o valor não se encontra. Assim como no caso médio, teremos complexidade $O(n)$.

### Busca Binária

#### Descrição

A busca binária é um algoritmo simples de se abstrair e implementar e totalmente baseado na ideia de *divide and conquer*, na qual adotando a ideia de ordenação do vetor, são realizadas sucessivas divisões no intervalo da amostra a fim de diminuir o campo de busca, e que por se tratar da *busca binária*, iremos sucessivamente dividir nosso alcance de busca por 2. Uma vez realizada tal divisão, checaremos a posição relativa do nosso valor procurado com as 3 regiões formadas, sendo estas: o intervalo do início ao centro obtido, o próprio elemento central e o intervalo do meio ao fim. Se o valor buscado se encontrar no meio, então o achamos e agora o retornamos, senão, passarão a existir duas possibilidades: o valor ser menor que o elemento central, ou ser maior. Em ambos os casos iremos realizar novamente o processo de *divide and conquer* no novo intervalo criado.

Neste projeto, iremos analisar tanto sua versão iterativa quanto recursiva.

##### Pseudocódigo Iterativo

```bash
buscaBinaria_Iterativa(inicio, fim, valor)
	enquanto(inicio <= fim)
		posicao recebe (fim - inicio)/2 # A posição central
		se(valor = inicio+posicao) entao 
		# Inicio+posicao definido como a quantidade central somado ao inicio do vetor, logo, obtemos o valor central
			devolva inicio+posicao #Valor encontrado
		senao se(valor < inicio+posicao) entao
			fim = inicio + pos - 1
			#Procura-se até o centro, porém como já analisamos o centro, então o desconsideramos.
		senao #Só resta a opção do valor > inicio+posicao
			inicio = inicio+posicao+1
			#Começaremos a checar a partir do seguinte ao central
		fimse
	fimenquanto
	devolva valor nao encontrado
fim
```

Por ser esta a versão iterativa, definimos um limite de validação para parada da função, e enquanto dentro deste limite, devemos alterar nosso valores de início e fim de vetor, para que as checagens possam ser feitas sucessivamente com novos limites. Caso o limite seja ultrapassado e o valor não encontrado, consideramos que o valor não existe na amostra.

##### Pseudocódigo Recursivo

```bash
buscaBinaria_Recursiva (Arranjo[], inicio, fim, valor)
	posicao recebe (fim - inicio)/2 #A posição central
	se (inicio <= fim) entao
		se (valor = inicio+posicao) entao
		# Inicio+posicao definido como a quantidade central somada ao inicio do vetor, logo, obtemos o valor central
			devolva inicio+posicao
			# valor encontrado
		senao se (valor > inicio+posicao) entao
			faça a buscaBinaria_Recursiva(Arranjo, inicio+posicao+1, fim, valor)
			# Procura do meio ao fim
		senao
			faça a buscaBinaria_Recursiva(Arranjo, inicio, inicio+posicao - 1, valor)
			# Procura do inicio ao meio
		fimse
	fimse
	# Ao não passar pela validação, temos que o valor já não mais pertence a um intervalo possível
	devolva valor nao encontrado
fim
```

Na versão recursiva, já não precisamos definir um limite para reiniciar loops de checagem, mas precisamos de um validador para checar se ainda é coerente nossa checagem. Uma vez determinado o possível intervalo de onde nosso valor buscado possa estar, executamos novamente nosso função de busca com a passagem dos novos parâmetros, definindo tal intervalo. Achando o valor, o retornamos e saímos da função. Caso não achemos, retornamos um valor posterior ao fim da amostra.



##### Cenários

Teremos um ***melhor caso*** e ***pior caso*** na análise de ambos algoritmos de busca binária.

- **Melhor Caso:** Neste caso, o valor que queremos achar está exatamente no meio do amostra original, dessa forma, na primeira divisão por 2 iremos comparar nosso valor buscado com essa posição central, mas como são iguais tais valores, iremos retornar esta posição central. Como ainda dentro do primeiro conjunto de passos o valor foi encontrado, teremos uma complexidade de algoritmo $O(1)$. Numa generalização, para um vetor de tamanho **N**(índices de **0** até **N-1**), para ser considerado **melhor caso**, o valor procurado **x**, deve se encontrar no vetor com índice de $floor[n/2]$.
- **Pior Caso:** Aqui observaremos que a pior situação possível é onde o valor procurado não se encontra no arranjo, dessa forma, teremos que checar todos os intervalos possíveis até restar apenas a busca em um único elemento, e como eles serão diferentes, haverá o retorno de valor não encontrado. Logo, como checaremos todos as possibilidades, e cada possibilidade surge baseada no paradigma de *divide and conquer* usando **2**, ou seja, sempre pegando metade de um intervalo anterior, teremos uma complexidade de $O(log_2 n)$

### Busca Ternária

#### Descrição

Assim como a busca binária, a busca ternária também segue a ideia de *divide and conquer*, exigindo também a ordenação do vetor amostra a ser analisado. Por sua vez, as diminuições nos campos de busca se darão por divisões por $3$, e gerarão 5 regiões de busca diferentes: intervalo do início ao **primeiro terço** da amostra, o próprio elemento no *primeiro terço*, intervalo do primeiro terço até o **segundo terço**, o próprio elemento do *segundo terço* e o intervalo do segundo terço até o final. A exemplo da binária, também faremos checagens e definições de possíveis intervalos para o valor procurado existir.

Primeiro vemos se o valor procurado é igual ao elemento definido no primeiro ou segundo terço, caso não seja nenhum dos dois, nosso valor ainda pode ser menor que o elemento do primeiro terço, entre o primeiro e segundo terço, e ser maior que o segundo terço. Agora para próxima busca, iremos definir nosso novo intervalo, sendo eles, respectivamente, procurar do início ao primeiro terço, do primeiro ao segundo terço, e do segundo terço até o final.

##### Pseudocódigo Iterativo

```bash
buscaTernaria_Iterativa (inicio, fim, valor)
	enquanto (inicio_vetor <= fim_vetor)
		t1 recebe (fim - inicio)/3
		t2 recebe (fim - inicio)/3 + (fim - inicio)/3
		se (valor = inicio+t1) entao
			devolva inicio+t1 # valor procurado encontrado
			# Inicio+t1 definido como a quantidade do primeiro terço somada ao inicio do vetor, logo, obtemos o valor do primeiro terço
		senao se (valor = inicio+t2) entao
			devolva inicio+t2 # valor procurado encontrado
			# Inicio+t2 definido como a quantidade do segundo terço somada ao inicio do vetor, logo, obtemos o valor do segundo terço
		senao se (valor < inicio+t1) entao
			fim = inicio + t1 - 1
			
		senao se (valor < inicio+t2) entao
			inicio = inicio+t1+1
			fim = inicio + t2 - 1
		senao
			inicio = inicio+t2+1
		fimse
	fimenquanto
	devolva valor nao encontrado
fim
```

Exatamente com o mesmo raciocínio da binária, porém com mais checagens e passos, vemos que a forma de execução da função permanece bastante similar. Na versão iterativa, definimos um limite de validação para parada da função, e enquanto dentro deste limite, devemos alterar nosso valores de início e fim de vetor, para que as checagens possam ser feitas sucessivamente com novos limites de intervalo. Caso o limite seja ultrapassado e o valor não encontrado, consideramos que o valor não existe na amostra.



#####Pseudocódigo Recursivo

```bash
buscaTernaria_Recursiva (inicio, fim, valor)
	se (inicio < fim)
		t1 recebe (fim - inicio)/3
		t2 recebe (fim - inicio)/3 + (fim - inicio)/3
		se (valor = inicio+t1)
			devolva inicio+t1 #valor procurado encontrado
		senao se (valor = inicio+t2)
			devolva inicio+t2 #valor procurado encontrado
		senao se (valor < inicio+t1)
			faça a buscaTernaria_Recursiva (inicio, inicio+t1 - 1, valor)
		senao se (valor < inicio+t2)
			faça a buscaTernaria_Recursiva (t1+1, inicio+t2 - 1, valor)
		senao
			faça a buscaTernaria_Recursiva (inicio+t2+1, fim, valor)
		fimse
	fimse
	# Ao não entrar na validação, vemos que o valor já não mais pertence a um intervalo possível
	devolva valor nao encontrado
fim
```

Também seguindo a estrutura lógica da binária (*divide and conquer*), temos que na versão recursiva já não precisamos definir um limite para reiniciar loops de checagem, mas precisamos de um validador para checar se ainda é coerente nossa checagem. Uma vez determinado o possível intervalo de onde nosso valor buscado possa estar, executamos novamente nosso função de busca com a passagem dos novos parâmetros, definindo tal intervalo. Achando o valor, o retornamos e saímos da função. Caso não achemos, retornamos um valor posterior ao fim da amostra.

##### Cenários

Tanto para a versão iterativa quanto recursiva, os seguintes ***melhor caso*** e ***pior caso*** representam ambas.

- **Melhor Caso:** Para o melhor caso, o valor buscado deve ser igual ao valor presente no primeiro terço do vetor amostra original. Como foi dentro do primeiro conjunto de comparações e atribuições que o valor foi encontrado, então a complexidade é de $O(1)$. Numa generalização, para um vetor de tamanho **N**(índices de **0** até **N-1**), para ser considerado **melhor caso**, o valor procurado **x**, deve se encontrar no vetor com índice de $floor[n/3]$.

  ###### Obs:

  *Embora seja minúscula a diferença entre passos tomados e complexidade entre o caso do valor estar no primeiro ou no segundo terço, ainda assim pela definição da busca ternária, a checagem do primeiro terço vem primeiro, logo, se o valor estivesse no segundo terço, haveria essa comparação a mais para se obter o resultado.*

- **Pior Caso:** No pior caso, o valor não pertence ao arranjo a ser buscado, logo, serão realizadas todas as subsequentes divisões por 3, até restar apenas 2 valores a serem analisados, e ao percebemos que o valor buscado não é nenhum destes 2 retornamos que o valor não foi encontrado. Como estaremos sempre reduzindo nossa busca para um intervalo com $1/3$ do tamanho do anterior, então teremos uma complexidade de $O(log_3 n)$.

### Busca Fibonacci

#### Descrição

Juntamente com as buscas binárias e ternárias, a busca Fibonacci segue o padrão de **divide and conquer**, exigindo ordenação no vetor e realizando sucessivas divisões, além de similarmente possuir um crescimento logarítmico em seu tempo de busca em função do tamanho do vetor. Quanto às divisões em si, a busca Fibonacci não seguirá um único padrão de divisão para redução do alcance de busca, diferentemente das binárias e ternárias, que, respectivamente, dividiam-se por $2$ e $3$. Como quesito de divisão, a busca Fibonacci usará os próprios números da sequência de Fibonacci, na qual uma vez achado um valor da sequência correspondente ao tamanho do nosso vetor, definimos um outro valor como referência de índice que irá dividir o vetor.

Começamos achando o menor número da sequência que seja maior ou igual ao tamanho do vetor, para então tomarmos o valor 2 posições atrás na sequência deste que foi achado, como referência de índice nas buscas e comparações. Como esta busca também segue o *divide and conquer*, realizaremos as comparações de praxe com este índice. Caso o valor procurado **x** encontre-se neste endereço, o retornamos. Caso **x** seja menor, realizamos a busca novamente entre o início do vetor checado até o elemento anterior ao encontrado no endereço. Caso **x** seja maior, buscaremos entre o endereço que checamos $+ 1$ até o final do vetor atual.

###### Obs:

Posteriormente na análise de complexidade usaremos a [propriedade na cadeia de Fibonacci](https://www.geeksforgeeks.org/fibonacci-search/) que diz: $F(n-2)\approx \frac{F(n)}{3}$ e $F(n-1)\approx\frac{2*F(n)}{3}$. 

##### Pseudocódigo Iterativo

```bash
busca_Fibonacci(comeco, fim, valor)
	FibM recebe menor numero de Fibonacci maior que ou igual a tamanho_vetor
	FibM1 recebe o elemento um passo abaixo de FibM
	FibM2 recebe o elemento um passo abaixo de FibM1
	enquanto (FibM > 1) faça
		se (valor = inicio+FibM2) entao
			devolve inicio+FibM2
		senao se(valor < inicio+FibM2) entao
			FibM, FibM1, FibM1 descem 2 passos na sequencia
		senao
			FibM, FibM1, FibM2 descem 1 passo na sequencia
			inicio = FibM2+1
		fimse
	fimenquanto
	se (FibM1 = 1 e valor = inicio) entao
		devolve inicio
	fimse
	devolve valor nao encontrado
fim
```

Como mostrado no pseudocódigo, existe uma checagem de validação msm após a saída do loop. Isso ocorre porque através das subsequentes diminuições nos valores de referência para a busca, ainda existe a possibilidade de chegarmos à situação onde $FibM = 1$, $FibM1 = 1$ e $FibM2 = 0$, e neste caso a saída do loop é realizada porém ainda sobre um valor sem checagem, o valor atual, logo, executamos uma checagem para vermos se o valor buscado existe ali.

##### Cenários

Análises dos ***piores*** e ***melhores*** casos.

- **Melhor caso:** Ocorre quando o valor procurado encontra-se no primeiro índice calculado. Dessa forma, temos uma complexidade $O(1)$, uma vez que a primeira comparação terá sucesso. Não podemos estipular uma formúla geral para para o índice no melhor caso, baseando-nos somente no tamanho do vetor, precisamos de Fibonacci ainda.
- **Pior Caso:** Uma vez encontrada a referência de endereço a analisar, precisamos que o valor buscado **x** seja maior que o presente na referência, uma vez que assim passaremos a checar um bloco com $\frac{2}{3}$ do bloco que analisamos antes, ao invés de somente $\frac{1}{3}$, no caso de **x** ser menor que o valor encontrado na referência. Ou seja, o pior caso se encontra como um valor procurado além do limite superior do vetor. Como estaremos analisando sempre um bloco com $\frac{2}{3}$ do tamanho anterior, percebe-se aqui a forma logarítmica deste algoritmo de busca, com uma complexidade $O(log_\frac{3}{2} n)$.

### Jump Search

#### Descrição

Partindo do pressuposto da ordenação no vetor, a Jump Search executa buscas cada vez menores, porém, diferentemente da busca binária ou ternária, que seguem um padrão sucessivo na divisão e criação dos intervalos de busca, a Jump Search já define no início quais serão os blocos a serem analisados. Por sua vez, esta definição se dá com a obtenção de um valor $m$ que será o tamanho de pulo entre os blocos de busca, e que, a cada vez entrada num novo bloco de busca, decidimos se continuaremos a pular ou se checamos os valores existentes neste. Obtido $m$, utilizamos um **contador $k$ **para a quantidade de pulos executados até que não se posso mais gerar blocos de tamanho $m$, ou seja, o maior valor de $k$ deve satisfazer a condição **k*m < tamanho vetor.** 

Como cada bloco começa e termina baseado em $k*m$, analogamente às buscas ternárias e binárias, tomaremos nossas decisões com base na comparação entre o valor procurado **x** com o elemento no índice $k*m$. Caso seja igual, retornamos o endereço de $k*m$. Caso **x** seja menor, realizamos uma **busca linear (sequencial)** no bloco começando em $(k-1)*m$ e terminando em $k*m$. Caso **x** seja maior, daremos outro salto e realizamos o procedimento de comparação novamente.

*Para efeitos de busca e divisão coerente entre blocos, adotaremos $m = \sqrt{n}.$*

###### OBS: 

*Considerando um vetor **Vet **de tamanho **N** de índices **0** até **N-1**, caso **N-1** não seja múltiplo de $m$, o processo de criação dos blocos criará um último bloco de tamanho inferior a $m$. Como exemplo, um vetor tamanho $n = 9$, temos que $m = \sqrt{9} $; $m = 3$. Para $k=1$ teremos o elemento **Vet[3]**, para $k=2$ teremos **Vet[6]**, e quando fôssemos analisar $k=3$ veríamos que ele ultrapassa a condição limite para **k**, e então teríamos um bloco de **Vet[0]** até **Vet[3]**, outro de **Vet[3]** até **Vet[6]** e por último um bloco de **Vet[6]** até **Vet[8]**.  Acontecendo isso, então realizamos uma busca linear de* $k*m + 1$ *até o último elemento do vetor.*



##### Pseudocódigo

```bash
Jump_Search (inicio, fim, valor)
	tam_pulo recebe a raiz do tamanho_do_vetor
	k recebe valor 1 #primeiro valor para o contador de pulos
	enquanto (k*tam_pulo <= tamanho_do_vetor) faça
		se (valor = inicio+k*tam_pulo) entao
			devolva inicio+k*tam_pulo
		senao se (valor < inicio+k*tam_pulo) entao
			devolva o retorno da função buscaSequencial_Iterativa(inicio+(k - 1)*tam_pulo, inicio+k*tam_pulo, valor)
		senao
			k recebe seu valor +1
		fimse
	fimenquanto
	se ((k - 1)*m < tamanho_do_vetor) entao
		devolva retorno de buscaSequencial_Iterativa(inicio+(k - 1)*m, fim, valor)
fim
```

Começamos atribuindo valor à nossa variável de pulo $m$, para que então possamos analisar os blocos gerados. Esse algoritmo de busca tem uma boa utilidade como uma substituição da busca linear, uma vez que no Jump Search a busca linear é executada, porém com uma margem bem menor que a busca linear completa. Pode se pensar nesta, como uma otimização da busca linear.

##### Cenários

Segue a análise do **melhor** e **pior** caso.

- **Melhor Caso:** Assim como na busca sequencial, o melhor caso se dá quando o valor procurado **x** estiver presente na primeira posição do vetor, ou seja, após definido que o primeiro bloco gerado será buscado linearmente, encontraremos na primeira chamada da busca sequencial nosso elemento procurado. Assim, temos uma complexidade $O(1)$.
- **Pior Caso:** O pior desta busca muda conforme o tamanho do vetor (**n**).  Caso $\sqrt{n}$ não seja exato, haverá o bloco restante no final do vetor. O **pior caso** então seria definido pela quantidade de saltos executados, mais o custo da busca sequencial neste último bloco formado. Chegando nesse ponto, o elemento buscado deve encontrar-se no final do bloco, para que a busca sequencial demore mais. Logo, no geral a fórmula para o **pior caso** pode ser definido como $f(n) \approx\frac{n}{m} + (m-1)$. Quanto a sua complexidade, considerando que $m = \sqrt{n}$, teremos que $f(n) \approx \sqrt{n} + \sqrt{n} -1$. Então, teremos uma complexidade baseado na raiz de **n**, e $O(\sqrt{n})$.

## Resultados Obtidos

### Discussão

Através das análises aqui reforçadas, foi possível perceber de forma mais clara o funcionamento dos algoritmos implementados. Primeiramente, usufruindo das técnicas de complexidade temporal, pudemos efetuar comparações e conclusões acerta dos algoritmos de busca, e ter noção de suas restrições de uso, assim como muitos benefícios.

Também pudemoss chegar à conclusão que, dentre os algoritmos aqui analisados e implementados, a Busca Binária é a ***mais eficiente em termos de tempo para vetores***. Para análises gerais de vetores ordenados poŕem desconhecidos, recomenda-se o uso da busca Binária. Embora sua complexidade assintótica seja maior do que a ternária, podendo levar a crer que a ternária seja mais eficiente em determinados tamanhos, ainda existem diferenças entre ambas a serem analisadas.

A **Binária** possui um custo de $log_2(n) + O(1)$, ao passo que a **Ternária** possui custo $2*log_3(n) + O(1)$, uma vez que a para dividir em mais partes, também são realizadas mais comparações e passos, assim a ternária realizada 2 vezes mais operações a cada instância da binária.

Como $2*log_3(n) + O(1) = 2* \frac{log(2)}{log(3)}*log_2(n) + O(1)$, através de cálculos podemos chegar que: $2*\frac{log(2)}{log(3)} > 1$. Portanto, o custo da binária sempre será menor que o da ternária.

Contudo, num cenário de sistemas paralelos, é recomendado o uso de buscas *n-árias* cada vez mais divididas, repartindo a busca entre os processadores e, dessa forma, quanto mais dividir, mais rápida será a busca.

####Picos e Deformidades

Ao observamos os gráficos de medição de tempo, é possível notar a presença de picos no eixo y. Tal acontecimento é causado pelo sobrecarregamento do processador, além do fato de que a máquina precisa alternar entre processos em execução, causando com que em certos momentos, aparenta-se uma demora maior.



## Gráficos

### Busca Sequencial Iterativa

#### Tempo

![000000_Tim](/home/danieloguerra/Analise-Test/Imagens/1000000_Time.png)

#### Iterações

![000000_Ste](/home/danieloguerra/Analise-Test/Imagens/1000000_Step.png)



##### Comentários

É fácil inferir que a complexidade matemática esperada da função do tempo por tamanho de vetor, refletiu-se e provou-se correta na complexidade gerada no gráfico.

 

### Busca Binária Iterativa

#### Tempo

![100000_Tim](/home/danieloguerra/Analise-Test/Imagens/0100000_Time.png)

#### Iterações

![100000_Ste](/home/danieloguerra/Analise-Test/Imagens/0100000_Step.png)

##### Comentários

Como calculado previamente, a função gerada no gráfico seguiu um comportamento muito semelhante ao de uma função logarítmico. $log_2(n)$



### Busca Binária Recursiva

#### Tempo

![010000_Tim](/home/danieloguerra/Analise-Test/Imagens/0010000_Time.png)

#### Iterações

![010000_Ste](/home/danieloguerra/Analise-Test/Imagens/0010000_Step.png)

##### Comentários

Seguem as mesmas observações do modo iterativo. Fica claro a semelhança entre ambos os modos de implementação. $log_2(n)$



### Busca Ternária Iterativa

#### Tempo

![001000_Tim](/home/danieloguerra/Analise-Test/Imagens/0001000_Time.png)

#### Iterações

![001000_Ste](/home/danieloguerra/Analise-Test/Imagens/0001000_Step.png)

##### Comentários

Comportamento do gráfico também seguiu o previamente calculdo, da mesma forma que a binária.$log_3(n)$



### Busca Ternária Recursiva

#### Tempo

![000100_Tim](/home/danieloguerra/Analise-Test/Imagens/0000100_Time.png)

#### Iterações

![000100_Ste](/home/danieloguerra/Analise-Test/Imagens/0000100_Step.png)

##### Comentários

Segue mesmas inferências da recursiva binária e iterativa ternária.$log_3(n)$



### Busca Fibonacci

#### Tempo

![000010_Tim](/home/danieloguerra/Analise-Test/Imagens/0000010_Time.png)

#### Iterações

![000010_Ste](/home/danieloguerra/Analise-Test/Imagens/0000010_Step.png)

##### Comentários

Assim como nas buscas binárias e ternárias, podemos observar a semelhança com a função logarítimica, assim como o esperado.$log_\frac{3}{2}(n)$



### Jump Search

#### Tempo

![000001_Tim](/home/danieloguerra/Analise-Test/Imagens/0000001_Time.png)

#### Iterações

![000001_Ste](/home/danieloguerra/Analise-Test/Imagens/0000001_Step.png)

##### Comentários

Como falado previamente, o pior caso depende muito do tamanho $n$ do vetor. No gráfico acima observa-se diversas quedas e subidas; isso se deve ao fato de que conforme $n$ aumenta, as divisões $\frac{n}{floor[\sqrt{n}]}$deixam de serem exatas, mas também tornam-se exatas. Digamos que em certo momento a divisão seja exata, claramente ao aumentarmos um pouco o valor de $n$, passsaremos a ter uma divisão não exata, e continuaremos a aumentar até uma divisão exata se mostrar novamente. O gráfico demonstra exatemente isso, com o pior caso se mostrando presente quando a divisão é inexata e realiza-se uma busca sequencial num bloco irregular.



### Buscas de Complexidade Logarítmica

#### Iterações

![101010_Ste](/home/danieloguerra/Analise-Test/Imagens/0101010_Step.png)

##### Comentários

Pelo fato do gráfico de iterações provar-se mais fiel à análise, uma vez que não sofre interferência das variações da máquina, usaremos-o para comparar estes algoritmos de busca. Como já demonstrado, as buscas binária, ternária e Fibonacci seguem um padrão de crescimento logarítimico. Acima observa-se a prova de que a Binária é a mais rápida, seguida da Ternária e, por fim, a busca de Fibonacci.



### Recursiva x Iterativo

#### Binária

##### Iterações

![110000_Ste](/home/danieloguerra/Analise-Test/Imagens/0110000_Step.png)

#### Ternária

##### Iterações

![001100_Ste](/home/danieloguerra/Analise-Test/Imagens/0001100_Step.png)

##### Comentários

Para efeito de análise, usamos somente o gráfico de iterações, visto que ele não sofre alteração pela máquina. Como dito anteriormente, as versões iterativas e recursivas de ambas as buscas Binárias e Ternárias, não apresentam muitas mudanças de comportamento, sendo viável tanto o seu uso recursivo quanto iterativo. Porém com a Binária sendo a implementação preferível.



### Todas as Buscas

#### Tempo

![111111_Tim](/home/danieloguerra/Analise-Test/Imagens/1111111_Time.png)

#### Iterações

![111111_Ste](/home/danieloguerra/Analise-Test/Imagens/1111111_Step.png)

##### Comentários

Ao vermos ambos gráficos, fica óbvio o crescimento absurdo da **Busca Sequencial** em relação aos outros algoritmos. É recomendado evitar esta implementação, porém nos casos de arranjos de tamanhos pequenos, a **Busca Sequencial** pode ser uma opção a se considerar, visto que a diferença entre os algoritmos é acentuada ao analisar-se assintoticamente. Um vetor de tamanho 10 seria buscado rapidamente com a **Busca Sequencial**.

