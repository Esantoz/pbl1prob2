/*******************************************************************************
Autor: Esdras Evangelista de Sena Santos
Componente Curricular: Algoritmos I
Concluido em: 21/01/2019
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char *curso;
	char *sexo;
	int *idade;
	int resp[100];
}Respond;

Respond respond[1000];
void dados();
void questoes();
void fa();
void ma();
void moda();
void filtrar();
void escore();
main(){
	int r;
	char o;
	puts("===============MENU===============");
	puts("Iniciar pesquisa[1]");
	puts("Frequencia absoluta[2]");
	puts("Media aritimetica[3]");
	puts("Moda[4]");
	puts("Filtrar[5]");
	puts("Escore[6]");
	scanf("%i",&r);
	switch(r){
		case 1:
			dados();
			break;
		case 2:
			fa();
			break;
		case 3:
			ma();
			break;
		case 4:
			moda();
			break;
		case 5:
			filtrar();
			break;
		case 6:
			escore();
			break;
	};		
}
//funcao para adicionar dados demograficos
void dados(){
	int i = 0;
	FILE *file = fopen("respostas.txt","a");
	fprintf(file,"\n");
	printf("Digite seu curso: \n");
    gets(respond[i].curso);
	printf("Digite sua idade: \n");
	scanf("%i",respond[i].idade);
	getchar();
	printf("Digite seu sexo: \n");
	gets(respond[i].sexo);
	fprintf(file,"%s\n %s\n %i\n",respond[i].curso,respond[i].sexo,*respond[i].idade);
	fclose(file);
	i++;
	//a funcao dados vai chamar as questoes
	questoes();
}
//funcao para adicionar novas perguntas ao codigo
void questoes(){
	int r;
	int o = 0;
	//aqui o usuario vai ter mais duas opecoes
	printf("Iniciar.[1]\tAdicionar novas questoes[2]");
	scanf("%i",&r);
	printf("\n");
	if(r == 1){
		int i = 0;
		int c = 0;
		int a = 0;
		int aux;
		int auxr = 0;
		int auxre = 0;
		int g;
		char q[200][100];
		char tr[19][100];
		FILE *file = fopen("questoes.txt","r");
		FILE *file1 = fopen("tiposrespostas.txt","r");
		//ler o arquivo de questoes
		while(fgets(q[i],100,file) != '\0'){
			++i;
		}
		//ler o arquivo de respostas
		while(fgets(tr[c],100,file1) != '\0'){
			++c;
		}
		for(int o = 0;o <= 30;o++){
			if(o % 2 != 0){
				puts(q[o]);
			}
			else if(o % 2 == 0){
				g = atoi(q[o]);
				for(int u = 0;u <= 18;u += 3){
					aux = u;
					if(g == atoi(tr[u])){
						aux += 2;
						for(int w = 0;w <= 100;w++){
							if(tr[aux][w] == ','){
								tr[aux][w] = '\t';
								++a;
							}
						}
						printf("%s ",tr[aux]);
						if(a == 2){
							printf("\n[1]\t\t[2]");
						}
						else if(a == 4){
							printf("\n[1]\t\t[2]\t\t[3]\t\t[4]");
						}
						else if(a == 3){
							printf("\n[1]\t\t[2]\t\t[3]");
						}
					}
					printf("\nReposta: ");
					scanf("%i",&respond[auxre].resp[auxr]);

					++auxr;
				}
			}

			++auxre;
		}
		fclose(file);
		fclose(file1);
	}
	//adiciona novas perguntas
	else if(r == 2){
		int numper;
		char *m[100];
		FILE *file = fopen("tiposrespostas.txt","r");
		FILE *file1 = fopen("questoes.txt","a");
		char tr[19][100];
		int i = 0;
		int a = 0;
		int escala;
		int cont = 1;
		while(fgets(tr[i],100,file) != '\0'){
			++i;
		}
		printf("==================== Escalas ====================");
		for(int c = 0;c <= 19;c++){
			if(c % 2 != 0){
				printf("%s.[%i]",tr[c],cont);
				++cont;
			}
		}
		printf("=================================================");
		puts("Digite o numero de perguntas da sua enquete: ");
		scanf("%i",&numper);
		for(a;a < numper;a++){
			printf("digite a pergunta %i: \n",a+1);
			gets(m[a]);
			while(1){
				printf("\nEscala utilizada: ");
				scanf("%i",&escala);
				if(escala >= 1 && escala <= 6)
					break;
				printf("\nEscala nao existe!");	
			}
			switch(escala){
				case 1:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
				case 2:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
				case 3:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
				case 4:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
				case 5:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
				case 6:
					fprintf(file1,"%s\n%i\n",m[a],o);
					break;
			};
			fclose(file);
		}
		questoes();
	}
//volta para a main	
main();	
}
//esta funcao vai fazer a frequencia absoluta da respostas
void fa(){
	int i;
	char q[100][100];
	int a=0,b=0,c=0,d=0,e=0,f=0;
	FILE *file = fopen("questoes.txt","r");
	while(fgets(q[i],100,file) != '\0'){
		i++;
	}
	for(int o = 0;q[o] != '\0';o++){
		if(o % 2 == 0){
			if(q[o][0] == '1'){
				++a;
			}
			else if(q[o][0] == '2'){
				++b;
			}
			else if(q[o][0] == '3'){
				++c;
			}
			else if(q[o][0] == '4'){
				++d;
			}
			else if(q[o][0] == '5'){
				++e;
			}
			else if(q[o][0] == '6'){
				++f;
			}
		}
	}
	printf("FA do primeiro nivel: %i",a);
	printf("FA do segundo nivel: %i",b);
	printf("FA do terceiro nivel: %i",c);
	printf("FA do quarto nivel: %i",d);
	printf("FA do quinto nivel: %i",e);
	printf("FA do sexto nivel: %i",f);
	//volta para a main	
	main();
}	
//esta funcao vai fazer a media aritmetica
void ma(){
	int i = 0;
	int aux = 0;
	int c = 0;
	char r[1000][100];
	int u = 0;
	FILE *file = fopen("respostas.txt","r");
	while(fgets(r[i],100,file) != '\0'){
		++i;
	}
	for(int o = 0;o <= 15;o++){
		for(int u = 4;r[u-1][o] != '\0';u += 4){
			if(r[u-1][o] == '1'){
				aux += 1;
			}
			else if(r[u-1][o] == '2'){
				aux += 2;
			}
			else if(r[u-1][o] == '3'){
				aux += 3;
			}
			else if(r[u-1][o] == '4'){
				aux += 4;
			}
			else if(r[u-1][o] == '5'){
				aux += 5;
			}
			c++;
		}
		printf("Questao %i: %f",o,(float)aux/c);
	}
	//volta para a main
	main();
}
//esta funcao vai procurar a moda
void moda(){
	FILE *file = fopen("respostas.txt","r");
	char r[100][100];
	int i = 0;
	int x = 1;
	int maior;
	int aux = 0;
	int m[5] = {0};
	while(fgets(r[i],100,file) != '\0'){
		i++;
	}
	for(int u = 4;r[u-1] != '\0';u++){
		for(int c = 0;c <= 15;c++){
			if(r[u-1][c] == '1'){
				m[0] += 1;
			}
			else if(r[u-1][c] == '2'){
				m[1] += 1;
			}
			else if(r[u-1][c] == '3'){
				m[2] += 1;
			}
			else if(r[u-1][c] == '4'){
				m[3] += 1;
			}
			else if(r[u-1][c] == '5'){
				m[4] += 1;
			}
		}
		maior = 0;
		for(int c = 0;c <= 5;c++){
			if(maior < m[c]){
				maior = m[c];
				aux = c;
			}	
		}
		if(aux == 1){
			printf("A moda da questao %i foi: %i",x,aux);
		}
		else if(aux == 2){
			printf("A moda da questao %i foi: %i",x,aux);
		}
		else if(aux == 3){
			printf("A moda da questao %i foi: %i",x,aux);
		}
		else if(aux == 4){
			printf("A moda da questao %i foi: %i",x,aux);
		}
		else if(aux == 5){
			printf("A moda da questao %i foi: %i",x,aux);
		}
		x++;
	}
	//volta para main
	main();
}
//filtrar os dados
void filtrar(){
	int a;
	int i = 0;
	FILE *file = fopen("respostas.txt","r");
	char r[100][1000];
	printf("Filtar por:\nIdade[1]\nSexo[2]\nCurso[3]\nResposta: ");
	scanf("%i",&a);
	while(fgets(r[i],1000,file) != '\0'){
		i++;
	}
	if(a == 1){
		int c;
		int ini,fim;
		int g;
		printf("Digite o escopo da idade.\n");
		printf("vai de: ");
		scanf("%i",&ini);
		getchar();
		printf("Ate: ");
		scanf("%i",&fim);
		
		for(c = 3;r[c] != '\0';c += 4){
			g = atoi(r[c-1]);
			if(g >= ini && g <= fim){
				printf("\n%s\n%s\n%s\n%s",r[c-3],r[c-2],r[c-1],r[c]);
			}
		}
	}
	else if(a == 2){
		int u;
		printf("Sexo:\nMasculino[1].\nFeminino[2]\n");
		scanf("%i",&u);
		if(u == 1){
			for(int c = 2;r[c] != '\0';c += 4){
				if(r[c-1] == "masculino"){
					printf("\n%s\n%s\n%s\n%s\n",r[c-2],r[c-1],r[c],r[c+1]);
				}
			}
		}
		if(u == 2){
			for(int c = 2;r[c] != '\0';c += 4){
				if(r[c-1] == "feminino"){
					printf("\n%s\n%s\n%s\n%s\n",r[c-2],r[c-1],r[c],r[c+1]);
				}
			}
		}
	}
	else if(a == 3){
		char curso[40];
		printf("Curso: ");
		scanf("%s",curso);
		for(int c = 0;r[c] != '\0';c += 4){
			if(r[c] == curso){
				printf("\n%s\n%s\n%s\n%s\n",r[c],r[c+1],r[c+2],r[c+3]);
			}
		}
	}
	//volta para a main
	main();
}
//escores das questoes
void escore(){
	int q;
	int l;
	int i = 0;
	int aux1 = 0,aux2 = 0;
	char ques[100][100];
	FILE *file = fopen("questoes.txt","r");
	while(fgets(ques[i],100,file) != '\0'){
		i++;
	}
	printf("Quantas questoes: ");
	scanf("%i",&q);
	int quest[q];
	for(int c = 0;c < q;c++){
		printf("digite a questao %i: ",c+1);
		scanf("%i",&quest[c]);
	}
	for(int i = 0;i <= q;i++){
		aux1 = quest[i];
		aux2 += atoi(ques[aux1+1]);
		i++;
	}
	printf("A media aritimetica das questoes e: %f",aux2/q);
	//volta para a main
	main();
}


	



