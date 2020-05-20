import java.util.ArrayList;
import java.util.Iterator;
import java.time.LocalDate;

public class Encomenda {
    private String nome;
    private String NIF;
    private String morada;
    private int num;
    private LocalDate data;
    private ArrayList<LinhaEncomenda> linhas;

    public Encomenda() {
        nome = NIF = morada = "";
        num = 0;
        data = null;
        linhas = new ArrayList<>();
    }

    public Encomenda(String nome, String NIF, String morada, int num, LocalDate data, ArrayList<LinhaEncomenda> linhas) {
        this.nome = nome;
        this.NIF = NIF;
        this.morada = morada;
        this.num = num;
        this.data = data;
        setLinhas(linhas);
    }

    public Encomenda(Encomenda enc) {
        nome = enc.getNome();
        NIF = enc.getNIF();
        morada = enc.getMorada();
        num = enc.getNum();
        data = enc.getData();
        setLinhas(enc.getLinhas());
    }

    public String getNome() {
        return this.nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNIF() {
        return this.NIF;
    }
    public void setNIF(String NIF) {
        this.NIF = NIF;
    }

    public String getMorada() {
        return this.morada;
    }
    public void setMorada(String morada) {
        this.morada = morada;
    }

    public int getNum() {
        return this.num;
    }
    public void setNum(int num) {
        this.num = num;
    }

    public LocalDate getData() {
        return this.data;
    }
    public void setData(LocalDate data) {
        this.data = data;
    }

    public ArrayList<LinhaEncomenda> getLinhas() {
        ArrayList<LinhaEncomenda> newlinhas = new ArrayList<>(this.linhas.size());
        for (LinhaEncomenda lin : this.linhas)
            newlinhas.add(lin.clone());
        return newlinhas;
    }
    public void setLinhas(ArrayList<LinhaEncomenda> linhas) {
        this.linhas = new ArrayList<>(linhas.size());
        for (LinhaEncomenda lin : linhas)
            this.linhas.add(lin.clone());
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("Nome: ");
        sb.append(nome);
        sb.append("\nNIF: ");
        sb.append(NIF);
        sb.append("\nMorada: ");
        sb.append(morada);
        sb.append("\nNúmero da encomenda: ");
        sb.append(num);
        sb.append("\nData da encomenda: ");
        sb.append(data);
        sb.append("\nLinhas da encomenda: ");
        sb.append(linhas);

        return sb.toString();
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if ((o == null) || (o.getClass() != this.getClass()))
            return false;

        Encomenda enc = (Encomenda) o;
        return enc.getNome().equals(this.nome) && enc.getNIF().equals(this.NIF)
                && enc.getMorada().equals(this.morada) && enc.getData().equals(this.data)
                && enc.getLinhas().equals(this.linhas);
    }

    public Encomenda clone() {
        return new Encomenda(this);
    }

    //ii
    public double calculaValorTotal() {
        int total = 0;
        for (LinhaEncomenda le : linhas)
            total += le.calculaValorLinhaEnc();
        return total;
    }

    //iii
    public double calculaValorDesconto() {
        int total = 0;
        for (LinhaEncomenda le : linhas)
            total += le.calculaValorDesconto();
        return total;
    }

    //iv
    public int numeroTotalProdutos() {
        int total = 0;
        for (LinhaEncomenda le : linhas)
            total += le.getQuantidade();
        return total;
    }

    //v
    public boolean existeProdutoEncomenda(String refProduto) {
        boolean res = false;

        Iterator<LinhaEncomenda> i = linhas.iterator();
        while (i.hasNext() && !res)
            if (i.next().getReferencia().equals(refProduto))
                res = true;

        return res;
    }

    //vi
    public void adicionaLinha(LinhaEncomenda linha) {
        linhas.add(linha.clone());
    } 

    //vii
    public void removeProduto(String codProd) {
        boolean existe = false;

        Iterator<LinhaEncomenda> i = linhas.iterator();
        while (i.hasNext() && !existe)
            if (i.next().getReferencia().equals(codProd))
                existe = true;

        if (existe)
            i.remove();
    }
}