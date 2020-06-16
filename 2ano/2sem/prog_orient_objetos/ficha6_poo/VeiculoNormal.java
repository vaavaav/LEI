public class VeiculoNormal extends Veiculo{
    private static final long serialVersionUID = 4L;
    public VeiculoNormal(){
        super();
    }
    
    public VeiculoNormal(String id,
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

    public VeiculoNormal(VeiculoNormal v){
        super(v);
    }

    public VeiculoNormal clone(){
        return new VeiculoNormal(this);
    }

    public boolean equals(Object o){
        if(!super.equals(o))
            return false;
        if(o == null || o.getClass() != this.getClass())
            return false;
        VeiculoNormal v = (VeiculoNormal) o;
        return this.getBrand().equals(v.getBrand()) 
            && this.getModel().equals(v.getModel())
            && this.getConstrYear() == v.getConstrYear()
            && this.getSpeed() == v.getSpeed()
            && this.getPrice() == v.getPrice()
            && this.getRating().equals(v.getRating())
            && this.getKmTotal() == v.getKmTotal();
    }

    public double custoRealKm(){
        return this.getPrice()*this.getKmTotal()*1.1;
    }
}