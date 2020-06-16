import java.io.Serializable;

/**
*   Rating Class has the porpouse hold a rate. 
*/
public class Rating implements Serializable{
    private static final long serialVersionUID = 2L;
    private double mean;
    private int num;

    /*
    *   Empty constructor creates a rating system with everything set to 0.
    */
    public Rating(){
        this.mean = 0;
        this.num = 0;
    }

    /*
    *  Simply inserts every parameter in the correct instance.
    */
    public Rating(double mean, int num){
        this.mean = mean;
        this.num = num;
    }

    /*
    *  Simply inserts every parameter of @param r in the correct instance.
    */
    public Rating(Rating r){
        this.mean = r.getMean();
        this.num = r.getNum();
    }

    
    /*
    *  Sets @param mean as the mean in this Rating.
    */
    public void setMean(double mean){
        this.mean = mean;
    }
     
    /*
    *  Sets @param num as the total number of reviews in this Rating.
    */
    public void setNum(int num){
        this.num = num;
    }

    /*
    *  Gets the mean in this Rating.
    */
    public double getMean(){
        return this.mean;
    }

    /*
    *  Gets the total number of reviews in this Rating.
    */
    public int getNum(){
        return this.num;
    }

    /*
    *  Turns this @class Rating in a @class String. 
    */
    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append(this.mean);
        sb.append("/10");
        sb.append(" of ");
        sb.append(this.num);

        return sb.toString();
    }

    /*
    *  Clones this @class Rating.
    */
    public Rating clone(){
        return new Rating(this.getMean(), this.getNum());
    }

    /*
    *  Determines if this @class Rating equals @param obj of generic class @class Object.
    */
    public boolean equals(Object obj){
        if(this == obj) return true;
        if(obj == null || this.getClass() != obj.getClass()) return false;
        Rating r = (Rating) obj;
        return r.getMean() == this.mean && r.getNum() == this.num;  
    }

    public boolean addRate(int r){
        boolean f;
        if(f = (r >= 0 && r <= 10))
            this.mean = (this.mean*this.num + r) / (++this.num);
        return f;
    }


}