//Maikon Liniker Araújo de Souza
//Algoritimos 2
//Trabalho N1
//2025/2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void login();
void tipoeixo();
void pneus(int eixo);
void legenda(int eixo);
int validarPlaca(char placa[]);
int existeNaMatriz(int matriz[3][12], int valor);

//login
void login() {
    char user[50], placa[10];
    int senha;

    printf("Usuario: ");
    scanf("%s", user);

    printf("Senha: ");
    scanf("%d", &senha);

   //validando login
    if (strcmp(user, "uniavan") != 0 || senha != 123)
    {
        printf("\nUsuario ou senha invalidos\n");
        return;
    }

    int valido;

    //Placa: abc1234
    do
    {
        printf("Placa: ");
        scanf("%s", placa);
        valido = validarPlaca(placa);
        if (!valido) printf("Placa invalida! Tente novamente.\n");
    } while (!valido);

    tipoeixo();
}

//Validando placa  Placa: abc1234
int validarPlaca(char placa[])
{
    if (strlen(placa) != 7) return 0;

    for (int i = 0; i < 3; i++)
        if (!isalpha(placa[i])) return 0;

    for (int i = 3; i < 7; i++)
        if (!isdigit(placa[i])) return 0;

    return 1;
}

//Verificar repetição de numero de fogo do pneu
int existeNaMatriz(int matriz[3][12], int valor)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 12; j++)
            if (matriz[i][j] == valor)
                return 1;
    return 0;
}

//Tipo de eixo
void tipoeixo()
{
    int eixo;
    printf("\nQual o tipo de EIXO?\n 1-Truck \n 2-Toco \n 3-Carreta 3 eixos\n");
    scanf("%d", &eixo);

    switch(eixo)
    {
        case 1:
        case 2:
        case 3:
            pneus(eixo);
            break;
        default:
            printf("Escolha entre 1, 2 ou 3\n");
    }
}

// Legenda dos pneus no formato de caminhão
void legenda(int eixo) {
    printf("\nLEGENDA DOS PNEUS  \n");

    if(eixo == 1) // TRUCK
    {
        printf("\nDIANTEIROS\n");
        printf("[D1]   [D2]\n");

        printf("\nTRASEIROS\n");
        printf("[T1] [T2]   [T3] [T4]\n");
        printf("[T5] [T6]   [T7] [T8]\n");

        printf("\nESTEPES\n");
        printf("[E1]  [E2]\n");

    }

    if(eixo == 2) // TOCO
    {
        printf("\nDIANTEIROS\n");
        printf("[D1]   [D2]\n");

        printf("\nTRASEIROS\n");
        printf("[T1] [T2]  [T3] [T4]\n");

        printf("\nESTEPES\n");
        printf("[E1]  [E2]\n");
    }

    if(eixo == 3) // CARRETA 3 EIXOS
    {
        printf("\nDIANTEIROS (sem dianteiros)\n");

        printf("\nTRASEIROS\n");
        printf("[T1] [T2]   [T3] [T4]\n");
        printf("[T5] [T6]   [T7] [T8]\n");
        printf("[T9] [T10] [T11] [T12]\n");

        printf("\nESTEPES\n");
        printf("[E1]  [E2]\n");
    }

    printf("\n---------------------------------\n\n");
}

// Validar eixo escolhido
void pneus(int eixo)
{
    int matriz[3][12] = {0};
    int qtdDianteiros=0, qtdTraseiros=0, qtdEstepes=0;

    if(eixo==1)
        {
            qtdDianteiros=2; qtdTraseiros=8; qtdEstepes=2; printf("\nEixo TRUCK selecionado.\n");
        }
    if(eixo==2)
        {
            qtdDianteiros=2; qtdTraseiros=4; qtdEstepes=2; printf("\nEixo TOCO selecionado.\n");
        }
    if(eixo==3)
        {
            qtdDianteiros=0; qtdTraseiros=12; qtdEstepes=2; printf("\nEixo CARRETA 3 EIXOS selecionado.\n");
        }

    // Mostra a legenda com o desenho do caminhão
    legenda(eixo);

    int valor;

    //Cadastro dianteiros
    for(int j=0;j<qtdDianteiros;j++)
    {
        do
        {
            printf("Digite o %dº pneu dianteiro: ", j+1);
            scanf("%d", &valor);
            if(existeNaMatriz(matriz, valor)) printf("Pneu já cadastrado, digite outro.\n");
            else break;
        } while(1);
        matriz[0][j] = valor;
    }

    //Cadastro traseiros
    for(int j=0;j<qtdTraseiros;j++)
    {
        do
        {
            printf("Digite o %dº pneu traseiro: ", j+1);
            scanf("%d", &valor);
            if(existeNaMatriz(matriz, valor)) printf("Pneu já cadastrado, digite outro.\n");
            else break;
        } while(1);
        matriz[1][j] = valor;
    }

    // Cadastro estepes
    for(int j=0;j<qtdEstepes;j++)
    {
        do
        {
            printf("Digite o %dº estepe: ", j+1);
            scanf("%d", &valor);
            if(existeNaMatriz(matriz, valor)) printf("Pneu já cadastrado, digite outro.\n");
            else break;
        } while(1);
        matriz[2][j] = valor;
    }

    // Menu
    int opcao;
    do {
        printf("\nMENU PNEUS\n");
        printf("1 - Mostrar pneus\n");
        printf("2 - Rodizio de pneus\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                if(qtdDianteiros>0)
                    {
                        printf("\nPneus dianteiros: "); for(int j=0;j<qtdDianteiros;j++) printf("[%d] ", matriz[0][j]);
                    }
                if(qtdTraseiros>0)
                    {
                        printf("\nPneus traseiros: "); for(int j=0;j<qtdTraseiros;j++) printf("[%d] ", matriz[1][j]);
                    }
                if(qtdEstepes>0)
                    {
                        printf("\nEstepes: "); for(int j=0;j<qtdEstepes;j++) printf("[%d] ", matriz[2][j]);
                    }
                printf("\n");
                break;

            case 2:
        {
                int l1,c1,l2,c2;
                printf("\nConsidere as posições iniciando do ZERO\n");
                printf("\nDigite a linha e coluna do primeiro pneu:\n0 = dianteiros\n1 = traseiros\n2 = estepes\n");
                scanf("%d %d",&l1,&c1);
                printf("Digite a linha e coluna do segundo pneu:   \n0 = dianteiros\n1 = traseiros\n2 = estepes\n");
                scanf("%d %d",&l2,&c2);

                // Validação
                if(l1<0 || l1>2 || l2<0 || l2>2)
                {
                    printf("Linha inválida!\n");
                    break;
                }
                if((l1==0 && c1>=qtdDianteiros) || (l1==1 && c1>=qtdTraseiros) || (l1==2 && c1>=qtdEstepes) ||
                   (l2==0 && c2>=qtdDianteiros) || (l2==1 && c2>=qtdTraseiros) || (l2==2 && c2>=qtdEstepes))
                {
                    printf("Coluna inválida!\n");
                    break;
                }
                if(l1==l2 && c1==c2)
                {
                    printf("Não pode escolher o mesmo pneu!\n");
                    break;
                }

                // Rodizio
                int temp = matriz[l1][c1];
                matriz[l1][c1] = matriz[l2][c2];
                matriz[l2][c2] = temp;
                printf("Rodizio concluido!\n");
                break;
            }

            case 3: printf("Saindo do programa...\n");
            break;
            default: printf("Opção inválida!\n");
        }

    }
    while(opcao !=3);
}

int main()
{
    setlocale(LC_ALL,"PORTUGUESE");
    login();
    return 0;
}
