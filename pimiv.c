//Bibliotecas-----------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<time.h>
#define SIZE 1000 //Define o tamanho----------------------------------------------------------------------------------
#define limpar_tela "cls"//Define o comando limpar tela--------------------------------------------------------------
#define limpar_tela "clear"//Define o comando limpar tela------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

//Variaveis do sistemas no registro struct----------------------------------------------------------------------------------------------
typedef struct paciente{
//Variaveis globais----------------------------------------------------------------------------------------------------
char nome[50];
char cpf[50];
char email[SIZE][50];
char telefone[50];
char datanasc[50];
char datadiag[SIZE][50];
char comorbidade[50];

}t_paciente;

typedef struct endereco{
//Variaveis globais-------------------------------------------------------------------------------------------------
char rua[20];
int numero[SIZE];
char cidade[20];
char cep[SIZE];
}enderecoPac;

typedef struct{
//Variaveis globais-----------------------------------------------------------------------------------------------
char login[30];
char senha [30];
}funcionario;
funcionario f[1];//Foi criado uma variavel f[1] do tipo funcionario----------------------------------------------------

//Fim dos structs-------------------------------------------------------------------------------------------------------

//Funções que serão utlizadas dentro do main------------------------------------------------------------------------------------------------------------------
void cadastro();
void calculaIdade();
//----------------------------------------------------------------------------------------------------------------------

//A seguir a função principal main--------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]){
//Início do login-------------------------------------------------------------------------------------------------------
//Variaveis locais------------------------------------------------------------------------------------------------------------
int op;
char login[30];
char senha[30];
//----------------------------------------------------------------------------------------------------------------------
//Pré definição do login e senha----------------------------------------------------------------------------------------
strcpy(f[0].login,"paccovid");
strcpy(f[0].senha, "123");

//----------------------------------------------------------------------------------------------------------------------

printf("\n\t\tlogin:\t");//Escrita-------------------------------------------------------------------------------------
scanf("%s", &login);//Leitura------------------------------------------------------------------------------------------
printf("\n\t\tsenha:\t");
scanf("%s",&senha);
//Condição parar fazer login-------------------------------------------------------------------------------------------
if ((strcmp(login,f[0].login)==0) && (strcmp(senha,f[0].senha)==0)){
    printf("\n\n\t\t\tUsuário logado! Seja bem vindo!!!\t\n\n");
}

else{
    printf("Login e/ou senha incorretos!");

exit(0);//Sai se os dados estiverem incorretos-------------------------------------------------------------------------


}

 system(limpar_tela);//Limpa a tela------------------------------------------------------------------------------------
 //--------------------------------------------------------------------------------------------------------------------

//Final do login--------------------------------------------------------------------------------------------------------


printf("\n\n\t\t\t----- Sistema PacCovid ------\t\t\n\n\n");
printf("\n  Cadastro de Paciente\n");
cadastro();//Chama a função cadastro dentro do main---------------------------------
//---------------------------------------------------------------------------------------------------------------------


system(limpar_tela);//Limpa a tela--------------------------------
//---------------------------------------------------------------------------------------------------------------------


printf("\n\n\t\t\tCalculo da Idade do paciente\n\n");
calculaIdade(); //Chama a função calculo da idade------------------------------

return(0);//Fim do main-----------------------------------------------------------------------------------------------
}


//Definição da função cadastro------------------------------------------------------------------------------------------------
void cadastro(){
    int op; //Variavel local

FILE *arq_pacientes = fopen("pac.txt", "a"); //Abre o arquivo------------------------------

	t_paciente pac; //Foi criado uma varivel pac do tipo t_paciente-------------------------------------------------------
	enderecoPac ep;//Foi criado uma variavel ep do tipo enderecoPac----------------------------------------------------


    do{//laço de repetição----------------------------------------------------------------------------------------------

        printf("\nDigite o nome: \t");
        scanf("%s",&pac.nome);
        fgets(pac.nome,50,stdin);//Ler a string no arquivio
        setbuf(stdin,NULL);//Limpar buffer
        fprintf(arq_pacientes, "%s","Nome:", pac.nome);//Armazena dados em um arquivo-----------------------------------------------------

        printf("\nDigite o cpf:\t");
        scanf("%s", &pac.cpf);
        fprintf(arq_pacientes, "%s","CPF:", pac.cpf);//Armazena dados em um arquivo-------------------------------------------------------

        printf("\nDigite o telefone:\t");
        scanf("%s", &pac.telefone);
        fprintf(arq_pacientes, "%s","Telefone:", pac.telefone);//Armazena dados em um arquivo------------------------------------------------

        printf("\n\n\t\t\t\tDigite o endereço:\t\n");

        printf("\nDigite a rua:\t");
        scanf("%s", &ep.rua);
        fgets(ep.rua,20,stdin);//Ler a string no arquivo
        setbuf(stdin,NULL);//Limpar buffer
        fprintf(arq_pacientes, "%s","Endero da Rua:", ep.rua);//Armazena dados em um arquivo-------------------------------------------------------

        printf("\nDigite o numero da residencia:\t");
        scanf("%d",&ep.numero);
        fprintf(arq_pacientes, "%d", ep.numero);//Armazena dados em um arquivo-------------------------------------------------

        printf("\nDigite a cidade:\t");
        scanf("%s", &ep.cidade);
        fgets(ep.cidade,20,stdin);//Ler a string no arquivo
        setbuf(stdin,NULL);//Limpar buffer
        fprintf(arq_pacientes, "%s", ep.cidade);//Armazena dados em um arquivo-----------------------------------------------

        printf("\nDigite o cep:\t");
        scanf("%s", &ep.cep);
        fprintf(arq_pacientes, "%s", ep.cep);//Armazena dados em um arquivo---------------------------------------------------



        printf("\n\nDigite a data de nascimento:\t");
        scanf("%s", &pac.datanasc);
        fgets(pac.datanasc,50,stdin);//Ler a string no arquivo
        setbuf(stdin,NULL); //Limpa buffer-----
        fprintf(arq_pacientes, "%s", pac.datanasc);//Armazena dados em um arquivo------------------------------------------

        printf("\nDigite o email:\t");
        scanf("%s", &pac.email);
        fprintf(arq_pacientes, "%s", pac.email);//Armazena dados em um arquivo----------------------------------------------

        printf("\nDigite a data de diagnostico:\t");
        scanf("%s", &pac.datadiag);
        fgets(pac.datadiag,50,stdin);//Ler a string no arquivo
        setbuf(stdin,NULL);//Limpa buffer-----
        fprintf(arq_pacientes, "%s", pac.datadiag);//Armazena dados em um arquivo-------------------------------------------------

        printf("\nDigite a comorbidade:\t");
        scanf("%s", &pac.comorbidade);
        fgets(pac.comorbidade,50,stdin);//Ler a string no arquivo
        setbuf(stdin,NULL);//Limpa buffer-------------------------------------------
        fprintf(arq_pacientes, "%s", pac.comorbidade);//Armazena dados em um arquivo-----------------------------------------

        printf("\n\n\t\t\tPaciente Cadastrado\n\n");

	fclose(arq_pacientes);//Fecha o arquivo----------------------------------------------------


printf("\nDigite 0 para calcular a idade!\t\n");
scanf("%d", &op);

    }while(op == 1);//Fim do laço com condição-----------------------------------------------------------------

}
//Fim da função cadastro--------------------------------------------------------------------------

//Começo da função calcula idade----------------------------------------------------------------
void calculaIdade(){
      int op;
    FILE *arq_pacientes = fopen("covid.txt", "a+b");//Abre o arquivo-------------------------------


t_paciente pac; //Foi criado uma varivel pac do tipo t_paciente----------------------------------------

enderecoPac ep; //Foi criado uma variavel ep do tipo enderecoPac----------------------------------------


 do{ //Laço de repetição---------------------------------------------------------------------------
//Variaveis locais-------------------------------------------------------
int diaAtual, diaNasc;
  int mesAtual, mesNasc;
  int anoAtual, anoNasc;
  int dia, mes, ano,diferenca;

  diaAtual = 0;  // Dia atual
  diaNasc = 0;  //Dia de nascimento
  mesAtual = 0;  // Mes atual
  mesNasc = 0;  // Mes de nascimento
  anoAtual = 0;  // Ano atual
  anoNasc = 0;  // Ano de nascimento

// Entrada de dados--------------------------------------------------------------------------------
//Leitura e escrita dos dados----------------------------------------------------------------------
  printf("%s","Por favor, informe a data de hoje:\n");
  printf("%s","(Ex: 28 10 2020):\n");
  scanf(" %d%d%d", &diaAtual, &mesAtual, &anoAtual);
  printf("              %2d/%2d/%3d\n\n", diaAtual, mesAtual, anoAtual);

  printf("%s","Por favor, informe a data de nascimento do paciente:\n");
  printf("%s","(Ex: 14 01 1963):\n");
  scanf(" %d%d%d", &diaNasc, &mesNasc, &anoNasc);
  printf("              %2d/%2d/%3d\n\n", diaNasc, mesNasc, anoNasc);

// Calculando os dados recebidos----------------------------------------------------------------------
  diferenca =   365*anoAtual + 30*mesAtual + diaAtual
              - 365*anoNasc - 30*mesNasc - diaNasc;

  ano = diferenca/365;
  diferenca = diferenca%365;

  mes = diferenca/30;
  diferenca = diferenca%30;

  dia = diferenca;

 //Resultado do calculo----------------------------------------------------------------------------
  printf("%s %d %s %d %s %d %s",
          "Idade do paciente:", ano, "ano(s)", mes, "mes(es)", dia, "dia(s).\n");

  if(ano> 65){//Condição para escrever no arquivo covid.txt---------------------------------------
    printf("\n\tEstá no grupo de risco!\t\n");
    scanf("%d", &diferenca);
    fprintf(arq_pacientes, "%s","Cep", ep.cep);//Armazena os dados no arquivo-------------------------------------
    fprintf(arq_pacientes, "%s %d %s %d %s %d %s",//Armazena os dados no arquivo-------------------------------------
          "Idade do paciente:", ano, "ano(s)", mes, "mes(es)", dia, "dia(s)" );
  }else{
  printf("\n\tNão está no grupo de risco!\t\n\n\n");
  }

	fclose(arq_pacientes);//Fecha o arquivo------------------------------------------------

printf("\nDigite 0 para sair!\t\n");
scanf("%d", &op);

    }while(op == 1);//Fim do laço de repetição com condição----------------------------------------------------

}

