import java.io.Serializable;

public abstract class Veiculo implements Serializable{
    private static final long serialVersionUID = 3L;
    private String id;
    private String brand;
    private String model;
    private int constrYear;
    private double speed; /* per km*/
    private double price; /*per km*/ 
    private Rating rating;
    private double kmTotal;

    public Veiculo() {
        this.id = this.brand =  this.model = "n/a";
        this.constrYear = 0;
        this.kmTotal = this.speed = this.price = 0;
        this.rating = new Rating(0,0);
    }

    public Veiculo(String id,
                   String brand,
                   String model,
                   int constrYear,
                   double speed,
                   double price, 
                   Rating rating,
                   double kmTotal
                   ){
                   this.id = id;
                   this.brand = brand;
                   this.model = model;
                   this.constrYear = constrYear;
                   this.speed = speed;
                   this.price = price;
                   this.rating = rating.clone();
                   this.kmTotal = kmTotal;
    }

    public Veiculo(Veiculo v){
        this.id = v.getId();
        this.brand = v.getBrand();
        this.model = v.getModel();
        this.constrYear = v.getConstrYear();
        this.speed = v.getSpeed();
        this.price = v.getPrice();
        this.rating = v.getRating();
        this.kmTotal = v.getKmTotal();
    }

    public String getId(){
        return this.id;
    }
    public String getBrand(){
        return this.brand;
    }
    public String getModel(){
        return this.model;
    }
    public int getConstrYear(){
        return this.constrYear;
    }
    public double getSpeed(){
        return this.speed;
    }
    public double getPrice(){
        return this.price;
    }
    public Rating getRating(){
        return this.rating;
    }
    public double getKmTotal(){
        return this.kmTotal;
    }

    public void setId(String id){
        this.id = id;
    }
    public void setBrand(String brand){
       this.brand = brand;
    }
    public void setModel(String model){
        this.model = model;
    }
    public void setConstrYear(int constrYear){
        this.constrYear = constrYear;
    }
    public void setSpeed(double speed){
        this.speed = speed;
    }
    public void setPrice(double price){
        this.price = price;
    }
    public void setRating(Rating rating){
        this.rating = rating;
    }
    public void setKmTotal(double kmTotal){
        this.kmTotal = kmTotal;
    }

    public abstract Veiculo clone();

    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Veiculo v = (Veiculo) o;
        return this.brand.equals(v.getBrand()) 
            && this.model.equals(v.getModel())
            && this.constrYear == v.getConstrYear()
            && this.speed == v.getSpeed()
            && this.price == v.getPrice()
            && this.rating.equals(v.getRating())
            && this.kmTotal == v.getKmTotal();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Matrícula: ");
        sb.append(this.id);
        sb.append("Marca: ");
        sb.append(this.brand);
        sb.append("\nModelo: ");
        sb.append(this.model);
        sb.append("\nAno de construção: ");
        sb.append(this.constrYear);
        sb.append("\nVelocidade média (Km/h): ");
        sb.append(this.speed);
        sb.append("\nPreço teórico (/Km): ");
        sb.append(this.price);
        sb.append("\nDistância percorrida (Km): ");
        sb.append(this.kmTotal);
        sb.append("\nClassificação: ");
        sb.append(this.rating.getMean());

        return sb.toString();
    } 

    public void addClassificacao(int n){
        this.rating.addRate(n);
    }

    public abstract double custoRealKm();


}