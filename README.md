# Algoritimos-e-Estrutura-de-dados-2
Códigos feito por mim durante o curso de Engenharia de Computação, na Faculdade Tecnológica do Paraná. Matéria: Algoritmos e Estruturas de Dados 2, ministrada por Jefferson Tales Oliva.

# Força-bruta - problema do troco
Implemente a solução do problema do troco (conforme apresentado em sala de aula) utilizando a estratégia de força-bruta.

**Input Format:**

A primeira linha deve conter o valor do troco. A segunda linha deve conter a quantidade de moedas, que representará o tamanho do vetor que deverá ser lido logo em sequência.

**Output Format:**

Sequência de moedas que foram retornados como troco.

# Agoritmos gulosos - sequenciamento de tarefas em uma máquina
Dada uma máquina que execute uma sequência de n tarefas. Cada tarefa tem um tempo de execução e um deadline. É desejável que todas as tarefas sejam finalizadas sem atrasos, mas nem sempre isso é possível. Uma alternativa para compensar possíveis atrasos, seria a execução de tarefas que terminam antes do tempo e aproveitar esse saldo para executar as outras tarefas. No final da execução de todas as tarefas, se o saldo de tempo (deadline acumulado) for maior igual a zero, então o atraso é igual a zero. Caso o saldo de tempo seja negativo, então o atraso é equivalente ao módulo desse saldo (nesse problema, basta multiplicar o saldo por -1). Desse, o objetivo seria encontrar uma sequência de atividades que minimize o atraso.

Implemente uma função que receba um vetor de atividades de tamanho n. A função deverá imprimir a sequência ótima de atividades que foram executados até ou antes do deadline e retornar o valor do atraso.

Sugestão de estrutura para a representação do problema:

    typedef struct{
        int id; // identificador da tarefa, que será a i-ésima tarefa lida
        int e; // tempo de execução
        int d; // deadline
    }
    
**Input Format:**

Na primeira linha, dever lido o valor de n, que é a quantidade de tarefas.

Nas n seguintes linhas devem ser lidos, em sequência, o tempo de execução e o deadline da i-ésima tarefa.

**Output Format:**

Na primeira linha deve ser impressa a sequência ótima de atividades executadas sem atraso.

Na segunda linha deve ser impressa o atraso total.

# Algoritmos gulosos - Seleção de atividade
Dona Lurdes é responsável pelo gerenciamento de uma sala de aula, onde ela deve alocar a maior quantidade de aulas possíveis durante o expediente. No entanto, fazer essa tarefa de forma otimizada e manualmente pode ser uma tarefa muito difícil, pois muitas disciplinas podem ter horários que sobrepõem entre elas.

Implemente uma função, por meio da estratégia gulosa, para que a maior quantidade possíveis de aula possam ser alocadas na sala.

**Input Format:**

A primeira linha deve ser um número inteiro n referente à quantidade de atividades. Para cada uma das próximas n linhas devem ser lidos o id da tarefa e os horários de início e de fim para cada atividade.

**Constraints:**

As aulas devem ser ordenadas crescentemente pelo horário de término.

**Output Format:**

A primeira linha apresenta a mensagem "Aulas alocadas:" seguida do id das aulas que foram alocadas na respectiva sala.

# Divisão e conquista - soma máxima
Dado um vetor de inteiros. Implemente uma função, utilizando divisão e conquista, que encontre a soma máxima no vetor. Por exemplo: para o vetor v = {-1, 3, 0, -2, 1, 3, -4, 5}, a soma máxima é 12 (3 + 0 + 1 + 3 + 5).

**Input Format:**

A primeira linha deve ser um número inteiro n referente ao tamanho do vetor. Em seguinda, Para cada uma das próximas n linhas devem ser lidos os elementos do vetor.

**Output Format:**

Soma máxima dos elementos do vetor.


# Árvore AVL - soma dos fatores de balanceamento
Implemente uma função que receba uma árvore AVL como parâmetro. A função deverá retornar a soma dos fatores de balanceamento.

**Input Format:**

Na primeira linha deve ser lido o número inteiro N, que é referente à quantidade de nós da árvore AVL. Em seguida, em cada linha deve ser lido um número inteiro para ser inserido como nó na árvore (fazer isso até que N números sejam lidos).

**Output Format:**

Imprimir o resultado da soma dos fatores de balanceamento de todos os nós da árvore.
