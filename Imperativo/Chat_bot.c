# include <stdio.h>
# include <strings.h>
# include <stdlib.h>
# include <time.h>

char msg[50] = "111";

void mostrar_hora(){
	time_t agora;
	struct tm *info;
		
	time(&agora);
	info = localtime(&agora);
	
	printf("\nSão: %02d:%02d:%02d \n\n",info->tm_hour,info->tm_min,info->tm_sec);
}


void mostrar_data(){
	time_t agora;
	struct tm *info;
		
	time(&agora);
	info = localtime(&agora);
	
	printf("\n %02d/%02d/%02d \n\n",info->tm_mday,info->tm_mon + 1,info->tm_year + 1900);
}

void remover_acento(){
	
	
	
	
}

void lista_de_comandos(){	
	printf("--------------------------------------\n");	
	printf("|          Lista de Comandos         |\n");
	printf("--------------------------------------\n\n");
	printf("\t[1] Ola/Oi\n");
	printf("\t[2] Bom dia/Boa tarde\n");
	printf("\t[3] Que hora sao?\n");
	printf("\t[4] Que dia e hoje?\n");
	printf("\t[5] Qual e o seu nome?\n");
	printf("\t[6] Ajuda\n");
	printf("\t[7] Sair\n\n");
}

void acerca(){
	printf("---------------------------------------\n");	
	printf("|       	Sobre nós              |\n");
	printf("---------------------------------------\n\n");
	
	printf("\tEstudantes da computação\n");
	printf("\tSegungo ano academico\n");
	printf("\tParadigmas de Programação\n");
	printf("\tGrupo número 10\n\n");	
}


void chat(){
		
		getchar();
		while(strcasecmp(msg ,"sair") != 0){
			
		printf("Como posso ajudar? \n");
		fgets(msg,sizeof(msg),stdin);
		msg[strcspn(msg,"\n")] ='\0';
	
		if(strcasecmp(msg ,"ola") == 0||strcasecmp(msg ,"oi") == 0){
		printf("\nOlá seja bem vindo\n\n");
		}else if(strcasecmp(msg ,"bom dia")== 0 || strcasecmp(msg ,"bom dia.")== 0){
			printf("\nBom dia \n\n");
		}else if(strcasecmp(msg ,"boa tarde")== 0 || strcasecmp(msg ,"boa tarde.")== 0){
			printf("\nBoa tarde\n\n");
		}else if((strcasecmp(msg ,"qual e o seu nome?")== 0 || strcasecmp(msg ,"qual e o seu nome")== 0)||(strcasecmp(msg ,"qual e o teu nome?")== 0 || strcasecmp(msg ,"qual e o teu nome")== 0)){
			printf("\nSou o chatbot um chat em desenvovimento que esta na versão 0.1 simulo conversas em tempo real\n\n");
		}else if(strcasecmp(msg ,"que hora sao?")== 0 || strcasecmp(msg ,"que hora sao")== 0){
			mostrar_hora();
		}else if(strcasecmp(msg ,"que dia e hoje?")== 0 || strcasecmp(msg ,"que dia e hoje")== 0){
			mostrar_data();
		}
		else if(strcasecmp(msg ,"ajuda")== 0 || strcasecmp(msg ,"ajuda!")== 0){
			lista_de_comandos();
		}else if(strcasecmp(msg ,"sair")== 0){
			printf("\nTchau e até a proxima, continuação de um bom dia.\n\n");
		}else{
			printf("\nComando não reconhecido caso queria ver a lista de comando digite ajuda.\n\n");		
		}
	
	}
	}
	
	void  menu(){
		int op = 4;
	
		while(op != 0){
		printf("---------------------------------------\n");	
		printf("|             Chatbot     	      |\n");
		printf("---------------------------------------\n\n");
		printf("\t[1] Entrar no chat \n");
		printf("\t[2] Lista de comandos \n");
		printf("\t[3] Sobre nós \n");
		printf("\t[0] sair \n\n");
		
		printf("Escolha uma opção: ");
		scanf("%d",&op);
	
		switch(op){
			case 1:system("cls");chat();break;
			case 2:system("cls");lista_de_comandos();break;
			case 3:system("cls");acerca(); break;
			case 0:printf("encerrando...\n");
		}
	}
	
}

int main(void){
	
	system("color 2");
	menu();

}
