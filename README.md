ALUNO: DARLISON DE SOUSA SANTOS PIRES.

ESTRUTURA GERAL DO PROGRAMA

ENTRADA
Usuário escolhe uma opção do menu (0 a 5)

Programa lê a opção com scanf

PROCESSAMENTO
switch-case direciona para a operação escolhida

SAÍDA
Executa a operação e mostra o resultado na tela


CASE 1 - CREATE (INCLUIR)
ENTRADA

- Nome digitado pelo usuário (scanf)

PROCESSAMENTO

1. Percorrer a matriz para encontrar primeira linha vazia
   - Se não encontrar (matriz cheia) → definir erro
   
2. Percorrer a matriz para verificar se o nome já existe
   - Comparar cada nome salvo com o nome digitado (strcmp)
   - Se encontrar igual → definir nome duplicado
   
3. Se tiver linha vazia E nome não duplicado:
   - Copiar nome para a linha vazia (while caractere por caractere)
   - Adicionar '\0' no final

 SAÍDA

- Se matriz cheia: "ERRO: Banco de dados cheio!"
- Se nome duplicado: "ERRO: Nome 'X' ja existe! Crie um nome unico."
- Se sucesso: "SUCESSO: Nome salvo na posicao X!"


CASE 2 - READ (BUSCAR)

ENTRADA

- Nome digitado pelo usuário (scanf)

PROCESSAMENTO

1. Percorrer a matriz comparando cada nome com o nome buscado (strcmp)
   - Ignorar linhas vazias (primeiro caractere '\0')
   
2. Se encontrar nome igual:
   - Guardar o índice da linha
   - Interromper busca (break)
   
3. Se não encontrar:
   - Manter índice como -1

SAÍDA

- Se encontrou: "Nome encontrado no indice: X"
- Se não encontrou: "Nome nao encontrado."



CASE 3 - UPDATE (MODIFICAR)

ENTRADA

- Nome antigo digitado pelo usuário (scanf)
- Novo nome digitado pelo usuário (scanf)

PROCESSAMENTO


1. Buscar nome antigo na matriz (strcmp)
   - Se não encontrar → definir erro
   - Se encontrar → guardar posição
   
2. Verificar se novo nome já existe em OUTRA posição
   - Percorrer matriz comparando (strcmp)
   - Pular a posição do nome que será alterado
   - Se encontrar igual → definir nome duplicado
   
3. Se nome antigo existe E novo nome não duplicado:
   - Substituir nome antigo pelo novo (while caractere por caractere)
   - Adicionar '\0' no final


SAÍDA


- Se nome antigo não existe: "ERRO: Nome 'X' nao encontrado!"
- Se novo nome duplicado: "ERRO: Nome 'X' ja existe no sistema!"
- Se sucesso: "SUCESSO: Nome alterado para 'X'!"



CASE 4 - DELETE (APAGAR)

ENTRADA

- Nome digitado pelo usuário (scanf)
- Confirmação S/N (scanf)

PROCESSAMENTO

1. Buscar nome na matriz (strcmp)
   - Se não encontrar → definir erro
   - Se encontrar → guardar posição
   
2. Pedir confirmação do usuário (S/N)
   
3. Se confirmado (S ou s):
   - Colocar '\0' no primeiro caractere da linha
   - Isso marca a linha como "vazia"


SAÍDA


- Se nome não existe: "ERRO: Nome 'X' nao encontrado!"
- Se cancelado: "Operacao cancelada."
- Se confirmado: "SUCESSO: Nome removido!"


CASE 5 - LISTAR TODOS

ENTRADA

- Nenhuma (não precisa de entrada do usuário)


PROCESSAMENTO
1. Percorrer toda a matriz
2. Contar quantas linhas não estão vazias (primeiro caractere != '\0')
3. Para cada linha ocupada, guardar índice e nome


SAÍDA

- Cabeçalho: "Indice | Nome"
- Para cada registro: "X | nome"
- Se vazio: "(banco de dados vazio)"
- Rodapé: "Total de registros: X / 50"

FLUXO COMPLETO DO PROGRAMA

INÍCIO
  |
  v
Inicializar matriz (todas linhas vazias)
  |
  v
Mostrar menu
  |
  v
Ler opção (ENTRADA)
  |
  v
switch(opcao)
  |
  ├─ case 1: ENTRADA(nome) → PROCESSAMENTO(validar, salvar) → SAÍDA(mensagem)
  |
  ├─ case 2: ENTRADA(nome) → PROCESSAMENTO(buscar) → SAÍDA(índice ou não encontrado)
  |
  ├─ case 3: ENTRADA(nome antigo, nome novo) → PROCESSAMENTO(validar, substituir) → SAÍDA(mensagem)
  |
  ├─ case 4: ENTRADA(nome, confirmação) → PROCESSAMENTO(buscar, apagar) → SAÍDA(mensagem)
  |
  ├─ case 5: ENTRADA(nenhuma) → PROCESSAMENTO(percorrer, contar) → SAÍDA(lista)
  |
  ├─ case 0: SAÍDA("Saindo do sistema...")
  |
  └─ default: SAÍDA("Opcao invalida!")
  |
  v
Se opção != 0 → pausar e voltar ao menu
Se opção == 0 → FIM

