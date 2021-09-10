#include <stdio.h>


 int formula(int resultado_da_soma) // Função que define os digitos finais do cpf
{   
    int digito_cpf;
    digito_cpf = 11 - (resultado_da_soma % 11);
    if (digito_cpf > 9){
        digito_cpf = 0;
    }
    return digito_cpf;


}

int soma_elementos_cpf(int comeco_loop, int arr[]) // Faz soma do processo de validacao
{
    int soma,aux,contador,indice;
    soma = 0;
    aux = 0;
    contador = 0;

    for(indice = comeco_loop; indice >= 2;indice--)
    {
    aux = arr[contador] * indice;
    contador += 1;
    soma += aux;
    aux = 0;

    }
    return soma;

}

void validacao(int arr[], int arr2[]) // Diz se o cpf é válido ou não
{ 
    int contador,i;

    contador = 0;
    for(i = 0; i < 11;i++)
    {
    if(arr[i] != arr2[i])
    {
        contador +=1;

    }
    }

    if(contador == 0)
    {
    printf("CPF valido");

    }

    else
    {
    printf("CPF invalido");
    }

}

main(){
    char cpf[11];
    int vetor[11],contador,primeira_soma,segunda_soma,penultimo_digito,ultimo_digito;
    int i,aux,vetor_conta_1[9],vetor_conta_2[10],vetor_comparacao[11];

    printf("Digite o cpf sem . ou -  ");
    gets(cpf);

    for (i = 0; i < 11;i++)
  {
    aux = cpf[i] - '0'; // Fazendo casting de char para int 
    vetor[i] = aux;
    aux = 0;
  }
  
  for(i = 0; i < 9;i++)
  {
    vetor_conta_1[i] = vetor[i];

  }
  

  primeira_soma = soma_elementos_cpf(10,vetor_conta_1);
  penultimo_digito = formula(primeira_soma);
  

  
  for(i = 0; i < 9;i++)
  {
    vetor_conta_2[i] = vetor[i];
   

  }
  vetor_conta_2[9] = penultimo_digito;

  segunda_soma = soma_elementos_cpf(11,vetor_conta_2);
  ultimo_digito = formula(segunda_soma);
  
  for(i = 0; i < 10;i++)
  {
    vetor_comparacao[i] = vetor_conta_2[i] ;
  }
  vetor_comparacao[10] = ultimo_digito;
  
  validacao(vetor_comparacao,vetor);
}