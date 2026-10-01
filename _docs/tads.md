# 📚 Guia TADs Baseados em Listas

As estruturas de dados lineares armazenam elementos de forma sequencial.

---

## 🔗 1. Lista Encadeada (Singly Linked List)
> **O que é?** Uma sequência de elementos (nós) onde cada nó contém o dado armazenado e um "ponteiro" (referência) para o próximo nó da sequência. Diferente de um array tradicional, seus elementos não precisam estar em posições contíguas na memória.

*   **Vantagens:** Tamanho dinâmico; inserção e remoção no início são incrivelmente rápidas (não exige realocação de elementos).
*   **Desvantagens:** Não permite acesso aleatório rápido (para achar o 5º elemento, você precisa passar pelos 4 primeiros).
*   **Quando usar?** 
    * Quando você não sabe a quantidade exata de itens que vai armazenar (crescimento dinâmico).
    * Quando há necessidade de muitas inserções e remoções no início ou meio da estrutura, e a busca não é a operação mais frequente.

---

## ↔️ 2. Lista Dinâmica Duplamente Encadeada (Doubly Linked List)
> **O que é?** Uma evolução da lista encadeada simples. Aqui, cada nó possui **dois** ponteiros: um aponta para o próximo elemento e outro aponta para o elemento anterior.

*   **Vantagens:** Permite percorrer a lista nos dois sentidos (frente para trás e trás para frente). Facilita a remoção de um nó específico se você já tem a referência dele.
*   **Desvantagens:** Ocupa mais memória (devido ao ponteiro extra) e exige mais cuidado na atualização dos ponteiros durante inserções/remoções.
*   **Quando usar?** 
    * Sistemas de navegação com "Avançar" e "Voltar" (ex: histórico de navegador web).
    * Editores de texto (navegação do cursor).
    * Cache LRU (Least Recently Used), onde itens precisam ser movidos rapidamente para o topo.

---

## 🔄 3. Lista Circular
> **O que é?** Pode ser simples ou duplamente encadeada, mas com um diferencial: o ponteiro do **último nó aponta de volta para o primeiro nó**, formando um ciclo infinito. Não existe um "fim" (null) na lista.

*   **Quando usar?** 
    * Algoritmos de escalonamento de processos em Sistemas Operacionais (ex: *Round-Robin*, onde a CPU dá um tempinho para cada processo em um ciclo eterno).
    * Jogos de tabuleiro multiplayer, onde os turnos passam de um jogador para outro e, após o último, voltam ao primeiro.
    * Buffers circulares de streaming de mídia.

---

## 🥞 4. Pilha (Stack)
> **O que é?** Uma estrutura que segue o princípio **LIFO** (*Last In, First Out* - O último a entrar é o primeiro a sair). Pense em uma pilha de pratos: você só pode colocar um prato no topo e só pode retirar o prato do topo.

*   **Quando usar?** 
    * Sistemas de "Desfazer/Refazer" (Undo/Redo) em softwares.
    * Avaliação de expressões matemáticas (notação polonesa reversa).
    * Rastreamento de chamadas de funções na memória (*Call Stack*).
    * Algoritmos de navegação em labirintos ou busca em profundidade (DFS) em grafos.

---

## 🚥 5. Fila (Queue)
> **O que é?** Uma estrutura que segue o princípio **FIFO** (*First In, First Out* - O primeiro a entrar é o primeiro a sair). Exatamente como uma fila de banco: quem chega primeiro, é atendido primeiro.

*   **Quando usar?** 
    * Spoolers de impressão (documentos aguardando para serem impressos).
    * Gerenciamento de requisições em servidores web (fila de atendimento).
    * Troca de mensagens entre sistemas assíncronos.
    * Busca em largura (BFS) em árvores e grafos.

---

## 🛸 6. Deque (Double-Ended Queue)
> **O que é?** Uma fila de duas pontas. É um híbrido maravilhoso que permite **inserir e remover elementos tanto no início quanto no fim** da estrutura, unindo características de Pilhas e Filas.

*   **Quando usar?** 
    * Verificação de palíndromos (palavras que são lidas iguais de frente para trás, retirando letras das pontas simultaneamente).
    * Algoritmos de "roubo de trabalho" (*Work-stealing*) em multiprocessamento.
    * Resolução de problemas complexos como "Máximo em Janelas Deslizantes" (Sliding Window Maximum).

---

## 🕸️ 7. Matrizes Esparsas (Sparse Matrices via Listas)
> **O que é?** Matrizes matemáticas enormes onde a grande maioria dos valores é zero. Armazenar todos esses zeros em um array 2D desperdiça muita memória. Como solução, representamos a matriz usando **listas encadeadas ortogonais**, armazenando apenas os elementos que *não são zero* (guardando suas coordenadas de linha e coluna).

*   **Quando usar?** 
    * Computação científica e simulações físicas pesadas.
    * Representação de Grafos gigantes através de Matrizes de Adjacência (redes sociais, mapas geográficos).
    * Machine Learning (sistemas de recomendação onde um usuário interage com muito poucos itens do catálogo total).

---

## ⭐️️ 8. Fila de Prioridade (Priority Queue)
Semelhante à fila convencional, mas os elementos possuem uma **prioridade**. O elemento de maior prioridade sempre sai primeiro, independentemente de quando ele entrou. (Geralmente implementada usando *Heaps*, mas conceitualmente é uma lista gerenciada por importância).
*   **Aplicações:** Sistemas de triagem de hospitais, algoritmos de compressão de dados (Huffman) e cálculo de menor caminho em mapas (Dijkstra).

## 🦘 9. Skip List (Lista de Saltos)
Uma lista encadeada "tunada" com múltiplas camadas sobrepostas de ponteiros, permitindo "pular" vários elementos de uma vez. É uma alternativa baseada em probabilidade às árvores binárias balanceadas.
*   **Aplicações:** Bancos de dados na memória (como o Redis) que precisam de buscas absurdamente rápidas (tempo $O(\log n)$) mantendo a estrutura simples de uma lista encadeada.

---

## 📝 Resumo Rápido para Decisão

| TAD | Preciso acessar o meio? | Inserções nas pontas? | Regra principal |
| :--- | :---: | :---: | :--- |
| **Pilha** | Não | Apenas Topo | LIFO (Último entra, 1º sai) |
| **Fila** | Não | Ambas pontas | FIFO (1º entra, 1º sai) |
| **Deque** | Não | Ambas pontas | Versátil (Pilhas + Filas) |
| **L. Encadeada** | Sim (lento) | Em qualquer lugar | Dinamismo |
| **L. Dupla** | Sim (lento) | Em qualquer lugar | Dinamismo + Vai e Volta |
| **Matriz Esparsa**| Sim (rápido) | - | Economia extrema de memória|
