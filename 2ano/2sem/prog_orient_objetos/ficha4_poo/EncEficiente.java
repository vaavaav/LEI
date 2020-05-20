public class EncEficiente{
	private String nome;
	private String nFiscal;
	private String morada;
	private LocalDate data;
	private ArrayList<LinhaEncomenda> linhaEncomenda;

	public EncEficiente(){
		this.nome = null;
		this.nFiscal = null;
		this.morada = null;
		this.data = LocalDate();
		this.linhaEncomenda = new ArrayList<>();
	}

	public EncEficiente(EncEficiente e){
		this.nome = e.getNome();
		this.nFiscal = e.getNFiscal();
		this.morada = e.getMorada();
		this.data = e.getData();
		this.linhaEncomenda = e.getLinhaEncomenda();
	}

	public EncEficiente(String nome, String nFiscal, String morada, LocalDate data, ArrayList<LinhaEncomenda> l){
		this.nome = nome;
		this.nFiscal = nFiscal;
		this.morada = morada;
		this.data = data;
		this.linhaEncomenda = l;
	}	

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setNFiscal(String nFiscal) {
		this.nFiscal = nFiscal;
	}

	public void setMorada(String morada) {
		this.morada = morada;
	}

	public void setData(LocalDate data) {
		this.data = data;
	}

	public void setLinhaEncomenda(ArrayList<LinhaEncomenda> l) {
		this.linhaEncomenda = new ArrayList<>(l.size());
		for(LinhaEncomenda le : l){
			this.linhaEncomenda.add(le);
	}

	public String getNome(){
		return this.nome;
	}

	public String getNFiscal(){
		return this.nFiscal;
	}
	public String getMorada(){
		return this.morada;
	}
	public LocalDate getData(){
		return this.data;
	}
	public ArrayList<LinhaEncomenda> getLinhaEncomenda(){
		ArrayList<LinhaEncomenda> res = new ArrayList<>(this.linhaEncomenda.size());
		for(LinhaEncomenda le : this.linhaEncomenda)
			res.add(le);
		return res;
	}

	public EncEficiente clone(EncEficiente e){
		this.nome = e.getNome();
		this.nFiscal = e.getNFiscal();
		this.morada = e.getMorada();
		this.data = e.getData();
		this.linhaEncomenda = e.getLinhaEncomenda();
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("---Encomenda---\n");
		sb.append("Nome: ");
		sb.append(this.nome);
		sb.append("\nNúmero Fiscal: ");
		sb.append(this.nFiscal);
		sb.append("\nMorada: ");
		sb.append(this.morada);
		sb.append("\nData: ");
		sb.append(this.data);
		sb.append("\nLinha de Encomenda:");
		sb.append("\n");
		for(LinhaEncomenda le : this.linhaEncomenda){
			sb.append(le);
			sb.append("\n");
		}
		return sb.toString;
	}

	public Boolean equals(Object o){
		if(this == o) return true;
		if(o == null || o.getClass() != this.getClass()) return false;
		EncEficiente e = (EncEficiente) o;
		return e.getNome().equals(this.nome) && e.getNFiscal().equals(this.nFiscal) &&
		e.getMorada().equals(this.morada) && e.getData().equals(this.data) &&
		e.getLinhaEncomenda().equals(this.linhaEncomenda);
	}

	public double calculaValorTotal(){
		double v = 0;
		for(linhaEncomenda le : this.linhaEncomenda)
			v += le.calculaValorLinhaEnc();
		return v;
	}

	public double calculaValorDesconto(){
		double v = 0;
		for(linhaEncomenda le : this.linhaEncomenda)
			v += le.calculaValorDesconto();
		return v;
	}

	public int numeroTotalProdutos(){
		int t = 0;
		for(linhaEncomenda le : this.linhaEncomenda)
			t += le.getQuantidade();
		return t;
	}
	
	public boolean existeProdutoEncomenda(String refProduto) {
        boolean r = false;
        Iterator<LinhaEncomenda> i = this.linhaEncomenda.iterator();
        while (i.hasNext() && !r)
            r = i.next().getReferencia().equals(refProduto);
        return r;
    }

    public void adicionaLinha(LinhaEncomenda linha){
    	this.linhaEncomenda.add(linha.clone());     }

    public void removeProduto(String codProd){
        Iterator<LinhaEncomenda> i = this.linhaEncomenda.iterator();
        while (i.hasNext())
            if(i.next().getReferencia().equals(codProduto))
        		i.remove();
    }
}