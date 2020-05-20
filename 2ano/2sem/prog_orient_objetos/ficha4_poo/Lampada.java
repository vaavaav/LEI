
public class Lampada{

	public static final int OFF = 0;
	public static final int ON = 1;
	public static final int ECO = 2;


	private int estado; /* 0 - Desligada; 1 - Ligada; 2 - Eco. */
	private final double consumoNormal = 0.1;
	private final double consumoEco = 0.05;
	private double total;
	private double cperiodo;
	private long stamp;


	public Lampada(){
		this.estado = OFF;
		this.total = 0;
		this.cperiodo = 0;
		this.stamp = System.currentTimeMillis();
	}

	public Lampada(Lampada l){
		this.estado = l.getEstado();
		this.total = l.totalConsumo();
		this.cperiodo = l.periodoConsumo();
		this.stamp = l.getStamp();
	}

	public Lampada(double total, double cperiodo, long stamp){
		this.estado = 0;
		this.total = total;
		this.cperiodo = cperiodo;
		this.stamp = stamp;
	}

	public void setEstado(int estado){
		this.estado = estado;
	}
	public void setTotal(double total){
		this.total = total;
	}
	public void setCPeriodo(double cperiodo){
		this.cperiodo = cperiodo;
	}
	public void setStamp(long stamp){
		this.stamp = stamp;
	}

	public int getEstado(){
		return this.estado;
	}
	public double getTotal()){
		return this.total;
	}
	public double getCPeriodo(){
		return this.cperiodo;
	}
	public long getStamp(){
		return this.stamp;
	}

	public Lampada clone(){
		return new Lampada(this);
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append("Lâmpada -{");
		switch(this.estado){
			case 0:
				sb.append("OFF}-");
				break;
			case 1:
				sb.append("ON}-");
				break;
			case 2:
				sb.append("ECO}-");
				break;
			default:
				break;
		}
		sb.append("\n\nConsumo total: ");
		sb.append(this.total);
		sb.append("\nPeríodo de consumo: ");
		sb.append(this.cperiodo);
		sb.append("\nStamp: ");
		sb.append(this.stamp);

		return sb.toString();
	}

	public boolean equals(Object obj){
		if(obj==this) return true;
        if(obj==null || obj.getClass() != this.getClass()) return false;
        Lampada l = (Lampada) obj;
        return l.getEstado().equals(this.estado) &&
              l.getTotal().equals(this.total) && 
              l.getCPeriodo().equals(this.cperiodo) &&
              l.getStamp().equals(this.stamp);
	}

}