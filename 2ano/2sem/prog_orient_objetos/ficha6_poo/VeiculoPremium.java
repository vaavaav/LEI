public class VeiculoPremium extends Veiculo implements BonificaKms{
    private static final long serialVersionUID = 6L;
    private double fator;
    private int pontospkm;

    public VeiculoPremium(){
        super();
        fator = 1;
    }
    
    public VeiculoPremium(String id,
                   String brand,
                   String model,
                   int constrYear,
                   double speed,
                   double price, 
                   Rating rating,
                   double kmTotal,
                   double fator
                   ){
                   super(id,
                   brand,
                   model,
                   constrYear,
                   speed,
                   price,
                   rating,
                   kmTotal);
                   this.fator = fator;
                   this.pontospkm = 0;
    }

    public VeiculoPremium(VeiculoPremium v){
        super(v);
        this.fator = v.getFator();
    }

    public void setFator(double fator){
        this.fator = fator;
    }

    public double getFator(){
        return this.fator;
    }

    public VeiculoPremium clone(){
        return new VeiculoPremium(this);
    }

    public boolean equals(Object o){
        if(!super.equals(o))
            return false;
        if(o == null || o.getClass() != this.getClass())
            return false;
        VeiculoPremium v = (VeiculoPremium) o;
        return this.getBrand().equals(v.getBrand()) 
            && this.getModel().equals(v.getModel())
            && this.getConstrYear() == v.getConstrYear()
            && this.getSpeed() == v.getSpeed()
            && this.getPrice() == v.getPrice()
            && this.getRating().equals(v.getRating())
            && this.getKmTotal() == v.getKmTotal()
            && this.fator == v.getFator();
    }

    public double custoRealKm(){
        return this.getPrice()*this.getKmTotal()*this.fator;
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