# Desafio

### Informações sobre o desafio:

Suponha que existam duas listas vinculadas individualmente que se cruzam em algum ponto e se tornar uma única lista vinculada. Os ponteiros de início ou início de ambas as listas são conhecidos, mas o nó de interseção não é conhecido. Além disso, o número de nós em cada uma das listas antes eles se cruzam é desconhecido e pode ser diferente em cada lista. List1 pode ter n nós antes atinge o ponto de interseção, e List2 pode ter m nós antes de atingir o ponto de interseção onde m e n podem ser m = n, m < n ou m > n. Construa um algoritmo para encontrar o ponto de fusão entre as listas L1 e L2. 

### Algoritmo: 
```
1. Crie duas pilhas: uma para a primeira lista e outra para a segunda lista. 
2. Percorra a primeira lista e empilhe todos os endereços de ‘nodes’ para a primeira pilha. 
3. Percorra a segunda lista e empurre todos os endereços de ‘nodes’ para a segunda pilha. 
4. Agora ambas as pilhas contêm o endereço do nó das listas correspondentes. 
5. Agora compare o endereço do nó superior de ambas as pilhas. 
6. Se forem iguais, pegue os elementos superiores de ambas as pilhas e mantenha-os em uma variável temporária. 
7. Continue este processo (desempilhando) até que os endereços dos nós no topo das pilhas não sejam os mesmos. 
8. Este ponto é aquele em que as listas se fundem em uma única lista. 
9. Retorna o valor da variável temporária.
```
### Resumo:

O desafio consiste em cria 2 listas e mesclar ao final de cada lista uma terceira lista. Apos isso, pegar os endereços de memoria de cada lista e empilhar, para verificar em que ponto da pilha e da lista o endereço de memoria se coincidem, retornando o valor do dado dentro desse endereço de memoria. 
