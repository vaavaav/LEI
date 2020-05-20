import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Collections;
import java.time.LocalDateTime;
import java.util.stream.Collectors;

public class FBFeedMap{
    private Map<String, List<FBPost>> feed;

    public FBFeedMap(){
        this.feed = new HashMap<>();
    }

    public FBFeedMap(Map<String, List<FBPost>> feed){
        this.setFeed(feed);
    }

    public FBFeedMap(FBFeedMap f){
        this.setFeed(f.getFeed());
    }

    public void setFeed(Map<String, List<FBPost>> feed){
        this.feed = new HashMap<>();

        for(String s : feed.keySet())
            this.feed.put(s, new ArrayList<>(feed.get(s)));
    }

    public Map<String, List<FBPost>> getFeed(){
        Map<String, List<FBPost>> r = new HashMap<>();

        for(String s : this.feed.keySet())
            r.put(s, new ArrayList<>(this.feed.get(s)));

        return r;
    }

    protected FBFeedMap clone() {
        return new FBFeedMap(this);
    }

    public boolean equals(Object obj) {
        if(obj==this) return true;
        if(obj==null || obj.getClass()!=this.getClass()) return false;
        FBFeedMap f = (FBFeedMap) obj;
        return this.feed.equals(f.feed);
    }


    public String toString() {
        StringBuilder sb = new StringBuilder();

        for(String s : this.feed.keySet()){
            sb.append("Utilizador: ");
            sb.append(s);
            sb.append("\nPosts:\n");
            sb.append(this.feed.get(s));
        }

        return sb.toString();
    }
    
    /** 
    * i. método que permite adicionar um post de um utilizador
    */
    public void addPost(String user, FBPost post){
        this.feed.putIfAbsent(user, new ArrayList<>());
        this.feed.get(user).add(post);
    }

    /** 
    * ii. método que remove os posts de um utilizador
    * entre duas datas.
    */
    public void removePosts(String user, LocalDateTime di, LocalDateTime df){
        
        for(FBPost p : this.feed.get(user))
            if(!p.getData().isBefore(di) && !p.getData().isAfter(df))
                this.feed.get(user).remove(p);
    
    }

    /** 
    * iii. método que determina quantos posts 
    * foram publicados durante um período de tempo
    */
    public int postsNumPeriodo(String user, LocalDateTime di, LocalDateTime df){
        int s = 0;
        for(FBPost p : this.feed.get(user))
            if(!p.getData().isBefore(di) && !p.getData().isAfter(df))
                s++;

        return s;
    }

    /** 
    * iv. método que determina o utilizador mais ativo
    * num determinado período de tempo
    */
    public String utilizadorMaisActivo(LocalDateTime di, LocalDateTime df){
        int user_a = 0, aux = 0;
        String user = "n/a";
        for(String s : this.feed.keySet()){
            aux = this.postsNumPeriodo(s, di, df);
            if(aux > user_a){
                user_a = aux;
                user = s;
            }
        }

        return user;
    }
    
    /** 
    * v. método que determina a timeline do sistema 
    * ordenando cronologicamente todos os posts
    */
    public List<FBPost> timelineGlobal(){
        Map<LocalDateTime, FBPost> aux = new HashMap<>();
        List<FBPost> p = new ArrayList<>(); 

        for(String user : this.feed.keySet())
            for(FBPost fp : this.feed.get(user))
                aux.put(fp.getData(), fp.clone());
        
        p.addAll(aux.values());

        return p;
    }

    /** 
    * vi. método que valida que não existe nenhum
    * utilizador que tenham feito mais que um post 
    * num determinado instante
    */
    public boolean validaPostsSimultaneos(){
        int l_size, s_size; 

        for(String user : this.feed.keySet()){
            l_size = this.feed.get(user).size();
            s_size = this.feed.get(user).stream().map(fp -> fp.getData()).collect(Collectors.toSet()).size();
            if(l_size != s_size)
                return false;
        }

        return true;
    }











}