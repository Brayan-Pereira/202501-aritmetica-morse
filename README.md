# 🔥 Warmup - Aritmética Morse

## 👥 Integrantes do Grupo

- **Brayan Pereira** - RA: 2023100832  
- **Bernardo Rodrigues** - RA: 2023100357  
- **João Gabriel** - RA: 2023100603  

---

## ⚙️ Como o Programa Funciona

O programa lê arquivos de instância do diretório `02-aritmetica-morse/input/` e processa expressões compostas por números em **código Morse aritmético**, usando a seguinte lógica:

1. **Conversão Morse**: Cada caractere representa um valor:
   - `.` → 1  
   - `-` → 5  
   - `:` → 2  
   - `=` → 10  

2. **Leitura da Expressão**: Alterna entre valores Morse e operadores (`+` ou `*`).

3. **Avaliação**: Soma e multiplicação são aplicadas da esquerda para a direita, sem precedência de operadores.

4. **Saída**: O resultado final é gravado no arquivo `output/solution.txt`.

---

## 🔧 Funções Principais

- `morse_to_value(char c)` → Converte um caractere Morse para inteiro  
- `parse_morse_number(const char* morse)` → Converte uma sequência Morse em número  
- `evaluate_expression(int values[], char operators[], int n)` → Avalia uma expressão entre valores e operadores  
- `solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance)` → Executa todo o processo para uma única instância  

---

## 🖥️ Como Compilar e Executar (via CMD)

### ✅ Pré-requisitos

- Ter o **GCC** instalado e configurado no PATH
- Estar no diretório raiz do projeto (ex: `warmup/`)

### 🛠️ Compilação

Abra o CMD na pasta do projeto e execute:

```bash
gcc -o warmup warmup.c solver/warmup_solver.c -Iinclude

e em seguida: warmup

ou: .\warmup.exe

