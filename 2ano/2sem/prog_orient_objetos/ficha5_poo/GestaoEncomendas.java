import java.util.Set;
import java.util.*;
import java.util.Map;
import java.util.HashMap;
import java.time.LocalDate;
import java.util.Collections; 
import java.util.stream.Collectors; 

class SortbyValorTotal implements Comparator<Encomenda> 
{ 
    // Used for sorting in descending order of 
    // Valor Total
    public int compare(Encomenda a, Encomenda b) 
    { 
        return (int) (b.calculaValorTotal() - a.calculaValorTotal()); 
    } 
} 

public class GestaoEncomendas{
	private Map<String, Encomenda> gest;

	public GestaoEncomendas(){
		this.gest = new HashMap<>();
	}

	public GestaoEncomendas(GestaoEncomendas g){
		this.gest = g.getGest();
	}

	public GestaoEncomendas(Map<String, Encomenda> m){
		this.setGest(m);
	}
	

	public void setGest(Map<String, Encomenda> m){
		this.gest = new HashMap<>();
		for (Map.Entry<String,Encomenda> entry: m.entrySet())
			this.gest.put(entry.getKey(), entry.getValue().clone());
	}

	public Map<String,Encomenda> getGest() {
	Map<String,Encomenda> copy = new HashMap<>();

	for (Map.Entry<String,Encomenda> entry: this.gest.entrySet()) 
		copy.put(entry.getKey(), entry.getValue().clone());

	return copy;
	}

	public boolean equals(Object o){
		if(o == this) return true;
		if(o == null || o.getClass() != this.getClass()) return false;

		GestaoEncomendas g = (GestaoEncomendas) o;
		if(this.gest.size() != g.gest.size()) return false;
		return this.gest.entrySet().stream()
      .allMatch(e -> e.getValue().equals(g.gest.get(e.getKey())));
	}

	public String toString(){
		StringBuilder mapAsString = new StringBuilder("{");
    	for (String key : this.gest.keySet()) 
        	mapAsString.append(key + "=" + this.gest.get(key) + ", ");
    	mapAsString.delete(mapAsString.length()-2, mapAsString.length()).append("}");
    	return mapAsString.toString();
	} 

	public GestaoEncomendas clone(){
		GestaoEncomendas g = new GestaoEncomendas(this.gest);
		return g;
	}

	public Set<String> todosCodigosEnc(){
		return this.gest.keySet();
	}

	public void addEncomenda(Encomenda enc){
		this.gest.put(enc.getNome(), enc.clone());
	}

	public Encomenda getEncomenda(String codEnc){
		return this.gest.get(codEnc);
	}

	public void removeEncomenda(String codEnc){
		this.gest.remove(codEnc);
	}

	public String encomendaComMaisProdutos(){
		int max = 0, aux;
		String maxS = null;
		for (Map.Entry<String,Encomenda> entry: this.gest.entrySet()) {
			aux = entry.getValue().getLinhas().size();
			if(aux > max){
				max = aux;
				maxS = entry.getKey();
			}
		}
		return maxS;
	}

	public Set<String> encomendasComProduto(String codProd){
		Set<String> r = new HashSet<>();
		for(Map.Entry<String,Encomenda> entry: this.gest.entrySet()){
			if(entry.getValue().getLinhas().stream().anyMatch(x -> x.getReferencia().equals(codProd)))
				r.add(entry.getKey());
		}
		return r;
	}

	public Set<String> encomendasAposData(LocalDate d){
		Set<String> r = new HashSet<>();
		for(Map.Entry<String,Encomenda> entry : this.gest.entrySet()){
			if(entry.getValue().getData().isAfter(d))
				r.add(entry.getKey());
		}
		return r;
	}

	public Set<Encomenda> encomendasValorDecrescente(){
		List<Encomenda> aux = new ArrayList<>();
		for( Encomenda e : this.gest.values())
		 	aux.add(e);

		Collections.sort(aux, new SortbyValorTotal());

		Set<Encomenda> r = aux.stream().collect(Collectors.toSet());

		return r;
	}


}