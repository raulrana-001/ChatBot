from datetime import datetime

def saudacao():
    return "Ola! Tudo bem?"

def bom_dia():
    return "Bom dia!"

def boa_tarde():
    return "Boa tarde!"

def nome():
    return "Eu sou um chatbot funcional."

def horas():
    agora = datetime.now()
    return f"Agora sao {agora.hour}:{agora.minute}"

def ajuda():
    return (
        "Comandos disponiveis\n"
        "ola \n"
        "oi\n"
        "bom dia \n"
        "boa tarde\n"
        "qual e o teu nome?\n"
        "que horas sao?\n"
        "sair"
    )

def naoconhecido():
    return "Nao entendi , digite um comando conhecido"

def execucao():
    comandos = {
        "ola": saudacao,
        "oi": saudacao,
        "bom dia": bom_dia,
        "boa tarde": boa_tarde,
        "qual e o teu nome?": nome,
        "que horas sao?": horas,
        "ajuda": ajuda
    }

    print("Chatbot iniciado!")
    print("Digite 'ajuda' para ter acesso aos comandos.")
    while True:
        mensagem = input("\nVoce: ").lower()

        if mensagem == "sair":
            print("Chatbot: Ate breve!")
            break

        funcao = comandos.get(mensagem, naoconhecido)
        print("Chatbot:", funcao())

execucao()
