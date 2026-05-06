import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

class ChatBot {
    private final String nomeChatbot = "Chatbot Simples";
    private Scanner teclado;
    private boolean activo;

    /**
     * Construtor que inicializa o scanner e o estado de execução.
     */
    public ChatBot() {
        this.teclado = new Scanner(System.in);
        this.activo = true;
    }

    /**
     * Método principal que inicia o loop de interação com o usuário.
     */
    public void iniciar() {
        System.out.println("\t\t==== CHATBOT SIMPLES - (CBS) ====\n");
        System.out.println("Bem-vindo ao " + nomeChatbot + "! Digite 'ajuda' para ver os comandos disponíveis.");

        while (activo) {
            System.out.print("Usuário: ");
            String mensagem = teclado.nextLine().trim().toLowerCase();
            String resposta = processarMensagem(mensagem);
            if (!resposta.isEmpty()) {
                System.out.println(nomeChatbot + ": " + resposta);
            }
        }

        teclado.close();
        System.out.println(nomeChatbot + ": Adeus! Até a próxima.");
    }

    /**
     * Método encapsulado que processa a mensagem do usuário e retorna a resposta apropriada.
     *
     * @param mensagem A mensagem do usuário em minúsculas.
     * @return A resposta do chatbot.
     */
    private String processarMensagem(String mensagem) {
        if (mensagem.equals("olá") || mensagem.equals("oi")) {
            return "Olá! Como posso ajudar hoje?";
        } else if (mensagem.equals("bom dia") || mensagem.equals("boa tarde")) {
            return getSaudacaoPorPeriodo();
        } else if (mensagem.equals("qual é o teu nome?") || mensagem.equals("qual é o seu nome?")) {
            return "O meu nome é " + nomeChatbot + ".";
        } else if (mensagem.equals("que horas são?") || mensagem.equals("que horas sao?")) {
            return getHoraAtual();
        } else if (mensagem.equals("ajuda")) {
            return getListaComandos();
        } else if (mensagem.equals("sair")) {
            activo = false;
            return "";
        } else {
            return "Desculpe, não entendi. Digite 'ajuda' para ver os comandos disponíveis.";
        }
    }

    /**
     * Método que retorna uma saudação baseada no período do dia.
     *
     * @return Saudação apropriada.
     */
    private String getSaudacaoPorPeriodo() {
        LocalTime agora = LocalTime.now();
        int hora = agora.getHour();

        if (hora >= 0 && hora < 12) {
            return "Bom dia!";
        } else if (hora >= 12 && hora < 18) {
            return "Boa tarde!";
        } else {
            return "Boa noite!";
        }
    }

    /**
     * Método que retorna a hora atual formatada.
     *
     * @return Hora no formato HH:mm:ss.
     */
    private String getHoraAtual() {
        LocalTime agora = LocalTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return "Agora são " + agora.format(formatter) + ".";
    }

    /**
     * Método que retorna a lista de comandos disponíveis.
     *
     * @return String com a lista de comandos.
     */
    private String getListaComandos() {
        return "Comandos disponíveis:\n" +
                "- 'olá' ou 'oi': Saudação\n" +
                "- 'bom dia' ou 'boa tarde': Saudação por período\n" +
                "- 'qual é o teu nome?': Nome do chatbot\n" +
                "- 'que horas são?': Hora atual\n" +
                "- 'ajuda': Esta lista\n" +
                "- 'sair': Encerrar";
    }
}