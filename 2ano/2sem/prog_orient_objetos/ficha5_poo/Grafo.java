import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;

public class Grafo {
    private Map<Integer, Set<Integer>> adj;

    public Grafo(){
        this.adj = new HashMap<>();
    }

    public Grafo(Map<Integer, Set<Integer>> adj){
        setAdj(adj);
    }

    public void setAdj(Map<Integer, Set<Integer>> adj){
        this.adj = new HashMap<>();

        for(Integer i : adj.keySet())
            this.adj.put(i, new HashSet<>(adj.get(i)));
    }

    public void addArco(Integer ori, Integer dest){
        this.adj.putIfAbsent(ori, new HashSet<>());
        this.adj.putIfAbsent(dest, new HashSet<>());
        this.adj.get(ori).add(dest);
    }

    public boolean isSink(Integer v){
        return this.adj.containsKey(v) && this.adj.get(v).isEmpty();
    }

    public boolean isSource(Integer v){
        if(this.adj.containsKey(v)) return false;

        for(Set<Integer> s : this.adj.values())
            if(s.contains(v))
                return false;
    
        return true;
    }

    public int size(){
        int tam = this.adj.size();
        tam += this.adj.values().stream().mapToInt(s -> s.size()).sum();
        return tam;
    }

    private boolean haCaminho(Integer ori, Integer dest, Set<Integer> visitados){
        boolean hac;
        if(ori.equals(dest))
            hac = true;
        else{
            if(visitados.contains(ori))
                hac = false;
            else{
                Iterator<Integer> i = adj.get(ori).iterator();
                hac = false;
                visitados.add(ori);
                while(i.hasNext() && !hac)
                    hac = haCaminho(i.next(), dest, visitados);
            }
        }
        return hac;
    }
    public boolean haCaminho(Integer ori, Integer dest){
        return haCaminho(ori, dest, new HashSet<>());
    }

    


}