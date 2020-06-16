/** Exceção para quando não existem veículos. */
public class NoVeiculoException extends Exception {
    private static final long serialVersionUID = 1L;
    
    /**
     * Exceção quando não existem veículos.
     * @param errorMessage Mensagem de erro.
     */
    public NoVeiculoException(String errorMessage) {
        super(errorMessage);
    }
}