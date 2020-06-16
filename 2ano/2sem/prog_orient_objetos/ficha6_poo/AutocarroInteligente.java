
public class AutocarroInteligente extends Veiculo implements BonificaKms{
    private static final long serialVersionUID = 7L;
    private int ocupacao; 
    private int pontospkm;

    public AutocarroInteligente(){
        super();
        this.ocupacao = 0;
    }
    
    public AutocarroInteligente(String id,
                   String brand,
                   String model,
                   int constrYear,
                   double speed,
                   double price, 
                   Rating rating,
                   double kmTotal,
                   double fator,
                   int ocupacao
                   ){
                   super(id,
                   brand,
                   model,
                   constrYear,
                   speed,
                   price,
                   rating,
                   kmTotal
                   );
                   this.ocupacao = ocupacao;
                   this.pontospkm = 0;
    }

    public AutocarroInteligente(AutocarroInteligente v){
        super(v);
        this.ocupacao = v.getOcupacao();
    }

    public void setOcupacao(int ocup){
        if(ocup >= 0 && ocup <= 100)
            this.ocupacao = ocup;
    }
    public int getOcupacao(){
        return this.ocupacao;
    }

    public AutocarroInteligente clone(){
        return new AutocarroInteligente(this);
    }

    public boolean equals(Object o){
        if(!super.equals(o))
            return false;
        if(o == null || o.getClass() != this.getClass())
            return false;
        AutocarroInteligente v = (AutocarroInteligente) o;
        return this.getBrand().equals(v.getBrand()) 
            && this.getModel().equals(v.getModel())
            && this.getConstrYear() == v.getConstrYear()
            && this.getSpeed() == v.getSpeed()
            && this.getPrice() == v.getPrice()
            && this.getRating().equals(v.getRating())
            && this.getKmTotal() == v.getKmTotal()
            && this.ocupacao == v.getOcupacao();
    }

    public double custoRealKm(){
        double fator;
        if(this.ocupacao <= 60)
            fator = this.ocupacao / 100.0;
        else
            fator = 0.75;
        return this.getKmTotal()*this.getPrice()*fator;
    }
    
    @Override
    public void setPontosPKm(int pontos){
        this.pontospkm = pontos;
    }

    @Override
    public int getPontosPKm(){
        return this.pontospkm;
    }

     @Override
    public int getPontosTotais(){
        return (int) Math.round(this.pontospkm*this.getKmTotal());
    }
    
} 