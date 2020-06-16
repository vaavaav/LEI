public class VeiculoOcasiao extends Veiculo{
    private static final long serialVersionUID = 5L;
    public VeiculoOcasiao(){
        super();
    }
    
    public VeiculoOcasiao(String id,
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
    }

    public VeiculoOcasiao(VeiculoOcasiao v){
        super(v);
    }

    public VeiculoOcasiao clone(){
        return new VeiculoOcasiao(this);
    }

    public boolean equals(Object o){
        if(!super.equals(o))
            return false;
        if(o == null || o.getClass() != this.getClass())
            return false;
        VeiculoOcasiao v = (VeiculoOcasiao) o;
        return this.getBrand().equals(v.getBrand()) 
            && this.getModel().equals(v.getModel())
            && this.getConstrYear() == v.getConstrYear()
            && this.getSpeed() == v.getSpeed()
            && this.getPrice() == v.getPrice()
            && this.getRating().equals(v.getRating())
            && this.getKmTotal() == v.getKmTotal();
    }

    public double custoRealKm(){
        return this.getPrice()*this.getKmTotal();
    }

}