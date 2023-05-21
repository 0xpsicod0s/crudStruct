# CRUD de struct

Um CRUD de struct para criar, ler, atualizar e apagar um produto

# Como funciona?

### Função storeProduct
Esta tem como objetivo armazenar o produto criado em um array alocado justamente para esta finalidade, armazenar os produtos ja criados.

### Função readProduct
Esta tem como objetivo ler o produto com base no id informado pelo usuário

### Função updateProduct
Esta tem como objetivo atualizar o produto com base no id informado pelo usuário. Ficou faltando alguns ajustes, como verificar se o usuário enviou o campo nome ou preço em branco, se sim, o programa nao atualiza o campo que ficou vazio (caso o usuário queira atualizar apenas o campo preço e nao queria atualizar o campo nome e vice-versa, entende?). Talvez eu faça isso.

### Função deleteProduct
Esta tem como objetivo deletar o produto com base no id informado pelo usuário. Percebe-se o seguinte: `arrRegisteredProduct[i].id = -1;` eu fiz isso porque na função main eu desaloco toda a memória alocada na HEAP, na linha: `free(arrRegisteredProduct); arrRegisteredProduct = NULL;`
