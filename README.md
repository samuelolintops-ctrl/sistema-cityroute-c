# CityRoute C — Sistema de Logística Urbana e Gerenciamento de Pedidos

Projeto desenvolvido em C para a disciplina de Estrutura de Dados I (Ciência da Computação - UESC).
O sistema simula o funcionamento de uma central de distribuição urbana, gerenciando pontos de entrega, fila de despacho por prioridade, histórico de operações e análise comparativa de algoritmos de ordenação.

**Estruturas de Dados Utilizadas:**
* Árvore Binária de Busca (BST): Cadastro, busca, remoção (com validação de pendências) e listagem ordenada (in-order) dos Pontos de Entrega, implementada com nós encadeados e recursividade.
* Heap Binário (Min-Heap Dinâmico): Gerenciamento da Fila de Prioridade de pedidos pendentes (1 = Convencional; 2 = VIP; 3 = Expressa), com critério de desempate FIFO via contador incremental de ordem de chegada.
* Lista Encadeada: Armazenamento persistente em memória do Histórico de Operações já despachadas.
* Algoritmos de Ordenação: Implementação de um algoritmo quadrático O(n^2) e um logarítmico O(n log n) para geração de relatórios e benchmarking de desempenho (N = 100, 1.000 e 10.000 elementos).

**Funcionalidades Principais:**
* Pontos de Entrega (BST): Cadastrar, buscar por ID, listar em ordem crescente e excluir pontos (bloqueando exclusão caso haja pedidos pendentes para o local).
* Pedidos (Heap): Inserir pedidos validando o destino na BST, consultar o próximo pedido da fila, processar despacho para o histórico e exibir pendentes.
* Histórico: Consultar todos os pedidos despachados ou buscar especificamente por código de rastreio.
* Relatórios e Testes: Gerar cópia ordenada do histórico (por código ou valor), executar carga inicial automatizada e comparar tempo/operações entre algoritmos O(n^2) e O(n log n).
  
**Autores:**
Discentes: Rodrigo Freitas, Samuel Olinto, Thaissa Sampaio e Vinicius Lopes
Curso: Ciência da Computação — UESC
