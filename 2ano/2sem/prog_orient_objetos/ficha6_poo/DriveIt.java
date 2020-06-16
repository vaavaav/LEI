import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class DriveIt implements Serializable{
   private static final long serialVersionUID = 1L;
   private static final String DRIVEIT_SAVE_FILE = "driveit.dat";
   private boolean veiculoOcasiaoPromo;
   private Map<String, Veiculo> veiculos;
   private Map<String, Comparator<Veiculo>> comparadores;

   public DriveIt(){
       this.veiculos = new HashMap<>();
       this.veiculoOcasiaoPromo = false;
       this.comparadores = new HashMap<>();
   }

   public DriveIt(Map<String, Veiculo> veiculos, boolean veiculoOcasiaoPromo, Map<String, Comparator<Veiculo>> m){
        this.veiculos = new HashMap<>();
        for(String s : veiculos.keySet())
            this.veiculos.putIfAbsent(s, veiculos.get(s));
        for(String s : m.keySet())
            this.comparadores.putIfAbsent(s, m.get(s));
        this.veiculoOcasiaoPromo = veiculoOcasiaoPromo;
   }


   /* a) */
   public boolean existeVeiculo(String cod){
       return this.veiculos.containsKey(cod);
   }
   /* b) */
   public int quantos(){
       return this.veiculos.size();
   }
   /* c) */
   public int quantos(String marca){
       return this.veiculos.values().stream().filter(x -> x.getBrand().equals(marca)).collect(Collectors.toList()).size();
   }
   /* d) */
   public Veiculo getVeiculo(String cod) throws NoVeiculoException{
        Veiculo v = this.veiculos.get(cod);   
        if(v == null)
            throw new NoVeiculoException("O veículo com a matrícula \'" + cod + "\' não existe.");
       return v.clone();
   }
   /* e) */
   public void adiciona(Veiculo v) throws RepeatedVeiculoException{
       if(this.veiculos.get(v.getId()) != null)
            throw new RepeatedVeiculoException("O veículo \'" + v.getId() + "\' já existe.");
       this.veiculos.putIfAbsent(v.getId(), v);
   }
   /* f) */
   public List<Veiculo> getVeiculos(){
        List<Veiculo> v = new ArrayList<>();
        for(Veiculo aux : this.veiculos.values())       
            v.add(aux.clone());
        return v;
   }
   /* g) */
   public void adiciona(Set<Veiculo> vs) throws RepeatedVeiculoException{
        this.veiculos = new HashMap<>();
        for(Veiculo v : vs)
            adiciona(v);
   }
   /* h) */
   public void registrarAluguer(String cod, int numKms) throws InvalidInputException, NoVeiculoException{
       if(numKms <= 0)
          throw new InvalidInputException("Número de Km \'" + numKms + "\' é inválido.");
       Veiculo v = this.veiculos.get(cod);
       if(v == null)
          throw new NoVeiculoException("O veículo com a matrícula \'" + cod + "\' não existe.");
       v.setKmTotal(v.getKmTotal() + numKms);
   }
   /* i) */
   public void classificarVeiculo(String cod, int classificacao) throws InvalidInputException, NoVeiculoException{
    if(classificacao < 0 && classificacao > 10)
        throw new InvalidInputException("A classificação \'" + classificacao + "\' é inválida.");
    Veiculo v = this.veiculos.get(cod);
    if(v == null)
          throw new NoVeiculoException("O veículo com a matrícula \'" + cod + "\' não existe.");
    v.addClassificacao(classificacao);
   }
   /* j) */
   public double custoRealKm(String cod) throws NoVeiculoException{
       double price;
        Veiculo v = this.veiculos.get(cod);
        if(v == null)
            throw new NoVeiculoException("O veículo com a matrícula \'" + cod + "\' não existe.");
        price = v.custoRealKm();
        if(this.veiculoOcasiaoPromo && v.getClass().getSimpleName() == "VeiculoOcasiao")
            price *= 0.75;
        return price;
   }
   /* c') */
   public int quantosT(String tipo){
    return this.veiculos.values().stream().filter(x -> x.getClass().getSimpleName().equals(tipo)).collect(Collectors.toList()).size();
   }
   /* g')*/
   public List<Veiculo> veiculosOrdenadosCusto(){
       return this.veiculos.values().stream().sorted((v1,v2) -> (int) v2.getPrice() - (int) v1.getPrice()).collect(Collectors.toList());
   }
   /* i') */
   public Veiculo veiculoMaisBarato(){
        return this.veiculos.values().stream().sorted((v1,v2) -> (int) v1.getPrice() - (int) v2.getPrice()).collect(Collectors.toList()).get(0);
   }
   /* j') */
   public Veiculo veiculoMenosUtilizado(){
       return this.veiculos.values().stream().sorted((v1,v2) -> (int) v1.getKmTotal() - (int) v2.getKmTotal()).collect(Collectors.toList()).get(0);
   }
   /* n) */
   public void alteraPromocao(boolean estado){
       this.veiculoOcasiaoPromo = estado;
   }

   public double valorMedioPorKm(){
        int size = this.veiculos.size();
        return this.veiculos.values().stream().map(x -> x.getPrice()).reduce(0.0, (c,x) -> c + x) / size;   
   }

  /** public Set<Veiculo> ordenarVeiculos(){
        return this.veiculos.values().stream().sorted((v1,v2) -> v1.getClass().getSimpleName().compareTo(v2.getClass().getSimpleName())).collect(Collectors.toSet());
   }*/

    public List<Veiculo> ordenarVeiculos(){
        return this.veiculos.values().stream().sorted((v1,v2) -> v1.getClass().getSimpleName().compareTo(v2.getClass().getSimpleName())).collect(Collectors.toList());
    }

    public Set<Veiculo> ordenarVeiculos(Comparator<Veiculo> c){
        return this.veiculos.values().stream().sorted(c).collect(Collectors.toSet());
    }

    public void guardarComparador (String id, Comparator<Veiculo> c){
        this.comparadores.putIfAbsent(id, c);
    }

    public Iterator<Veiculo> ordenarVeiculo(String criterio){
        return this.veiculos.values().stream().sorted(this.comparadores.get(criterio)).iterator();
    }

    public List<BonificaKms> daoPontos(){
        return this.veiculos.values().stream().filter(x -> x instanceof BonificaKms).map(c -> (BonificaKms) c).collect(Collectors.toList());
    }

    public void load() throws IOException, ClassNotFoundException, RepeatedVeiculoException {
        ObjectInputStream is = new ObjectInputStream(new FileInputStream(DRIVEIT_SAVE_FILE));
        DriveIt d = (DriveIt) is.readObject(); 

        this.adiciona(d.getVeiculos().stream().collect(Collectors.toSet()));
        this.veiculoOcasiaoPromo = d.veiculoOcasiaoPromo;
        d.comparadores.entrySet().stream().forEach(me -> this.guardarComparador(me.getKey(), me.getValue()));
       
        is.close();
    }

    public void save() throws IOException {
        ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(DRIVEIT_SAVE_FILE));
        os.writeObject(this);
        os.close();
    }

    /*public void toCSV() throws IOException, ClassNotFoundException{
    }*/



}