/** Exceção para veiculos repetidos. */
public class RepeatedVeiculoException extends Exception {
    private static final long serialVersionUID = 2L;
    
    /**
     * Exceção veiculos repetidos.
     * @param errorMessage Mensagem de erro.
     */
    public RepeatedVeiculoException(String errorMessage) {
        super(errorMessage);
    }
}